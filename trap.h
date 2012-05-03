#ifndef TRAP_H
#define TRAP_H

#include <iostream>
#include <QRect>
#include <QImage>


class Trap
{
private:
	QImage image;
	QRect trap;
public:
	Trap(int x, int y)
	{
		image.load("image/trap.png");
		trap=image.rect();		
		trap.translate(x,y);
		
	}	

	QRect getRect()
	{
		return trap;
	}
	QImage & getImage()
	{
		return image;
	}
};
#endif
