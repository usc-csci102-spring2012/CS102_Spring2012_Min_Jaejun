#ifndef RABBIT_H
#define RABBIT_H

#include <iostream>
#include <QRect>
#include <QImage>

class Rabbit
{
private:
	QImage image;
	QRect rabbit;
	int xdir;
	int ydir;
	bool destroyed;
public:
	//constructor
	Rabbit(int x, int y)
	{
		image.load("image/rabbit.png");
		rabbit = image.rect();
		destroyed =FALSE;
		rabbit.translate(x,y);
	}
	
	
	//check for killed rabbit
	bool isdestroyed()
	{
		return destroyed;
	}

	void setdestroyed(bool dest)
	{
		destroyed=dest;
	}

	//rabbit movement
	void move(int x,int y)
	{
		
			rabbit.moveTo(x,y);
	}
	//get position of rabbit
	QRect getRect()
	{
		return rabbit;
	}
	// get image of rabbit
	QImage & getImage()
	{
		return image;
	}

};

#endif 

	

	