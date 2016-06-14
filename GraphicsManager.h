#ifndef _GRAPHICSMANAGER_
#define _GRAPHICSMANAGER_

#include <string>
#include <vector>
#include <map>

#include "Graphic.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "TowerManager.h"
#include "MoneyManager.h"



class GraphicsManager{

	public:
		static int screenWidth; //width of window
		static int screenHeight; //height of window
		static int curX; //x-position of the mouse
		static int curY; //y-position of the mouse
		static GameManager gameManager; //the work-around for objects that cannot be static.
		static EnemyManager enemyManager; //ditto
		static TowerManager towerManager; //ditto
		static MoneyManager moneyManager;	//ditto
		static map<string,int> textureMap; //Vector that holds all the images we call for different types of enemies, towers, etc.

		static Graphic * bgImage; //the background image of the window.

		GraphicsManager(){};//Graphic * GraphicsManager::bgImage = new Graphic("BG.ppm",0,0); };
		~GraphicsManager(){};
		void update(); //updates graphics
		void setUp(); //calls init_gl_window() i.e. instantiates glut and draws a window on the screen
		void drawWindow(); //Draws everything in the window.

};



#endif  // _GRAPHICSMANAGER_
