#include <QRect>
#include <QImage>

class Item
{
private:
	QImage image;
	QRect item;
	bool destroyed;
	

public:
	Item()
	{
		image.load("image/super.png");
		item=image.rect();
		move();
		destroyed=FALSE;
		
	}
	void setdestroyed(bool dest)
	{
		destroyed=dest;
	}
	bool isdestroyed()
	{
		return destroyed;
	}

	void move()
	{
		int tempx =rand()%450;
		int tempy =rand()%450;

		item.moveTo(tempx,tempy);
	}

	QRect getRect()//get position of bomb
	{
		return item;
	}

	//get image of bomb
	QImage & getImage()
	{
		return image;
	}
};