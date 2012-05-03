#include "collision.h"
#include<QApplication>
#include<QDesktopWidget>
#include <QImage>
#include <QRect>


//Main
int main(int argc, char *argv[])
{
	
  QApplication app(argc, argv);
  //variables
  int posx, posy;
  int screenW;
  int screenH;
  int WIDTH = 500;//monitor size width
  int HEIGHT = 500;//monitor size height
  QDesktopWidget *desktop = QApplication::desktop();
  //get size of monitor
  screenW = desktop->width();
  screenH = desktop->height(); 
  posx = (screenW - WIDTH) / 2;
  posy = (screenH - HEIGHT) / 2;   
    
  collision window;
  window.setGeometry(posx, posy, WIDTH, HEIGHT);
  window.setFixedSize(WIDTH, HEIGHT);
  window.setWindowTitle("HUNT");
   // window.setStyleSheet("background-image:Image/background.png");
  window.show();

 

  return app.exec();
}
