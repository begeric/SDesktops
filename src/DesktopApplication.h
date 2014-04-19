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

#ifndef DESKTOPAPPLICATION_H
#define DESKTOPAPPLICATION_H

#include <array>

#include "Desktop.h"

/*Current number of desktops, 9 for conveniance*/
const unsigned int maxDesktops = 9;

class DesktopApplication {

    public :

        DesktopApplication();

        /*Go to the right desktop*/
        void right();

        /*Go to the left desktop*/
        void left();

        /*Move the current window to the right desktop*/
        void moveRight();

        /*Move the current window to the left desktop*/
        void moveLeft();

        /*Go to the desktopID desktop*/
        void moveTo(unsigned int desktopID);

        /*Move the current window to the desktopID desktop*/
        void goTo(unsigned int desktopID);

        void displayAll();

    private :


        BOOL IsAltTabWindow(HWND hwnd);

        std::vector<WindowID> getCurrentWindows();

        std::array<Desktop, maxDesktops> desktops;
        unsigned int current;
};


#endif // DESKTOPAPPLICATION_H
