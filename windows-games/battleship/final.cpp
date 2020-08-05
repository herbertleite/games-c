# include <windows.h>
# include <iostream>
# include <conio.h>
# include <string>
# include <fstream>
# include <iomanip>
# include <stdlib.h>
# include <time.h>
//# include <dsound.h>
# include <mmsystem.h>
# include "graphics.h"


std::ofstream prn ("prn");
std::ifstream in_file ("input.txt");
const int MAX_ROW=10;
const int MAX_COL=10;
const int MAX=6;
int visual_p[MAX_ROW][MAX_COL];
int visual_c[MAX_ROW][MAX_COL];
int list_c[MAX];
int list_p[MAX];
int final=0;
int temp;
int ai[MAX];
int ai_x1=0;
int ai_y1=0;
int ai_x2=0;
int ai_y2=0;
int what=0;
int ha=0;


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:print
//this prints out screen
void print();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:player
//this lets the player chose cordinates.
void player();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:computer
//this lets computer chose cordinates.
void computer();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:destroy_c
//this keeps track of the computers sunken ships.
void destroy_c(int x, int y);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:destroy_p
//this keeps track of the players sunken ships.
void destroy_p(int x, int y);

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:randomize
//this creates a random number
int randomize(int high, int low);

void a();

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main () {

    initwindow(500,500);
    int count=0;
    int mx1,my1;
    char vorh;
    int num;
    time_t t;

    srand((unsigned) time(&t));

    ai[1]=0;
    ai[2]=0;
    ai[3]=0;

//******start title screen
//SND_NODEFAULT Or SND_ASYNC Or SND_LOOP
    sndPlaySound("intro.wav", SND_NODEFAULT);
    sndPlaySound("theme.wav", SND_ASYNC);
//sndPlaySound(nil, 0); // Stops the sound

//PlaySound("intro.wav", NULL, NULL);
//hInstance, SND_RESOURCE or SND_ASYNC

    setcolor(15);
    setbkcolor(0);

    for(int i=1; i <=40; ++i) {
        settextstyle(6,0,8);
        moveto(40,150);
        outtext("BATTLE");
        moveto(220,230);
        settextstyle(6,0,4);
        outtext("SPACESHIP");
        circle(200,200+(2*i),50);
        circle(200+(2*i),200,50);
        circle(200,200-(2*i),50);
        circle(200-(2*i),200,50);
        delay(100);
        if (i==40) {
            for (int i=1; i<=50; ++i) {
                settextstyle(6,0,8);
                moveto(40,150);
                outtext("BATTLE");
                moveto(220,230);
                settextstyle(6,0,4);
                outtext("SPACESHIP");
                circle(200,280,50);
                circle(280,200,50);
                circle(200,120,50);
                circle(120,200,50);
                moveto(0+(4*i),350);
                settextstyle(6,0,2);
                outtext("By Werner and Matt");
                delay(1);
                if (i==50) {
                    for(int i=5; i<=15; ++i) {
                        setcolor(i);
                        settextstyle(6,0,8);
                        moveto(40,150);
                        outtext("BATTLE");
                        moveto(220,230);
                        settextstyle(6,0,4);
                        outtext("SPACESHIP");
                        circle(200,280,50);
                        circle(280,200,50);
                        circle(200,120,50);
                        circle(120,200,50);
                        moveto(200,350);
                        settextstyle(6,0,2);
                        outtext("By Werner and Matt");
                        delay(100);
                        if (i ==15) {
                            delay(2000);
                            cleardevice();
                        } else
                            cleardevice();
                        delay(100);
                    }
                } else
                    cleardevice();
            }
        } else
            cleardevice();
    }
    settextstyle(0,0,1);
//end title screen


//initialize the visual's

    for(int a=0; a<10; a=a+1) {
        for (int b=0; b<10; b=b+1) {
            visual_p[a][b]=0;
            visual_c[a][b]=0;
        }
    }

//input information

    do {
        do {
            print();
            temp=0;
            outtextxy(35,320,"Would you like your spaceship to be vertical or horizontal ??");
            rectangle(100,340,200,400);
            rectangle(300,340,400,400);
            outtextxy(117,355,"click here");
            outtextxy(140,365,"for");
            outtextxy(120,375,"vertical");
            outtextxy(317,355,"click here");
            outtextxy(340,365,"for");
            outtextxy(320,375,"horizontal");


            while (!ismouseclick(WM_LBUTTONDOWN)) {
                delay(500);
            }

            getmouseclick(WM_LBUTTONDOWN, mx1, my1);

            if((mx1>=100)&&(mx1<=200)&&(my1>=340)&&(my1<=400)) {
                vorh='v';
            } else if ((mx1>=300)&&(mx1<=400)&&(my1>=340)&&(my1<=400)) {
                vorh='h';
            } else {
                print();
                outtextxy(35,320,"Click inside the box!!");
                sndPlaySound("spin.wav", SND_ASYNC);
                delay(3000);
                temp=-1;
            }
        } while (temp !=0);
        PlaySound("tump.wav", NULL, NULL);


        if (vorh == 'h') {
            print();
            outtextxy(35,320,"Click on your grid to place your battleship");
            while (!ismouseclick(WM_LBUTTONDOWN)) {
                delay(500);
            }

            getmouseclick(WM_LBUTTONDOWN, mx1, my1);
            mx1= (mx1-25)/20;
            my1= (my1-50)/20;
            sndPlaySound("tump.wav", SND_ASYNC);


            if ((mx1 <=7)&&(my1 <=9)) {
                if ((visual_p[my1][mx1]==0)&&(visual_p[my1][mx1+1]==0)&&(visual_p[my1][mx1+2]==0)) {
                    count=count+1;
                    visual_p[my1][mx1]=count;
                    visual_p[my1][mx1+1]=count;
                    visual_p[my1][mx1+2]=count;
                    cleardevice();
                    print();
                    outtextxy(35,320,"Afirmative");
                    temp=randomize(3,1);
                    switch(temp) {
                    case 1:
                        sndPlaySound("land_1.wav", SND_ASYNC);
                        break;
                    case 2:
                        sndPlaySound("land_2.wav", SND_ASYNC);
                        break;
                    case 3:
                        sndPlaySound("land_3.wav", SND_ASYNC);
                        break;
                    }
                    delay(2000);
                } else {
                    print();
                    outtextxy(35,320, "That spot is already taken by another spaceship");
                    sndPlaySound("spin.wav", SND_ASYNC);
                    delay(2000);
                }

            } else {
                print();
                outtextxy(35,320, "That is outside the bounderies of the grid");
                sndPlaySound("spin.wav", SND_ASYNC);
                delay(2000);
            }
        }

        if (vorh == 'v') {
            print();
            outtextxy(35,320,"Click on your grid to place your battleship");
            while (!ismouseclick(WM_LBUTTONDOWN)) {
                delay(500);
            }

            getmouseclick(WM_LBUTTONDOWN, mx1, my1);
            mx1=(mx1-25)/20;
            my1=(my1-50)/20;
            sndPlaySound("tump.wav", SND_ASYNC);

            if ((mx1 <=9)&&(my1 <=7)) {
                if ((visual_p[my1][mx1]==0)&&(visual_p[my1+1][mx1]==0)&&(visual_p[my1+2][mx1]==0)) {
                    count=count+1;
                    visual_p[my1][mx1]=count;
                    visual_p[my1+1][mx1]=count;
                    visual_p[my1+2][mx1]=count;
                    cleardevice();
                    print();
                    outtextxy(35,320,"Afirmative");
                    temp=randomize(3,1);
                    switch(temp) {
                    case 1:
                        sndPlaySound("land_1.wav", SND_ASYNC);
                        break;
                    case 2:
                        sndPlaySound("land_2.wav", SND_ASYNC);
                        break;
                    case 3:
                        sndPlaySound("land_3.wav", SND_ASYNC);
                        break;
                    }
                    delay(2000);
                } else {
                    print();
                    outtextxy(35,320, "That spot is already taken by another spaceship");
                    sndPlaySound("spin.wav", SND_ASYNC);
                    delay(2000);
                }
            } else {
                print();
                outtextxy(35,320, "That is outside the bounderies of the grid");
                sndPlaySound("spin.wav", SND_ASYNC);
                delay(2000);
            }
        }
    } while (count <5);
//end input

//for(int a=0; a<10; a=a+1)
//  {
//  for (int b=0; b<10; b=b+1)
//   {
//   cout << visual_p[a][b];
//    } cout << endl;
//  }

//create computer spacecrafts
    count =0;
    do {
        num= randomize(2,1);
        switch(num) {
        case 1:
            vorh='v';
            break;
        case 2:
            vorh='h';
            break;
        }

        if (vorh == 'h') {
            mx1=(rand() % 8);
            my1=(rand() % 10);


            if ((visual_c[my1][mx1]==0)&&(visual_c[my1][mx1+1]==0)&&(visual_c[my1][mx1+2]==0)) {
                count=count+1;
                visual_c[my1][mx1]=count;
                visual_c[my1][mx1+1]=count;
                visual_c[my1][mx1+2]=count;
            }
        }

        if (vorh == 'v') {

            mx1=(rand() % 10);
            my1=(rand() % 8);

            if ((visual_c[my1][mx1]==0)&&(visual_c[my1+1][mx1]==0)&&(visual_c[my1+2][mx1]==0)) {
                count=count+1;
                visual_c[my1][mx1]=count;
                visual_c[my1+1][mx1]=count;
                visual_c[my1+2][mx1]=count;
            }
        }
    } while (count <5);

// cout << endl;
// for(int a=0; a<10; a=a+1)
//  {
//  for (int b=0; b<10; b=b+1)
//   {
//   cout << visual_c[a][b];
//    } cout << endl;
//  }


    delay(2000);
//countdown
    for(int i=5; i>=1; i=i-1) {
        cleardevice();
        outtextxy(130,240,"Get ready to engage in battle in");

        switch(i) {
        case 1:
            outtextxy(240,250,"1");
            break;
        case 2:
            outtextxy(240,250,"2");
            break;
        case 3:
            outtextxy(240,250,"3");
            break;
        case 4:
            outtextxy(240,250,"4");
            break;
        case 5:
            outtextxy(240,250,"5");
            break;
        }
        sndPlaySound("heart.wav", SND_ASYNC);
        delay(1500);
    }

    //initialize destroy
    for(int a=0; a<=5; ++a) {
        list_p[a]=0;
        list_c[a]=0;
    }
    for(int a=0; a<=5; ++a) {
//   cout <<list_c[a] << " " <<a<< "list_computer" << endl;
//   cout <<list_p[a] << " " <<a<< "list_player" << endl;
    } //cout<< endl;
    do {
        player();
        if (final ==1) {
            closegraph();
            return 0;
        }
        computer();
    } while (final !=1);

    closegraph();

    return 0;
}

//******************************************************************************
//                         print implementation
void print() {

    cleardevice();

    setlinestyle(0,-1,1);
    setfillstyle(10,1);
    setcolor(2);
    bar(25,50,225,250);
    bar(275,50,475,250);
    rectangle(25,50,225,250);
    rectangle(275,50,475,250);
    for(int i=20; i<200; i=i+20) {
        line(25,50+i,225,50+i);
        line(275,50+i,475,50+i);
        line(25+i,50,25+i,250);
        line(275+i,50,275+i,250);
    }
    moveto(20,30);
    outtext(" 0  1  2  3  4  5  6  7  8  9");
    moveto(270,30);
    outtext(" 0  1  2  3  4  5  6  7  8  9");

    for (int i=15; i<=265; i= i+250) {
        outtextxy(i,55,"0");
        outtextxy(i,75,"1");
        outtextxy(i,95,"2");
        outtextxy(i,115,"3");
        outtextxy(i,135,"4");
        outtextxy(i,155,"5");
        outtextxy(i,175,"6");
        outtextxy(i,195,"7");
        outtextxy(i,215,"8");
        outtextxy(i,235,"9");
    }
    outtextxy(100,260,"Player");
    outtextxy(350,260,"Computer");

    bar(25,300,475,450);
    rectangle(25,300,475,450);

    for(int a=0; a<10; ++a) {
        for(int b=0; b<10; ++b) {
            if (visual_p[a][b]!=0)
                if (visual_p[a][b]==-1) {
                    setlinestyle(0,-1,3);
                    setcolor(4);
                    circle(35+(20*b),60+(20*a),2);
                    setcolor(2);
                } else if(visual_p[a][b]==-2) {
                    setlinestyle(0,-1,1);
                    setcolor(2);
                    circle(35+(20*b),60+(20*a),5);
                    setlinestyle(0,-1,3);
                    setcolor(4);
                    line(25+(20*b),50+(20*a),45+(20*b),70+(20*a));
                    line(25+(20*b),70+(20*a),45+(20*b),50+(20*a));
                    setcolor(2);
                } else {
                    setlinestyle(0,-1,1);
                    setcolor(2);
                    circle(35+(20*b),60+(20*a),5);
                }
        }


        for(int b=0; b<10; b=b+1) {
            if (visual_c[a][b]==-1) {
                setlinestyle(0,-1,3);
                setcolor(4);
                circle(285+(20*b),60+(20*a),2);
                setcolor(2);
            } else if (visual_c[a][b]==-2) {
                setlinestyle(0,-1,1);
                setcolor(2);
                circle(285+(20*b),60+(20*a),5);
                setlinestyle(0,-1,3);
                setcolor(4);
                line(275+(20*b),50+(20*a),295+(20*b),70+(20*a));
                line(275+(20*b),70+(20*a),295+(20*b),50+(20*a));
                setcolor(2);
            }

        }
    }
}

//******************************************************************************
//                        player implementation
void player() {
    int mx,my;
    int temp2;
    do {
        ha=0;
        print();
        outtextxy(35,320, "Click in the computers grid to shoot" );
        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(500);
        }

        getmouseclick(WM_LBUTTONDOWN, mx, my);
        mx= (mx-275)/20;
        my= (my-50)/20;
        sndPlaySound("tump.wav", SND_ASYNC);

        if((mx>=10)||(mx<0)||(my>=10)||(my<0)) {
            print();
            outtextxy(35,320, "That is outside the computers grid!");
            sndPlaySound("spin.wav", SND_ASYNC);
            delay(2000);
            ha=1;
        } else if ((visual_c[my][mx]== -1)||(visual_c[my][mx]==-2)) {
            print();
            outtextxy(35,320, "You already choose that target before");
            sndPlaySound("spin.wav", SND_ASYNC);
            delay(2000);
            ha=1;
        }
    } while(ha==1);
    if (visual_c[my][mx]==0) {
        print();
        outtextxy(35,320, "YOU MISS!!");
        sndPlaySound("shoot.wav", SND_NODEFAULT);
        temp2=randomize(2,1);
        switch(temp2) {
        case 1:
            sndPlaySound("room.wav", SND_ASYNC);
            break;
        case 2:
            sndPlaySound("woop.wav", SND_ASYNC);
            break;
        }
        delay(2000);
        visual_c[my][mx]=-1;
    } else {
        for(int a=1; a<=4; ++a) {
            cleardevice();
            delay(100);
            print();
            delay(100);
        }
        outtextxy(35,320, "YOU HIT!!!");
        sndPlaySound("fire_1.wav", SND_NODEFAULT);
        sndPlaySound("fire_2.wav", SND_ASYNC);
        delay(3000);
        destroy_c(mx,my);
        visual_c[my][mx]=-2;
    }
    a();
}
//******************************************************************************
//                       computer implementation
void computer() {
    int x,y;
    int temp1;
    print();

//artificial inteligence

    do {
        what=0;
        switch(ai[1]) {
        case 0: {
            do {
                x=(rand() % 10);
                y=(rand() % 10);
                ai_x1=x;
                ai_y1=y;
// cout << "***case:0 x and y "<< x << " " << y<< endl;
            } while((visual_p[y][x]==-1)||(visual_p[y][x]==-2));
        }
        break;
        case 1: {
            do {
                do {
                    if (ai[2]>20) {
                        ai[2]=0;
                        ai[1]=0;
                        what=1;
                        break;
                    }
                    x=randomize(ai_x1+1,ai_x1-1);
                    y=randomize(ai_y1+1,ai_y1-1);
                    ai_x2=x;
                    ai_y2=y;
                    // cout << "***case:1 x and y "<< x << " " << y<< endl;
                } while((x<0)||(x>=10)||(y<0)||(y>=10)||((ai_x1!=ai_x2)&&(ai_y1!=ai_y2)));
                ++ai[2];
            } while((visual_p[y][x]==-1)||(visual_p[y][x]==-2));
        }
        break;

        case 2: {
            do {
                if (ai[3]>10) {
                    ai[3]=0;
                    ai[2]=0;
                    ai[1]=1;
                    what=1;
                    break;
                }
                if (ai_x1==ai_x2) {
                    x=ai_x1;
                } else if (ai_x1 < ai_x2)
                    do {
                        temp1=randomize(2,1);
                        switch(temp1) {
                        case 1:
                            x=ai_x1-1;
                            break;
                        case 2:
                            x=ai_x2+1;
                            break;
                        }
                    } while ((x<0)||(x>=10));
                else
                    do {
                        temp1=randomize(2,1);
                        switch(temp1) {
                        case 1:
                            x=ai_x1+1;
                            break;
                        case 2:
                            x=ai_x2-1;
                            break;
                        }
                    } while((x<0)||(x>=10));

                if (ai_y1==ai_y2) {
                    y=ai_y1;
                } else if (ai_y1 < ai_y2)
                    do {
                        temp1=randomize(2,1);
                        switch(temp1) {
                        case 1:
                            y=ai_y1-1;
                            break;
                        case 2:
                            y=ai_y2+1;
                            break;
                        }
                    } while ((y<0)||(y>=10));
                else
                    do {
                        temp1=randomize(2,1);
                        switch(temp1) {
                        case 1:
                            y=ai_y1+1;
                            break;
                        case 2:
                            y=ai_y2-1;
                            break;
                        }
                    } while((y<0)||(y>=10));
                ++ai[3];

                // cout << "***case:2 x and y "<< x << " " << y<< endl;
            } while((visual_p[y][x]==-1)||(visual_p[y][x]==-2));

        }
        break;
        case 3: {
            ai[1]=1;
            what=1;
        }
        break;
        }
    } while(what==1);
    // cout << "ai=" << ai[1] << " ai_2=" << ai[2] << " ai_3=" << ai[3] << " " << x << " " << y  << endl;


    if (visual_p[y][x]==0) {
        outtextxy(35,320, "The computer missed!!!");
        delay(3000);
        visual_p[y][x]=-1;
    } else {
        ++ai[1];
        for(int a=1; a<=4; ++a) {
            cleardevice();
            delay(100);
            print();
            delay(100);
        }
        print();
        outtextxy(35,320, "The computer hit!!");
        sndPlaySound("fire_1.wav", SND_NODEFAULT);
        sndPlaySound("fire_2.wav", SND_ASYNC);
        delay(3000);
        // cout << "the print before destroy_p: x and y "<< x << " " << y<< endl;
        destroy_p(x,y);
        visual_p[y][x]=-2;
    }
}

//******************************************************************************
//                           destroy_c implementation
void destroy_c(int dmx, int dmy) {
    ++list_c[(visual_c[dmy][dmx])];
// cout << "list_c " << visual_c[dmy][dmx]<< " " << list_c[(visual_c[dmy][dmx])]<<endl;delay(1000);

    if (list_c[(visual_c[dmy][dmx])]== 3) {
        ++list_c[0];
        print();
        outtextxy(35,320, "SHIP SUNK!");
        sndPlaySound("down.wav", SND_NODEFAULT);
    }

    if (list_c[0]==5) {
        cleardevice();
        outtextxy(220,240, "YOU WIN!!");
        sndPlaySound("theme.wav", SND_NODEFAULT);
        delay(2000);
        final=1;
    }

}

//******************************************************************************
//                           destroy_p implementation
void destroy_p(int dx, int dy) {
    //cout << list_p[(visual_p[dy][dx])] << " this is the computer count before the thing" << endl;
    ++list_p[(visual_p[dy][dx])];
    //cout << list_p[(visual_p[dy][dx])] << " this is the computer count after the thing" << endl;
    //cout << "list_p " << visual_p[dy][dx]<< " " << list_p[(visual_p[dy][dx])];delay(1000);

    if (list_p[(visual_p[dy][dx])]== 3) {
        print();
        outtextxy(35,320,"COMPTUER SUNK YOUR SHIP!!" );
        sndPlaySound("down.wav", SND_NODEFAULT);
        //cout << ai[1] << endl;
        ai[1]=0;
        ai[2]=0;
        ai[3]=0;
        ++list_p[0];
    }

    if (list_p[0]==5) {
        cleardevice();
        outtextxy(220,240, "YOU LOOSE!!");
        sndPlaySound("down.wav", SND_NODEFAULT);
        sndPlaySound("woop.wav", SND_ASYNC);
        delay(2000);
        final=1;
    }
}
//******************************************************************************
//                           randomize implementation
int randomize(int rhigh, int rlow) {
    return rand()%(rhigh - rlow + 1) + rlow;
}


void a() {
    for(int a=0; a<=5; ++a) {
        //cout <<list_c[a] << " " <<a<< "list_computer" << endl;
        //cout <<list_p[a] << " " <<a<< "list_player" << endl;
    } //cout<< endl;
}
