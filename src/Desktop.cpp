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

#include "Desktop.h"


Desktop::Desktop() {}

Desktop::Desktop(const std::vector<WindowID>& windows_): windows(windows_){}

HWND Desktop::first(){
    if (windows.size() > 0)
        return windows[0];
    return NULL;
}

void Desktop::close(){
    for (auto w : windows)
        ShowWindow(w, SW_HIDE);
}

void Desktop::open(){
    for (auto w : windows)
        ShowWindow(w, SW_SHOW);
}

void Desktop::add(WindowID wind){
    windows.push_back(wind);
}

bool Desktop::remove(WindowID wind){
    for (auto it =  windows.begin(); it != windows.end(); ++it){
        if (*it == wind){
            windows.erase(it);
            return true;
        }
    }
    return false;
}
