/*************************************************************************************
 *   Created on: Jan 23, 2013
 *
 *	AxaGame - http://axatrikx.com
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

#include "play.h"

Play::Play() {
	setStateName(STATE_PLAY);
}

Play::~Play() {
	// TODO Auto-generated destructor stub
}

int Play::init() {
	Logger(INFO) << "Initialized play state";

	IAnimatedMesh* mesh = irrScene->getMesh("data/media/spaceCraft.obj"); //3ds , obj
	IAnimatedMeshSceneNode* node = irrScene->addAnimatedMeshSceneNode(mesh);

	IAnimatedMesh* mesh1 = irrScene->getMesh("data/media/levelOne.dae"); //3ds , obj
	IAnimatedMeshSceneNode* node1 = irrScene->addAnimatedMeshSceneNode(mesh1);
	node1->setScale(vector3df(20, 20, 20));

	if (node) {
		//node->setMaterialFlag(EMF_LIGHTING, false);
		node->setFrameLoop(0, 310);
		node->setMaterialTexture(0, irrDriver->getTexture("data/media/spaceCraft.png"));
		node->setPosition(vector3df(0, 0, 0));
	}
	if (node1) {
		//node->setMaterialFlag(EMF_LIGHTING, false);
		node1->setFrameLoop(0, 310);
		node1->setMaterialTexture(0, irrDriver->getTexture("data/media/levelOne.png"));
		node1->setPosition(vector3df(0, 0, 0));
	}

	ICameraSceneNode* cam = irrScene->addCameraSceneNode(0, core::vector3df(0.0f, 0.0f, 0.0f),
			core::vector3df(0.0f, 0.0f, 0.0f), -1);
	cam->bindTargetAndRotation(true);
	cam->setPosition(vector3df(0, 10, -5));
	cam->setTarget(vector3df(0, 0, 30));
	vector3df diff = vector3df(0, 0, 0) - vector3df(0, 30, -30);
	ILightSceneNode* light = irrScene->addLightSceneNode(0, vector3df(0.0f, 200.0f, 0.0f),
			SColorf(1.0f, 1.0f, 1.0f, 1.0f), 300.0f);
	ILightSceneNode* ulight = irrScene->addLightSceneNode(0, vector3df(0.0f, -200.0f, 0.0f),
			SColorf(1.0f, 1.0f, 1.0f, 1.0f), 50.0f);
	ILightSceneNode* blight = irrScene->addLightSceneNode(0, vector3df(0.0f, -200.0f, -100.0f),
			SColorf(1.0f, 1.0f, 1.0f, 1.0f), 50.0f);
	return 1;
}
int Play::close() {
	return 1;
}

bool Play::onKeyPress(int key) {
	return false;
}
bool Play::onKeyLift(int key) {
	return false;
}
void Play::onMouseMotion(float valueX, float valueY) {
}
bool Play::onMousePress(int button, int valueX, int valueY) {
	return false;
}
void Play::onMouseLift(int button, int valueX, int valueY) {
}
//		virtual void onMouseWheel(float direction) { }

void Play::update() {
}
void Play::updateRender() {
}
void Play::render(float interpolation) {
}
