#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ip[4], trans[4] = { 0,0,0,0 }, m[4] = { 0,0,0,0 }, fuhao[4] = { 0,0,0,0 };
//ip表示input,trans用来储存数字排序,m用来记忆排序过的数字,fuhao用来把数字转变成符号
bool b[15][15][15][15];
void out()             //加括号并输出
{
	int kuo[4]={0,0,0,0};//判断这个位置要不要括号
	if(fuhao[2]>=3 && fuhao[1]<=2) kuo[0]=1,kuo[1]=2;
	if(fuhao[3]>=3 && fuhao[2]<=2) kuo[0]=1,kuo[2]=2;
	for(int i=0;i<4;i++)
	{
		if(kuo[i]==1) printf("(");
		if(!i) {if(fuhao[i]==2) putchar('-');}
		else
		{
			switch(fuhao[i])
			{
				case(0):break;
				case(1):printf("+"); break;
				case(2):printf("-"); break;
				case(3):printf("*"); break;
				case(4):printf("/"); break;
			}
		}
		printf("%d",ip[trans[i]]);
		if(kuo[i]==2) printf(")");
	}
	printf("=24\n");
	/* 
	for (int i = 1; i <= 3; i++)
		switch(fuhao[i])
		{
		case(1):fh[i] = '+'; break;
		case(2):fh[i] = '-'; break;
		case(3):fh[i] = '*'; break;
		case(4):fh[i] = '/'; break;
		}
	if (fuhao[2] == 3 ||fuhao[2] == 4)
	{
		if (fuhao[1] == 1 || fuhao[1] == 2)
			cout << "(" << ip[trans[0]] << fh[1] << ip[trans[1]] << ")" << fh[2] << ip[trans[2]] << fh[3] << ip[trans[3]] << "=24\n";
	}
	else if (fuhao[3] == 3 || fuhao[3] == 4)
	{
		if(fuhao[1] == 1 || fuhao[1] == 2)
			cout << "(" << ip[trans[0]] << fh[1] << ip[trans[1]] << fh[2] << ip[trans[2]]<< ")"  << fh[3] << ip[trans[3]] << "=24\n";
		else
			cout << ip[trans[0]] << fh[1] << "("<< ip[trans[1]]   << fh[2] << ip[trans[2]]<< ")" << fh[3] << ip[trans[3]] << "=24\n";
	}
	else
		cout << ip[trans[0]] << fh[1] << ip[trans[1]] << fh[2] << ip[trans[2]]  << fh[3] << ip[trans[3]] << "=24\n";*/
	
}


void run(int k,float ans)            //对排序完的数字进行运算
{
	for (int i = 1; i <= 4; i++)
	{
		if(!k && i>2) break;
		switch (i)
		{
			case(1):ans += ip[trans[k]]; break;
			case(2):ans -= ip[trans[k]]; break;
			case(3):ans *= ip[trans[k]]; break;
			case(4):ans /= ip[trans[k]]; break;
		}
		fuhao[k] = i;
		if (k == 3 && abs(ans-24)<0.0001)
			out();
		else if (k <= 2)
			run(k+1, ans);
		switch (i)
		{
			case(1):ans -= ip[trans[k]]; break;
			case(2):ans += ip[trans[k]]; break;
			case(3):ans /= ip[trans[k]]; break;
			case(4):ans *= ip[trans[k]]; break;
		}
	}
}


void arrange(int k)            //对四个数字进行排序
{
	for (int i = 0; i <= 3; i++)
	{
		if (m[i] == 0)
		{
			trans[k] = i;
			m[i] = 1;
			if (k == 3)
			{
				if(!b[ip[trans[0]]][ip[trans[1]]][ip[trans[2]]][ip[trans[3]]])
					run(0,0),b[ip[trans[0]]][ip[trans[1]]][ip[trans[2]]][ip[trans[3]]]=true;
			}
			else
				arrange(k+1);
			m[i] = 0;
		}
	}
}


int main()
{
	cout << "欢迎使用24点\n请输入四个13以内的正整数\n";
	cin >>ip[0]>> ip[1]>>ip[2]>>ip[3];
	memset(b,false,sizeof(b));
	arrange(0);
	return 0;
}
