#ifndef _TOWER_
#define _TOWER_

using namespace std;

#include "Tile.h"
#include "Graphic.h"


class Tower{

	public:
		Graphic * myGraphic; 
		Tile * myTile;

		string type;

		bool set;

		int shotSpeed;
		int curShot;
		int power;
		

		Tower(string type, int x, int y);
		~Tower(){};

		void setMe(Tile * newTile);
		void setPosition(int x,int y);

		void update();
		void draw();
		
};

#endif  // _TOWER_
