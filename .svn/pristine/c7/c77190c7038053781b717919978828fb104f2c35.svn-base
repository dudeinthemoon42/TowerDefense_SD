#include "Particle.h"
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265

std::vector<Particle *> Particle::particleAr;

Particle::Particle(string tempType, int newX, int newY){
	type = tempType;

	//set graphic color based on type

	myGraphic = new Graphic("circle",newX,newY);
	myGraphic->setRadius(1);

	dead = false;

	double tempAng = rand()%359;
	double tempMult = ( rand()%30 )/(double)2;
	xStep = cos(tempAng * PI/180)*(tempMult);
	yStep = sin(tempAng * PI/180)*(tempMult);

	numSteps = 0;

}


void Particle::update(){
	xStep *= .95;
	yStep *= .95;
	
	myGraphic->setPosition(myGraphic->x + xStep,myGraphic->y + yStep);
	numSteps ++;

	if(numSteps > 10)
		dead = true;
}

void Particle::draw(){
	myGraphic->draw();
}
