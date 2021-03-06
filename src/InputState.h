/*
Copyright © 2011-2012 Clint Bellanger

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/


#pragma once
#ifndef INPUT_STATE_H
#define INPUT_STATE_H

#include "CommonIncludes.h"
#include "Utils.h"

#define JOY_POS_CENTER	0
#define JOY_POS_LEFT	-1
#define JOY_POS_RIGHT	1
#define JOY_POS_UP	-1
#define JOY_POS_DOWN	1


// Input commands enum
const int CANCEL = 0;
const int ACCEPT = 1;
const int UP = 2;
const int DOWN = 3;
const int LEFT = 4;
const int RIGHT = 5;
const int BAR_1 = 6;
const int BAR_2 = 7;
const int BAR_3 = 8;
const int BAR_4 = 9;
const int BAR_5 = 10;
const int BAR_6 = 11;
const int BAR_7 = 12;
const int BAR_8 = 13;
const int BAR_9 = 14;
const int BAR_0 = 15;
const int CHARACTER = 16;
const int INVENTORY = 17;
const int POWERS = 18;
const int LOG = 19;
const int MAIN1 = 20;
const int MAIN2 = 21;
const int CTRL = 22;
const int SHIFT = 23;
const int DEL = 24;
const int ACTIONBAR = 25;
const int ACTIONBAR_BACK = 26;
const int ACTIONBAR_FORWARD = 27;
const int ACTIONBAR_USE = 28;

/**
 * class InputState
 *
 * Handles keyboard and mouse states
 */

class InputState {
private:
	std::vector<int> wheel_binds;

public:
	static const int key_count = 29;
	int binding[key_count];
	int binding_alt[key_count];
	int binding_joy[key_count];

	std::string binding_name[29];
	std::string mouse_button[7];

	InputState(void);
	~InputState();

	void defaultQwertyKeyBindings();
	void defaultJoystickBindings();
	void loadKeyBindings();
	void saveKeyBindings();
	void handle(bool dump_event);
	void resetScroll();
	void lockActionBar();
	void unlockActionBar();
	void setKeybindNames();
	void hideCursor();
	void showCursor();

	bool pressing[key_count];
	bool lock[key_count];

	bool done;
	Point mouse;
	std::string inkeys;
	int last_key;
	int last_button;
	bool scroll_up;
	bool scroll_down;
	bool lock_scroll;
};

#endif
