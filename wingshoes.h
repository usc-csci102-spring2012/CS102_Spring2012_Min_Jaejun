#include <QRect>
#include <QImage>

class Wingshoes
{
private:
	QImage image;
	QRect wingshoes;
	bool destroyed;
	

public:
	Wingshoes()
	{
		image.load("image/wingshoes");
		wingshoes=image.rect();
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

		wingshoes.moveTo(tempx,tempy);
	}

	QRect getRect()//get position of bomb
	{
		return wingshoes;
	}

	//get image of bomb
	QImage & getImage()
	{
		return image;
	}
};