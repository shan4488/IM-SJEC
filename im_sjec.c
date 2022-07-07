#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>

int i=0,j=0,k=0,l=0;
int menuFlag = 0;
float xval=255.0, yval=10.0;
int moveFlag=0, breakFlag=0, breakFlag1=0, civilFlag=0, indFlag=0;
void timer();
void moveBox();

void path(int x1,int y1,int x2,int y2){
        glColor3f(0.0,1.0,0.0);
        glLineWidth(300);
        glBegin(GL_LINES);
        glVertex2i(x1-50,y1);
        glVertex2i(x2-50,y2);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        glLineWidth(50);
        glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        glLineWidth(50);
        glBegin(GL_LINES);
        glVertex2i(x1-100,y1);
        glVertex2i(x2-100,y2);
        glEnd();

}

/*void writeOnScreen(int x, int y, float r, float g, float b, char *string)
{
  glColor3f( r, g, b );
//  glScalef(1,1,1);
  glRasterPos2f(210, 300);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }
}*/

void writeOnScreen(int x, int y, float r, float g, float b, char *string)
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, string);

}


void drawLine(int x, int y, int x1, int y1, int thick, float r, float g, float b){
	glColor3f(r,g,b);
	glLineWidth(thick);
	glBegin(GL_LINES);
	glVertex2i(x,y);
	glVertex2i(x1,y1);
	glEnd();
}

void roadLine(float x1, float y1, float x2, float y2,float width){
        glColor3f(0.0,0.0,1.0);
        glLineWidth(width);
        glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glEnd();

}

void roadLineNew(float x1, float y1, float x2, float y2,float width, float r, float g, float b){
        glColor3f(r,g,b);
        glLineWidth(width);
        glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glEnd();

}


void wholeMap(){
        roadLine(260,10,260,100,80);//entrance
	roadLine(260,100,170,100,60);//leftFromE
	roadLine(220,100,420,100,60);//rightFromE
	roadLine(170,86,170,440,60);//ghRoad
	roadLine(30,200,240,200,60);//albertosRoad
	roadLine(30,90,170,100,60);//bethaniaRoad
	roadLine(30,76,40,400,60);//bhToBethania
	roadLine(80,430,178,430,60);//groundfromGH
	roadLine(100,330,470,330,40);//BoyshostelToParking-BTP
	roadLine(70,300,100,330,40);//bendtoBTP
	roadLine(40,300,70,300,40);//bend2ToBTP
	roadLine(420,25,400,250,60);//AB1ParkRoad
	roadLine(410,150,430,325,40);//parkSideRoad
        roadLine(90,210,90,270,41);//civil
       // roadLine(81,260,96,260,40);//civil bend

}

void administration(float x, float y){
	glColor3f(1.0,1.0,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
	glVertex2f(x+40,y);
	glVertex2f(x+40,y+140);
	glVertex2f(x,y+140);
	glEnd();
	glFlush();
}

void ab1(float x, float y){
        glColor3f(1.0,0.6,0.5);
        glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+170,y);
        glVertex2f(x+170,y+60);
        glVertex2f(x,y+60);
        glEnd();
        glFlush();
}

void ideaLab(float x, float y){
        glColor3f(1.0,0.8,0.5);
        glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+50,y);
        glVertex2f(x+50,y+100);
        glVertex2f(x,y+100);
        glEnd();
        glFlush();
}

void generalParking(float x, float y, float xinc, float yinc, float red, float green, float blue){
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+xinc+18,y);
        glVertex2f(x+xinc+6,y+yinc);
        glVertex2f(x,y+yinc);
        glEnd();
        glFlush();

}

void generalBuilding(float x, float y, float xinc, float yinc, float red, float green, float blue){
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+xinc,y);
        glVertex2f(x+xinc,y+yinc);
        glVertex2f(x,y+yinc);
        glEnd();
        glFlush();

}

void canteenAndShop(float x, float y, float xinc, float yinc, float red, float green, float blue){
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+xinc,y);
        glVertex2f(x+xinc,y+yinc);
        glVertex2f(x-6,y+yinc);
        glEnd();
        glFlush();

}

void transHospBethania(float x, float y, float xinc, float yinc, float red, float green, float blue){
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x+xinc,y);
        glVertex2f(x+xinc,y+yinc+10);
        glVertex2f(x,y+yinc);
        glEnd();
        glFlush();

}

void aB3bend(float red, float green, float blue){
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        glVertex2f(80,267);
        glVertex2f(100,292);
        glVertex2f(100,317);
        glVertex2f(80,297);
        glEnd();
        glFlush();

}


//define a cross section of the ab3 and civil after analysis phase

void ground(int x, int y, int r){
	glBegin(GL_TRIANGLE_FAN);
	for(i=0;i<360;i++){
		float theta = (i*360)/180;
		glVertex2f(x+(r*cosf(theta)), y+(r*sinf(theta)));
	}
	glEnd();
}

void reset(float x, float y){
	xval = x;
	yval = y;
	moveBox();
}


void amphi(){

	glColor3f(0.6,0.6,0.9);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(45,180);
	glVertex2f(98,180);
	glVertex2f(97,170);
	glVertex2f(95,160);
        glVertex2f(91,150);
        glVertex2f(86,140);
        glVertex2f(80,130);
        glVertex2f(73,120);
     	glVertex2f(65,110);
      	glVertex2f(60,110);
        glVertex2f(42,110);
      	glEnd();
}

void fillMenu(int choice){
//                xval = 255.0;
  //              yval = 10.0;
    //            moveBox();

	if(choice==1){
		menuFlag=1;
		reset(255.0, 10.0);
	}
        if(choice==2){
                menuFlag=2;
                reset(255.0, 10.0);
        }
        if(choice==3){
                menuFlag=3;
                reset(255.0, 10.0);
        }
        if(choice==4){
                menuFlag=4;
                reset(255.0, 10.0);
        }
        if(choice==5){
                menuFlag=5;
                reset(255.0, 10.0);
        }
        if(choice==6){
                menuFlag=6;
                reset(255.0, 10.0);
        }
        if(choice==7){
                menuFlag=7;
                reset(255.0, 10.0);
        }
        if(choice==8){
                menuFlag=8;
                reset(255.0, 10.0);
        }
        if(choice==9){
                menuFlag=9;
                reset(255.0, 10.0);
        }
        if(choice==10){
                menuFlag=10;
                reset(255.0, 10.0);
        }
        if(choice==11){
                menuFlag=11;
                reset(255.0, 10.0);
        }
        if(choice==12){
                menuFlag=12;
                reset(255.0, 10.0);
        }
        if(choice==13){
                menuFlag=13;
                reset(255.0, 10.0);
        }
        if(choice==14){
                menuFlag=14;
                reset(255.0, 10.0);
        }
        if(choice==15){
                menuFlag=15;
                reset(255.0, 10.0);
        }
        if(choice==16){
                menuFlag=16;
                reset(255.0, 10.0);
        }
        if(choice==17){
                menuFlag=17;
                reset(255.0, 10.0);
        }
        if(choice==18){
                menuFlag=18;
                reset(255.0, 10.0);
        }
        if(choice==19){
                menuFlag=19;
                reset(255.0, 10.0);
        }
        if(choice==20){
                menuFlag=20;
                reset(255.0,10.0);
        }

	if(choice==21){
		menuFlag=21;
		reset(255.0,10.0);
	}

}

void menuActions(){

	//xval=255.0, yval=10.0;
	//Administration
        if(menuFlag == 1){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
		//xval=255.0, yval=10.0;
//	        administration(240,120);//administration
		moveFlag = 1;
        }

	//AB3
	if(menuFlag == 2){
		//xval=255.0, yval=10.0;
		roadLineNew(170,86,170,300,60,0.8,1.0,0.2);//ghRoad
	        roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
        	roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
		generalBuilding(120,272,40,45,0.2,1.0,0.0);//ab3

		moveFlag = 2;
	}

	//Albertos
	if(menuFlag == 3){
	        roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
        	roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
	        roadLineNew(170,86,170,215,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(60,200,170,200,60,0.8,1.0,0.2);//albertos road
		moveFlag=3;

	}

	//AB1
        if(menuFlag == 4){
		roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
	        roadLineNew(260,100,420,100,60,0.8,1.0,0.2);//rightFromE
	        roadLineNew(415,85,400,250,60,0.8,1.0,0.2);//AB1ParkRoad

		//Second road
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                roadLineNew(170,86,170,215,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(170,200,240,200,60,0.8,1.0,0.2);//albertos road
                moveFlag = 4;


        }

	//Idea Lab
        if(menuFlag == 5){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(260,100,300,100,60,0.8,1.0,0.2);//rightFromE
                moveFlag = 5;

        }

	//Student Square
        if(menuFlag == 6){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(170,86,170,230,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                moveFlag = 6;

        }

	//Chappel
        if(menuFlag == 7){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
	        roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
	        roadLineNew(150,97,170,100,60,0.8,1.0,0.2);//bethaniaRoad
                moveFlag = 7;

        }

	//CCC
        if(menuFlag == 8){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(170,86,170,240,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                moveFlag = 8;

        }

	//Volleyball Ground
        if(menuFlag == 9){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(170,86,170,350,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                moveFlag = 9;

        }

	//Civil Block
        if(menuFlag == 10){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                roadLineNew(170,86,170,215,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(85,200,170,200,60,0.8,1.0,0.2);//albertos road
	        roadLineNew(90,210,90,270,41,0.8,1.0,0.2);//civil

                moveFlag=10;

        }

	//Basketball Ground
        if(menuFlag == 11){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(170,86,170,245,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                moveFlag = 11;

        }

	//E-Baha
        if(menuFlag == 12){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(170,86,170,340,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
	        roadLineNew(170,330,320,330,40,0.8,1.0,0.2);//bhToParking-BTP
                moveFlag = 12;

        }

	//Amphi-Theater
        if(menuFlag == 13){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(260,100,150,100,60,0.8,1.0,0.2);//leftFromE
                roadLineNew(100,95,170,100,60,0.8,1.0,0.2);//bethaniaRoad
                moveFlag = 13;

        }

	//Play Ground
        if(menuFlag == 14){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(170,86,170,420,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
	        roadLineNew(80,430,178,430,60,0.8,1.0,0.2);//groundfromGH
	        roadLineNew(100,330,170,330,40,0.8,1.0,0.2);//bhToParking-BTP
                roadLineNew(37,290,40,400,60,0.8,1.0,0.2);//bhToBethania
                roadLineNew(70,300,100,330,40,0.8,1.0,0.2);//bendtoBTP
                roadLineNew(40,300,70,300,40,0.8,1.0,0.2);//bend2ToBTP
                moveFlag = 14;
        }

	//Placements Office
	if(menuFlag == 15){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                roadLineNew(170,86,170,215,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(170,200,240,200,60,0.8,1.0,0.2);//albertos road
                moveFlag = 15;

	}

        //Boys Hostel
        if(menuFlag == 16){
		//Fisrst Road
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(170,86,170,340,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                roadLineNew(100,330,170,330,40,0.8,1.0,0.2);//bhToParking-BTP
                roadLineNew(70,300,100,330,40,0.8,1.0,0.2);//bendtoBTP
                roadLineNew(40,300,70,300,40,0.8,1.0,0.2);//bend2ToBTP

		//Second Road
                roadLineNew(30,200,170,200,60,0.8,1.0,0.2);//albertos road


		//Third Road
                roadLineNew(100,95,170,100,60,0.8,1.0,0.2);//bethaniaRoad
	        roadLineNew(30,76,37,310,60,0.8,1.0,0.2);//bhToBethania
	        roadLineNew(30,90,170,100,60,0.8,1.0,0.2);//bethaniaRoad
                moveFlag = 16;


        }

        //Girls Hostel
        if(menuFlag == 17){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(170,86,170,445,60,0.8,1.0,0.2);//ghRoad
                roadLineNew(260,100,170,100,60,0.8,1.0,0.2);//leftFromE
                moveFlag = 17;

        }

	//Canteen and Shops
        if(menuFlag == 18){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(260,100,420,100,60,0.8,1.0,0.2);//rightFromE
                roadLineNew(420,25,412,115,60,0.8,1.0,0.2);//AB1ParkRoad
                moveFlag = 18;

	}

	//Transport/Hospital/Bethania
        if(menuFlag == 19){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(260,100,150,100,60,0.8,1.0,0.2);//leftFromE
                roadLineNew(100,95,170,100,60,0.8,1.0,0.2);//bethaniaRoad
		drawLine(210,79,210,115,10,1.0,0.4,1.0);
                drawLine(160,75,160,114,10,1.0,0.4,1.0);
                drawLine(140,75,140,112,10,1.0,0.4,1.0);
                moveFlag = 19;

        }

        if(menuFlag == 20){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(260,100,420,100,60,0.8,1.0,0.2);//rightFromE
                roadLineNew(408,160,415,85,60,0.8,1.0,0.2);//AB1ParkRoad
                moveFlag=20;
        }


	if(menuFlag == 21){
                roadLineNew(260,10,260,115,80,0.8,1.0,0.2);//entrance
                roadLineNew(260,100,300,100,60,0.8,1.0,0.2);//rightFromE
		moveFlag=21;
	}


}

void moveBox(){
        glLoadIdentity();
        glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(xval,yval);
        glVertex2f(xval+12,yval);
        glVertex2f(xval+12,yval+20);
        glVertex2f(xval,yval+20);
        glEnd();

}

void init(){
	glClearColor(0.3,0.3,0.0,1.0);
}

void reshape(int w, int h){
	glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0,500,0,500);
        glMatrixMode(GL_MODELVIEW);
}

void display(){
        glClear(GL_COLOR_BUFFER_BIT);
	//path(200,0,200,900);
	//roadLine(260,10,260,100,80);
	administration(240,120);//administration
	ab1(240,253);//ab1
	ideaLab(283,120);//ideaLab
	generalParking(336,120,48,130,1.0,0.5,0.2);
	generalBuilding(280,345,70,90,0.8,0.6,0.6);//Ebaha
	generalBuilding(110,110,50,70,0.6,0.6,0.6);//chappel
        generalBuilding(120,218,40,40,0.6,0.6,0.6);//ccc
        generalBuilding(120,272,40,45,0.6,0.6,0.6);//ab3
        generalBuilding(50,218,30,30,0.6,0.6,0.6);//albertos
        generalBuilding(100,343,60,70,0.6,0.9,0.6);//volleyball gnd
	generalBuilding(100,292,20,25,0.6,0.6,0.6);//ab3 extension
	generalBuilding(50,255,30,30,0.6,0.6,0.6);//civil
	generalBuilding(182,258,55,55,0.8,0.6,0.6);//basketball gnd
        generalBuilding(182,220,55,35,0.8,0.8,0.6);//studentSquare
        generalBuilding(5,235,20,70,0.8,0.6,0.6);//boys hostel
        generalBuilding(145,450,50,30,0.8,0.8,0.6);//girls hostel
        canteenAndShop(430,25,30,70,0.8,0.9,0.6);//Canteen and shop
        generalBuilding(275,40,130,40,0.4,0.8,0.6);//Staff parking

        aB3bend(0.6,0.6,0.6);
        //Transport/hospital/bethania seperations
        transHospBethania(50,40,170,30,0.8,0.6,0.8);//transport hospital bethania 
        drawLine(190,40,190,78,5,1.0,1.0,1.0);
        drawLine(150,40,150,75,5,1.0,1.0,1.0);

        amphi();
        ground(43,438,35);
        wholeMap();
        menuActions();



	//administration
	writeOnScreen(240,150,0.8,0.1,0.1,"Administration");
        writeOnScreen(250,140,0.8,0.1,0.1,"Block");
	//ab1
        writeOnScreen(300,270,0.8,0.1,0.1,"Academic Block 1");
	//idea lab
        writeOnScreen(295,150,0.8,0.1,0.1,"Idea Lab");
	//Ebaha
        writeOnScreen(300,380,0.8,0.1,0.1,"E-Baha");
	//chappel
        writeOnScreen(122,150,0.8,0.1,0.1,"Chappel");
	//CCC
        writeOnScreen(123,240,0.8,0.1,0.1,"CCC-Library");
	//AB3
        writeOnScreen(120,300,0.8,0.1,0.1,"Academic");
        writeOnScreen(125,280,0.8,0.1,0.1,"Block 3");
	//albertos
        writeOnScreen(54,230,0.8,0.1,0.1,"Albertos");
	//Volleyball Court
        writeOnScreen(110,370,0.8,0.1,0.1,"Volleyball Court");
	//Civil
        writeOnScreen(56,265,0.8,0.1,0.1,"Civil");
	//Basketball Ground
        writeOnScreen(185,280,0.8,0.1,0.1,"Basketball Ground");
	//Student Square
        writeOnScreen(185,230,0.8,0.1,0.1,"Student Square");
	//boys hostel
        writeOnScreen(6,280,0.8,0.1,0.1,"Boys");
        writeOnScreen(6,270,0.8,0.1,0.1,"Hostel");
	//Girls Hostel
        writeOnScreen(155,460,0.8,0.1,0.1,"Girls Hostel");
	//Playground
        writeOnScreen(25,450,0.8,0.1,0.1,"Playground");
	// Student parking
        writeOnScreen(345,150,0.8,0.1,0.1,"Students Parking");
	//Transport/Hospital/Bethania
        writeOnScreen(100,50,0.8,0.1,0.1,"Bethania                  Hospital          Transport");
	//Amphi Theater
        writeOnScreen(45,150,0.8,0.1,0.1,"Amphi Theater");
	//Placements
        writeOnScreen(245,190,0.8,0.1,0.1,"Placement");
        writeOnScreen(255,180,0.8,0.1,0.1,"Cell");
	//Canteen and Shops
        writeOnScreen(430,65,0.8,0.1,0.1,"Canteen/");
        writeOnScreen(430,55,0.8,0.1,0.1,"Xerox/");
        writeOnScreen(430,45,0.8,0.1,0.1,"Shops");
	//Staff parking
        writeOnScreen(320,62,0.8,0.1,0.1,"Staff Parking");
        //Entrance Marking
        writeOnScreen(248,3,0.0,1.0,0.0,"Entrance");



//Just for trial movements in map**************
	moveBox();
//**********************************************
	glutSwapBuffers();//for mmovement
	glFlush();

}

//for movement repeated call to display the animation
void timer(){
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);

	//administration
	if(moveFlag==1){
		if(yval < 90.0){
			yval+=0.5;
		}
	}

	//AB3
        if(moveFlag==2){
                if(yval < 90.0){
                        yval+=0.5;
                }
		if(xval >164 && yval >=90.0){
			xval-=0.5;
		}
		if(yval<278.0 && xval <=164){
			yval+=0.5;
		}
        }

	//Albertos
	if(moveFlag == 3){
		//glLoadIdentity();
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<190.0 && xval <=164){
                        yval+=0.5;
                }
		if(xval>65 && yval>=190){
			xval-=0.5;
		}

	}

	//AB1
        if(moveFlag==4){
		int breakFlag = 0;
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<190.0 && xval <=164){
                        yval+=0.5;
                }
		if(xval<230 && yval>=190.0){
			xval+=1;
		}
       }

        //ideaLab
        if(moveFlag==5){
                if(yval < 90.0){
                        yval+=0.5;
                }
		if(xval<285 && yval>=90){
			xval+=0.5;
		}
        }

        //student square
        if(moveFlag==6){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<205.0 && xval <=164){
                        yval+=0.5;
                }
        }

        //chappel
        if(moveFlag==7){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >154 && yval >=90.0){
                        xval-=0.5;
                }
        }

        //CCC & Library
        if(moveFlag==8){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<210.0 && xval <=164){
                        yval+=0.5;
                }
        }

        //Volleyball
        if(moveFlag==9){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<325.0 && xval <=164){
                        yval+=0.5;
                }
        }

        //Albertos
        if(moveFlag == 10){
                //glLoadIdentity();
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<190.0 && xval <=164){
                        yval+=0.5;
                }
                if(xval>84 && yval>=190){
                        xval-=0.5;
                }
		if(xval<=84){
			civilFlag=1;
		}
		if(yval<245 && civilFlag==1){
			yval+=0.5;
		}

        }


        //BasketBall ground
        if(moveFlag==11){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<220.0 && xval <=164){
                        yval+=0.5;
                }
        }

        //E-Baha
        if(moveFlag==12){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<320.0 && xval <=164){
                        yval+=0.5;
                }

                if(xval<310 && yval>=320.0){
                        xval+=1;
                }

        }

        //chappel
        if(moveFlag==13){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >134 && yval >=90.0){
                        xval-=0.5;
                }
		if(xval>104 && xval <= 134 && yval >= 70){
			xval-=0.5;
			yval-=0.5;
		}
        }

        //Play ground
        if(moveFlag==14){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<420.0 && xval <=164){
                        yval+=0.5;
                }

                if(xval>82 && yval>=420.0){
                        xval-=1;
                }

        }


        //Placement office
        if(moveFlag==15){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<190.0 && xval <=164){
                        yval+=0.5;
                }
                if(xval<230 && yval>=190.0){
                        xval+=1;
                }
       }

        //Boys hostel
        if(moveFlag == 16){
                //glLoadIdentity();
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<190.0 && xval <=164){
                        yval+=0.5;
                }
                if(xval>25 && yval>=190){
                        xval-=0.5;
                }
		if(xval<=25){
			indFlag=1; //This flag is needed to controll the movement in bant road
		}
		if(yval<270 && indFlag==1){
			yval+=0.5;
			xval+=0.53;
		}

        }


	//Girls hostel
        if(moveFlag==17){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >164 && yval >=90.0){
                        xval-=0.5;
                }
                if(yval<420.0 && xval <=164){
                        yval+=0.5;
                }

        }

        //Canteen
        if(moveFlag==18){
                if(yval < 90.0 && breakFlag==0){
                        yval+=0.5;
                }
		if(xval<406 && yval>=90){
			xval+=1;
		}
		if(xval>=406){
			breakFlag=1;
		}
		if(yval>30 && breakFlag==1){
			yval-=0.5;
			xval+=0.07;
		}

       }

        //Transport/hospital/bethania
        if(moveFlag==19){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval >210 && yval >=90.0){
                        xval-=0.5;
                }
	//	if(xval<=210 && xval>150){
	//		xval-=0.3;
	//	}
        }

        //Canteen
        if(moveFlag==20){
                if(yval < 90.0 && breakFlag1==0){
                        yval+=0.5;
                }
                if(xval<406 && yval>=90){
                        xval+=1;
                }
                if(xval>=406){
                        breakFlag1=1;
                }
                if(yval<130 && breakFlag1==1){
                        yval+=0.5;
                        xval-=0.07;
                }

       }

        //Staff Parking
        if(moveFlag==21){
                if(yval < 90.0){
                        yval+=0.5;
                }
                if(xval<285 && yval>=90){
                        xval+=0.5;
                }
        }

}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1600,1000);
	glutInitWindowPosition(40,40);
	glutCreateWindow("Hello World!");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);//for movement-optional used for reshape adjustment of application
	glutTimerFunc(0,timer,0);//used to redisplay and call the display at intervals
	glutCreateMenu(fillMenu);
        glutAddMenuEntry("Administration", 1);
	glutAddMenuEntry("AB3",2);
	glutAddMenuEntry("Albertos", 3);
        glutAddMenuEntry("AB1", 4);
        glutAddMenuEntry("Idea Lab", 5);
        glutAddMenuEntry("Student Square", 6);
        glutAddMenuEntry("Chappel", 7);
        glutAddMenuEntry("CCC & Library", 8);
        glutAddMenuEntry("Volleyball Ground", 9);
        glutAddMenuEntry("Civil Block", 10);
        glutAddMenuEntry("Basketball Ground", 11);
        glutAddMenuEntry("E-Baha", 12);
        glutAddMenuEntry("Amphi Theater", 13);
        glutAddMenuEntry("Play Ground", 14);
        glutAddMenuEntry("Placements Office", 15);
        glutAddMenuEntry("Boys Hostel", 16);
        glutAddMenuEntry("Girls-Hostel", 17);
        glutAddMenuEntry("Canteen and Shops", 18);
        glutAddMenuEntry("Transport/Hospital/Bethania", 19);
	glutAddMenuEntry("Student Parking", 20);
	glutAddMenuEntry("Staff Parking", 21);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
