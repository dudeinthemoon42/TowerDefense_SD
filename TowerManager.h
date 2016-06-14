#ifndef _TOWERMANAGER_
#define _TOWERMANAGER_

#include "Tower.h"
#include "Tile.h"
#include "Enemy.h"

class TowerManager{

	public:
		static std::vector<Tower *> towerAr;
		static std::vector<Tile *> tileAr;
		static Tower * placingTower;		

		static Graphic * GunTowerBuy;
		static Graphic * RodTowerBuy;
		static Graphic * NetTowerBuy;
		static Graphic * LightningTowerBuy;
		static Graphic * BPTowerBuy;

		TowerManager(){};
		~TowerManager(){};
		void setUp();
		void update();


		static bool hitTest(const Graphic * graphic1, const Graphic * graphic2){

			bool tester=false;
			if(graphic1->x+(graphic1->width)/2>graphic2->x-(graphic2->width)/2 && graphic1->y+(graphic1->height)/2>graphic2->y-(graphic2->height)/2 && graphic2->x+(graphic2->width)/2>graphic1->x-(graphic1->width)/2 && graphic2->y+(graphic2->height)/2>graphic1->y-(graphic1->height)/2)
				tester=true;

			return tester;
		}


		static bool hitTest(const Tower * tower, const Enemy * enemy){
			bool tester=false;	
			if( hitTest(tower,enemy) )
				tester=true;
			return tester;
		}


		static bool hitTest(const Enemy * enemy, const Tower * tower){
			bool tester=false;
			if( hitTest(enemy,tower) )
				tester=true;
			return tester;
		}

};


#endif  // _TOWERMANAGER_
