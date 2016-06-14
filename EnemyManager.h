#ifndef _ENEMYMANAGER_
#define _ENEMYMANAGER_

#include "Enemy.h"
#include "Shot.h"

class EnemyManager{

	public:
		static std::vector<Enemy *> enemyAr; //Vector to hold the enemies
		static std::vector<Shot *> shotAr; //Vector to hold the shots from towers

		EnemyManager(){}; //Default constructor
		~EnemyManager(){}; //Deconstructor
		void update(); //Updates the vectors holding enemies and shots
		void setUp(); //Empty???????????? 
};


#endif  // _ENEMYMANAGER_
