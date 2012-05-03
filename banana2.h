#ifndef BANANA2_H
#define BANANA2_H

#include <QRect>
#include <QImage>

class Banana2
{
private:
	QImage image;
	
	QRect banana2;
	bool destroyed;
	int bananax,bananay,py, px,dx,dy,slope;
	
public:
	Banana2(int tempx, int tempy)
	{

		image.load("image/banana.png");
		banana2=image.rect();
		 px=tempx;
		 py =tempy;

		 banana2.translate(tempx,tempy);
		

		
	}	
	
QRect getRect()
	{
		return banana2;
	}
	QImage & getImage()
	{
		return image;
	}
	bool destoryboar()
	{
		return destroyed;
	}
	void setdestoryed(bool dest)
	{
		destroyed =dest;
	}
	
};
#endif
