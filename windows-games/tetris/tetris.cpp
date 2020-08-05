#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
//#include <dsound.h>
#include <mmsystem.h>
#include "graphics.h"
#include <stdio.h> // <== must be included if you want to print a number in graphics window.
#include <math.h>

using namespace std;

//ofstream prn ("output.txt");
//ifstream in_file ("input.txt");
const int MAX_ROW=26;
const int MAX_COL=13;
int visual[MAX_ROW][MAX_COL];
int back[MAX_ROW][MAX_COL];
int x;
int y;
int score=0;
int speed=1000;
int tlines=0;

class figure {
private:
    int shape[5][5];
    int temp[5][5];
public:

    figure(int a,int b,int c,int d,int e,int f,int g,int h,int i,
           int j,int k, int l, int m, int n, int o, int p) {
        shape[1][1]=a;
        shape[1][2]=b;
        shape[1][3]=c;
        shape[1][4]=d;
        shape[2][1]=e;
        shape[2][2]=f;
        shape[2][3]=g;
        shape[2][4]=h;
        shape[3][1]=i;
        shape[3][2]=j;
        shape[3][3]=k;
        shape[3][4]=l;
        shape[4][1]=m;
        shape[4][2]=n;
        shape[4][3]=o;
        shape[4][4]=p;
    }

    void move() {
        for (int a=1; a<=4; ++a)
            for (int b=1; b<=4; ++b)
                temp[a][b]=shape[a][b];

        shape[1][1]=temp[1][4];
        shape[1][2]=temp[2][4];
        shape[1][3]=temp[3][4];
        shape[1][4]=temp[4][4];
        shape[2][1]=temp[1][3];
        shape[2][2]=temp[2][3];
        shape[2][3]=temp[3][3];
        shape[2][4]=temp[4][3];
        shape[3][1]=temp[1][2];
        shape[3][2]=temp[2][2];
        shape[3][3]=temp[3][2];
        shape[3][4]=temp[4][2];
        shape[4][1]=temp[1][1];
        shape[4][2]=temp[2][1];
        shape[4][3]=temp[3][1];
        shape[4][4]=temp[4][1];
    }

    void change(int xc, int yc) {
        back[yc][xc]    =shape[1][1];
        back[yc][xc+1]  =shape[1][2];
        back[yc][xc+2]  =shape[1][3];
        back[yc][xc+3]  =shape[1][4];
        back[yc+1][xc]  =shape[2][1];
        back[yc+1][xc+1]=shape[2][2];
        back[yc+1][xc+2]=shape[2][3];
        back[yc+1][xc+3]=shape[2][4];
        back[yc+2][xc]  =shape[3][1];
        back[yc+2][xc+1]=shape[3][2];
        back[yc+2][xc+2]=shape[3][3];
        back[yc+2][xc+3]=shape[3][4];
        back[yc+3][xc]  =shape[4][1];
        back[yc+3][xc+1]=shape[4][2];
        back[yc+3][xc+2]=shape[4][3];
        back[yc+3][xc+3]=shape[4][4];
    }

    void changetemp(int xc, int yc) {
        back[yc][xc]    =temp[1][1];
        back[yc][xc+1]  =temp[1][2];
        back[yc][xc+2]  =temp[1][3];
        back[yc][xc+3]  =temp[1][4];
        back[yc+1][xc]  =temp[2][1];
        back[yc+1][xc+1]=temp[2][2];
        back[yc+1][xc+2]=temp[2][3];
        back[yc+1][xc+3]=temp[2][4];
        back[yc+2][xc]  =temp[3][1];
        back[yc+2][xc+1]=temp[3][2];
        back[yc+2][xc+2]=temp[3][3];
        back[yc+2][xc+3]=temp[3][4];
        back[yc+3][xc]  =temp[4][1];
        back[yc+3][xc+1]=temp[4][2];
        back[yc+3][xc+2]=temp[4][3];
        back[yc+3][xc+3]=temp[4][4];
    }

    void print() {
        for (int a=1; a<=4; ++a)
            for (int b=1; b<=4; ++b) {
                if (shape[a][b]!=0) {
                    setcolor(15);
                    setfillstyle(1,shape[a][b]);
                    bar(70+20*b,50+20*a,90+20*b,70+20*a);
                    rectangle(71+20*b,51+20*a,89+20*b,69+20*a);
                }
            }
        outtextxy(66,55,"THE NEXT SHAPE");
    }

};

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:randomize
//this creates a random number
int randomize(int high, int low);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:outintxy
//prints out a variable
void outintxy(int x, int y, int value);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:print
//prints out the map screen
void print(figure shape1);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:clearback
//clears the back
void clearback();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:check
//
int check(int g, int h, figure shape);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:combine
//
void combine();

void clearline();

void movedown(int j);

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main () {
    string name;
    int end=0;
    int end2=0;
    int elcount=0;
    char c;
    time_t t;
    srand((unsigned) time(&t));

//cout << "Type in your name:" << endl;
//cin >> name;

    initwindow(500,500);

    settextstyle(0,0,10);
    outtextxy(20,160,"TETRIS");
    settextstyle(0,0,1);
    outtextxy(30,240,"Hit any key to start");
    getch();


//initialize the graphics

    for (int a=0; a<=24; ++a)
        for (int b=0; b<=11; ++b) {
            back[a][b]=0;
            visual[a][b]=0;
        }

    for (int a=0; a<=24; ++a) {
        visual[a][0]=1;

        visual[a][11]=1;

        if (a<=11)
            visual[24][a]=1;
    }

    figure shape   (0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    figure shape1  (0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    figure triangle(0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0);
    figure ese     (0,0,0,0,2,2,0,0,0,2,2,0,0,0,0,0);
    figure ese2    (0,0,0,0,0,0,3,3,0,3,3,0,0,0,0,0);
    figure line    (0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0);
    figure square  (0,0,0,0,0,5,5,0,0,5,5,0,0,0,0,0);
    figure ele     (0,0,0,0,0,6,0,0,0,6,6,6,0,0,0,0);
    figure ele2    (0,0,0,0,0,0,7,0,7,7,7,0,0,0,0,0);


    int figuretype=randomize(7,1);

//   figuretype=4;
    switch(figuretype) {
    case 1:
        shape=triangle;
        break;
    case 2:
        shape=ese;
        break;
    case 3:
        shape=ese2;
        break;
    case 4:
        shape=line;
        break;
    case 5:
        shape=square;
        break;
    case 6:
        shape=ele;
        break;
    case 7:
        shape=ele2;
        break;
    }

    do {

        if (elcount!=0)
            shape=shape1;

        if (elcount==0)
            elcount++;

        int figuretype=randomize(7,1);

//   figuretype=4;
        switch(figuretype) {
        case 1:
            shape1=triangle;
            break;
        case 2:
            shape1=ese;
            break;
        case 3:
            shape1=ese2;
            break;
        case 4:
            shape1=line;
            break;
        case 5:
            shape1=square;
            break;
        case 6:
            shape1=ele;
            break;
        case 7:
            shape1=ele2;
            break;
        }


        if((visual[4][4]!=0)||(visual[4][5]!=0)||(visual[4][6]!=0)||(visual[4][7]!=0)) {
            end=1;
            end2=1;
        } else if((visual[5][4]!=0)||(visual[5][5]!=0)||(visual[5][6]!=0)||(visual[5][7]!=0)) {
            x=4;
            y=0;
            end=0;
        } else if((visual[6][4]!=0)||(visual[6][5]!=0)||(visual[6][6]!=0)||(visual[6][7]!=0)) {
            x=4;
            y=1;
            end=0;
        } else if((visual[7][4]!=0)||(visual[7][5]!=0)||(visual[7][6]!=0)||(visual[7][7]!=0)) {
            x=4;
            y=2;
            end=0;
        } else {
            x=4;
            y=3;
            end=0;
        }


//for (int a=10; a<=20; a++)
//{
// shape.change(0,a); print(); delay(2000);
// cout << endl<< a << endl;
// }

        do {

            for (int i=0; !kbhit( ); i++) {
                switch(check(x,y+1,shape)) {
                case 0:
                    end=1;
                    shape.change(x,y);
                    combine();
                    getch();

                    break;
                case 1:
                    y=y+1;
                    clearback();
                    shape.change(x,y);
                    print(shape1);
                    delay(speed);
                    break;
                }

            }

//use keyboard
            if(end!=1) {
                c = (char) getch( );
                switch (c) {
                case KEY_UP: {
                    shape.move();
                    clearback();
                    shape.change(x,y);

                    switch(check(x,y,shape)) {
                    case 0:
                        clearback();
                        shape.move();
                        shape.move();
                        shape.move();
                        shape.change(x,y);
                        break;
                    case 1:
                        print(shape1);
                        delay(50);
                        break;
                    }
                }
                break;

                case KEY_LEFT: {
                    switch(check(x-1,y,shape)) {
                    case 0:
                        break;
                        break;
                    case 1:
                        x=x-1;
                        clearback();
                        shape.change(x,y);
                        print(shape1);
                        delay(50);
                        break;
                    }
                }
                break;

                case KEY_RIGHT: {
                    switch(check(x+1,y,shape)) {
                    case 0:
                        break;
                        break;
                    case 1:
                        x=x+1;
                        clearback();
                        shape.change(x,y);
                        print(shape1);
                        delay(50);
                        break;
                    }
                }
                break;

                case KEY_DOWN:

                    do {
                        switch(check(x,y+1,shape)) {
                        case 0:
                            end=1;
                            clearback();
                            shape.change(x,y);
                            combine();
                            break;
                        case 1:
                            y=y+1;
                            clearback();
                            shape.change(x,y);
                            print(shape1);
                            delay(50);
                            break;
                        }
                    } while(end!=1);
                    break;
                }
            }
        }   while (end!=1);
//end keyboard

        clearline();

    } while (end2!=1);


    settextstyle(1,0,5);
    cleardevice();
    outtextxy(50,200,"GAME OVER");

    delay(5000);
    return 0;
    closegraph();

}



//******************************************************************************
//                           randomize implementation
int randomize(int rhigh, int rlow) {
    return rand()%(rhigh - rlow + 1) + rlow;
}

//******************************************************************************
//                           print out a variable
void outintxy(int x, int y, int value) {
    char digit_string[20];
    sprintf(digit_string, "%d", value);
    outtextxy(x, y, digit_string);
}

//******************************************************************************
//
void print(figure shape1) {
    setactivepage(2);
    setvisualpage(1);

    setfillstyle(0,0);
    setfillstyle(11,7);
    bar(0,0,500,500);
    setfillstyle(1,0);
    setcolor(7);
    bar(250,50,450,450);
    rectangle(250,50,450,450);

    bar(50,50,200,450);
    rectangle(50,50,200,450);

    for (int a=4; a<=23; ++a)
        for (int b=1; b<=10; ++b) {
            if (visual[a][b]!=0) {
                setcolor(15);
                setfillstyle(1,visual[a][b]);
                bar(230+20*b,-30+20*a,250+20*b,-10+20*a);
                rectangle(231+20*b,-29+20*a,249+20*b,-11+20*a);
            }
            if (back[a][b]!=0) {
                setcolor(15);
                setfillstyle(1,back[a][b]);
                bar(230+20*b,-30+20*a,250+20*b,-10+20*a);
                rectangle(231+20*b,-29+20*a,249+20*b,-11+20*a);
            }
        }

    shape1.print();

    setcolor(7);
    rectangle(250,50,450,450);

    setcolor(15);
    outtextxy(65,150,"SCORE");
    outtextxy(150,150,"LINES");

    outintxy(65,160,score);
    outintxy(150,160,tlines);

    setvisualpage(2);

    //print to dos
    // for (int a=1;a<=24;++a)
    //  {
    //  for (int b=0;b<=11;++b)
    //   cout << back[a][b];
    //   cout << "     ";

    //   for (int b=0;b<=11;++b)
    //  cout << visual[a][b];
    //   cout << endl;
    //   }
}


//******************************************************************************
//
void clearback() {
    for (int a=1; a<=24; ++a)
        for (int b=1; b<=10; ++b)
            back[a][b]=0;
}

//******************************************************************************
//
int check(int g, int h, figure shape) {
    int temp=1;

    shape.change(g,h);

//cout << "&&&&&&&&&&&&&&" << endl;
//cout << endl << g << " & " << h << endl << endl;

    for (int a=0; a<=3; ++a)
        for (int b=0; b<=3; ++b)
            if ((back[h+a][g+b]!=0)&&(visual[h+a][g+b]!=0))
                temp=0;
    //  else
    //     cout << temp << endl << endl;
    return temp;
}

//******************************************************************************
//
void combine() {
    for (int a=1; a<=23; ++a)
        for (int b=1; b<=10; ++b)
            if (back[a][b]!=0)
                visual[a][b]=back[a][b];
}

//******************************************************************************
//
void clearline() {
    int line=0;
    int lines=0;
    int tempscore=0;

    for (int a=1; a<=23; ++a) {
        line =0;
        for (int b=1; b<=10; ++b) {
            if (visual[a][b]!=0)
                line++;
            if (line==10) {
                lines++;
                movedown(a);
                tlines++;

                if(tlines==10)
                    speed=speed-200;

                if(tlines==20)
                    speed=speed-200;

                if(tlines==30)
                    speed=speed-200;

                if(tlines==40)
                    speed=speed-200;

                if(tlines==50)
                    speed=speed-200;
            }
        }
    }

    tempscore= pow(lines,2)*100;
    score=score+tempscore;

// cout << "!%@#$^%$&^%*&(*&" << endl;
// cout << "!%@#$^%$&^%*&(*&" << endl;
// cout << "!%@#$^%$&^%*&(*&" << endl;
// cout << "line " << line << " lines " << lines << endl;

}

//******************************************************************************
//
void movedown(int j) {
    for (int a=j; a>=1; a=a-1)
        for (int b=1; b<=10; ++b)
            visual[a][b]=visual[a-1][b];
    for (int b=1; b<=10; ++b)
        visual[1][b]=0;
}
