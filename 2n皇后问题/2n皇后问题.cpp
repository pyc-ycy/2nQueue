// 2n�ʺ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
using namespace std;
int  a[10][10];
int bj[3][20]={0};//�׻ʺ���
int bj1[3][20]={0};//�ڻʺ���
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
void f(int x )//���ð׺� 
{int y;
if(x==n)f2(0);//���� �ں� 
     else 
     { for(y=0;y<n;y++)
       if(a[x][y]==1&&bj[0][y]==0&&bj[1][x+y]==0&&bj[2][x-y+n]==0)//���ҶԽ� �� �͵�ǰ���궼δ����ǿɷ� 
           {   a[x][y]=2;//��ǰ׺� ����λ�� Ϊ�����úں� ���� 
            bj[0][y]=bj[1][x+y]=bj[2][x-y+n]=1;//������ҶԽ� �� 
            f(x+1);
            bj[0][y]=bj[1][x+y]=bj[2][x-y+n]=0;//������ 
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