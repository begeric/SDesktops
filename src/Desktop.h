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

#ifndef DESKTOP_H
#define DESKTOP_H

#include <windows.h>
#include <vector>

/*Current representation of a window*/
typedef HWND WindowID;

/*Class describing a desktop, it contains a set of accesivle windows*/
class Desktop {

    public :

        Desktop();

        Desktop(const std::vector<WindowID>& windows_);

        HWND first();

        /*Close all windows of this desktops*/
        void close();

        /*Display all windows of this desktops*/
        void open();

        /*Add a window to this desktop, used to move a window from another desktop*/
        void add(WindowID wind);

        /*Remove a window from this desktop, used to move a window to another desktop*/
        bool remove(WindowID wind);

    private :

        std::vector<WindowID> windows;
};

#endif // DESKTOP_H
