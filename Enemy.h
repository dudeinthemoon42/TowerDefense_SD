#ifndef _ENEMY_
#define _ENEMY_

using namespace std;

#include <string>
#include <vector>
#include "Graphic.h"
#include "Tile.h"

class Enemy{

	public:
		Graphic * myGraphic; //The visualization of each enemy
		Graphic * healthBG; //White background of health bar
		Graphic * healthMainGreen; //Green rectangle on the health bar -> gets resized as health diminishes
		Graphic * healthMainRed; //Red rectangle on the health bar.

		string type; //the type of enemy it is -> octopus, goldfish, etc.

		int targetX; //X-Coordinate the enemy would like to reach
		int targetY; //Y-Coordinate the enemy would like to reach
		double targetAngle; //The angle to reach the taret location
		int health; //The enemy's current health
		int maxHealth; //The enemy's maximum (starting) health
		bool dead; //if True, the enemy is dead and no longer displayed

		Tile * targetTile;
		Tile * currentTile;

		int xStep; //dx
		int yStep; //dy
				

		Enemy(string type, int x, int y); //Constructor for Enemy
		~Enemy(){}; //Deconstructor

		void update(); //Updates health, user's health, bool dead, and health bar
		void moveTo(int newX, int newY); //updates the target X and Y position
		void shoot(int damage); //If enemy is shot, damage is incurred.
		void draw(); //Draws the enemy
		
};

#endif  // _ENEMY_
