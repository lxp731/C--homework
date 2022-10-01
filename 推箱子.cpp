//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <conio.h>
//
//int map[13][14] = {
//    {0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0},
//    {0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0},
//    {0, 2, 2, 2, 2, 0, 0, 4, 4, 2, 2, 2, 2, 2},
//    {0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2},
//    {0, 2, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 2},
//    {0, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2},
//    {2, 2, 2, 2, 4, 2, 2, 0, 0, 0, 0, 0, 0, 2},
//    {2, 0, 0, 0, 4, 0, 2, 0, 0, 0, 8, 0, 0, 2},
//    {2, 0, 4, 0, 4, 0, 2, 0, 2, 2, 2, 2, 2, 2},
//    {2, 2, 0, 0, 4, 0, 2, 0 ,2, 1, 1, 1, 2, 0},
//    {0, 2, 0, 2, 0, 0, 0, 0, 0, 1, 1, 1, 2, 0},
//    {0, 2, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 2, 0},
//    {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0}
//};
//
//int tarPos[][2] = {
//	{9, 9},
//	{9, 10},
//	{9, 11},
//	{10, 9},
//	{10, 10},
//	{10, 11},
//	{11, 8},
//	{11, 9},
//	{11, 10},
//	{11, 11}
//};
//
//char key = 0;
//int row = 0, column = 0;
//int oldType = 0;
//int oldBoxType = 0;
//
//
//void DrawMap() {
//    for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++)
//    {
//        for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++)
//        {
//        	switch (map[i][j])
//        	{
//        	case 0:
//        		printf("  ");
//        		break;
//        	case 1:
//        		printf("☆");
//        		break;
//        	case 2:
//        		printf("■");
//        		break;
//        	case 4:
//        		printf("▓");
//        		break;
//        	case 8:
//        		printf("♀");
//        		row = i;
//        		column = j;
//        		break;
//        	case 16:
//        		printf("★");
//        		break;
//        	}
//        }
//        printf("\n");
//    }
//}
//
//void Move(int r, int c)
//{
//	if (map[row + r][column + c] != 2)	// 如果前面不是墙壁的话，就可以移动
//	{
//		if (map[row + r][column + c] == 4 || map[row + r][column + c] == 16)	// 如果遇到箱子的处理办法
//		{
//			if (map[row + 2 * r][column + 2 * c] != 2 && map[row + 2 * r][column + 2 * c] != 4
//			 && map[row + 2 * r][column + 2 * c] != 16)	// 箱子后面不是墙壁和箱子
//			{
//				// 移动箱子
//				if (map[row + r][column + c] == 16)
//				{
//					oldBoxType = 1;
//				}
//				else if (map[row + r][column + c] == 4)
//				{
//					oldBoxType = 0;
//				}
//				map[row + r][column + c] = oldBoxType;
//				if (map[row + 2 * r][column + 2 * c] == 1)
//				{
//					map[row + 2 * r][column + 2 * c] = 16;
//				}
//				else
//				{
//					map[row + 2 * r][column + 2 * c] = 4;
//				}
//			}
//			else {
//				return;
//			}
//		}
//		map[row][column] = oldType;
//		oldType = map[row + r][column + c];
//		map[row + r][column + c] = 8;
//	}
//}
//
//void resultCheck()
//{
//	bool result = true;
//	for (int i = 0; i < sizeof(tarPos) / sizeof(tarPos[0]); i++)
//	{
//		if (map[tarPos[i][0]][tarPos[i][1]] != 16)
//		{
//			result = false;
//		}
//	}
//	if (result)
//	{
//		MessageBox(NULL, TEXT("你赢了!!"), TEXT("游戏结束"), MB_OK);
//		exit(0);
//	}
//}
//
//int main()
//{
//	DrawMap();
//	while (true)
//	{
//		key = _getch();
//		switch (key)
//		{
//		case 'a':
//			Move(0, -1);
//			break;
//		case 'd':
//			Move(0, 1);
//			break;
//		case 'w':
//			Move(-1, 0);
//			break;
//		case 's':
//			Move(1, 0);
//			break;
//		}
//		resultCheck();
//		system("cls");
//		DrawMap();
//	}
//	return 0;
//}




#include<stdio.h>
#include<conio.h>
#include<windows.h>
//#include<graphics.h>
//#include <easyx.h>


#define ROW 9
#define COL 11



int map[ROW][COL]={
   {0,1,1,1,1,1,1,1,1,1,0},
   {0,1,0,0,0,1,0,0,0,1,0},
   {0,1,0,4,4,4,4,4,0,1,0},
   {0,1,0,4,0,4,0,4,0,1,1},
   {0,1,0,0,0,5,0,0,4,0,1},
   {1,1,0,1,1,1,1,0,4,0,1},
   {1,0,3,3,3,3,3,1,0,0,1},
   {1,0,3,3,3,3,3,0,0,1,1},
   {1,1,1,1,1,1,1,1,1,1,0} };
   
void drawmap();
void begingame();


int main()
{
	//initgraph(450, 350);
	while(1)
	{
		system("cls");
		drawmap();
		begingame();	
	}

	return 0;
 } 
void drawmap()
 {
 	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			switch(map[i][j])
			{
				case 0 : printf(" ");
				break;
				case 1 : printf("#");
				break;
				case 3 : printf("$");
				break;
				case 4 : printf("&");
				break;
				case 5 : printf("*");
				break; 
				case 7 : printf("!");
				break;
				case 8 : printf("%");
				break;
			}
		}
		printf("\n");
	}
 }
 
void begingame()
{
	int r,c;
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(map[i][j]==5||map[i][j]==8)
			{
				r=i;
				c=j;	
			}
		}
	}
	printf("(%d %d)",r,c);
	
	int ch;
	ch=getch();
	switch(ch)
	{
		case 'W' :
		case 'w' :
		case 72  :
			if(map[r-1][c]==0)
			{
				map[r][c]=0;
				map[r-1][c]=5;
			}
			if(map[r-1][c]==3)
			{
				map[r][c]=0;
				map[r-1][c]=8;
			 } 
			break;
		case 'S' :
		case 's' :
		case  80 :
			if(map[r+1][c]==0)
			{
				map[r][c]=0;
				map[r+1][c]=5;
			}
			if(map[r+1][c]==3)
			{
				map[r][c]=0;
				map[r+1][c]=8;
			 }
			break;
		case 'A' :
		case 'a' :
		case 75  :
			if(map[r][c-1]==0)
			{
				map[r][c]=0;
				map[r][c-1]=5;
			}
			if(map[r][c-1]==3)
			{
				map[r][c]=0;
				map[r][c-1]=8;
			 }
			break;
		case 'D' :
		case 'd' :
		case 77  :
			if(map[r][c+1]==0)
			{
				map[r][c]=0;
				map[r][c+1]=5;
			}
			if(map[r][c+1]==3)
			{
				map[r][c]=0;
				map[r][c+1]=8;
			 }
			break;
	}
}
