#include <boost/timer.hpp>
#include "GraphicsManager.h"
#include "GameManager.h"
#include "SearchManager.h"

#include<iostream>
using namespace std;
#include <vector>
#include<string.h>

#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>

char * GameManager::currentLevel;

std::vector<Graphic *> GameManager::heartAr; //Necessary since heartAr is static.

int GameManager::numLives=5; //Declares the users lives as an int.



void GameManager::loseLife(){

	if (numLives>=1){
		numLives--; //subtracts life if there are any left.
			GameManager::heartAr.erase(heartAr.begin()+numLives);
	}
	if (numLives == 0){ //Quits game if there are no more lives.
		cout << "GAME OVER" << endl;
		exit(0);
	}
}

void GameManager::setUp(){
	steps = 0;
	for (int k = 0; k<numLives; k++) {
		Graphic *newGraphic;
		newGraphic = new Graphic("Heart", GraphicsManager::screenWidth - 40*k - 100, 25); //creates a heart graphic
		GameManager::heartAr.push_back( newGraphic ); //appends the heart graphic to the end of heartAr.
		}
	
}
bool notSpawned = true;
void GameManager::gameLoop(){
		
		//time in milliseconds
		int curTime = (int)(timerObj.elapsed()*100);
		
		//int curTime = 0;
		//we set up a stepping system here, with each
		//	step ~50 times a second.  Now that we have
		//	this we can update towers/graphics etc with
		//	the steps created here
		if(curTime % 2 == 0 && lastTime != curTime){
			steps ++;
			lastTime = curTime;
		}

		//make sure we don't repeat steps before we update 
		//	things
		if(lastStep == steps)
			return;
		else
			lastStep = steps;

		if(steps % 2 == 0){
			//If 2 steps have gone, enemies are updated and towers are updated.;
			GraphicsManager::towerManager.update();		
		}
		if(steps % 2 == 0)
			GraphicsManager::enemyManager.update();

		if(steps % 1 == 0){
			for(unsigned int x = 0; x < Particle::particleAr.size(); x ++){
				if( Particle::particleAr.at(x)->dead )
					Particle::particleAr.erase(Particle::particleAr.begin()+x);
				else{
					Particle::particleAr.at(x)->update();
					Particle::particleAr.at(x)->draw();
				}
			}
		}
		
		//Pointer to the enemy that may be created.
		Enemy * newEnemy;
		//Creates a new enemy every 60 steps.  approximately 1/s
		int tempStep = -1;
		
		if (curTime < 200) {
			GameManager::currentLevel = ("Level 1");
		}
		else if (curTime >= 200 && curTime < 1800) {
			GameManager::currentLevel = NULL;
			if (curTime >1650 && curTime < 1800)
				tempStep = -1;
			else
				tempStep = 120;
			}
		
		else if (curTime >=1800 && curTime <2000) {
			GameManager::currentLevel = ("Level 2");
			}
		
		else if (curTime >=2000 && curTime < 3800) {
			GameManager::currentLevel = NULL;
			if (curTime > 3750 && curTime < 3800)
				tempStep = -1;
			else
				tempStep = 90;
			}
			
		else if (curTime >= 3800 && curTime < 4000) {
			GameManager::currentLevel = ("Level 3");
			}
			
		else if (curTime >= 4000 && curTime < 5800) {
			GameManager::currentLevel = NULL;
			if (curTime > 5750 && curTime < 5800)
				tempStep = -1;
			else
				tempStep = 70;
			}
			
		else if (curTime > 5800 && curTime < 6000) {
			GameManager::currentLevel = ("Level 4");
			}
		else if (curTime >= 6000 && curTime < 7800) {
			GameManager::currentLevel = NULL;
			if (curTime > 7750 && curTime < 7800) 
				tempStep = -1;
			else
				tempStep = 60;
			}
		else if (curTime >= 7800 && curTime < 8000) {
			GameManager::currentLevel = ("Level 4");
			}
		else if (curTime >= 8000 && curTime <9800) {
			GameManager::currentLevel = NULL;
			tempStep = 40;
			}
		else if (curTime >= 9800 && curTime <12000) {
			GameManager::currentLevel = ("WIN!!!");
			}
		else {
			cout << "WINNING!!!!" << endl;
			cout << "Score gained: " << MoneyManager::totalPoints << endl;
			exit(0);
			}
			
		
		if (steps % tempStep == 0 && tempStep != -1) {
			//random number used to determine which enemies are created.
			int rand = random()%100;			
			notSpawned = false;
			
			int startX = 40;
			int startY = 60;
			if (curTime <= 1500) {
				if (rand <=90) 
					newEnemy = new Enemy("Goldfish", startX, startY);
				else
					newEnemy = new Enemy("Seahorse", startX, startY);
				}
				
			else if (curTime <= 2000 && curTime < 4000)
				if (rand <= 20)
					newEnemy = new Enemy("Goldfish", startX, startY);
				else if (rand <= 40)
					newEnemy = new Enemy("Seahorse", startX, startY);
				else 
					newEnemy = new Enemy("Shark", startX, startY);
			
			else if (curTime <= 4000 && curTime < 6000) 
				if (rand <=10)
					newEnemy = new Enemy("Goldfish", startX, startY);
				else if (rand <=30)
					newEnemy = new Enemy("Seahorse", startX, startY);
				else if (rand <= 60)
					newEnemy = new Enemy ("Shark", startX, startY);
				else
					newEnemy = new Enemy("Octopus", startX, startY);
			
			else if (curTime <= 6000 && curTime < 8000)
				if (rand <= 5)
					newEnemy = new Enemy("Goldfish", startX, startY);
				else if (rand <= 15)
					newEnemy = new Enemy ("Seahorse", startX, startY);
				else if (rand <= 40)
					newEnemy = new Enemy ("Shark", startX, startY);
				else if (rand <= 70)
					newEnemy = new Enemy ("Octopus", startX, startY);
				else
					newEnemy = new Enemy("Triton", startX, startY);
			
			else if (curTime <= 8000 && curTime < 10000)
				if (rand <= 3)
					newEnemy = new Enemy ("Goldfish", startX, startY);
				else if (rand <= 10)
					newEnemy = new Enemy("Seahorse", startX, startY);
				else if (rand <= 20)
					newEnemy = new Enemy("Shark", startX, startY);
				else if (rand <= 50)
					newEnemy = new Enemy("Octopus", startX, startY);
				else
					newEnemy = new Enemy("Triton", startX, startY);
					
			if(newEnemy != NULL){
				//makes the initial enemy movement so it is displayed on the screen.
				newEnemy->moveTo(20, 100);
				//newEnemy is appended to the enemy vector.
				EnemyManager::enemyAr.push_back( newEnemy );	
			}
		}
		
}



