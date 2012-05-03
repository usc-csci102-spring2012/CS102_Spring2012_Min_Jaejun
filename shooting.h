#ifndef SHOOTING_H
#define SHOOTING_H

#include <QRect>
#include <QImage>

class SHOOT
{
private:
	QImage image;
	QRect Shoot;
	
public:
	SHOOT(int x,int y)
	{
		image.load("image/shoot.png");
		Shoot=image.rect();
		Shoot.moveTo(x,y);

	}

	

	void move(int px, int py)
	{
		Shoot.moveTo(px,py);
	}

	
	QRect getRect()
	{
		return Shoot;
	}
	QImage & getImage()
	{
		return image;
	}
};
#endif

