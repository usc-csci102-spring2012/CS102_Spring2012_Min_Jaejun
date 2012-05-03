#include "collision.h"
#include <QPainter>
#include <QApplication>
#include <QBrush>
#include <QPixmap>
#include <QPalette>

// class for movement and collision of characters
//constructor
collision::collision(QWidget *parent):QWidget(parent)
{
	countclock =15;
	countclock1=15;
	score =0;
	level=0;
	boarlife=100;	
	rabbitnum=2;
	turtlenum=2;
	bombnum=3;
	tigerspeed=3;
	boarspeed=3;
	x=0;
	y=0;
	clock=0;
	clock1=0;
	check =-1;
	//set game statues
	itemcheckapple=FALSE;
	itemcheckshoes=FALSE;
	timecount = FALSE;
	gameover =FALSE; 
	gamewon =FALSE;
	started =FALSE;
	paused = FALSE;
	//new object for classes of bomb, player, tutle, rabbit, and tiger
	hunter = new player();
	tig = new Tig();	
	monkey=new Monkey();	
	
	
	scorebar();
	
	
}
//paint:display game statues and display images of chracters
void collision::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	if(gameover)
	{
		QFont font("Times",15,QFont::Bold);
		QFontMetrics Fmetric(font);
		int pixw=Fmetric.width("GAME OVER");
		int pixw1=Fmetric.width("Press space to restart");
		painter.setFont(font);
		int high=height();
		int wide =width();
		painter.translate(QPoint(wide/2,high/2));
		painter.drawText(-pixw/2,0,"GAME OVER");
		painter.drawText(-pixw1/2,20,"Press space to restart");
	}
	else if(gamewon)
	{
	
		QFont font("Times",15,QFont::Bold);
		QFontMetrics Fmetric(font);
		int pixw=Fmetric.width("YOU WON");
		int pixw1=Fmetric.width("Press space to restart.'q' to quit");
		painter.setFont(font);
		int high=height();
		int wide =width();
		painter.translate(QPoint(wide/2,high/2));
		painter.drawText(-pixw/2,0,"YOU WON");
		painter.drawText(-pixw1/2,20,"Press space to restart, 'q' to quit");
	}
	else if(!started)
	{
		QFont font("Times",10,QFont::Bold);
		QFontMetrics Fmetric(font);
		int pixw=Fmetric.width("Hunting game,kill rabbits, boar and turtles.Be careful for bombs and tiger.");
		int pixw1=Fmetric.width("	Press space to start, if you want to Quit press 'q'.Move hunter with arrow buttons,'s' for bullet.");
		painter.setFont(font);
		int high=height();
		int wide =width();
		painter.translate(QPoint(wide/2,high/2));
		painter.drawText(-pixw/2,0,"Hunting game,kill rabbits, boar and turtles.Be careful for bombs and tiger.");
		painter.drawText(-pixw1/2,10,"	Press space to start. Press 'q' to quit. Move hunter with arrow buttons,'s' for bullet.");
	}

	else{
	painter.drawImage(tig->getRect(),tig->getImage());
	painter.drawImage(monkey->getRect(),monkey->getImage());
	painter.drawImage(trap->getRect(),trap->getImage());


	
//	painter.drawImage(banana->getRect(),banana->getImage());
	for(int bo =0; bo <boar.size() ; bo ++)
	{
		painter.drawImage(boar[bo]->getRect(),boar[bo]->getImage());
	}

	if(!hunter->destoryplayer())
	{
		if(!hunter->giantplayer())
		painter.drawImage(hunter->gethunt(),hunter->getImage());
		else if(hunter->giantplayer())
		painter.drawImage(hunter->gethunt(),hunter->getImage2());
	}
	for (int i=0; i < rat.size(); i++)
	{
		//if(!rat[i]->isdestroyed())
		painter.drawImage(rat[i]->getRect(),rat[i]->getImage());
	}
	for (int h=0; h < turt.size(); h++)
	{
		//if(!turt[h]->isdestroyed())
		painter.drawImage(turt[h]->getRect(),turt[h]->getImage());
	}
	for (int g=0; g < sht.size(); g++)
	{
		painter.drawImage(sht[g]->getRect(),sht[g]->getImage());
	}
	//painter.drawImage(sht->getRect(),sht->getImage());
	for(int j =0; j<bombnum;j++)
	{
		painter.drawImage(bomb[j]->getRect(),bomb[j]->getImage());
	}	
	for (int j =0 ; j <banana.size(); j++)
	{	
		painter.drawImage(banana[j]->getRect(),banana[j]->getImage());
			
	}
	for(int b=0;b<banana2.size();b++)
	{				
		painter.drawImage(banana2[b]->getRect(),banana2[b]->getImage());
	}
	for( int i=0 ; i<fire.size(); i++)
	{
		painter.drawImage(fire[i]->getRect(),fire[i]->getImage());
	}
	
	for (int g =0 ; g <item.size(); g++)
	{
		if(hunter->giantplayer()==FALSE)
		painter.drawImage(item[g]->getRect(),item[g]->getImage());
	}
		
	for (int s =0 ; s<wingshoes.size();s++)
	{
		if(hunter->fastplayer()==FALSE)
			painter.drawImage(wingshoes[s]->getRect(),wingshoes[s]->getImage());
	}
	}
}
//timer (auto play setting)
void collision::timerEvent(QTimerEvent *event)
{	
	static int timer=0;	
	static int timer1=0;
	int tempapple =rand()%300;
	int tempshoes =rand()%600;
	if(hunter->giantplayer()==TRUE)
	{	
		timer ++;
		if(timer==100)
		{
			timer=0;
			
			TIME->display(countclock--);	

			if(countclock+1 ==0)
			{
				hunter->setgiant(FALSE);				
				itemcheckapple=FALSE;
				countclock=15;
			}			
		}
	}
	if(hunter->fastplayer()==TRUE)
	{	
		timer1 ++;
		if(timer1==100)
		{
			timer1=0;
			
			SHOES->display(countclock1--);	

			if(countclock1+1 ==0)
			{
				hunter->setshoes(FALSE);				
				itemcheckshoes=FALSE;
				countclock1=15;
			}			
		}
	}
	moverabbit();
	moveturtle();	
	moveshot();
	movemonkey();
	movebanana();
	movefire();
		if(tempapple ==6 && itemcheckapple ==FALSE)
		{
			item.push_back(new Item());
			itemcheckapple =TRUE;
		}
		if(tempshoes==8 && itemcheckshoes ==FALSE)
		{
			wingshoes.push_back(new Wingshoes());
			itemcheckshoes =TRUE;
		}
	
	if(clock%tigerspeed==0)
	{
	movetiger();
	clock =0;
	}
	if(clock1%boarspeed==0)
	{
		moveboar();
		clock1=0;
	}
		clock++;
		clock1++;
	delshot();
	//delbanana();
    checkcollision();
	repaint();
}
void collision::movemonkey()
{
	int px,py,mx,my;
		
		if(monkey->getRect().y()>30)
		{
			
			int temn =rand()%500;
			if(temn==6)
			{
			int tempx = rand()%500;
			monkey->move(tempx,-10);	
			}		

		}	
		else 
		{				
			int y=monkey->getRect().y()+1;
			int x =monkey->getRect().x();
			//bananacheck=FALSE;
			monkey->move(x,y);
			if (monkey->getRect().y()==30)				
				{
					int tempx =hunter->gethunt().x();
					int tempy =hunter->gethunt().y();
					bananacheck=FALSE;
					banana.push_back(new Banana(monkey->getRect().x(),monkey->getRect().y(),tempx,tempy));					
					
				}	
				//timecount =TRUE;		
		}
}
void collision::movebanana()
{
	
	for(int i = 0; i <banana.size(); i++)
	{
		int bananax = banana[i]->getRect().x();
		int bananay =banana[i]->getRect().y();
		bananacheck=FALSE;
		banana[i]->move(bananax,bananay);
		if(banana[i]->getRect().x()==banana[i]->getplayerx() && banana[i]->getRect().y() ==banana[i]->getplayery() && !(banana[i]->getRect()).intersects(hunter->gethunt()) )
		{
			
			//banana.remove(i);
			banana[i]->setdestoryed(TRUE);
			banana2.push_back(new Banana2(banana[i]->getplayerx(),banana[i]->getplayery()));
		}
	}
	
}
void collision::moveboar()
{	
	for (int bo = 0 ; bo<boar.size();bo++)
	{
		if (boar[bo]->getRect().x() <-70)
	{
		int tempn =rand()%100;		
		if(tempn ==5)
		{
		int tempy =rand()%500;
		int tempx=500;		
		boar[bo]->move(tempx,tempy);
		}
	}
	else
	{
	int y =boar[bo]->getRect().y();
	int x =boar[bo]->getRect().x()-2;	
	boar[bo]->move(x,y);
	}	
	}
}
void collision::movetiger()//movetiger
{
	int dx, dy;
	int ty = tig->getRect().y();
	int tx = tig->getRect().x();
	int hy =hunter->gethunt().y();
	int hx =hunter->gethunt().x();
	dx = tx-hx;
	dy =ty -hy;
	if(abs(dx)>abs(dy))
	{
		if (dx>0)
		{
			
			tig->moveleft(--tx,ty);
		}
		else if(dx<0)
		{
			
			tig->moveright(++tx,ty);
		}
	}
	else if(abs(dx)<abs(dy))
	{
		if(dy>0)
		{
			
			tig ->moveup(tx,--ty);
		}
		else if(dy<0)
		{
			
			tig->movedown(tx,++ty);
		}
	}
	else if(abs(dx)==abs(dy))
	{
		if(dy>0&& dx>0)
		{
			tig->movetopleft(--tx,--ty);
		}
		else if(dy<0&&dx>0)
		{
			tig->movedownleft(--tx,++ty);
		}
		else if(dy<0&&dx<0)
		{
			tig->movedownright(++tx,++ty);
		}
		else if(dy>0&&dx<0)
		{
			tig->moveupright(++tx,--ty);
		}
		
	}
}
void collision::moveturtle()//move turtles
{
	for (int i=0; i <turt.size() ; i ++)
	{
		int n = rand()%8+1;
		if( n ==1)
		{
			int y = turt[i]->getRect().y()+1;
			int x =turt[i]->getRect().x();
			if(y>500)
			{
				y=y-2;
				for (int g =0; g<4; g++)
				turt[i]->move(x,y);
			}
			else				
				for (int g =0; g<4; g++)
				turt[i]->move(x,y);
		}
		if( n ==2)
		{	int y = turt[i]->getRect().y()-1;
			int x =turt[i]->getRect().x();
			if(y<0)
			{
				y=y+2;
				for (int g=0; g<4; g++)
				turt[i]->move(x,y);
			}
			else
				for (int g =0; g<4; g++)
				turt[i]->move(x,y);
		}
		
		
	
		if(n==3)
		{
			int y = turt[i]->getRect().y();
			int x =turt[i]->getRect().x()-1;
			if(x<0)
			{
				x=x+2;
				for (int g =0; g<4; g++)
				turt[i]->move(x,y);
			}
			else
				for (int g =0; g<4; g++)
				turt[i]->move(x,y);
		}
		if(n==4)
		{
			int y = turt[i]->getRect().y();
			int x =turt[i]->getRect().x()+1;
			if( x>500)
			{
				x=x-2;
				for (int g =0; g<4; g++)
				turt[i]->move(x,y);
			}
			else
				for (int g =0; g<4; g++)
				turt[i]->move(x,y);
		}
	}
}
void collision::moverabbit()
{
	for (int i=0; i <rat.size() ; i ++)
	{
		int n = rand()%8+1;
		if( n ==1)
		{
			int y = rat[i]->getRect().y()+3;
			int x =rat[i]->getRect().x();
			if(y>500)
			{
				y=y-6;
				rat[i]->move(x,y);
			}
			else				
				rat[i]->move(x,y);
		}
		if( n ==2)
		{	int y = rat[i]->getRect().y()-3;
			int x =rat[i]->getRect().x();
			if(y<0)
			{
				y=y+6;
				rat[i]->move(x,y);
			}
			else
				rat[i]->move(x,y);
		}
		if(n==3)
		{
			int y = rat[i]->getRect().y()+3;
			int x =rat[i]->getRect().x()-3;
			if(y>500 &&x<0)
			{
				y=y-6;
				x=x+6;
				rat[i]->move(x,y);
			}
			else
				rat[i]->move(x,y);
		}	
		if(n==4)
		{
			int y = rat[i]->getRect().y()+3;
			int x =rat[i]->getRect().x()+3;
			if(y>500 &&x>500)
			{
				x=x-6;
				y=y-6;
			rat[i]->move(x,y);
			}
			else
				rat[i]->move(x,y);
		}
		if(n==5)
		{
			int y = rat[i]->getRect().y()-3;
			int x =rat[i]->getRect().x()-3;
			if(y<0 && x<0)
			{
				y=y+6;
				x=x+6;
				rat[i]->move(x,y);
			}
			else
				rat[i]->move(x,y);
		}
		if(n==6)
		{
			int y = rat[i]->getRect().y()-3;
			int x =rat[i]->getRect().x()+3;
			if(y<0 &&x>500)
			{
				y=y+6;
				x=x-6;
				rat[i]->move(x,y);
			}
			else
				
				rat[i]->move(x,y);
		}
		if(n==7)
		{
			int y = rat[i]->getRect().y();
			int x =rat[i]->getRect().x()-3;
			if(x<0)
			{
				x=x+6;
				rat[i]->move(x,y);
			}
			else
				rat[i]->move(x,y);
		}
		if(n==8)
		{
			int y = rat[i]->getRect().y();
			int x =rat[i]->getRect().x()+3;
			if( x>500)
			{
				x=x-6;
				rat[i]->move(x,y);
			}
			else
				rat[i]->move(x,y);
		}
	}
}
void collision::movefire()
{
	int firetime = rand()% 400;
	int playerx = hunter->gethunt().x();
	int playery=hunter->gethunt().y();
	if( firetime == 4)
	{
		int trapx =trap->getRect().x();
		int trapy =trap->getRect().y();
		int playerx = hunter->gethunt().x();
		int playery=hunter->gethunt().y();
		fire.push_back(new Fire(trapx,trapy, playerx,playery));

	}
	if(fire.size())
	{
		for(int i =0 ; i <fire.size() ; i ++)
		{
			int firex=fire[i]->getRect().x();
			int firey=fire[i]->getRect().y();			
			fire[i]->move(firex,firey);
		}
	}
}

	

//move plaeyr shot
void collision::moveshot()
{
	
	for(int i = 0; i <sht.size();i++)
	{
		int x=sht[i]->getRect().x();
		int y=sht[i]->getRect().y();
		for(int j= 0;j<3;j++)
		sht[i]->move(x++,y);
	}
}
void collision::delshot()
{
		for(int i=0 ; i <sht.size() ; i++)
		{
			for( int bo = 0 ; bo <boar.size() ; bo++)
			{
			if(sht[i]->getRect().x() > 500)		
				sht.remove(i);
			else if((sht[i]->getRect()).intersects(boar[bo]->getRect()))
			{
				if(boarlife>0)
				{boarlife = boarlife-5;
				Boarlife->display(boarlife);
				sht.remove(i);
				}
				if (boarlife==0)
				{
					score=score+300;
					boarcheck =TRUE;
					scorenum->display(score);
					boar[bo]->setdestoryed(TRUE);
					boar.remove(bo);
				}
			}
			}
		}
		for (int j =0 ; j <banana.size() ; j ++)
		{
			if(banana[j]->destorybanana()==TRUE)
				banana.remove(j);
		}
		for (int k =0 ; k <banana2.size() ; k++)
		{
			if(banana2[k]->destoryboar()==TRUE)
				banana2.remove(k);
		}
		for (int r=0; r <rat.size();r++)
		{
			if(rat[r]->isdestroyed()==TRUE)
				rat.remove(r);
		}
		for (int t=0;t< turt.size(); t++)
		{		if(turt[t]->isdestroyed()==TRUE)
				turt.remove(t);
		}
		for (int f = 0 ; f < fire.size() ; f++)
		{
			if(fire[f]->getRect().x() ==fire[f]->getplayerx() && fire[f]->getRect().y() ==fire[f]->getplayery())
				fire.remove(f);
		}
		
}
void collision::keyPressEvent(QKeyEvent *event)
{
	switch(event->key())
	{
	case Qt::Key_Left:
		{
			if(!hunter->fastplayer())
			{
			int y=hunter->gethunt().y();
			int x =hunter->gethunt().x()-3;				
			hunter->moveleft(x,y);
			}
			else if(hunter->fastplayer())
			{
				int y=hunter->gethunt().y();
				int x =hunter->gethunt().x()-6;				
				hunter->moveleft(x,y);
			}

			break;
		}
	case Qt::Key_Right:
		{
			if(!hunter->fastplayer())
			{
			int x =hunter->gethunt().x()+3;
			int y =hunter->gethunt().y();			
			hunter->moveright(x,y);
			}
			else if(hunter->fastplayer())
			{
				int x =hunter->gethunt().x()+6;
				int y =hunter->gethunt().y();			
				hunter->moveright(x,y);
			}
			break;
		}
	case Qt::Key_Down:
		{
			if(!hunter->fastplayer())
			{
				int y=hunter->gethunt().y()+3;
				int x =hunter->gethunt().x();
				hunter->movedown(x,y);
			}
			else if(hunter->fastplayer())
			{
				int y=hunter->gethunt().y()+6;
				int x =hunter->gethunt().x();
				hunter->movedown(x,y);
			}
			break;
		}
	case Qt::Key_Up:
		{	if(!hunter->fastplayer())
			{
				int y=hunter->gethunt().y()-3;
				int x =hunter->gethunt().x();
				hunter->moveup(x,y);
			}
			else if(hunter->fastplayer())
			{
				int y=hunter->gethunt().y()-6;
				int x =hunter->gethunt().x();
				hunter->moveup(x,y);
			}


			break;
		}
	case Qt::Key_Space:
		{
			if(!started)
			start();
		}
		break;
	case Qt::Key_S:
		{
			sht.push_back(new SHOOT(hunter->gethunt().x()+22,hunter->gethunt().y()+15));	
			
		}
		break;
	case Qt::Key_P:
		{
			pausegame();
		}
		break;
	case Qt::Key_Q:
		{
			qApp->exit();
		}
	
	default:
		QWidget::keyPressEvent(event);
	}
}
//set starting positions
void collision::start()
{
	//boarlife =100;
	if(level==0)
	{
	boarlife=100;	
	rabbitnum=2;
	turcount=0;
	rabcount=0;
	turtlenum=2;
	bombnum=3;
	tigerspeed=4;
	boarspeed=4;
	}
	else if(level==1)
	{
		tigerspeed=3;
		bombnum=4;
		turcount=0;
		rabcount=0;
		rabbitnum =4;
		turtlenum =4;
		boarspeed=3;
	}
	else if(level ==2)
	{
		tigerspeed=2;
		bombnum=7;
		rabbitnum =5;
		boarspeed=2;
		turtlenum =5;
	}
	if(!started)
	{
	
	
	for (int j =0 ; j <bombnum; j++)
	{
		int bx =rand()%440;
		int  by=rand()%440;
		
		bomb[j] = new BOMB(bx,by);
	}
		tig->initialposition();
		hunter->initialposition();
		monkey->initailposition();
		boar.clear();		
		banana.clear();
		sht.clear();
		item.clear();
		banana2.clear();
		wingshoes.clear();
		rat.clear();
		turt.clear();
		fire.clear();
		scorenum->display(0);
		RAB->display(0);
		TUR->display(0);
		TIME->display(15);
		SHOES->display(15);
		Boarlife->display(boarlife);

		
	}
		if(level==0)
	qApp->setStyleSheet("QWidget{background-image:url(./image/background1.png)}");
	else if(level==1)
	qApp->setStyleSheet("QWidget{background-image:url(./image/background2.png)}");
	else if(level==2)
	qApp->setStyleSheet("QWidget{background-image:url(./image/background3.png)}");
	int boarx =500; 
	int boary =50;
	boar.push_back(new Boar(boarx,boary));
		for (int i = 0; i <rabbitnum ; i ++)
	{
		int r =rand()%470;
		int c =rand()%470;
		rat.push_back(new Rabbit(r,c));
	}
	int trapx =450;
	int trapy =450;
	trap = new Trap(trapx,trapy);
	for(int i =0; i <rat.size(); i++)
	{
		rat[i]->setdestroyed(FALSE);
	}
	for (int j =0 ; j <bombnum; j++)
	{
		int bx =rand()%440;
		int by=rand()%440;
		
		bomb[j] = new BOMB(bx,by);
	}
	for (int h = 0; h <turtlenum ; h ++)
	{
		int r =rand()%490;
		int c =rand()%490;
		turt.push_back(new Turtle(r,c));
	}
	for(int h =0; h <turt.size(); h++)
	{
		turt[h]->setdestroyed(FALSE);

	}
	for (int bb =0 ;bb <banana.size(); bb++)
	banana[bb]->setdestoryed(FALSE);
	hunter->setdestoryed(FALSE);
	hunter->setgiant(FALSE);
	hunter->setshoes(FALSE);
	for( int bo = 0 ;bo < boar.size(); bo++)
	boar[bo]->setdestoryed(FALSE);
	for (int b=0; b <banana2.size() ; b++)
	banana2[b]->setdestoryed(FALSE);
	gameover=FALSE;
	gamewon=FALSE;
	boarcheck =FALSE;
	itemcheckapple=FALSE;
	itemcheckshoes=FALSE;
	bananacheck=FALSE;
	timecount=FALSE;
	started=TRUE;
	timerld=startTimer(10);
	boarlife=100;
	score=0;
}
// quit when lose
void collision::Gameover()
{
	killTimer(timerld);
	gameover=TRUE;
	started=FALSE;
}
//quit when win
void collision::victory()
{
  killTimer(timerld);
  gamewon = TRUE;  
  started = FALSE;
}
//pause game
void collision::pausegame()
{
	if(paused)
	{
		timerld =startTimer(10);
		paused=FALSE;
	}
	else
	{
		paused=TRUE;
		killTimer(timerld);
	}
}
//check for collision
void collision::checkcollision()
{
	
	
	for( int i =0; i < rat.size() ; i ++)
	{
		if((hunter->gethunt()).intersects(rat[i]->getRect()))
		{			
			rat[i]->setdestroyed(TRUE);		
			rabcount++;
			RAB->display(rabcount);
			score=score+100;
			scorenum->display(score);
		}		
	}
	for( int h =0 ; h < turt.size() ; h ++)
	{
		if((hunter->gethunt()).intersects(turt[h]->getRect()))
		{			
			turt[h]->setdestroyed(TRUE);
			turcount++;
			TUR->display(turcount);
			score=score+50;
			scorenum->display(score);
						
		}
		
	}
		for ( int  j = 0 ; j <banana2.size() ; j++)
		{
		if(hunter->gethunt().intersects(banana2[j]->getRect()))
		{
			score = score+30;
			banana2[j]->setdestoryed(TRUE);
			scorenum->display(score);
		}
		}
		
		
		if(rabcount==rabbitnum&&turcount==turtlenum  &&boarcheck ==TRUE)
			{victory();
			if(level!=2)
			level++;
			else if(level==2)
				level =0;
			}
		
		
	for (int t=0;t <item.size() ; t++)
	{
		if((hunter->gethunt()).intersects(item[t]->getRect()))
		{
			
			hunter->setgiant(TRUE);
			item.remove(t);
		}
	}
	// hunter gets shoes
	for (int s=0; s<wingshoes.size();s++)
	{
		if((hunter->gethunt()).intersects(wingshoes[s]->getRect()))
			{
				//wingshoes[s]->setdestroyed(TRUE);
				hunter->setshoes(TRUE);
				wingshoes.remove(s);
		}
	}	
	for (int b=0; b<banana.size(); b++)
	{
		if((banana[b]->getRect()).intersects(hunter->gethunt()))
		{
			if(hunter->giantplayer()==FALSE)
			{
			hunter->setdestoryed(TRUE);
			Gameover();
			}
		}
	}
	for (int b=0; b<fire.size(); b++)
	{
		if((fire[b]->getRect()).intersects(hunter->gethunt()))
		{
			if(hunter->giantplayer()==FALSE)
			{
			hunter->setdestoryed(TRUE);
			Gameover();
			}
		}
	}
	

	if((tig->getRect()).intersects(hunter->gethunt()))
	{
		if(hunter->giantplayer()==FALSE)
		{
		hunter->setdestoryed(TRUE);
		Gameover();
		}
	}
	for ( int bo = 0 ; bo < boar.size() ; bo++)
	{
	if(!boar[bo]->destoryboar())
	{
	if((boar[bo]->getRect()).intersects(hunter->gethunt()))
	{
		if(hunter->giantplayer()==FALSE)
		{

			hunter->setdestoryed(TRUE);
			Gameover();
		}
	}
	}
	}
}
void collision::scorebar()
{
	QHBoxLayout *layout = new QHBoxLayout;
	//Rabbit life
	RAB = new QLCDNumber(2);
	RAB->setSegmentStyle(QLCDNumber::Flat);
	QLabel *life=new QLabel(tr("Rabbit"));
	RAB->setFont(QFont("Times",10));
	layout->addWidget(life);
	layout->addWidget(RAB);
	//Turtle life
	TUR = new QLCDNumber(2);
	TUR->setSegmentStyle(QLCDNumber::Flat);
	QLabel *TURlife=new QLabel(tr("Turtle"));
	TUR->setFont(QFont("Times",10));
	layout->addWidget(TURlife);
	layout->addWidget(TUR);
	// APPLE	
	TIME = new QLCDNumber(4);
	TIME->setSegmentStyle(QLCDNumber::Flat);
	QLabel *time = new QLabel(tr("SUPERMAN"));	
	layout->addWidget(time);
	layout->addWidget(TIME);
	TIME->setFont(QFont("Times",10));	
	//SHOES;
	SHOES = new QLCDNumber(4);
	SHOES->setSegmentStyle(QLCDNumber::Flat);
	QLabel *shoes = new QLabel(tr("SHOES"));	
	layout->addWidget(shoes);
	layout->addWidget(SHOES);
	SHOES->setFont(QFont("Times",10));
	//boarlife
	Boarlife = new QLCDNumber(3);
	Boarlife->setSegmentStyle(QLCDNumber::Flat);
	QLabel *boarlife = new QLabel(tr("Boar HP"));	
	layout->addWidget(boarlife);
	layout->addWidget(Boarlife);
	Boarlife->setFont(QFont("Times",10));
	

    // SCORE
	scorenum = new QLCDNumber(5);
    scorenum->setSegmentStyle(QLCDNumber::Flat);
    QLabel *score = new QLabel(tr("SCORE"));
	scorenum->setFont(QFont("Times",10));
	layout->addWidget(score);
	layout->addWidget(scorenum);
	QWidget *window =new QWidget;
	window->setLayout(layout);
	window->show();
	window->setGeometry(350,50,0,0);


}
