using namespace std;
#include"texture.h"

#include "GameManager.h"
#include "GraphicsManager.h"

#include <vector>

#include <sstream> 
#include<iostream>
#include<fstream>
#include<GL/glut.h>
#include<math.h>


Graphic::Graphic(string tempType,int tempX, int tempY){

	//Different actions are followed depending on what type of graphic is passed in the constructor.
	if(tempType == "rectangle"){
		type = tempType;

		r = 255;
		g = 0;
		b = 0;

		width = 30;
		height = 10;

		x = tempX;
		y = tempY;
	}
	else if(tempType == "circle"){
		type = tempType;

		r = 0;
		g	=	255;
		b	=	255;

		radius = 10;
		width 	= radius*2;
		height 	= radius*2;

		x=tempX;
		y=tempY;
	}
	else if(tempType == "triangle"){
		cout << "making a triangle" << endl;
		type = tempType;

		r = 0;
		g = 0;
		b = 255;

		width = 30;
		height = 30;
		x = tempX;
		y = tempY;
	}
	else{
		//defaults for opacity and rotation
		opacity = 1;
		rotation = 0;

		x = tempX;
		y = tempY;
		type = "image";
		fileID = tempType;
		file = GraphicsManager::textureMap[fileID];//loadTexture( "Hobbes.pam" );  // loading in the main window ;

		if(tempType == "BG"){
			width = 700;
			height = 500;
		}
		else if(tempType == "Hobbes"){
			width = 200;
			height = 100;
			//rotation = 30;
		}
		else if(tempType == "Octopus"){
			width = 32;
			height = 37;
		}
		else if(tempType == "Goldfish"){
			//372x279
			width = 34.5;
			height = 29.5;
		}
		else if(tempType == "Seahorse"){
			//194x297
			width = 24;
			height = 37;
		}
		else if(tempType == "Triton"){
			//478x533
			width = 34;
			height = 37;
		}
		else if(tempType == "Shark"){
			//200x116
			width = 39;
			height = 22.5;
		}
		else if(	tempType == "Gun" || tempType == "Rod" || 
							tempType == "Net" || "Lightning" || "BP"	){
			width = 40;
			height = 40;
		}
		
		else if( tempType == "Heart" ){
			width = 5;
			height = 5;
			}

	}
	
}


void Graphic::draw(){
	//these temp variables are necessary because the x,y position is in the top left. 
	// We move it to the center temporarily.
	int tempX = x;
	int tempY = y;

	x -= width/2;
	y -= height/2;

	//Different methods are necessary for different types since they are different shapes.
	if(type=="rectangle"){

		glColor3f(r/255.0f, g/255.0f, b/255.0f);
	  	
		double x0 = min(x, x + width);
		double x1 = max(x, x + width);
		double y0 = min(y, y + height);
		double y1 = max(y, y + height);
	
		glBegin(GL_QUADS);
	  glVertex2d(x0, y0);
	  glVertex2d(x1, y0);
	  glVertex2d(x1, y1);
	  glVertex2d(x0, y1);
		glEnd();
		
	}
	else if(type=="circle"){
		glColor3f(r/255.0f, g/255.0f, b/255.0f);
		const int NUM_DIVS = 50;
		  glBegin(GL_TRIANGLE_FAN);
		    glVertex2d(x, y);
			int r = radius;
		    for ( int i = 0; i < NUM_DIVS; ++i )
		      glVertex2d(x + r*cos(i*2*M_PI/(NUM_DIVS-1)),
				 y + r*sin(i*2*M_PI/(NUM_DIVS-1)));
		  glEnd();
	}
	else if(type=="triangle") {
		glColor3f(r/255.0f, g/255.0f, b/255.0f);  // make it blue 
  		glBegin(GL_TRIANGLES);
    		glVertex2i(x, y+height);
   		glVertex2i(x+width, y+height);
		glVertex2i(x+width/2, y);
    		glEnd();
	}
	if(type == "image"){ 
			drawTexture(file,  x ,y, width, height,opacity,rotation);  // texNum, x,y, width, height
	}
	//resets the position to the top-left corner.
	x = tempX;
	y = tempY;

}


bool Graphic::containsPoint(int mouseX, int mouseY) {

	//Different methods for different types.  Just checks to see if the mouse is hovering above
	//one of the graphics.
	if (type=="rectangle" || type=="image" || type =="triangle") {
		if ((mouseX >= (x-width/2)) && (mouseX <= (x+width/2)) && 
		(mouseY >= (y-height/2)) && (mouseY <= (y+height/2)))
		   	return true;
		else 
			return false;
	}
	
	if (type=="circle") {
		if (sqrt((mouseX-x)*(mouseX-x) + (mouseY-y)*(mouseY-y)) <= radius)
			return true;
		else 
			return false;
	}
	

	return false;
		
}


