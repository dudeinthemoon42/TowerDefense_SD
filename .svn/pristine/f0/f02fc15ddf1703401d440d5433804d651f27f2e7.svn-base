using namespace std;
#include "Graphic.h"
#include "Enemy.h"
#include "Particle.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "SearchManager.h"
#include<iostream>

#include <vector>

#include <sstream> 
#include<iostream>
#include<fstream>
#include<GL/glut.h>
#include<math.h>



Enemy::Enemy(string tempType,int tempX, int tempY){
	type = tempType; //The type of the enemy is declared.

	dead = false;

	//Different cases for each type.  Gives the enemy a position and starting health.
	if(type == "Goldfish"){
		myGraphic = new Graphic("Goldfish",tempX,tempY);
		health = 8;
	}
	else if(type == "Seahorse"){
		myGraphic = new Graphic("Seahorse",tempX,tempY);
		health = 20;
	}
	else if(type == "Shark"){
		myGraphic = new Graphic("Shark",tempX,tempY);
		health = 50;
	}
	else if(type == "Octopus"){
		myGraphic = new Graphic("Octopus",tempX,tempY);
		health = 75;
	}
	else if(type == "Triton"){
		myGraphic = new Graphic("Triton",tempX,tempY);
		health = 125;
	}
	
	//This next section creates the health bar.  A white background, a red bar, and a green bar that gets resized on top of it.
	maxHealth = health;
	
	healthBG = new Graphic("rectangle",tempX,tempY - myGraphic->height/2 - 5);
	healthMainGreen	= new Graphic("rectangle",tempX,tempY - myGraphic->height/2 - 5);
	healthMainRed = new Graphic("rectangle",tempX,tempY - myGraphic->height/2 - 5);

	healthBG->setDimensions(40,6);
	healthMainGreen->setDimensions(36,4);
	healthMainRed->setDimensions(36,4);

	healthMainGreen->setColor(0,255,0);
	healthMainRed->setColor(255,0,0);
	healthBG->setColor(255,255,255);

};
//If the enemy is shot, health is subtracted.
void Enemy::shoot(int damage){
	health -= damage;
}
//Where the enemy wants to move is updated.
void Enemy::moveTo(int newX,int newY){

	targetX = newX;
	targetY = newY;
}
//Updates health, whether or not the enemy is alive, causes the the user 
//to lose life if the enemy has reached the user, and updates the health bar.
void Enemy::update(){

	if(health <= 0){
		for(int x = 0; x < 750; x ++){
			cout << "creating particles" << endl;
			Particle::particleAr.push_back( new Particle("purple",myGraphic->x,myGraphic->y ) );
		}

		dead = true;
		MoneyManager::addMoney(this);
	}
	else if( myGraphic->x > TowerManager::tileAr.at(138)->myGraphic->x ){
		GameManager::loseLife();
		dead = true;
	}
	else{

		double curXStep = 7 * cos( atan( (double)(myGraphic->y-targetY)/(double)(myGraphic->x-targetX) ) );
		double curYStep = 7 * sin( atan( (double)(myGraphic->y-targetY)/(double)(myGraphic->x-targetX) ) );
	
		double newX = myGraphic->x + curXStep;
		double newY = myGraphic->y + curYStep;		

		double newWidth = 36.0 * ( (double) health / (double) maxHealth)+1;
		healthMainGreen->setDimensions(newWidth,healthMainGreen->height);


		if( fabs(myGraphic->x - targetX) > 2 ){
			myGraphic->setPosition(newX, newY);
			newY = myGraphic->y + curYStep - myGraphic->height/2 - 5;
	
			healthBG->setPosition(newX,newY);
			double newX2 = (double)newX + ( (double)healthMainGreen->width/(double)2 - (double)healthMainRed->width/(double)2)-1;

			healthMainGreen->setPosition(newX2,newY);
			healthMainRed->setPosition(newX,newY);
		}


		int element = -1;

		for(unsigned int x = 0; x < TowerManager::tileAr.size();x ++)
			if(TowerManager::tileAr.at(x)->whiteBG->containsPoint(myGraphic->x,myGraphic->y)){
				element = x;
				break;
			}

		if(element == 139){
			dead = true;
			return;
		}
		
		bool updateMe = true;

		if(element != -1){
			if(currentTile != TowerManager::tileAr.at(element)){
				currentTile = TowerManager::tileAr.at(element);
				cout << "cur:(" << currentTile->row << "," << currentTile->col << ")"<<endl;
			}
			else
				updateMe = false;
		}

		if(updateMe){
			//run A*
			bool result = true;
			SearchManager::updateMap();
			if(element != -1)
				result = SearchManager::runMap(currentTile->row,currentTile->col);
			else
				result = SearchManager::runMap(0,0);
			//SearchManager::printMap();

			//Get the next element this is supposed to go to, this was set when A* was run
			element = (SearchManager::lastCol*14)+SearchManager::lastRow;
			targetTile = TowerManager::tileAr.at(element);

			targetX = targetTile->myGraphic->x;
			targetY = targetTile->myGraphic->y;

			if(!result)
				dead = true;
		}
		
		//SearchManager::printMap();

		

			
	}
	
}
//Draws the enemy and health bars.
void Enemy::draw(){
	if(!dead){
		myGraphic->draw();

		healthBG->draw();
		healthMainRed->draw();
		healthMainGreen->draw();
	}
}



