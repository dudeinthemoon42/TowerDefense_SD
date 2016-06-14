#ifndef _GRAPHIC_
#define _GRAPHIC_

#include <string>

class Graphic{

	public:
		int width; //width of graphic
		int height; //height of graphic
		int radius; //radius of graphic, only used in circles.
		double x; //x-position
		double y; //y-position

		double r,g,b; //r,g,b values used for shots and other non image graphics

		std::string type; //type of graphic. i.e. circle, Goldfish, etc.
		int file; 	//for image only
		std::string fileID;		//for image only
		double opacity;		//for image only
		double rotation;	//for image only

		Graphic(std::string type, int x, int y); //constructor for graphic. type, x-position, y-position
		~Graphic(){}; //deconstructor for graphic

		void setDimensions(int w, int h){width = w; height = h;}; //sets the dimension of graphic
		void setRadius(int tempRadius){radius = tempRadius;width=radius*2;height=radius*2;}; //sets radius of circle-type graphics
		void setColor(int tempR, int tempG, int tempB){r = tempR; g = tempG; b = tempB;}; //sets color of non-image-type graphics
		void setPosition(int tempX,int tempY){x = tempX;y = tempY;}; //sets position of graphics

		bool containsPoint(int mouseX,int mouseY); //Method to check if the mouse is hovering above a graphic.

		void draw(); //draws graphics.
};

#endif  // _GRAPHIC_
