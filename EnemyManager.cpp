#include "EnemyManager.h"

#include<iostream>
using namespace std;
#include <vector>

#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include "Shot.h"
#include "Particle.h"

std::vector<Enemy *> EnemyManager::enemyAr; //Necessary since the vectors are static.
std::vector<Shot *> EnemyManager::shotAr; //ditto

void EnemyManager::setUp(){ ///Jeg har ikke ide.

}

void EnemyManager::update(){

	//Updates the shot vector.  If the shot has hit it's target, it is removed from the vector.
	for(unsigned int x = 0; x < EnemyManager::shotAr.size(); x ++){
		if( EnemyManager::shotAr.at(x)->dead )
			EnemyManager::shotAr.erase(EnemyManager::shotAr.begin()+x);
	}
	
	//Updates the enemy vector.  If it's health is <= 0 i.e. dead = true, it is erased.
	for(unsigned int x = 0; x < EnemyManager::enemyAr.size(); x ++){
		if( EnemyManager::enemyAr.at(x)->dead )
			EnemyManager::enemyAr.erase(EnemyManager::enemyAr.begin()+x);
	}
	//Calls for the shot positions to be updated.
	for(unsigned int x = 0; x < EnemyManager::shotAr.size(); x ++){
		EnemyManager::shotAr.at(x)->update();
	}

	//Calls for the enemy positions to be updated.
	for(unsigned int x = 0; x < EnemyManager::enemyAr.size(); x ++){
		EnemyManager::enemyAr.at(x)->update();
	}	
	
}
