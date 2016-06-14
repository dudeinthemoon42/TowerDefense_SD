using namespace std;
#include "Graphic.h"
#include "Enemy.h"
#include "Tower.h"
#include "TowerManager.h"
#include "EnemyManager.h"
#include<iostream>

#include <vector>

#include <sstream> 
#include<iostream>
#include<fstream>
#include<GL/glut.h>
#include<math.h>



Tower::Tower(string tempType,int tempX, int tempY){
	type = tempType;

	myGraphic = new Graphic("rectangle",tempX,tempY);
	myGraphic->setDimensions(36,36);

	if(type == "Rod"){
		myGraphic = new Graphic("Rod",tempX,tempY);
		shotSpeed = 12;
		power = 2;
	}
	else if(type == "Gun"){
		myGraphic = new Graphic("Gun",tempX,tempY);
		shotSpeed = 10;
		power = 4;
	}
	else if(type == "Net"){
		myGraphic = new Graphic("Net",tempX,tempY);
		shotSpeed = 3;
		power = 5;
	}
	else if(type == "Lightning"){
		myGraphic = new Graphic("Lightning",tempX,tempY);
		shotSpeed = 8;
		power = 6;
	}
	else if(type == "BP"){
		myGraphic = new Graphic("BP",tempX,tempY);
		shotSpeed = 10;
		power = 7;
	}

	curShot = shotSpeed;//start 
	
	myGraphic->setDimensions(36,36);

};

void Tower::setPosition(int newX,int newY){
	myGraphic->setPosition(newX,newY);
}

void Tower::setMe(Tile * newTile){
	myTile = newTile;
	setPosition( myTile->myGraphic->x, myTile->myGraphic->y );

	set = true;
	TowerManager::towerAr.push_back(this);
	TowerManager::placingTower = NULL;
}


void Tower::update(){

	if(curShot == shotSpeed){

		for(unsigned int x = 0; x < EnemyManager::enemyAr.size(); x ++){
			Graphic tempGraphic("rectangle",myGraphic->x,myGraphic->y);
			tempGraphic.setDimensions(myGraphic->width + 100,myGraphic->height + 100);
			tempGraphic.setPosition(myGraphic->x,myGraphic->y);
		
			if( TowerManager::hitTest(&(tempGraphic),EnemyManager::enemyAr.at(x)->myGraphic) ){
				EnemyManager::shotAr.push_back( new Shot("shotType",this,EnemyManager::enemyAr.at(x)) );
				EnemyManager::enemyAr.at(x)->shoot(power);
				curShot = 0;
				break;
			}
		}

	}
	else
		curShot ++;

}


void Tower::draw(){

	myGraphic->draw();

}



