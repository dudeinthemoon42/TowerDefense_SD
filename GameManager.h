#ifndef _GAMEMANAGER_
#define _GAMEMANAGER_

#include <boost/timer.hpp>
#include <string>
#include <vector>
#include "Enemy.h"
#include "Graphic.h"
#include "Particle.h"

class GameManager{

	private:
		boost::timer timerObj; //Looks at the clock on the computer.  timerObj is given this time.
		
		bool gameOver; //If the game is over or not.

		//double startTime; //CURRENTLY UNUSED
		double lastTime; //Used to compare times.  The time used before what it is previously at.
		int steps; //Time between steps
		int lastStep; //The previous step
		static int numLives; //Number of lives the user starts with

	public:
		std::vector<Enemy *> graphicsAr; //Vector to hold enemy graphics
		static std::vector<Graphic *> heartAr; //Vector to hold heart graphics.

		GameManager(){}; //constructor for gameManager.  Never actually called
		~GameManager(){}; //deconstructor for gameManager.  Never actually called.
		void gameLoop(); //The actual loop the game runs in
		void setUp(); //Sets up the steps = 0 and displays the heart graphics for # of lives.
		static void loseLife(); //Removes a heart every time an enemy reaches the user.  If the user has no more lives, the game ends.
		static char * currentLevel;
};

#endif  // _GAMEMANAGER_


