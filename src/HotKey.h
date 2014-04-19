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

#ifndef HOTKEY_H
#define HOTKEY_H

#include <windows.h>


/*
Proxy class for the RegisterHotKey and UnregisterHotKey functions, so that one doesn't need to care about calling
UnregisterHotKey manually.
*/
class HotKey {

    public :

        HotKey();

        HotKey(HWND hwnd_, int id_, UINT fsModifiers,UINT vk);

        void register_(HWND hwnd_, int id_, UINT fsModifiers,UINT vk);

        void unregister();

    private :

        HWND hwnd;
        int id;
};
#endif // HOTKEY_H
