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

using namespace std;

//ofstream prn ("output.txt");
//ifstream in_file ("input.txt");
const int MAX_ROW=6;
const int MAX_COL=10;
int visual[MAX_ROW][MAX_COL];
int mapitem[MAX_ROW][MAX_COL];
int bigmap[5][5]= {
    { 1, 2, 3, 4, 5},
    { 6, 7, 8, 9,10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25},
};

int mapitem1[6][10]= {
    { 0, 0, 0, 0, 0,11,12,11,11,11},
    { 0, 0, 0, 0,12,12,11, 0, 0, 0},
    { 0, 0, 0,11,11,11,11, 0,11, 2},
    { 0, 0, 0,12,11, 0, 0, 0,12, 0},
    { 0, 0, 0,11,11, 0, 0, 0, 0, 0},
    { 0, 0, 0, 1, 0, 0, 0,13, 0,13}
};

int mapitem2[6][10]= {
    {13, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0,11,11,12,11, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0,11,14, 0, 9, 0},
    { 0, 0, 0,12, 0,11, 0, 0,12,13},
    { 0, 0, 0,11, 0,11,11, 0, 0, 0},
    { 0, 0, 0,14, 0, 0, 0, 0, 0, 0}
};

int mapitem3[6][10]= {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0,12, 9,11,11,11, 0, 0,11,14},
    { 0,11,11, 0, 0,12, 0,11, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0,12, 0, 0, 0, 0, 0,12,12, 0},
    { 0, 0, 0,14,14,11, 0, 0,11,11}
};

int mapitem4[6][10]= {
    { 0, 0, 0, 0, 0, 0, 0, 0,14,11},
    { 0, 0, 0, 0, 9, 9,14,11,11,12},
    { 0, 0, 0, 0, 0, 0, 0, 0,14,14},
    { 0, 0, 0, 0, 0, 0, 0, 9, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0,16, 0,12},
    { 0, 0, 0, 0, 0,13,11,10,12,13}
};

int mapitem5[6][10]= {
    {17,17, 0, 0, 0, 0, 0, 0, 0, 7},
    {17,17, 0, 0, 0, 0, 0, 0, 0, 0},
    {17,17, 0, 0, 0, 0, 0, 0,20, 0},
    {17,17, 0, 0, 0, 0, 0, 0,19, 0},
    {17,17, 0, 0, 0, 0, 0, 0,19, 0},
    {17,17, 0, 0, 0, 0, 0, 0,19, 0}
};

int mapitem6[6][10]= {
    { 0, 0, 0,14, 0,11,11, 0, 0, 0},
    { 0, 0, 0,11, 0, 0,12, 0, 0, 0},
    { 0, 0, 0,12,14, 0,14, 0, 0, 0},
    { 0, 0,16, 0, 0, 0, 0,12,15,11},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int mapitem7[6][10]= {
    { 0,13,13, 0, 0, 0, 0,13,13,11},
    { 0, 0, 0,12, 0, 0, 0, 0, 0, 0},
    { 0, 0,11, 0, 0, 0, 0, 0, 0, 0},
    { 9,11, 0,12, 0, 0,15,11,12,12},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0,13, 0, 0,13,13, 0, 0,13, 0}
};

int mapitem8[6][10]= {
    {12,13,11,13, 0,13,12,13,11,13},
    {15,11, 0, 0, 0, 0, 0, 0, 0,11},
    {12, 0,11, 0,11, 0,12, 0, 0,13},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0,15},
    { 0, 0,11, 0, 0, 0, 0, 0, 0, 0},
    { 9, 0, 0, 9,11,15, 0,11, 0,15}
};

int mapitem9[6][10]= {
    {13,13,13, 0, 9,13, 9, 3, 9,13},
    {14, 0,11, 0, 0, 0, 0, 0, 0,13},
    {11, 0, 0,14, 0, 0, 9, 0, 0,11},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0,11,14,12, 0, 0,11,11,11,13},
    {13,13, 0, 0, 0, 0,12, 0,13,13}
};

int mapitem10[6][10]= {
    {13,13,13, 0,13,13,13, 0,19, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 9, 0},
    { 0, 0, 0,19, 0,19, 0,19, 9, 0},
    { 0, 0,19, 0,19, 0,19, 0,19, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {13,13,13,13, 0,13, 4,13,13,13}
};

int mapitem11[6][10]= {
    { 0,11,11,12,14, 9,11,11,11, 0},
    {13, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 9, 0, 0, 0, 0, 9, 0, 0}
};

int mapitem12[6][10]= {
    { 0, 9, 0, 0,13,13, 0, 0, 9,13},
    {13, 0, 0,11, 0, 0,12, 0, 0,12},
    {13, 0, 0,14, 0, 0,12, 0, 0, 0},
    { 0, 0, 0,15, 0, 0,12, 0, 0, 0},
    {13, 0,12,11, 0, 0, 0, 9, 0,13},
    { 0,11, 0,13,13,13, 0,13,13,13}
};

int mapitem13[6][10]= {
    { 0,12, 0, 0, 9, 9, 0, 0,12, 0},
    {13, 0, 0, 0, 0, 0, 0, 0, 0,13},
    { 0, 0, 0, 0,15, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0,15, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0,12, 0, 0, 9, 9, 0, 0, 0, 0}
};

int mapitem14[6][10]= {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0,13, 0, 0, 0, 0, 0, 0,13, 0}
};

int mapitem15[6][10]= {
    {13,13,11,12,13,13,18,18, 0,13},
    {13,12,12, 0, 0, 0, 0,11,18,13},
    { 0, 0, 0, 0, 0, 0, 0, 0,12, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0,18, 0},
    {13,15,14, 0, 0,21, 0,14,18,13},
    {13,13, 9, 0,13,13,18,18,13,13}
};

int mapitem16[6][10]= {
    {13,11,12, 0, 0, 0, 9, 0,15,12},
    { 0, 0,12,12, 0, 0, 0, 0, 9, 0},
    {13, 0, 0, 9, 0, 0, 0, 9, 0, 9},
    {13, 0, 0, 0, 0, 0, 0, 0, 9, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int mapitem17[6][10]= {
    {13,13, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {13, 0, 0, 0, 0, 0, 0, 0, 0,13},
    {13,13, 0, 0, 0, 0, 0, 0,13,13}
};

int mapitem18[6][10]= {
    {18, 0, 0, 0,16,16, 0, 0, 0,18},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {18, 0, 0, 0,16,16, 0, 0, 0,18}
};

int mapitem19[6][10]= {
    {13,13,12,13, 0, 0, 9,12,13,13},
    {13,11,14, 0, 0, 0, 0, 0,11,13},
    { 0, 9, 0, 0, 0, 0, 0, 0,11,11},
    { 0, 9, 0, 0, 0,14, 0,18, 0,12},
    {15, 0, 0, 0, 0,15, 0, 0, 0, 0},
    {13,15, 9, 0, 0, 0,12,12, 0,13}
};

int mapitem20[6][10]= {
    {13,13,11,19, 0, 0, 0,15,13,13},
    {13, 9, 0,19, 5, 0, 0,18, 0,13},
    {12, 0, 0,19, 0, 0, 0, 0, 0, 9},
    {14, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {15, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {13,17, 0, 0, 0, 0, 0, 0,17,13}
};

int mapitem21[6][10]= {
    { 0, 0, 0,16,22, 0, 0, 0, 0, 0},
    { 0, 0, 0,16, 0,16, 0, 0, 0, 0},
    { 0, 0, 0,16,23,16, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 6,17, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0,17,17, 0, 0, 0}
};

int mapitem22[6][10]= {
    {12, 0,12, 0, 0, 0, 0, 0,13,13},
    {15, 0, 0, 0, 0, 0, 0, 0,12,13},
    {13, 0, 0, 0, 9, 0, 0, 0, 0, 0},
    {12, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {14, 0, 0,11, 0, 0,12,14,15, 9},
    {12, 0,15, 0, 0,14,11,15,12, 0}
};

int mapitem23[6][10]= {
    {13,13,15,14,12, 0, 0,15,12,13},
    {13,12,11, 0,12, 9, 9, 9,12,13},
    { 0, 0, 0,15,14, 0, 0, 0, 0,13},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0,13},
    { 0, 0, 0, 0,15,14, 0, 0, 0,13},
    { 0, 0, 0,12,11, 0, 9, 0, 0,13}
};

int mapitem24[6][10]= {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int mapitem25[6][10]= {
    { 0, 0, 0, 0, 0, 0, 0,12,12,12},
    { 0, 0, 0, 0, 0, 0,15,15,12,12},
    {15, 0, 0,15,15, 0,15, 0, 9, 0},
    {15,15,15,15, 0, 0,15,15,15, 0},
    { 0, 0, 0, 0, 0, 0, 0,18, 0,19},
    {15,15, 9,15, 9, 0,18,18,18, 8}
};

//visual maps
int map1[6][10]= {
    {2, 2, 2, 2, 4, 0, 0, 0, 0, 0},
    {4, 2, 2, 2, 0, 0, 0, 5, 5, 5},
    {1, 1, 0, 2, 0, 0, 0, 5, 0, 6},
    {1, 1, 1, 0, 0, 5, 5, 5, 0, 4},
    {1 ,1, 1, 0, 0, 5, 2, 4, 2, 4},
    {1, 1, 1, 3, 5, 5, 4, 2, 4, 2}
};

int map2[6][10]= {
    {2, 2, 4, 1, 1, 2, 4, 2, 2, 2},
    {5, 2, 0, 0, 0, 0, 2, 0, 2, 0},
    {5, 5, 5, 5, 5, 0, 0, 2, 6, 2},
    {4, 4, 4, 0, 5, 0, 0, 2, 0, 2},
    {2, 4, 0, 0, 5, 0, 0, 4, 0, 4},
    {2, 2, 2, 0, 5, 5, 5, 5, 5, 5}
};

int map3[6][10]= {
    {4, 1, 1, 4, 1, 1, 4, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {4, 0, 0, 4, 0, 0, 4, 0, 0, 0},
    {0, 0, 5, 5, 5, 5, 5, 5, 5, 5},
    {4, 0, 5, 4, 0, 0, 4, 0, 0, 0},
    {5, 5, 5, 0, 0, 2, 0, 2, 0, 0}
};

int map4[6][10]= {
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 4, 0, 0, 0, 0, 0},
    {0, 0, 2, 2, 0, 5, 5, 4, 0, 0},
    {5, 5, 5, 0, 0, 5, 0, 0, 0, 0},
    {0, 0, 5, 0, 5, 5, 2, 0, 2, 0},
    {0, 0, 5, 5, 5, 2, 0, 6, 0, 2}
};

int map5[6][10]= {
    {4, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 5, 5, 5, 5, 5, 5, 4, 4, 4},
    {0, 5, 2, 2, 4, 4, 5, 4, 6, 4},
    {0, 5, 4, 4, 2, 2, 5, 4, 0, 4},
    {0, 5, 5, 5, 5, 5, 5, 4, 0, 4},
    {4, 0, 0, 0, 0, 0, 0, 4, 0, 4}
};

int map6[6][10]= {
    {1, 1, 1, 0, 5, 0, 0, 4, 6, 4},
    {1, 1, 1, 0, 5, 5, 0, 4, 0, 4},
    {1, 1, 1, 0, 0, 5, 0, 4, 0, 4},
    {1, 1, 0, 2, 4, 5, 2, 0, 0, 0},
    {2, 4, 2, 2, 2, 5, 2, 2, 5, 5},
    {6, 5, 5, 5, 5, 5, 5, 5, 5, 4},
};

int map7[6][10]= {
    { 0, 2, 2, 0, 5, 5, 0, 2, 2, 0},
    { 0, 0, 2, 0, 5, 5, 0, 2, 0, 0},
    { 4, 4, 0, 2, 5, 5, 2, 0, 4, 0},
    { 0, 0, 4, 0, 5, 5, 0, 0, 0, 0},
    { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    { 4, 2, 5, 0, 2, 2, 0, 5, 2, 4}
};

int map8[6][10]= {
    { 0, 2, 0, 2, 4, 2, 0, 2, 0, 2},
    { 0, 0, 4, 0, 0, 0, 0, 0, 0, 0},
    { 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},
    { 0, 0, 4, 0, 0, 0, 4, 0, 0, 0},
    { 0, 2, 0, 2, 0, 2, 0, 2, 0, 2},
    { 0, 0, 0, 0, 0, 0, 4, 0, 4, 0}
};

int map9[6][10]= {
    { 2, 2, 2, 5, 0, 2, 0, 3, 0, 2},
    { 0, 2, 0, 5, 5, 0, 2, 2, 2, 2},
    { 0, 0, 0, 4, 5, 5, 4, 0, 0, 0},
    { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    { 2, 0, 0, 0, 5, 5, 0, 0, 0, 2},
    { 2, 2, 0, 0, 5, 5, 0, 0, 2, 2}
};

int map10[6][10]= {
    { 2, 2, 2, 0, 2, 2, 2, 4, 0, 4},
    { 4, 4, 4, 4, 4, 4, 4, 4, 0, 4},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    { 2, 2, 2, 2, 0, 2, 6, 2, 2, 2}
};

int map11[6][10]= {
    { 4, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    { 2, 2, 2, 4, 2, 2, 4, 2, 2, 2},
    { 2, 2, 4, 2, 2, 4, 2, 2, 2, 4},
    { 6, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    { 2, 2, 2, 2, 5, 2, 2, 4, 2, 2},
    { 4, 0, 0, 4, 5, 4, 0, 0, 0, 4}
};

int map12[6][10]= {
    { 4, 0, 5, 0, 2, 2, 0, 5, 0, 2},
    { 2, 2, 5, 0, 2, 4, 0, 5, 4, 0},
    { 2, 4, 5, 0, 2, 2, 0, 5, 5, 5},
    { 5, 5, 5, 0, 4, 2, 0, 5, 5, 5},
    { 2, 2, 0, 0, 2, 4, 0, 0, 4, 2},
    { 4, 0, 4, 2, 2, 2, 0, 2, 2, 2}
};

int map13[6][10]= {
    { 4, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    { 2, 2, 2, 2, 4, 2, 2, 2, 4, 2},
    { 5, 5, 5, 0, 0, 0, 0, 5, 5, 5},
    { 5, 5, 5, 0, 0, 0, 0, 5, 5, 5},
    { 0, 0, 2, 2, 4, 2, 2, 4, 0, 0},
    { 4, 0, 0, 0, 0, 0, 0, 0, 0, 4}
};

int map14[6][10]= {
    { 4, 4, 5, 5, 5, 5, 5, 5, 4, 4},
    { 4, 2, 5, 1, 1, 1, 1, 5, 2, 4},
    { 5, 5, 5, 1, 2, 4, 1, 5, 5, 5},
    { 5, 5, 5, 1, 4, 2, 1, 5, 5, 5},
    { 4, 4, 5, 1, 1, 1, 1, 5, 4, 4},
    { 4, 2, 5, 5, 5, 5, 5, 5, 2, 4}
};

int map15[6][10]= {
    { 2, 2, 0, 0, 2, 2, 0, 0, 2, 2},
    { 2, 0, 0, 2, 6, 4, 2, 0, 0, 2},
    { 5, 5, 2, 2, 5, 5, 4, 2, 0, 4},
    { 5, 5, 2, 2, 5, 5, 4, 2, 0, 4},
    { 2, 0, 0, 2, 4, 6, 2, 0, 0, 2},
    { 2, 2, 0, 0, 2, 2, 0, 0, 2, 2}
};

int map16[6][10]= {
    { 2, 0, 0, 4, 5, 4, 0, 0, 0, 0},
    { 4, 2, 0, 0, 5, 0, 0, 4, 0, 4},
    { 2, 1, 1, 0, 5, 2, 0, 0, 4, 0},
    { 2, 1, 1, 0, 5, 0, 0, 4, 0, 4},
    { 4, 2, 0, 0, 5, 2, 0, 0, 0, 0},
    { 2, 0, 0, 0, 5, 0, 0, 0, 0, 0}
};

int map17[6][10]= {
    { 2, 2, 0, 0, 0, 0, 0, 0, 0, 0},
    { 2, 0, 2, 2, 3, 2, 3, 2, 0, 0},
    { 4, 0, 6, 5, 5, 5, 5, 6, 0, 0},
    { 2, 0, 2, 5, 6, 2, 6, 2, 0, 0},
    { 2, 2, 0, 5, 0, 0, 0, 0, 0, 2},
    { 2, 2, 0, 5, 0, 0, 0, 0, 2, 2}
};

int map18[6][10]= {
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    { 7, 8, 8, 8, 8, 8, 8, 8, 8, 7},
    { 7, 8, 1, 1, 1, 1, 1, 1, 8, 7},
    { 7, 8, 1, 1, 1, 1, 1, 1, 8, 7},
    { 7, 8, 8, 8, 8, 8, 8, 8, 8, 7},
    { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}
};

int map19[6][10]= {
    { 2, 2, 0, 2, 5, 5, 0, 0, 2, 2},
    { 2, 0, 0, 5, 5, 5, 0, 0, 0, 2},
    { 0, 0, 0, 5, 2, 2, 0, 2, 0, 0},
    { 0, 0, 0, 5, 2, 0, 0, 2, 2, 0},
    { 0, 0, 0, 5, 5, 0, 0, 0, 0, 0},
    { 2, 0, 0, 4, 5, 4, 0, 0, 4, 2}
};

int map20[6][10]= {
    { 2, 2, 0, 0, 2, 2, 5, 0, 2, 2},
    { 2, 0, 0, 0, 6, 2, 5, 0, 0, 2},
    { 0, 0, 0, 0, 2, 2, 5, 5, 5, 0},
    { 0, 0, 2, 4, 2, 2, 2, 2, 5, 0},
    { 0, 0, 0, 2, 2, 4, 2, 5, 5, 0},
    { 2, 0, 0, 0, 4, 5, 5, 5, 0, 2}
};

int map21[6][10]= {
    { 0, 0, 0, 0, 5, 0, 0, 0, 0, 0},
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    { 0, 2, 0, 0, 5, 0, 2, 0, 1, 0},
    { 2, 0, 2, 0, 5, 6, 0, 2, 1, 0},
    { 4, 2, 0, 4, 5, 5, 4, 0, 1, 0},
    { 2, 4, 0, 0, 0, 0, 0, 2, 1, 0}
};

int map22[6][10]= {
    { 0, 0, 0, 5, 0, 0, 0, 0, 2, 2},
    { 0, 2, 2, 5, 0, 0, 0, 4, 0, 2},
    { 0, 2, 4, 5, 0, 0, 0, 0, 0, 0},
    { 0, 2, 2, 5, 5, 5, 5, 5, 5, 5},
    { 0, 4, 2, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 2, 2, 0, 0, 0, 0, 4}
};

int map23[6][10]= {
    { 2, 2, 0, 0, 0, 0, 0, 0, 0, 2},
    { 2, 0, 4, 0, 0, 0, 0, 0, 0, 2},
    { 0, 0, 0, 0, 0, 5, 5, 6, 2, 2},
    { 5, 5, 5, 5, 5, 5, 4, 2, 2, 2},
    { 0, 0, 0, 4, 0, 0, 2, 2, 6, 2},
    { 4, 2, 2, 0, 0, 2, 3, 2, 2, 2}
};

int map24[6][10]= {
    { 4, 0, 0, 4, 5, 4, 0, 0, 0, 4},
    { 8, 8, 7, 7,10, 7, 9, 7, 7, 7},
    { 8, 7, 7, 7,10, 7, 7, 9, 9, 9},
    { 9, 7, 9, 7,10, 9, 7, 7, 7, 7},
    { 8, 7, 9, 7,10,10,10,10,10,10},
    { 9, 7, 7, 7, 7, 7, 9, 7, 7, 7}
};

int map25[6][10]= {
    { 4, 0, 0, 0, 4, 5, 4, 0, 0, 0},
    { 9, 8, 9, 8, 9,10, 7, 7, 0, 0},
    { 7, 9, 9, 7, 7,10, 7, 9, 7, 8},
    { 7, 7, 7, 7, 8,10, 7, 7, 7, 9},
    {10,10,10,10,10,10, 9, 7, 9, 0},
    { 7, 7, 7, 7, 7, 7, 7, 7, 0, 6}
};

int guy_x, guy_y;
int map_x,map_y;
int end_game;
int item[20];
int badguy;
int p_health, p_strength,p_magic,c_health,c_strength,c_magic;
int x,y;
int monster;

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
void print();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:map
//change the maps
void map();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:items
//this function checks for items and bad guys.
void items();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:map2item
//this function makes the items equal to the temp items.
void map2item();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:print2
//prints out battle
void print2();

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//function:battle
//this function deals with the battles
int battle();

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main () {
    char c;
    time_t t;
    srand((unsigned) time(&t));
    end_game=0;
    map_x=0;
    map_y=0;
    badguy=0;
    p_health=1;
    p_strength=10;
    p_magic=0;
    x=0;
    y=0;
    int count=0;

    for(int a=0; a<20; ++a)
        item[a]=0;

    initwindow(500,500);

//start the title screen

    sndPlaySound("intro.wav", SND_ASYNC);

    setcolor(15);
    setbkcolor(0);

    for(int i=1; i <=40; ++i) {
        settextstyle(6,0,8);
        moveto(100,150);
        outtext("CELDA");
        moveto(220,230);
        settextstyle(6,0,4);
        outtext("The Legend of");
        circle(200,200+(2*i),50);
        circle(200+(2*i),200,50);
        circle(200,200-(2*i),50);
        circle(200-(2*i),200,50);
        delay(100);
        if (i==40) {
            for (int i=1; i<=50; ++i) {
                settextstyle(6,0,8);
                moveto(100,150);
                outtext("CELDA");
                moveto(220,230);
                settextstyle(6,0,4);
                outtext("The Legend of");
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
                        moveto(100,150);
                        outtext("CELDA");
                        moveto(220,230);
                        settextstyle(6,0,4);
                        outtext("The Legend of");
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
                            settextstyle(5,0,1);
                            outtextxy(200,370,"(Hit any key to continue)");
                            getch();
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

//draw program
//print2();
//    do
//     {
//     while (!ismouseclick(WM_LBUTTONDOWN))
//         {
//             delay(500);
//         }
//         getmouseclick(WM_LBUTTONDOWN, x, y);
//         cout << "The mouse was clicked at: ";
//         cout << "x=" << x;
//         cout << " y=" << y << endl;
//
//            if (count==0)
//           {
//            moveto(x,y);
//            prn<< "moveto("<<x<<","<<y<<");"<< endl;
//            count=1;
//           }
//           else
//            {
//            lineto(x,y);
//            prn<< "lineto("<<x<<","<<y<<");"<< endl;
//            }
//       }while(end!=0);

    map();

    guy_x=4;
    guy_y=5;
//use keyboard
    print();
    do {
        c = (char) getch( );

        {
            c = (char) getch( );
            switch (c) {
            case KEY_UP:
                guy_y=guy_y-1;
                if ((guy_y<0)&&(map_y>0)) {
                    map2item();
                    guy_y=5;
                    map_y=map_y-1;
                    map();
                } else if ((guy_y==-1)&&(map_y==0))
                    guy_y=guy_y+1;
                else if ((visual[guy_y][guy_x]==1)||(visual[guy_y][guy_x]==2)||(visual[guy_y][guy_x]==4)||(visual[guy_y][guy_x]==8)||(visual[guy_y][guy_x]==9))
                    guy_y=guy_y+1;
                break;

            case KEY_LEFT:
                guy_x=guy_x-1;
                if ((guy_x<0)&&(map_x>0)) {
                    map2item();
                    guy_x=9;
                    map_x=map_x-1;
                    map();
                } else if ((guy_x==-1)&&(map_x==0))
                    guy_x=guy_x+1;
                else if ((visual[guy_y][guy_x]==1)||(visual[guy_y][guy_x]==2)||(visual[guy_y][guy_x]==4)||(visual[guy_y][guy_x]==8)||(visual[guy_y][guy_x]==9))
                    guy_x=guy_x+1;
                break;

            case KEY_RIGHT:
                guy_x=guy_x+1;
                if ((guy_x>9)&&(map_x<4)) {
                    map2item();
                    guy_x=0;
                    map_x=map_x+1;
                    map();
                } else if ((guy_x==10)&&(map_x==4))
                    guy_x=guy_x-1;
                else if ((visual[guy_y][guy_x]==1)||(visual[guy_y][guy_x]==2)||(visual[guy_y][guy_x]==4)||(visual[guy_y][guy_x]==8)||(visual[guy_y][guy_x]==9))
                    guy_x=guy_x-1;
                break;

            case KEY_DOWN:
                guy_y=guy_y+1;
                if ((guy_y>5)&&(map_y<4)) {
                    map2item();
                    guy_y=0;
                    map_y=map_y+1;
                    map();
                } else if ((guy_y==6)&&(map_y==4))
                    guy_y=guy_y-1;
                else if ((visual[guy_y][guy_x]==1)||(visual[guy_y][guy_x]==2)||(visual[guy_y][guy_x]==4)||(visual[guy_y][guy_x]==8)||(visual[guy_y][guy_x]==9))
                    guy_y=guy_y-1;
                break;
            }
        }
        print();
        items();
    }   while (end_game !=1);
//end keyboard

    return 0;
    closegraph();

}



//******************************************************************************
//                           randomize implementation
int randomize(int rhigh, int rlow) {
    return rand()%(rhigh - rlow + 1) + rlow;
}

//******************************************************************************
//
void print() {

    setactivepage(1);
    setvisualpage(2);

    setfillstyle(0,0);
    setfillstyle(11,7);
    bar(0,0,500,500);
    setfillstyle(1,0);
    setcolor(7);
    bar(50,50,450,290);
    rectangle(50,50,450,290);
    bar(50,350,450,450);
    rectangle(50,350,450,450);


    for (int a=0; a<6; ++a)
        for (int b=0; b<10; ++b) {

            switch(visual[a][b]) {
            case 0:
//grass
                setpalette(0,COLOR(20,110,20));
                setfillstyle(11,2);
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,0);
                break;

            case 1:
//water
                setfillstyle(3,COLOR(0,0,250));
                setpalette(0,COLOR(50,50,150));
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,0);
                break;

            case 2:
//tree
                setfillstyle(11,2);
                setpalette(0,COLOR(20,110,20));
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,COLOR(10,70,10));
                bar(70+(40*b),60+(40*a),80+(40*b),90+(40*a));
                setcolor(COLOR(20,110,20));
                fillellipse(70+(40*b),65+(40*a),20,9);
                setpalette(0,COLOR(50,20,20));
                setfillstyle(11,4);
                setcolor(6);
                bar(65+(40*b),55+(40*a),75+(40*b),85+(40*a));
                rectangle(65+(40*b),55+(40*a),75+(40*b),85+(40*a));
                setfillstyle(11,COLOR(90,250,90));
                setpalette(0,COLOR(30,130,30));
                fillellipse(70+(40*b),62+(40*a),20,9);
                setpalette(0,0);
                setcolor(COLOR(110,170,110));
                ellipse(70+(40*b),62+(40*a),0,360,20,9);
                break;

            case 3:
//house
                setfillstyle(11,2);
                setpalette(0,COLOR(20,110,20));
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,COLOR(10,70,10));
                bar(60+(40*b),60+(40*a),90+(40*b),90+(40*a));
                setpalette(0,0);
                setfillstyle(11,4);
                bar(55+(40*b),70+(40*a),85+(40*b),85+(40*a));
                setcolor(COLOR(80,10,10));
                rectangle(55+(40*b),70+(40*a),85+(40*b),85+(40*a));
                pieslice(70+(40*b),70+(40*a),0,180,15);
                setfillstyle(9,4);
                bar(65+(40*b),75+(40*a),75+(40*b),85+(40*a));
                break;

            case 4:
//rocks
                setfillstyle(11,2);
                setpalette(0,COLOR(20,110,20));
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,COLOR(10,70,10));
                bar(60+(40*b),80+(40*a),75+(40*b),85+(40*a));
                bar(70+(40*b),75+(40*a),85+(40*b),80+(40*a));
                setpalette(0,0);
                setfillstyle(11,COLOR(70,70,70));
                setcolor(COLOR(110,110,110));
                pieslice(70+(40*b),70+(40*a),0,180,10);
                setfillstyle(11,COLOR(120,120,120));
                setcolor(COLOR(130,130,130));
                pieslice(75+(40*b),75+(40*a),0,180,10);
                setfillstyle(11,COLOR(130,130,130));
                setcolor(COLOR(150,150,150));
                pieslice(65+(40*b),80+(40*a),0,180,10);
                break;

            case 5:
//road
                setpalette(0,COLOR(51,0,0));
                setfillstyle(11,14);
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,0);
                break;

            case 6:
//house II
                setfillstyle(11,2);
                setpalette(0,COLOR(20,110,20));
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,COLOR(10,70,10));
                bar(60+(40*b),60+(40*a),90+(40*b),90+(40*a));
                setpalette(0,0);
                setfillstyle(11,1);
                bar(55+(40*b),70+(40*a),85+(40*b),85+(40*a));
                setcolor(COLOR(20,20,20));
                rectangle(55+(40*b),70+(40*a),85+(40*b),85+(40*a));
                pieslice(70+(40*b),70+(40*a),0,180,15);
                setfillstyle(9,COLOR(150,150,150));
                bar(65+(40*b),75+(40*a),75+(40*b),85+(40*a));
                break;

            case 7:
//desert
                setpalette(0,COLOR(148,104,0));
                setfillstyle(11,14);
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,0);
                break;

            case 8:
//desert rocks
                setpalette(0,COLOR(148,104,0));
                setfillstyle(11,14);
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,COLOR(108,80,0));
                bar(60+(40*b),80+(40*a),75+(40*b),85+(40*a));
                bar(70+(40*b),75+(40*a),85+(40*b),80+(40*a));
                setpalette(0,0);
                setfillstyle(11,COLOR(70,70,70));
                setcolor(COLOR(110,110,110));
                pieslice(70+(40*b),70+(40*a),0,180,10);
                setfillstyle(11,COLOR(120,120,120));
                setcolor(COLOR(130,130,130));
                pieslice(75+(40*b),75+(40*a),0,180,10);
                setfillstyle(11,COLOR(130,130,130));
                setcolor(COLOR(150,150,150));
                pieslice(65+(40*b),80+(40*a),0,180,10);
                break;

            case 9:
//cactus
                setpalette(0,COLOR(148,104,0));
                setfillstyle(11,14);
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,COLOR(108,80,0));
                bar(70+(40*b),65+(40*a),80+(40*b),85+(40*a));
                bar(65+(40*b),70+(40*a),85+(40*b),75+(40*a));
                setfillstyle(11,2);
                setcolor(COLOR(20,110,20));
                setpalette(0,COLOR(20,110,20));
                bar(65+(40*b),60+(40*a),75+(40*b),80+(40*a));
                rectangle(65+(40*b),60+(40*a),75+(40*b),80+(40*a));
                bar(60+(40*b),65+(40*a),80+(40*b),70+(40*a));
                setpalette(0,0);
                break;

            case 10:
//desert
                setpalette(0,COLOR(108,80,0));
                setfillstyle(11,14);
                bar(50+(40*b),50+(40*a),90+(40*b),90+(40*a));
                setpalette(0,0);
                break;
            }
        }

    setcolor(7);
    rectangle(50,50,450,290);
    rectangle(50,350,450,450);


//character
    setcolor(COLOR(120,120,120));
    setfillstyle(1,0);
    fillellipse(64+(40*guy_x),84+(40*guy_y),3,5);
    fillellipse(76+(40*guy_x),84+(40*guy_y),3,5);
    setcolor(COLOR(100,100,250));
    setfillstyle(1,1);
    fillellipse(70+(40*guy_x),74+(40*guy_y),10,10);
    setfillstyle(1,1);
    fillellipse(70+(40*guy_x),69+(40*guy_y),10,10);
    setcolor(COLOR(250,200,250));
    setfillstyle(1,12);
    fillellipse(60+(40*guy_x),74+(40*guy_y),2,7);
    fillellipse(80+(40*guy_x),74+(40*guy_y),2,7);
    fillellipse(70+(40*guy_x),64+(40*guy_y),8,8);
    setcolor(COLOR(100,100,250));
    setfillstyle(1,1);
    fillellipse(60+(40*guy_x),69+(40*guy_y),3,4);
    fillellipse(80+(40*guy_x),69+(40*guy_y),3,4);
    setcolor(COLOR(50,50,50));
    setfillstyle(1,0);
    fillellipse(70+(40*guy_x),62+(40*guy_y),8,6);

    if (item[1]==1) {
        setcolor(1);
        setfillstyle(11,1);
        bar(70+(40*guy_x),70+(40*guy_y),90+(40*guy_x),80+(40*guy_y));
        rectangle(70+(40*guy_x),70+(40*guy_y),90+(40*guy_x),80+(40*guy_y));
        pieslice(80+(40*guy_x),80+(40*guy_y),180,0,10);
    }

    if (item[2]==1) {
        setcolor(15);
        moveto(60+(40*guy_x),80+(40*guy_y));
        lineto(55+(40*guy_x),50+(40*guy_y));
    }

    setvisualpage(1);
}

//******************************************************************************
//                           print out a variable
void outintxy(int x, int y, int value) {
    char digit_string[20];
    sprintf(digit_string, "%d", value);
    outtextxy(x, y, digit_string);
}

//******************************************************************************
//                           map implementation
void map() {
    int a,b;

    switch(bigmap[map_y][map_x]) {
    case 1:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map1[a][b];
                mapitem[a][b]=mapitem1[a][b];
            }
        break;

    case 2:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map2[a][b];
                mapitem[a][b]=mapitem2[a][b];
            }
        break;

    case 3:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map3[a][b];
                mapitem[a][b]=mapitem3[a][b];
            }
        break;

    case 4:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map4[a][b];
                mapitem[a][b]=mapitem4[a][b];
            }
        break;

    case 5:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map5[a][b];
                mapitem[a][b]=mapitem5[a][b];
            }
        break;

    case 6:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map6[a][b];
                mapitem[a][b]=mapitem6[a][b];
            }
        break;

    case 7:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map7[a][b];
                mapitem[a][b]=mapitem7[a][b];
            }
        break;

    case 8:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map8[a][b];
                mapitem[a][b]=mapitem8[a][b];
            }
        break;

    case 9:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map9[a][b];
                mapitem[a][b]=mapitem9[a][b];
            }
        break;

    case 10:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map10[a][b];
                mapitem[a][b]=mapitem10[a][b];
            }
        break;

    case 11:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map11[a][b];
                mapitem[a][b]=mapitem11[a][b];
            }
        break;

    case 12:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map12[a][b];
                mapitem[a][b]=mapitem12[a][b];
            }
        break;

    case 13:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map13[a][b];
                mapitem[a][b]=mapitem13[a][b];
            }
        break;

    case 14:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map14[a][b];
                mapitem[a][b]=mapitem14[a][b];
            }
        break;

    case 15:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map15[a][b];
                mapitem[a][b]=mapitem15[a][b];
            }
        break;

    case 16:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map16[a][b];
                mapitem[a][b]=mapitem16[a][b];
            }
        break;

    case 17:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map17[a][b];
                mapitem[a][b]=mapitem17[a][b];
            }
        break;

    case 18:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map18[a][b];
                mapitem[a][b]=mapitem18[a][b];
            }
        break;

    case 19:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map19[a][b];
                mapitem[a][b]=mapitem19[a][b];
            }
        break;

    case 20:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map20[a][b];
                mapitem[a][b]=mapitem20[a][b];
            }
        break;

    case 21:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map21[a][b];
                mapitem[a][b]=mapitem21[a][b];
            }
        break;

    case 22:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map22[a][b];
                mapitem[a][b]=mapitem22[a][b];
            }
        break;

    case 23:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map23[a][b];
                mapitem[a][b]=mapitem23[a][b];
            }
        break;

    case 24:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map24[a][b];
                mapitem[a][b]=mapitem24[a][b];
            }
        break;

    case 25:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                visual[a][b]=map25[a][b];
                mapitem[a][b]=mapitem25[a][b];
            }
        break;
    }
}
//******************************************************************************
//                       items implementation
void items() {
    int temp;
    int a;
    setcolor(15);

    switch(mapitem[guy_y][guy_x]) {
//items
    case 1:
        outtextxy(70,360,"You found a shield");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_health=100;
        item[1]=1;
        print2();
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        delay(2000);
        print();
        break;

    case 2:
        outtextxy(70,360,"you found a sword");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_strength=p_strength+10;
        item[2]=1;
        print2();
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        delay(2000);
        print();
        break;

    case 3:
        outtextxy(70,360,"You found a hammer");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_strength=p_strength+20;
        item[3]=1;
        print2();
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        delay(2000);
        print();
        break;

    case 4:
        outtextxy(70,360,"You found an axe");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_strength=p_strength+20;
        item[4]=1;
        print2();
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        delay(2000);
        print();
        break;

    case 5:
        outtextxy(70,360,"You found the master sword");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_strength=p_strength+20;
        item[5]=1;
        print2();
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        delay(2000);
        print();
        break;

    case 6:
        outtextxy(70,360,"You found the water stone");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_strength=p_strength+10;
        item[6]=1;
        print2();
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        delay(2000);
        print();
        break;

    case 7:
        outtextxy(70,360,"You found the fire stone");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_strength=p_strength+10;
        item[7]=1;
        print2();
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        delay(2000);
        print();
        break;

    case 8:
        outtextxy(70,360,"You found the earth stone");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_strength=p_strength+10;
        item[8]=1;
        print2();
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        delay(2000);
        print();
        break;

    case 9:
        outtextxy(70,360,"You found a small potion");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        p_health=p_health+50;
        print();
        break;

    case 10:
        outtextxy(70,360,"You found a raft");
        delay(2000);
        mapitem[guy_y][guy_x]=0;
        item[10]=1;
        sndPlaySound("item.wav", SND_NODEFAULT);
        sndPlaySound("intro.wav", SND_ASYNC);
        print();
        break;

//monsters
    case 11:
        outtextxy(70,360,"You encountered a bat");
        delay(2000);
        badguy=11;
        c_health=20;
        c_strength=20;
        c_magic=0;
        monster=0;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"bat was killed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 12:
        outtextxy(70,360,"You encountered a grass creature");
        delay(2000);
        badguy=12;
        c_health=30;
        c_strength=30;
        c_magic=0;
        monster=0;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"grass creature was killed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 13:
        outtextxy(70,360,"You encountered a living tree");
        delay(2000);
        badguy=13;
        c_health=40;
        c_strength=40;
        c_magic=0;
        monster=0;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"living tree was killed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 14:
        outtextxy(70,360,"You encountered a ghost");
        delay(2000);
        badguy=14;
        c_health=50;
        c_strength=50;
        c_magic=0;
        monster=0;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"ghost was killed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 15:
        outtextxy(70,360,"You encountered a blob");
        delay(2000);
        badguy=15;
        c_health=60;
        c_strength=60;
        c_magic=0;
        monster=0;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"blob was killed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 16:
        outtextxy(70,360,"You encountered a water creature");
        delay(2000);
        badguy=16;
        c_health=70;
        c_strength=70;
        c_magic=0;
        monster=1;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"water creature was killed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 17:
        outtextxy(70,360,"You encountered a red deamon");
        delay(2000);
        badguy=17;
        c_health=80;
        c_strength=80;
        c_magic=0;
        monster=2;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"red deamon was killed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 18:
        outtextxy(70,360,"You encountered a lightning");
        delay(2000);
        badguy=18;
        c_health=90;
        c_strength=90;
        c_magic=0;
        monster=3;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"lightning was destroyed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 19:
        outtextxy(70,360,"You encountered the hand of doom");
        delay(2000);
        badguy=19;
        c_health=100;
        c_strength=100;
        c_magic=0;
        monster=0;
        sndPlaySound("monster.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"hand of doom was killed");
            delay(2000);
        }
        print();
        sndPlaySound("intro.wav", SND_ASYNC);
        break;

    case 20:
        outtextxy(70,360,"You encountered the boss");
        delay(2000);
        badguy=20;
        c_health=1000;
        c_strength=110;
        c_magic=0;
        monster=4;
        sndPlaySound("boss.wav", SND_NODEFAULT);
        sndPlaySound("boss1.wav", SND_ASYNC);
        temp=battle();
        if (temp==1) {
            end_game=1;
            break;
        }
        badguy=0;
        if (temp==0) {
            p_magic=p_magic+10;
            mapitem[guy_y][guy_x]=9;
            print();
            outtextxy(70,360,"boss was killed");
            delay(2000);
        }

        print();
        delay(100);
        cleardevice();
        delay(100);
        print();
        delay(100);
        cleardevice();
        delay(100);
        print();
        delay(100);
        cleardevice();
        delay(100);

        cleardevice();
        setcolor(15);
        settextstyle(1,0,5);
        outtextxy(90,230,"YOU WIN!");
        sndPlaySound("intro.wav", SND_NODEFAULT);
        end_game=1;
        break;

    case 21:
        outtextxy(70,360,"You found a back door");
        delay(2000);
        guy_x=6;
        guy_y=5;
        print();
        break;

    case 22:
        cout << item[10];
        if(item[10]==1) {
            outtextxy(70,360,"I will cross this river with my raft");
            delay(2000);
            guy_x=4;
            guy_y=2;
            print();
        } else {
            outtextxy(70,360,"If i only had a raft");
            delay(2000);
            print();
        }
        break;

    case 23:
        outtextxy(70,360,"I will cross this river with my raft");
        delay(2000);
        guy_x=4;
        guy_y=0;
        print();
    }

}

////******************************************************************************
//                       map2item implementation
void map2item() {
    int a,b;

    switch(bigmap[map_y][map_x]) {
    case 1:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem1[a][b]=mapitem[a][b];
            }
        break;

    case 2:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem2[a][b]=mapitem[a][b];
            }
        break;

    case 3:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem3[a][b]=mapitem[a][b];
            }
        break;

    case 4:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem4[a][b]=mapitem[a][b];
            }
        break;

    case 5:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem5[a][b]=mapitem[a][b];
            }
        break;

    case 6:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem6[a][b]=mapitem[a][b];
            }
        break;

    case 7:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem7[a][b]=mapitem[a][b];
            }
        break;


    case 8:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem8[a][b]=mapitem[a][b];
            }
        break;

    case 9:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem9[a][b]=mapitem[a][b];
            }
        break;

    case 10:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem10[a][b]=mapitem[a][b];
            }
        break;

    case 11:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem11[a][b]=mapitem[a][b];
            }
        break;

    case 12:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem12[a][b]=mapitem[a][b];
            }
        break;

    case 13:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem13[a][b]=mapitem[a][b];
            }
        break;

    case 14:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem14[a][b]=mapitem[a][b];
            }
        break;

    case 15:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem15[a][b]=mapitem[a][b];
            }
        break;

    case 16:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem16[a][b]=mapitem[a][b];
            }
        break;

    case 17:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem17[a][b]=mapitem[a][b];
            }
        break;

    case 18:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem18[a][b]=mapitem[a][b];
            }
        break;

    case 19:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem19[a][b]=mapitem[a][b];
            }
        break;


    case 20:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem20[a][b]=mapitem[a][b];
            }
        break;

    case 21:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem21[a][b]=mapitem[a][b];
            }
        break;

    case 22:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem22[a][b]=mapitem[a][b];
            }
        break;

    case 23:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem23[a][b]=mapitem[a][b];
            }
        break;

    case 24:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem24[a][b]=mapitem[a][b];
            }
        break;

    case 25:
        for (a=0; a<6; ++a)
            for (b=0; b<10; ++b) {
                mapitem25[a][b]=mapitem[a][b];
            }
        break;
    }
}

//******************************************************************************
//                        print2 implementation
void print2() {
    setactivepage(1);
    setvisualpage(2);

//begining grid
    setfillstyle(0,0);
    setfillstyle(11,7);
    bar(0,0,500,500);
    setfillstyle(1,0);
    setcolor(7);
    bar(50,50,450,290);
    rectangle(50,50,450,290);
    bar(50,350,450,450);
    rectangle(50,350,450,450);
    setlinestyle(0,3,2);

//%%%%%%%%%%%%%%%%%%%%%%%
//BAD GUYS

//bat
    if(badguy==11) {
        setcolor(1);
        moveto(446,146);
        lineto(413,142);
        lineto(399,139);
        lineto(378,149);
        lineto(366,159);
        lineto(363,169);
        lineto(370,176);
        lineto(382,180);
        lineto(389,184);
        lineto(390,191);
        lineto(386,194);
        lineto(377,194);
        lineto(374,186);
        lineto(362,179);
        lineto(351,182);
        lineto(342,182);
        lineto(342,194);
        lineto(344,198);
        lineto(344,205);
        lineto(337,207);
        lineto(332,203);
        lineto(332,194);
        lineto(334,182);
        lineto(327,172);
        lineto(314,166);
        lineto(291,172);
        lineto(270,184);
        lineto(245,202);
        lineto(258,160);
        lineto(276,132);
        lineto(294,132);
        lineto(311,130);
        lineto(324,129);
        lineto(321,120);
        lineto(310,117);
        lineto(311,106);
        lineto(320,110);
        lineto(332,109);
        lineto(339,99);
        lineto(344,105);
        lineto(340,115);
        lineto(344,126);
        lineto(388,104);
        lineto(424,109);
        lineto(446,146);
        setfillstyle(11,1);
        floodfill(339,141,1);
    }

//grass man
    if(badguy==12) {
        setcolor(2);
        moveto(358,117);
        lineto(322,122);
        lineto(317,139);
        lineto(317,154);
        lineto(332,165);
        lineto(318,175);
        lineto(306,174);
        lineto(292,140);
        lineto(302,110);
        lineto(290,108);
        lineto(283,112);
        lineto(280,129);
        lineto(279,143);
        lineto(288,174);
        lineto(306,188);
        lineto(310,204);
        lineto(311,231);
        lineto(327,250);
        lineto(346,251);
        lineto(362,250);
        lineto(370,237);
        lineto(379,211);
        lineto(378,183);
        lineto(399,175);
        lineto(404,144);
        lineto(404,116);
        lineto(392,105);
        lineto(384,112);
        lineto(387,134);
        lineto(383,156);
        lineto(371,167);
        lineto(352,162);
        lineto(364,149);
        lineto(358,117);
        setfillstyle(11,2);
        floodfill(324,180,2);
    }

//tree
    if(badguy==13) {
        setcolor(6);
        moveto(423,258);
        lineto(389,230);
        lineto(383,191);
        lineto(398,150);
        lineto(414,129);
        lineto(428,127);
        lineto(450,120);
        lineto(450,110);
        lineto(413,117);
        lineto(418,100);
        lineto(427,80);
        lineto(408,66);
        lineto(384,69);
        lineto(367,87);
        lineto(369,110);
        lineto(355,128);
        lineto(331,134);
        lineto(302,124);
        lineto(288,109);
        lineto(279,88);
        lineto(270,89);
        lineto(275,100);
        lineto(244,67);
        lineto(240,69);
        lineto(269,106);
        lineto(284,127);
        lineto(304,133);
        lineto(329,142);
        lineto(355,138);
        lineto(343,186);
        lineto(323,216);
        lineto(288,243);
        lineto(230,258);
        lineto(249,269);
        lineto(275,263);
        lineto(328,258);
        lineto(336,264);
        lineto(360,257);
        lineto(387,260);
        lineto(408,269);
        lineto(428,273);
        lineto(437,265);
        lineto(423,258);
        setfillstyle(11,6);
        floodfill(360,189,6);
    }

//ghost
    if (badguy==14) {
        setcolor(15);
        moveto(333,266);
        lineto(371,264);
        lineto(389,245);
        lineto(373,233);
        lineto(371,197);
        lineto(371,154);
        lineto(413,154);
        lineto(426,142);
        lineto(427,69);
        lineto(412,69);
        lineto(407,91);
        lineto(404,132);
        lineto(371,134);
        lineto(367,117);
        lineto(376,93);
        lineto(352,78);
        lineto(324,90);
        lineto(323,110);
        lineto(339,120);
        lineto(346,141);
        lineto(321,151);
        lineto(283,115);
        lineto(266,122);
        lineto(305,162);
        lineto(323,172);
        lineto(350,154);
        lineto(345,234);
        lineto(327,245);
        lineto(333,266);
        setfillstyle(11,7);
        floodfill(360,170,15);
    }

//bloob
    if (badguy==15) {
        setcolor(1);
        moveto(307,92);
        lineto(314,68);
        lineto(338,67);
        lineto(358,73);
        lineto(362,95);
        lineto(392,99);
        lineto(413,113);
        lineto(422,135);
        lineto(417,224);
        lineto(419,238);
        lineto(404,243);
        lineto(389,245);
        lineto(373,241);
        lineto(373,229);
        lineto(363,226);
        lineto(363,213);
        lineto(369,206);
        lineto(383,193);
        lineto(378,138);
        lineto(362,196);
        lineto(350,222);
        lineto(357,247);
        lineto(379,254);
        lineto(389,264);
        lineto(389,276);
        lineto(365,278);
        lineto(317,277);
        lineto(274,274);
        lineto(258,271);
        lineto(239,265);
        lineto(241,250);
        lineto(256,242);
        lineto(280,238);
        lineto(292,212);
        lineto(287,197);
        lineto(294,135);
        lineto(251,139);
        lineto(228,137);
        lineto(215,108);
        lineto(197,68);
        lineto(208,50);
        lineto(235,50);
        lineto(243,64);
        lineto(234,75);
        lineto(247,95);
        lineto(256,104);
        lineto(307,92);
        setfillstyle(11,1);
        floodfill(350,90,1);
    }

//water guy
    if(badguy==16) {
        setcolor(1);
        moveto(325,122);
        lineto(310,116);
        lineto(290,99);
        lineto(289,78);
        lineto(295,68);
        lineto(333,66);
        lineto(354,68);
        lineto(370,85);
        lineto(369,108);
        lineto(344,125);
        lineto(391,134);
        lineto(430,70);
        lineto(440,67);
        lineto(449,76);
        lineto(449,100);
        lineto(427,145);
        lineto(399,175);
        lineto(363,172);
        lineto(374,202);
        lineto(393,237);
        lineto(413,245);
        lineto(428,263);
        lineto(425,281);
        lineto(400,286);
        lineto(343,286);
        lineto(277,284);
        lineto(249,274);
        lineto(241,254);
        lineto(263,238);
        lineto(295,232);
        lineto(313,170);
        lineto(261,165);
        lineto(227,129);
        lineto(205,61);
        lineto(214,49);
        lineto(230,50);
        lineto(239,60);
        lineto(254,106);
        lineto(269,135);
        lineto(325,122);
        setfillstyle(11,1);
        floodfill(338,194,1);
    }

//red demon
    if(badguy==17) {
        setcolor(4);
        moveto(352,243);
        lineto(352,194);
        lineto(357,194);
        lineto(372,217);
        lineto(364,240);
        lineto(366,247);
        lineto(393,253);
        lineto(400,254);
        lineto(405,251);
        lineto(406,243);
        lineto(377,237);
        lineto(387,218);
        lineto(385,212);
        lineto(373,187);
        lineto(375,141);
        lineto(396,141);
        lineto(400,169);
        lineto(394,180);
        lineto(399,183);
        lineto(402,176);
        lineto(406,186);
        lineto(410,186);
        lineto(408,175);
        lineto(415,181);
        lineto(418,177);
        lineto(412,171);
        lineto(422,173);
        lineto(422,168);
        lineto(412,165);
        lineto(406,160);
        lineto(408,132);
        lineto(375,127);
        lineto(364,126);
        lineto(374,116);
        lineto(373,60);
        lineto(367,94);
        lineto(344,91);
        lineto(337,58);
        lineto(336,91);
        lineto(339,115);
        lineto(351,124);
        lineto(316,131);
        lineto(306,95);
        lineto(314,84);
        lineto(309,78);
        lineto(305,84);
        lineto(299,67);
        lineto(294,71);
        lineto(298,79);
        lineto(287,76);
        lineto(287,80);
        lineto(294,81);
        lineto(286,84);
        lineto(288,88);
        lineto(296,86);
        lineto(300,139);
        lineto(338,139);
        lineto(339,178);
        lineto(339,231);
        lineto(340,236);
        lineto(310,239);
        lineto(308,245);
        lineto(312,252);
        lineto(352,243);
        setfillstyle(11,4);
        floodfill(353,163,4);
    }

//lighning guy
    if (badguy==18) {
        setcolor(14);
        moveto(383,80);
        lineto(302,66);
        lineto(319,138);
        lineto(282,122);
        lineto(310,198);
        lineto(277,181);
        lineto(312,257);
        lineto(305,207);
        lineto(325,219);
        lineto(307,150);
        lineto(340,163);
        lineto(340,102);
        lineto(377,107);
        lineto(383,80);
        setfillstyle(11,14);
        floodfill(323,138,14);
    }

//hand
    if(badguy==19) {
        setcolor(15);
        moveto(362,237);
        lineto(363,212);
        lineto(377,205);
        lineto(399,189);
        lineto(417,167);
        lineto(417,103);
        lineto(409,96);
        lineto(399,100);
        lineto(393,113);
        lineto(394,132);
        lineto(390,143);
        lineto(376,133);
        lineto(367,90);
        lineto(363,73);
        lineto(356,67);
        lineto(344,70);
        lineto(342,77);
        lineto(356,134);
        lineto(348,134);
        lineto(332,76);
        lineto(327,75);
        lineto(317,76);
        lineto(316,85);
        lineto(329,139);
        lineto(318,142);
        lineto(307,86);
        lineto(297,80);
        lineto(286,83);
        lineto(287,97);
        lineto(299,141);
        lineto(292,142);
        lineto(269,95);
        lineto(260,93);
        lineto(251,96);
        lineto(252,105);
        lineto(275,147);
        lineto(285,190);
        lineto(301,211);
        lineto(312,219);
        lineto(309,235);
        lineto(282,250);
        lineto(310,260);
        lineto(346,264);
        lineto(365,262);
        lineto(386,250);
        lineto(362,237);
        setfillstyle(11,4);
        floodfill(351,166,15);
    }

//boss
    if(badguy==20) {
        setcolor(8);
        moveto(324,63);
        lineto(365,61);
        lineto(377,70);
        lineto(384,90);
        lineto(385,121);
        lineto(386,132);
        lineto(408,136);
        lineto(430,142);
        lineto(449,148);
        lineto(450,289);
        lineto(221,289);
        lineto(225,209);
        lineto(230,168);
        lineto(249,151);
        lineto(265,148);
        lineto(288,145);
        lineto(313,137);
        lineto(314,94);
        lineto(317,71);
        lineto(324,63);
        setfillstyle(11,8);
        floodfill(348,213,8);
    }

//ITEMS

    if(item[5]==1) {
//master sword
        setcolor(11);
        moveto(82,272);
        lineto(192,133);
        lineto(234,113);
        lineto(218,149);
        lineto(82,272);
        setfillstyle(11,11);
        floodfill(194,163,11);
        lineto(234,113);
    }

    else if(item[4]==1) {
//axe
        setcolor(11);
        moveto(192,120);
        lineto(228,161);
        lineto(224,172);
        lineto(207,182);
        lineto(187,187);
        lineto(199,197);
        lineto(214,204);
        lineto(234,205);
        lineto(260,197);
        lineto(278,181);
        lineto(289,159);
        lineto(280,126);
        lineto(272,117);
        lineto(266,131);
        lineto(256,141);
        lineto(245,149);
        lineto(234,148);
        lineto(198,113);
        lineto(192,120);
        setfillstyle(11,11);
        floodfill(251,177,11);
        moveto(81,265);
        lineto(232,129);
        lineto(237,135);
        lineto(88,270);
        lineto(81,265);
        setfillstyle(11,11);
        floodfill(194,166,11);
        floodfill(226,137,11);
    }

    else if(item[3]==1) {
//hammer
        setcolor(11);
        moveto(176,127);
        lineto(203,105);
        lineto(215,118);
        lineto(210,131);
        lineto(228,153);
        lineto(245,153);
        lineto(253,162);
        lineto(221,186);
        lineto(211,172);
        lineto(219,158);
        lineto(205,136);
        lineto(188,139);
        lineto(175,126);
        setfillstyle(11,11);
        floodfill(197,120,11);
        moveto(81,265);
        lineto(232,129);
        lineto(237,135);
        lineto(88,270);
        lineto(81,265);
        setfillstyle(11,11);
        floodfill(194,166,11);
        floodfill(226,137,11);
    }

    else if(item[2]==1) {
//sword
        setcolor(11);
        moveto(82,272);
        lineto(192,133);
        lineto(234,113);
        lineto(218,149);
        lineto(82,272);
        setfillstyle(11,11);
        floodfill(194,163,11);
        lineto(234,113);
    }

//character
    setcolor(COLOR(230,180,180));
    moveto(126,135);
    lineto(152,139);
    lineto(156,150);
    lineto(157,155);
    lineto(157,160);
    lineto(153,162);
    lineto(154,165);
    lineto(154,168);
    lineto(149,178);
    lineto(148,181);
    lineto(149,186);
    lineto(146,189);
    lineto(123,185);
    lineto(112,195);
    lineto(90,168);
    lineto(108,156);
    lineto(112,136);
    lineto(126,135);
    setfillstyle(1,12);
    floodfill(129,157,COLOR(230,180,180));
//hair
    setcolor(COLOR(50,50,50));
    moveto(138,172);
    lineto(143,161);
    lineto(151,159);
    lineto(154,151);
    lineto(163,144);
    lineto(168,136);
    lineto(126,127);
    lineto(111,129);
    lineto(106,132);
    lineto(103,155);
    lineto(103,168);
    lineto(114,173);
    lineto(121,174);
    lineto(128,172);
    lineto(123,169);
    lineto(125,162);
    lineto(130,158);
    lineto(134,159);
    lineto(136,161);
    lineto(133,169);
    lineto(138,171);
    setfillstyle(1,0);
    floodfill(135,142,COLOR(50,50,50));
//shirt
    setcolor(COLOR(100,100,200));
    moveto(50,173);
    lineto(74,165);
    lineto(89,165);
    lineto(115,199);
    lineto(125,223);
    lineto(102,289);
    lineto(50,289);
    lineto(50,173);
    setfillstyle(1,1);
    floodfill(90,233,COLOR(100,100,200));
//arms
    setcolor(COLOR(230,180,180));
    moveto(97,241);
    lineto(117,290);
    lineto(146,290);
    lineto(176,254);
    lineto(185,242);
    lineto(191,238);
    lineto(201,221);
    lineto(177,198);
    lineto(172,204);
    lineto(163,200);
    lineto(161,207);
    lineto(162,219);
    lineto(161,228);
    lineto(160,236);
    lineto(139,246);
    lineto(123,253);
    lineto(136,246);
    lineto(126,223);
    lineto(97,241);
    setfillstyle(1,12);
    floodfill(144,262,COLOR(230,180,180));
//sleves
    setcolor(COLOR(110,110,200));
    moveto(99,253);
    lineto(133,231);
    lineto(121,207);
    lineto(111,203);
    lineto(93,211);
    lineto(90,225);
    lineto(99,253);
    setfillstyle(1,1);
    floodfill(111,228,COLOR(110,110,200));

    if(item[1]==1) {
//shield
        setcolor(COLOR(0,0,200));
        moveto(224,290);
        lineto(232,274);
        lineto(238,245);
        lineto(239,226);
        lineto(214,220);
        lineto(184,214);
        lineto(158,217);
        lineto(139,223);
        lineto(120,231);
        lineto(123,255);
        lineto(124,270);
        lineto(133,285);
        lineto(134,290);
        lineto(224,290);
        setfillstyle(11,COLOR(0,0,200));
        floodfill(195,268,COLOR(0,0,200));
    }

    if(item[6]==1) {
        setcolor(WHITE);
        setfillstyle(1,BLUE);
        fillellipse(160,246,10,10);
    }

    if(item[7]==1) {
        setcolor(WHITE);
        setfillstyle(1,RED);
        fillellipse(195,246,10,10);
    }

    if(item[8]==1) {
        setcolor(WHITE);
        setfillstyle(1,GREEN);
        fillellipse(179,271,10,10);
    }

//boxes around the boxes
    setcolor(7);
    rectangle(50,50,450,290);
    rectangle(50,350,450,450);
    setlinestyle(0,1,1);

    setvisualpage(1);
}


//******************************************************************************
//                      battle implementation
int battle() {
    int damage;
    int endbattle=0;
    int p,c;
    print2();
    delay(2000);

    do {
        do {
            p=1;
            c=0;
            print2();
            setcolor(15);
            rectangle(70,70,180,110);
            outtextxy(80,75,"Health:");
            outtextxy(80,85,"Strength:");
            outtextxy(80,95,"Magic: ");
            outintxy(150,75,p_health);
            outintxy(150,85,p_strength);
            outintxy(150,95,p_magic);

            rectangle(320,230,430,270);
            outtextxy(330,235,"Health:");
            outtextxy(330,245,"Strength:");
            outtextxy(330,255,"Magic: ");
            outintxy(400,235,c_health);
            outintxy(400,245,c_strength);
            outintxy(400,255,c_magic);

            rectangle(70,370,140,430);
            outtextxy(80,390,"Melee");
            outtextxy(80,400,"Attack");
            rectangle(170,370,240,430);
            if (item[6]==1) {
                outtextxy(185,390,"Water");
                outtextxy(185,400,"Magic");
            }
            rectangle(250,370,320,430);
            if (item[7]==1) {
                outtextxy(265,390,"Fire");
                outtextxy(265,400,"Magic");
            }
            rectangle(330,370,400,430);
            if (item[8]==1) {
                outtextxy(345,390,"Earth");
                outtextxy(345,400,"Magic");
            }
            rectangle(410,370,440,430);
            outtextxy(415,395,"Run");

            while (!ismouseclick(WM_LBUTTONDOWN)) {
                delay(500);
            }
            getmouseclick(WM_LBUTTONDOWN, x, y);



            if ((x>70)&&(x<140)&&(y>370)&&(y<430)) {
                if((monster==0)||(monster==1)) {
                    damage=randomize(p_strength, p_strength-10);
                    c_health=c_health-damage;
                    setfillstyle(1,0);
                    setcolor(15);
                    bar(50,350,450,450);
                    rectangle(50,350,450,450);
                    outtextxy(70,360,"You deal");
                    outintxy(130,360,damage);
                    outtextxy(150,360,"damage");
                    sndPlaySound("attack.wav", SND_ASYNC);
                    delay(2000);
                } else {
                    setfillstyle(1,0);
                    setcolor(15);
                    bar(50,350,450,450);
                    rectangle(50,350,450,450);
                    outtextxy(70,360,"Your attack has no effect on this creature");
                    sndPlaySound("spin.wav", SND_ASYNC);
                    delay(2000);
                }

            } else if ((x>170)&&(x<240)&&(y>370)&&(y<430)) {
                if(item[6]==1) {
                    if(p_magic-10>=0) {
                        if((monster==0)||(monster==2)||(monster==4)) {
                            damage=randomize(p_strength, p_strength-10);
                            c_health=c_health-damage;
                            setfillstyle(1,0);
                            setcolor(15);
                            bar(50,350,450,450);
                            rectangle(50,350,450,450);
                            outtextxy(70,360,"You deal");
                            outintxy(130,360,damage);
                            outtextxy(150,360,"Water damage");
                            sndPlaySound("magic.wav", SND_ASYNC);
                            delay(2000);
                            p_magic=p_magic-10;
                        } else {
                            setfillstyle(1,0);
                            setcolor(15);
                            bar(50,350,450,450);
                            rectangle(50,350,450,450);
                            outtextxy(70,360,"Your attack has no effect on this creature");
                            sndPlaySound("spin.wav", SND_ASYNC);
                            delay(2000);
                        }
                    } else {
                        setfillstyle(1,0);
                        setcolor(15);
                        bar(50,350,450,450);
                        rectangle(50,350,450,450);
                        outtextxy(70,360,"You do not have enough magic");
                        sndPlaySound("spin.wav", SND_ASYNC);
                        delay(2000);
                        p=0;
                    }
                } else {
                    setfillstyle(1,0);
                    setcolor(15);
                    bar(50,350,450,450);
                    rectangle(50,350,450,450);
                    outtextxy(70,360,"You do not have that item yet");
                    sndPlaySound("spin.wav", SND_ASYNC);
                    delay(2000);
                    p=0;
                }
            } else if ((x>250)&&(x<320)&&(y>370)&&(y<430)) {
                if(item[7]==1) {
                    if(p_magic-10>=0) {
                        if((monster==0)||(monster==1)||(monster==3)||(monster==4)) {
                            damage=randomize(p_strength, p_strength-10);
                            c_health=c_health-damage;
                            setfillstyle(1,0);
                            setcolor(15);
                            bar(50,350,450,450);
                            rectangle(50,350,450,450);
                            outtextxy(70,360,"You deal");
                            outintxy(130,360,damage);
                            outtextxy(150,360,"Fire damage");
                            sndPlaySound("magic.wav", SND_ASYNC);
                            delay(2000);
                            p_magic=p_magic-10;
                        } else {
                            setfillstyle(1,0);
                            setcolor(15);
                            bar(50,350,450,450);
                            rectangle(50,350,450,450);
                            outtextxy(70,360,"Your attack has no effect on this creature");
                            sndPlaySound("spin.wav", SND_ASYNC);
                            delay(2000);
                        }
                    } else {
                        setfillstyle(1,0);
                        setcolor(15);
                        bar(50,350,450,450);
                        rectangle(50,350,450,450);
                        outtextxy(70,360,"You do not have enough magic");
                        sndPlaySound("spin.wav", SND_ASYNC);
                        delay(2000);
                        p=0;
                    }
                } else {
                    setfillstyle(1,0);
                    setcolor(15);
                    bar(50,350,450,450);
                    rectangle(50,350,450,450);
                    outtextxy(70,360,"You do not have that item yet");
                    sndPlaySound("spin.wav", SND_ASYNC);
                    delay(2000);
                    p=0;
                }
            } else if ((x>330)&&(x<400)&&(y>370)&&(y<430)) {
                if(item[8]==1) {
                    if(p_magic-10>=0) {
                        if((monster==0)||(monster==1)||(monster==2)||(monster==4)) {
                            damage=randomize(p_strength, p_strength-10);
                            c_health=c_health-damage;
                            setfillstyle(1,0);
                            setcolor(15);
                            bar(50,350,450,450);
                            rectangle(50,350,450,450);
                            outtextxy(70,360,"You deal");
                            outintxy(130,360,damage);
                            outtextxy(150,360,"Earth damage");
                            sndPlaySound("magic.wav", SND_ASYNC);
                            delay(2000);
                            p_magic=p_magic-10;
                        } else {
                            setfillstyle(1,0);
                            setcolor(15);
                            bar(50,350,450,450);
                            rectangle(50,350,450,450);
                            outtextxy(70,360,"Your attack has no effect on this creature");
                            sndPlaySound("spin.wav", SND_ASYNC);
                            delay(2000);
                        }
                    } else {
                        setfillstyle(1,0);
                        setcolor(15);
                        bar(50,350,450,450);
                        rectangle(50,350,450,450);
                        outtextxy(70,360,"You do not have enough magic");
                        sndPlaySound("spin.wav", SND_ASYNC);
                        delay(2000);
                        p=0;
                    }
                } else {
                    setfillstyle(1,0);
                    setcolor(15);
                    bar(50,350,450,450);
                    rectangle(50,350,450,450);
                    outtextxy(70,360,"You do not have that item yet");
                    sndPlaySound("spin.wav", SND_ASYNC);
                    delay(2000);
                    p=0;
                }
            } else if ((x>410)&&(x<440)&&(y>370)&&(y<430)) {
                int temp=randomize(3,1);
                if(temp==1) {
                    setfillstyle(1,0);
                    setcolor(15);
                    bar(50,350,450,450);
                    rectangle(50,350,450,450);
                    outtextxy(70,360,"You ran away");
                    sndPlaySound("run.wav", SND_ASYNC);
                    delay(2000);
                    return 2;
                } else {
                    setfillstyle(1,0);
                    setcolor(15);
                    bar(50,350,450,450);
                    rectangle(50,350,450,450);
                    outtextxy(70,360,"You failed to run away");
                    sndPlaySound("spin.wav", SND_ASYNC);
                    delay(2000);
                }
            } else {
                setfillstyle(1,0);
                setcolor(15);
                bar(50,350,450,450);
                rectangle(50,350,450,450);
                outtextxy(70,360,"Click on the boxes");
                sndPlaySound("spin.wav", SND_ASYNC);
                delay(2000);
                p=0;
            }
        } while (p==0);

        if(c_health<=0) {
            endbattle=1;
        }

        if (endbattle!=1) {
            damage=randomize(c_strength, c_strength-10);
            p_health=p_health-damage;
            setfillstyle(1,0);
            setcolor(15);
            bar(50,350,450,450);
            rectangle(50,350,450,450);
            outtextxy(70,360,"Computer Deals");
            outintxy(175,360,damage);
            outtextxy(195,360,"damage");
            delay(2000);
        }

        if(p_health<=0) {
            cleardevice();
            setcolor(15);
            settextstyle(1,0,5);
            outtextxy(30,230,"GAME OVER");
            sndPlaySound("die.wav", SND_NODEFAULT);
            sndPlaySound("boss1.wav", SND_ASYNC);
            delay(3000);
            return 1;
        }

    } while(endbattle==0);
    return 0;
}
