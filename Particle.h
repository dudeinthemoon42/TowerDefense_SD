#ifndef _PARTICLE_
#define _PARTICLE_

using namespace std;

#include <string>
#include <vector>
#include "Graphic.h"

class Particle{

	public:
		Graphic * myGraphic; //The visualization of each enemy

		static std::vector<Particle *> particleAr;

		double xStep;
		double yStep;

		int numSteps;

		string type;

		bool dead;

		Particle(string type, int x, int y);
		~Particle(){}; //Deconstructor

		void update(); 
		void draw();
		
};

#endif  // _PARTICLE_
