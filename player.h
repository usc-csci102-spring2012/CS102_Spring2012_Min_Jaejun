#ifndef PLAYER_H
#define PLAYER_H

#include <QImage>
#include <iostream>
#include <QRect>



class player
{
private:
		QImage image;
		QImage image2;
		QRect hunt;
		//QRect hunt2;
		bool destroyed;
		bool giant;
		bool shoes;

public:
	player()
	{
	
	//destroyed =FALSE;
	//giant=FALSE;	
	image.load("image/hunter.png");	
	image2.load("image/superman.png");	
	hunt =image.rect();
	//hunt2=image.rect();
	initialposition();
	//giant=FALSE;
	//destroyed =FALSE;
	}

	void initialposition()
	{
		hunt.moveTo(0,0);
	}

	void moveup(int x, int y)
		{
			if(hunt.top() <0)
			{
				y=499;
			hunt.moveTop(y);
			}
			else
				hunt.moveTo(x,y);
				
	}

	void movedown(int x, int y)
	{
		if(hunt.bottom()>499)
		{	y=0;
			hunt.moveBottom(y);
		}
		else
		hunt.moveTo(x,y);
				
	}

	void moveleft(int x,int y)
	{
		if(hunt.left()<0)
		{
			x =499;
			hunt.moveLeft(x);
		}
		else
		hunt.moveTo(x,y);
	}


	void moveright(int x,int y)
	{
		if(hunt.right()>499)
		{
			x=0;
			hunt.moveRight(x);
		}
		else
			hunt.moveTo(x,y);
	}

	bool destoryplayer()
	{
		return destroyed;
	}
	void setdestoryed(bool dest)
	{
		destroyed =dest;
	}
	void setgiant(bool big)
	{
		giant =big;
	}
	bool giantplayer()
	{
		return giant;
	}
	void setshoes(bool fast)
	{
		shoes =fast;
	}
	bool fastplayer()
	{
		return shoes;
	}
	QImage & getImage()
	{
		return image;
	}
	QImage & getImage2()
	{
		return image2;
	}
	
	QRect gethunt()
	{
		return hunt;
	}
	

};
#endif