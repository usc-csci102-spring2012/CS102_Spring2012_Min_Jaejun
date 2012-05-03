#include <iostream>
#include <QRect>
#include <QImage>

class BOMB
{
private:
	QImage image;
	QRect bomb;
	bool destroyed;
public:
	//construtor
	BOMB(int x, int y)
	{
		image.load("image/bomb.png");
		bomb=image.rect();
		bomb.translate(x,y);
	
	}
	QRect getRect()//get position of bomb
	{
		return bomb;
	}

	//get image of bomb
	QImage & getImage()
	{
		return image;
	}

	};