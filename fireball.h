#ifndef FIREBALL_H
#define FIREBALL_H

#include <QRect>
#include <QImage>
class Fire
{
private:
	QImage image;
	QRect fire;
	
	 bool destroyed;
	 int firex,firey,py, px,dx,dy,slope;
	
public:
	Fire(int x, int y, int tempx, int tempy)
	{

		image.load("image/fireball.png");
		fire=image.rect();
		 px=tempx;
		 py =tempy;
		 firex=x;
		 firey=y;
		 dx =px-firex;
		 dy = py-firey;
		 if(abs(dy)>abs(dx) && abs(dx)>0)
			 slope =abs(dy)/abs(dx);
		 else if(abs(dx)>abs(dy) &&abs(dy)>0)
			 slope =abs(dx)/abs(dy);
		fire.moveTo(x,y);
		
	}	
	void move(int bx, int by)
	{	
		 
		 
		if(bx <px &&by<py)
		{
			for (int g =0; g <20 ; g++)
			fire.moveTo(++bx,++by);
		}
		else if(bx==px &&by<py)
		{
		fire.moveTo(bx,++by);}
		else if(bx>px&&by<py)
		{
		fire.moveTo(--bx,++by);}
		else if(bx<px &&by==py)
		{
		fire.moveTo(++bx,by);}
		else if(bx<px &&by>py)
		{
		fire.moveTo(++bx,--by);}
		else if(bx==px&&by>py)
		{
		fire.moveTo(bx,--by);}
		else if(bx>px && by>px)
		{
		fire.moveTo(--bx,--by);}
		else if(bx>px&&by==py)
		{
		fire.moveTo(--bx,by);}
		
		
	}
	int getplayerx()
	{
		return px;
	}
	int getplayery()
	{
		return py;
	}

bool destorybanana()
	{
		return destroyed;
	}
	void setdestoryed(bool dest)
	{
		destroyed =dest;
	}
QRect getRect()
	{
		return fire;
	}
	QImage & getImage()
	{
		return image;
	}
	
};
#endif
