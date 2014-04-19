/*Copyright (C) 2014  Béguet Eric

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.*/

#include "DesktopApplication.h"


DesktopApplication::DesktopApplication(): current(0) {}

void DesktopApplication::right(){
    goTo(current >= maxDesktops - 1 ? 0 : current + 1);
}

void DesktopApplication::left(){
    goTo(current <= 0 ? maxDesktops - 1 : current - 1);
}

void DesktopApplication::moveRight(){
    moveTo(current >= maxDesktops - 1 ? 0 : current + 1);
}

void DesktopApplication::moveLeft(){
    moveTo(current <= 0 ? maxDesktops - 1 : current - 1);
}

void DesktopApplication::moveTo(unsigned int desktopID){
    if (current != desktopID && desktopID >= 0 && desktopID < maxDesktops){
        auto tmp = current;
        HWND hwnd = GetForegroundWindow();
        ShowWindow(hwnd, SW_HIDE);
        goTo(desktopID);
        desktops[tmp].remove(hwnd);
        desktops[desktopID].add(hwnd);
        ShowWindow(hwnd, SW_SHOW);
        SetActiveWindow(hwnd);
    }
}

void DesktopApplication::goTo(unsigned int desktopID){
    if (current != desktopID && desktopID >= 0 && desktopID < maxDesktops){
        desktops[current] = getCurrentWindows();
        desktops[current].close();
        desktops[desktopID].open();
        current = desktopID;
        SetActiveWindow(desktops[current].first());
   }
}

void DesktopApplication::displayAll() {
    for (auto desktop :  desktops)
         desktop.open();
    SetActiveWindow(GetTopWindow(NULL));
}

//from http://blogs.msdn.com/b/oldnewthing/archive/2007/10/08/5351207.aspx
BOOL DesktopApplication::IsAltTabWindow(HWND hwnd){
    // Start at the root owner
    HWND hwndWalk = GetAncestor(hwnd, GA_ROOTOWNER);
    // See if we are the last active visible popup
    HWND hwndTry;
    while ((hwndTry = GetLastActivePopup(hwndWalk)) != hwndWalk) {
        if (IsWindowVisible(hwndTry))
            break;
        hwndWalk = hwndTry;
    }
    return hwndWalk == hwnd;
}

std::vector<WindowID> DesktopApplication::getCurrentWindows(){
    std::vector<WindowID> windows;
    HWND hwnd = GetForegroundWindow();
    while (hwnd) {
        if (IsWindowVisible(hwnd) && IsAltTabWindow(hwnd)) // /*(wininfo.dwStyle & (WS_TABSTOP | WS_VISIBLE)) && !(winplace.showCmd & SW_HIDE) &&*/
            windows.push_back(hwnd);

        hwnd = GetNextWindow(hwnd,GW_HWNDNEXT);
    }
    return windows;
}
