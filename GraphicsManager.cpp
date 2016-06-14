#include<iostream>
#include<fstream>
using namespace std;
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include <sstream>

#include<string.h>

#include <boost/timer.hpp>
#include "GraphicsManager.h"
#include "Graphic.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "TowerManager.h"
#include "MoneyManager.h"
#include "texture.h"
#include "Particle.h"

#include "SearchManager.h"

//-------Start Static Definitions--------
int GraphicsManager::screenWidth = 700; // definition outside class declaration
int GraphicsManager::screenHeight = 500; // definition outside class declaration
int GraphicsManager::curX = 0; //what will become the mouse x-position
int GraphicsManager::curY = 0;// what will become the mouse y-position

GameManager GraphicsManager::gameManager = *( new GameManager() ); //definition outside the class declaration
EnemyManager GraphicsManager::enemyManager = *( new EnemyManager() ); //definition outside the class declaration
TowerManager GraphicsManager::towerManager = *( new TowerManager() ); //definition outside the class declaration

MoneyManager GraphicsManager::moneyManager = *( new MoneyManager() );	//
map<string,int> GraphicsManager::textureMap; //vector that holds all textures (images) we call to display
Graphic * GraphicsManager::bgImage = new Graphic("BG",screenWidth / 2,screenHeight / 2); //background of window
//-------End Static Definitions-----------

char programName[] = "The Awesomest TD Ever"; //Title of main screen.

void drawText(double x, double y, int number, bool isBlack) //Not used.
{
	if (isBlack) {
		if (number <= MoneyManager::totalMoney) 
			glColor3f(0., 0., 0.);
		else 
			glColor3f(1., 0., 0.);
		}
	std::string pointer;
	std::stringstream out;
	out << number;
	pointer = "$" + out.str();
	const char * text = pointer.c_str();
  	glRasterPos2f( x, y );
  	int length = strlen(text);
	if (isBlack == false){
  		for (int i = 0; i < length; i++){
    		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    		}
    	}
    else {
    	if (number <= MoneyManager::totalMoney) {
    		//cout << "black: " << number << " " << MoneyManager::totalMoney << endl;
    		for (int i = 0; i < length; i++) {
    			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    			}
    		}
    	else {
    		//cout << "red: " << number << " " << MoneyManager::totalMoney << endl;
    		for (int i = 0; i < length; i++) {
    			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    			}
    		}
    }
}

void drawTotalPoints(double x, double y, int number) 
{
	glColor3f(255/255.0, 165/255.0, 0.0);
	std::string pointer;
	std::stringstream out;
	out << number;
	pointer = "Total Points: " + out.str();
	const char * text = pointer.c_str();
	glRasterPos2f( x,y );
	int length = strlen(text);
	for (int i = 0; i < length; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    	}
}

void drawLevel(double x, double y, const char * text) 
{
	Graphic tempGraphic("rectangle",x+34,y-8);
	tempGraphic.setDimensions(100,50);
	tempGraphic.setColor(255,255,255);
	tempGraphic.draw();

	glColor3f(0/255.0, 0/255.0, 0.0);	
	glRasterPos2f( x ,y );
	int length = strlen(text);
	for (int i = 0; i < length; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    	}
}


void drawWindow()
{

  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // tell the graphics card that we're done-- go ahead and draw!
  // (technically, we are switching between two color buffers...)

	//draws background
	GraphicsManager::bgImage->draw();
	
	//draws tiles
	for(unsigned int x = 0; x < TowerManager::tileAr.size(); x ++){
		TowerManager::tileAr.at(x)->draw();
	}
	
	//Cover up piece.
	Graphic coverGraphic("rectangle",50,100);
	coverGraphic.setDimensions(10,48);
	coverGraphic.setColor(0,0,0);
	coverGraphic.draw();

	//HOMELAND!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Graphic homeGraphic("rectangle", 553, 463);
	homeGraphic.setDimensions(37,37);
	homeGraphic.setColor(255, 0, 0);
	homeGraphic.draw();

	//draws towers
	for(unsigned int x = 0; x < TowerManager::towerAr.size(); x ++){
		TowerManager::towerAr.at(x)->draw();
	}

	//draws enemies
	for(unsigned int x = 0; x < EnemyManager::enemyAr.size(); x ++){
		EnemyManager::enemyAr.at(x)->draw();
	}
	//draws shots
	for (unsigned int x = 0; x < EnemyManager::shotAr.size(); x++) {
				EnemyManager::shotAr.at(x)->draw();
	}
	//draws users health
	for (unsigned int x = 0; x < GameManager::heartAr.size(); x++) {
		GameManager::heartAr.at(x)->draw();
	}

	for (unsigned int x = 0; x < Particle::particleAr.size(); x++) {
		Particle::particleAr.at(x)->draw();
	}
	
	
	//Draw the money the user currently has.
	drawText(GraphicsManager::screenWidth - 115, 65, MoneyManager::totalMoney, false);
	//Draw the costs of each tower.
	
	if (GameManager::currentLevel != NULL) {
		drawLevel(GraphicsManager::screenWidth/2 - 50, GraphicsManager::screenHeight/2+20, GameManager::currentLevel);
		}
	
	drawText(656, 90, MoneyManager::rodPrice, (true));
	drawText(656, 160, MoneyManager::gunPrice, (true));
	drawText(656, 230, MoneyManager::netPrice, (true));
	drawText(656, 300, MoneyManager::lightningPrice, (true));
	drawText(656, 370, MoneyManager::bpPrice, (true)); 
	drawTotalPoints(GraphicsManager::screenWidth - 300, 65, MoneyManager::totalPoints);


	//draws the different options of towers on the right side of the window	
	TowerManager::GunTowerBuy->draw();
	TowerManager::NetTowerBuy->draw();
	TowerManager::RodTowerBuy->draw();
	TowerManager::BPTowerBuy->draw();
	TowerManager::LightningTowerBuy->draw();
	

	//if you have instantiated placingTower i.e. bought a tower and continue to hold
	//down left-click, a tower is drawn where the mouse is.
	if(TowerManager::placingTower != NULL){
		TowerManager::placingTower->draw();
	}
	//swaps the buffers.
	glutSwapBuffers();
	
	//runs through the game loop. i.e. updates all the towers and whatnot.
	GraphicsManager::gameManager.gameLoop();

	//display
	glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{

  if ( GLUT_LEFT_BUTTON == button ) {

    if ( GLUT_DOWN == state ) {
		//THE MOUSE IS DOWN

		//creates a tower if you buy one. -> when you click on a tower on the left a tower of that type is made.
		if(TowerManager::placingTower == NULL){
			if( TowerManager::GunTowerBuy->containsPoint(x,y) ){
				TowerManager::placingTower = new Tower("Gun",x,y);
			}
			else if( TowerManager::NetTowerBuy->containsPoint(x,y) ){
				TowerManager::placingTower = new Tower("Net",x,y);
			}
			else if( TowerManager::RodTowerBuy->containsPoint(x,y) ){
				TowerManager::placingTower = new Tower("Rod",x,y);
			}
			else if( TowerManager::LightningTowerBuy->containsPoint(x,y) ){
				TowerManager::placingTower = new Tower("Lightning",x,y);
			}
			else if( TowerManager::BPTowerBuy->containsPoint(x,y) ){
				TowerManager::placingTower = new Tower("BP",x,y);
			}

			if(TowerManager::placingTower != NULL){
				if( MoneyManager::hasMoney(TowerManager::placingTower)) {
					cout << "You Have Enough" << endl;
					}
				else{
					cout << "You don't have enough" << endl;
					delete TowerManager::placingTower;
					TowerManager::placingTower = NULL;
				}
			}

		}

    } else {
		//THE MOUSE IS UP
			if(TowerManager::placingTower != NULL){

				Tile * placedTile = NULL;
				
				//Checks if a tower is in the tile where the mouse is when trying to place a tower.
				for(unsigned int z = 0; z < TowerManager::tileAr.size(); z ++){
					if( TowerManager::tileAr.at(z)->greenBG->containsPoint(x,y) ){ 
						placedTile = TowerManager::tileAr.at(z);
						//if the tile you are placing is not taken, place the tile
						if( !placedTile->taken ){
							placedTile->setMe( true );
							SearchManager::updateMap();
							if( SearchManager::runMap(0,0) ){
								MoneyManager::takeMoney(TowerManager::placingTower);
								placedTile->setMe( true );
								TowerManager::placingTower->setMe(placedTile);

								break;
							}
							else
								placedTile->setMe( false );

							placedTile->mouseOver = false;
								
						}

						}

				}
				
				if(placedTile == NULL)
					delete TowerManager::placingTower;
				
				TowerManager::placingTower = NULL;
				
			}
			
    }
  } else if ( GLUT_RIGHT_BUTTON == button ) {
		
  }
  glutPostRedisplay();
}

// the mouse_motion function is called when the mouse is being dragged,
//   and gives the current location of the mouse
void mouse_motion(int mouseX,int mouseY)
{
	//mouse position is (curX, curY)
	GraphicsManager::curX = mouseX;
	GraphicsManager::curY = mouseY;

	//We are currently placing a tower
	if(TowerManager::placingTower != NULL){
		//So set that tower's X,Y to our current mouseX and mouseY
		TowerManager::placingTower->setPosition(mouseX,mouseY);

				for(unsigned int z = 0; z < TowerManager::tileAr.size(); z ++){
					if( TowerManager::tileAr.at(z)->greenBG->containsPoint(mouseX,mouseY) )
						TowerManager::tileAr.at(z)->mouseOver = true;
					else
						TowerManager::tileAr.at(z)->mouseOver = false;
				}
				
	}
  
  glutPostRedisplay();
}


// the init function sets up the graphics card to draw properly
void init(void)
{
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., GraphicsManager::screenWidth-1, GraphicsManager::screenHeight-1, 0., -1.0, 1.0);

  // welcome message
  cout << "Welcome to " << programName << "." << endl;

}
//method to load all the textures we use
void loadTextures(){
	GraphicsManager::textureMap["BG"] = loadTexture("images/BG.ppm");
	GraphicsManager::textureMap["Hobbes"] = loadTexture("images/Hobbes.pam");

	GraphicsManager::textureMap["Octopus"] = loadTexture("images/octopus.pam");
	GraphicsManager::textureMap["Goldfish"] = loadTexture("images/goldfish.pam");
	GraphicsManager::textureMap["Shark"] = loadTexture("images/shark.pam");
	GraphicsManager::textureMap["Triton"] = loadTexture("images/triton.pam");
	GraphicsManager::textureMap["Seahorse"] = loadTexture("images/seahorse.pam");

	// 
	GraphicsManager::textureMap["Gun"] = loadTexture("images/gun.pam");
	GraphicsManager::textureMap["Rod"] = loadTexture("images/pole.pam");
	GraphicsManager::textureMap["Net"] = loadTexture("images/net.pam");
	GraphicsManager::textureMap["BP"] = loadTexture("images/BP.pam");
	GraphicsManager::textureMap["Lightning"] = loadTexture("images/lightning.pam");
	
	GraphicsManager::textureMap["Heart"] = loadTexture("images/heart.pam");
	
}

// the reshape function handles the case where the user changes the size
//   of the window.  We need to fix the coordinate
//   system, so that the drawing area is still the unit square.
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   GraphicsManager::screenWidth = w;  GraphicsManager::screenHeight = h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., GraphicsManager::screenWidth-1, GraphicsManager::screenHeight-1, 0., -1.0, 1.0);
}

// init_gl_window is the function that starts the ball rolling, in
//  terms of getting everything set up and passing control over to the
//  glut library for event handling.  It needs to tell the glut library
//  about all the essential functions:  what function to call if the
//  window changes shape, what to do to redraw, handle the keyboard,
//  etc.


void init_gl_window()
{
	//
  	char *argv[] = {programName};
  	//
  	int argc = sizeof(argv) / sizeof(argv[0]);
  	//
  	glutInit(&argc, argv);
  	//
  	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
  	//create a window of hte size screenWidth x screenHeight
  	glutInitWindowSize(GraphicsManager::screenWidth,GraphicsManager::screenHeight);	//Change Here
  	//place the window at (100,000) on the user's screen.
  	glutInitWindowPosition(100,100);
  	//
  	glutCreateWindow(programName);
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  	init();

	loadTextures();

	GraphicsManager::gameManager.setUp();
	GraphicsManager::enemyManager.setUp();
	GraphicsManager::towerManager.setUp();

  	glutDisplayFunc(drawWindow);
  	glutReshapeFunc(reshape);
  	//glutKeyboardFunc(keyboard);
  	glutMouseFunc(mouse);
  	glutMotionFunc(mouse_motion);
  	glutMainLoop();

}

void GraphicsManager::setUp(){
	init_gl_window();
}

void GraphicsManager::update(){
	cout << "Updating GraphicsManager..." << endl;
}






