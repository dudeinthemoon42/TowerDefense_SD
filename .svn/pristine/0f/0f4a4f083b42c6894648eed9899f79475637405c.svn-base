using namespace std;
#include "Shot.h"
#include "Graphic.h"
#include "Enemy.h"
#include "Tower.h"
#include "EnemyManager.h"
#include<iostream>

#include <vector>

#include <sstream> 
#include<iostream>
#include<fstream>
#include<GL/glut.h>
#include<math.h>

Shot::Shot(string type, Tower * newTower, Enemy * newEnemy) {
	shotTower = newTower;
	targetEnemy = newEnemy;

	if(shotTower->type == "Gun"){
		myGraphic = new Graphic("circle",0,0);
		myGraphic->setRadius(4);
		myGraphic->setPosition(shotTower->myGraphic->x, shotTower->myGraphic->y);
		myGraphic->setColor(191,122,10);
	}
	else if(shotTower->type == "Rod"){
		myGraphic = new Graphic("circle",0,0);
		myGraphic->setRadius(4);
		myGraphic->setPosition(shotTower->myGraphic->x, shotTower->myGraphic->y);
		myGraphic->setColor(255,162,10);
	}
	else if(shotTower->type == "Net"){
		myGraphic = new Graphic("circle",0,0);
		myGraphic->setRadius(4);
		myGraphic->setPosition(shotTower->myGraphic->x, shotTower->myGraphic->y);
		myGraphic->setColor(29,189,8);
	}
	else if(shotTower->type == "BP"){
		myGraphic = new Graphic("circle",0,0);
		myGraphic->setRadius(7);
		myGraphic->setPosition(shotTower->myGraphic->x, shotTower->myGraphic->y);
		myGraphic->setColor(255,255,0);
	}
	else if(shotTower->type == "Lightning"){
		myGraphic = new Graphic("circle",0,0);
		myGraphic->setRadius(4);
		myGraphic->setPosition(shotTower->myGraphic->x, shotTower->myGraphic->y);
		myGraphic->setColor(11,81,230);
	}

	dead = false;
}	

void Shot::update () {
	int targetX = targetEnemy->myGraphic->x;
	int targetY = targetEnemy->myGraphic->y;	

	double curXStep = 15 * cos( atan2( (double)(targetY - myGraphic->y),(double)(targetX - myGraphic->x) ) );
	double curYStep = 15 * sin( atan2( (double)(targetY - myGraphic->y),(double)(targetX - myGraphic->x) ) );

	double targetRotation = atan2( (double)(myGraphic->y-targetY),(double)(myGraphic->x-targetX) );

	if( fabs(targetX - myGraphic->x ) > 3  && !targetEnemy->dead)
		myGraphic->setPosition( myGraphic->x + curXStep, myGraphic->y + curYStep );
	else{
		dead = true;
	}

}

void Shot::draw () {
	if(!dead )
		myGraphic -> draw();
}

