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

Tile::Tile(int tempX, int tempY,int newRow,int newCol){

	whiteBG = new Graphic("rectangle",tempX,tempY);
	whiteBG->setDimensions( 40, 40 );
	whiteBG->setColor(255,255,255);

	redBG = new Graphic("rectangle",tempX,tempY);
	redBG->setDimensions( 40, 40 );
	redBG->setColor(255,0,0);

	greenBG = new Graphic("rectangle",tempX,tempY);
	greenBG->setDimensions( 40, 40 );
	greenBG->setColor(0,255,0);

	yellowBG = new Graphic("rectangle",tempX,tempY);
	yellowBG->setDimensions( 40, 40 );
	yellowBG->setColor(255,255,255);

	myGraphicBlack = new Graphic("rectangle",tempX,tempY);
	myGraphicBlack->setDimensions( 40, 40 );
	myGraphicBlack->setColor(0,0,0);

	myGraphic = new Graphic("rectangle", tempX,tempY);
	myGraphic->setDimensions( 36, 36 );
	myGraphic->setColor(0,0,0);

	myGraphicWhite = new Graphic("rectangle", tempX,tempY);
	myGraphicWhite->setDimensions( 36, 36 );
	myGraphicWhite->setColor(100,100,100);

	myGraphicSmall = new Graphic("rectangle",tempX,tempY);
	myGraphicSmall->setDimensions( 20, 20 );
	
	row = newRow;
	col = newCol;

	drawMe = true;

	if( (row == 13 && col != 9) || (row >= 1 && col == 0) ){//|| (row < 3 && col < 4) )
		taken = true;
		drawMe = false;
	}
	else
		taken = false;

	if(row == 0 && col == 0 || row == 13 && col == 9)
		drawMe = false;
	

	mouseOver = false;
	//myTower = NULL;
}

void Tile::draw(){

	//If we're trying to place a tower, we'll display 
	//	either a green or red for this tower. Green
	//	means not set, red means set.
		
	if(drawMe){
		//we're placing a tower, draw red or green
		if(TowerManager::placingTower != NULL){
			if(taken)	
				redBG->draw();
			else if(mouseOver)
				yellowBG->draw();
			else
				greenBG->draw();
		}
		//we're not placing a tower, draw normally
		else
			whiteBG->draw();
		
		if(mouseOver && !taken)
			myGraphicWhite->draw();
		else
			myGraphic->draw();
	}
	else{
		myGraphicBlack->draw();
	}
		
}


