#ifndef _SHOT_
#define _SHOT_
#include "Graphic.h"
#include "Enemy.h"
#include "Tower.h"
#include <string>
#include <vector>
#include "Graphic.h"

class Shot {
	private:
		Graphic * myGraphic;
		Tower * shotTower;
		Enemy * targetEnemy;

		

	public:
		bool dead;
		//Shot(){};
		Shot(string type, Tower * newTower, Enemy * newEnemy);
		~Shot(){};
		void update();
		void draw();


};


#endif  // _SHOT_
