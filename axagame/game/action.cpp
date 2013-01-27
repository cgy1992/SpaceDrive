/*************************************************************************************
 *   Created on: Jan 27, 2013
 *
 *	SpaceDrive - http://axatrikx.com
 *	Copyright (C) 2013  Amal Bose
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************************/

#include "action.h"

Action::Action() {
	std::ifstream file(keyConfigFile);
	keyFile = &file;
	if (file == NULL) {
		Logger(ERROR) << "Error initializing log file : " << keyFile;
	}
	getConfiguration();
}

void Action::collectData() {
	std::string line;
	std::string name;
	std::string value;
	std::string inSection;
	int posEqual;
	while (std::getline(*keyFile, line)) {

		if (!line.length())
			continue;

		if (line[0] == '#')
			continue;
		if (line[0] == ';')
			continue;

		posEqual = line.find('=');
		name = line.substr(0, posEqual);
		value = line.substr(posEqual + 1);
		keyList.insert(std::pair<std::string,const char*>(Utils::trim(name), Utils::trim(value).c_str()));
	}
}

void Action::getConfiguration() {
	//collecting data for config
	collectData();

	//Converting keyList to key configure map
	//ACCELERATE
	keyConfig.insert(std::pair<Actions, irr::EKEY_CODE>(ACCELERATE, Event::getKey(getValue("ACCELERATE"))));
}

const char* Action::getValue(const char* key) {
	const char* value = keyList[key];
	if (value == "") {
		Logger(ERROR) << "Could not find key " << key;
	}
	return value;
}

std::string Action::getAction(Actions actionType) {
	std::string action;
	switch (actionType) {
	case UP:
		action = "up";
		break;
	case DOWN:
		action = "down";
		break;
	case ACCELERATE:
		action = "accelerate";
		break;
	case DECELERATE:
		action = "decelerate";
		break;
	case LEFT:
		action = "left";
		break;
	case RIGHT:
		action = "right";
		break;
	case BRAKE:
		action = "brake";
		break;
	default:
		Logger(ERROR) << "Could not identify action type " << actionType;
		break;
	}
	return action;
}

int Action::getKey(Actions actionType) {
	return keyConfig[actionType];
}
