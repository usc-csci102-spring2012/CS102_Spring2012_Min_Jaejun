#ifndef BANANA_H
#define BANANA_H

#include <QRect>
#include <QImage>

class Banana
{
private:
	QImage image;
	QImage image2;
	QRect banana;	
	bool destroyed;
	int bananax,bananay,py, px,dx,dy,slope;
	
public:
	Banana(int x, int y, int tempx, int tempy)
	{

		image.load("image/banana1.png");
		image2.load("image/banana.png");
		banana=image.rect();
		 px=tempx;
		 py =tempy;
		 bananax=x;
		 bananay=y;
		// dx =playerx-bananax;
		 //dy = playery-bananay;
		 if(abs(dy)>abs(dx) && abs(dx)>0)
			 slope =abs(dy)/abs(dx);
		 else if(abs(dx)>abs(dy) &&abs(dy)>0)
			 slope =abs(dx)/abs(dy);
		banana.moveTo(x,y);
		
	}	
	void move(int bx, int by)
	{

		/*if(abs(dy)>abs(dx) && abs(dx)>0)
			{
				slope =abs(dy)/abs(dx);
				if(bananax <px &&bananay <py)					
						banana.moveTo(++bx,by+slope);
				else if(bananax>px&&bananay<py)
					banana.moveTo(--bx,by+slope);
				else if(bananax<px &&bananay>py)
					banana.moveTo(++bx,by-slope);
				else if(bananax>px && bananay>px)
					banana.moveTo(--bx,by-slope);
			}
		 else if(abs(dx)>abs(dy) &&abs(dy)>0)
			 {
				 slope =abs(dx)/abs(dy);
				 if(bananax <px &&bananay <py)					
						banana.moveTo(bx+slope,by++);
				else if(bananax>px&&bananay<py)
					banana.moveTo(bx-slope,by++);
				else if(bananax<px &&bananay>py)
					banana.moveTo(bx+slope,by--);
				else if(bananax>px && bananay>px)
					banana.moveTo(bx-slope,by--);
			}	
		 else if(abs(dx)==0&&abs(dy)!=0)
		 {
			 if(dy>0)
				 banana.moveTo(bx,++by);
			 else if(dy <0)
				 banana.moveTo(bx,--by);
		 }
		 else if(abs(dy)==0 &&abs(dx)!=0)
		 {
			 if(dx>0)
				 banana.moveTo(++bx,by);
			 else if(dx<0)
				 banana.moveTo(--bx,by);
		 }
		 else if(abs(dy)!=0 &&abs(dx)!=0 &&abs(dx)==abs(dy))
		 {
				if(bananax <px &&bananay <py)					
						banana.moveTo(bx++,by++);
				else if(bananax>px&&bananay<py)
					banana.moveTo(bx--,by++);
				else if(bananax<px &&bananay>py)
					banana.moveTo(bx++,by--);
				else if(bananax>px && bananay>px)
					banana.moveTo(bx--,by--);
		 }*/
		 
		 
		if(bx <px &&by<py)
			banana.moveTo(++bx,++by);
		else if(bx==px &&by<py)
			banana.moveTo(bx,++by);
		else if(bx>px&&by<py)
			banana.moveTo(--bx,++by);
		else if(bx<px &&by==py)
			banana.moveTo(++bx,by);
		else if(bx<px &&by>py)
			banana.moveTo(++bx,--by);
		else if(bx==px&&by>py)
			banana.moveTo(bx,--by);
		else if(bx>px && by>px)
			banana.moveTo(--bx,--by);
		else if(bx>px&&by==py)
			banana.moveTo(--bx,by);
		
		
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
		return banana;
	}
	QImage & getImage()
	{
		return image;
	}
	QImage & getImage2()
	{
		return image2;
	}
};
#endif
