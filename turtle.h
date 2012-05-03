#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>
#include <QRect>
#include <QImage>
//turtle class
class Turtle
{
private:
	QImage image;
	QRect turtle;	
	bool destroyed;
public:
	//constructor
	Turtle(int x, int y)
	{
		//load turtle picture
		image.load("image/turtle.png");
		turtle = image.rect();
		destroyed =FALSE;
		turtle.translate(x,y);
	}
	
	
	//check for killed turtle
	bool isdestroyed()
	{
		return destroyed;
	}

	void setdestroyed(bool dest)
	{
		destroyed=dest;
	}

	//move turtle
	void move(int x,int y)
	{
		
			turtle.moveTo(x,y);
	}
	// get position of turtle
	QRect getRect()
	{
		return turtle;
	}
	//return image (picture)
	QImage & getImage()
	{
		return image;
	}

};

#endif 

	

	