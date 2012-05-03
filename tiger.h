#include <iostream>
#include <QRect>
#include <QImage>

class Tig
{
private:
	QImage image;
	QRect tiger;
public:
	//constructor
	Tig()
	{	image.load("image/tiger.png");
		tiger = image.rect();
		initialposition();
	}
	
	//positioning tiger when game start
	void initialposition()
	{
		tiger.moveTo(0,497);
	}
	//move tiger
	void moveup(int x, int y)
		{
			if(tiger.top() <0)
			{
				y=499;
			tiger.moveTop(y);
			}
			else
				tiger.moveTo(x,y);
				
		}
	void movedownleft(int x, int y)
	{
		if(tiger.bottom()>499 &&tiger.left()<0)
		{
			x=499;
			y=0;
			tiger.moveTo(x,y);
		}
		else
			tiger.moveTo(x,y);
	}
	void movedownright(int x, int y)
	{
		if(tiger.bottom()>499 &&tiger.right()>499)
		{
			x=0;
			y=0;
			tiger.moveTo(x,y);
		}
		else
			tiger.moveTo(x,y);
	}
	void movetopleft(int x, int y)
	{
		if(tiger.top()<0 &&tiger.left()<0)
		{
			x=499;
			y=0;
			tiger.moveTo(x,y);
		}
		else
			tiger.moveTo(x,y);
	}
	void moveupright(int x, int y)
	{
		if(tiger.top()<0 &&tiger.right()>499)
		{
			x=0;
			y=499;
			tiger.moveTo(x,y);
		}
		else
			tiger.moveTo(x,y);
	}
	void movedown(int x, int y)
	{
		if(tiger.bottom()>499)
		{	y=0;
			tiger.moveBottom(y);
		}
		else
		tiger.moveTo(x,y);
				
	}

	void moveleft(int x,int y)
	{
		if(tiger.left()<0)
		{
			x =499;
			tiger.moveLeft(x);
		}
		else
		tiger.moveTo(x,y);
	}


	void moveright(int x,int y)
	{
		if(tiger.right()>499)
		{
			x=0;
			tiger.moveRight(x);
		}
		else
			tiger.moveTo(x,y);
	}
	QRect getRect()
	{
		return tiger;
	}
	QImage & getImage()
	{
		return image;

	}

};