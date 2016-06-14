#ifndef _TILE_
#define _TILE_

using namespace std;

#include <string>
#include <vector>
#include "Graphic.h"

class Tile{

	public:
		Graphic * redBG;
		Graphic * greenBG;
		Graphic * whiteBG;
		Graphic * yellowBG;
		Graphic * myGraphic;
		Graphic * myGraphicWhite;
		Graphic * myGraphicSmall;
		Graphic * myGraphicBlack;

		bool taken;
		bool drawMe;
		bool mouseOver;
		int row;
		int col;

		Tile();
		Tile(int x, int y,int newRow,int newCol);
		~Tile(){};

		void setMe(bool newTaken){taken = newTaken;};
		void draw();	
};

#endif  // _TILE_
