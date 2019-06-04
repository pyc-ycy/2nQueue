// 2n皇后问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
using namespace std;
int  a[10][10];
int bj[3][20]={0};//白皇后标记
int bj1[3][20]={0};//黑皇后标记
int n;
int sum=0;
void f2(int x )
{int y;
if(x==n)sum++; 
     else 
     { for(y=0;y<n;y++)
       if(a[x][y]==1&&bj1[0][y]==0&&bj1[1][x+y]==0&&bj1[2][x-y+n]==0)
           {   a[x][y]=3;
            bj1[0][y]=bj1[1][x+y]=bj1[2][x-y+n]=1;
            f2(x+1);
            bj1[0][y]=bj1[1][x+y]=bj1[2][x-y+n]=0;
            a[x][y]=1;
           } 
     }
}
void f(int x )//放置白后 
{int y;
if(x==n)f2(0);//放置 黑后 
     else 
     { for(y=0;y<n;y++)
       if(a[x][y]==1&&bj[0][y]==0&&bj[1][x+y]==0&&bj[2][x-y+n]==0)//左右对角 列 和当前坐标都未被标记可放 
           {   a[x][y]=2;//标记白后 放置位置 为防放置黑后 放重 
            bj[0][y]=bj[1][x+y]=bj[2][x-y+n]=1;//标记左右对角 列 
            f(x+1);
            bj[0][y]=bj[1][x+y]=bj[2][x-y+n]=0;//清除标记 
            a[x][y]=1;
           } 
     }  
}
int main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	f(0);
	cout<<sum<<endl;
	return 0;
}