#ifndef BOAR_H
#define BOAR_H

#include <iostream>
#include <QRect>
#include <QImage>


class Boar
{
private:
	QImage image;
	QRect boar;
	bool destroyed;
public:
	Boar(int x, int y)
	{
		image.load("image/boar.png");
		boar=image.rect();
		
		boar.translate(x,y);
		
	}
	
	void move(int x, int y)
	{
		
		boar.moveTo(x,y);
	}
	bool destoryboar()
	{
		return destroyed;
	}
	void setdestoryed(bool dest)
	{
		destroyed =dest;
	}

	QRect getRect()
	{
		return boar;
	}
	QImage & getImage()
	{
		return image;
	}
};
#endif
