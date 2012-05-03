#ifndef COLLISION_H
#define COLLISION_H

#include "player.h"
#include "rabbit.h"
#include "trap.h"
#include "fireball.h"
#include "tiger.h"
#include "monkey.h"
#include "turtle.h"
#include "shooting.h"
#include "bomb.h"
#include "wingshoes.h"
#include "boar.h"
#include "banana.h"
#include "banana2.h"
#include "item.h"
#include <QWidget>
#include <QKeyEvent>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QLabel>
//class for collision
class collision: public QWidget

{
//Q_OBJECT
protected:
	void keyPressEvent(QKeyEvent *event);//control keyboard
	void paintEvent(QPaintEvent *event);//display picture and messge
	void timerEvent(QTimerEvent *event);//time control
	void start();
	void moverabbit();
	void pausegame();
	void quitgame();
	void Gameover();
	void victory();
	void checkcollision();
	void movetiger();
	void moveturtle();
	void scorebar();
	void moveboar();
	void moveshot();
	void delshot();
	void delbanana();
	void movemonkey();
	void movebanana();
	void movefire();	
private:
	int x,y;
	int clock,clock1;
	int check;
	int timerld;
	int level;
	int score;
	int boarspeed;
	bool timecount;
	bool gameover;
	bool gamewon;
	bool started;
	bool boarcheck;
	bool big;
	bool paused;
	bool itemcheckapple;
	bool itemcheckshoes;
	bool bananacheck;
	int turtlenum;
	int tigerspeed;
	int rabbitnum;
	int rabcount;
	int boarlife;
	int turcount;
	int bombnum;
	int countclock,countclock1;
	//sub classes
	player *hunter;
	Tig *tig;
	Trap *trap;
	//Turtle *turt[10];
	BOMB *bomb[10];
	QVector<Banana*> banana;
//	Banana *banana;
	QVector<Fire*> fire;
	QVector<Boar*> boar;
	QVector<SHOOT*> sht;
	QVector<Item*> item;
	QVector<Wingshoes*> wingshoes;
	QVector<Banana2*> banana2;
	QVector <Rabbit*> rat;
	QVector <Turtle*> turt;
	Monkey *monkey;
	//Rabbit *rat[10];
	QLCDNumber *scorenum;
	QLCDNumber *RAB;
	QLCDNumber *TUR;
	QLCDNumber*TIME;
	QLCDNumber *SHOES;
	QLCDNumber *Boarlife;
	
public:
	collision (QWidget *parent=0);
	
};

#endif COLLISION_H



