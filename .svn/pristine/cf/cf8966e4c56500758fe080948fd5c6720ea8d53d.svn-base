#include "Tower.h"
#include "TowerManager.h"

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

std::vector<Tower *> TowerManager::towerAr;
std::vector<Tile *> TowerManager::tileAr;
Tower * TowerManager::placingTower = NULL;

Graphic *	TowerManager::GunTowerBuy;
Graphic * TowerManager::RodTowerBuy;
Graphic *	TowerManager::NetTowerBuy;
Graphic * TowerManager::BPTowerBuy;
Graphic * TowerManager::LightningTowerBuy;



void TowerManager::setUp(){

	TowerManager::RodTowerBuy = new Graphic("Rod",671,50);
	TowerManager::GunTowerBuy = new Graphic("Gun",671,120);
	TowerManager::NetTowerBuy = new Graphic("Net",671,190);
	TowerManager::LightningTowerBuy = new Graphic("Lightning",671,260);
	TowerManager::BPTowerBuy = new Graphic("BP",671,330);


	TowerManager::GunTowerBuy->setDimensions(40,40);
	TowerManager::RodTowerBuy->setDimensions(40,40);
	TowerManager::NetTowerBuy->setDimensions(40,40);

	int startX = 74;
	int startY = 104;
	
	for(int y = 0; y < 10; y ++){
		for(int x = 0; x < 14; x ++){
			TowerManager::tileAr.push_back( new Tile( startX + x * 40, startY + y * 40,x,y) );
		}
	}

}

void TowerManager::update(){

	for(unsigned int x = 0; x < TowerManager::towerAr.size(); x ++){
		TowerManager::towerAr.at(x)->update();
	}
	
}

