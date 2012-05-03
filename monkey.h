#include <QRect>
#include <QImage>


class Monkey
{
private:
	QImage image;
	QRect monkey;
public:
	Monkey()
	{
		image.load("image/monkey.png");
		monkey = image.rect();
		initailposition();
	}	
	void initailposition()
	{
		monkey.translate(500,-10);
	}
	void move(int x, int y)
	{
		monkey.moveTo(x,y);
	}
	QRect getRect()
	{
		return monkey;
	}
	QImage & getImage()
	{
		return image;
	}
};
