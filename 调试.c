#define _CRT_SECURE_NO_WARNINGS 1//���������¼�����ÿ�㲻ֹһ������д���о�����ʵ��һ����
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
const int T = 10;//T��ʱ��Ϊһ��ʱ��
int mymin(int x, int y) { return x < y ? x : y; }
int myabs(int x) { return x < 0 ? -x : x; }
int n, sum/*����������*/, num/*��ǰ¥��*/, ti[2][15]/*�����и��������������*/;
int last/*��һ��ͣ����¥��*/,time/*�ϴ�ͣ������ʱ*/,now/*ʵʱʱ��*/;
int a[15][1500][2]/*���к���ʱ�䡢Ŀ�ĵ�*/, b[15][1500][2], c[15]/*����µ�����*/;
int numa[15][1500], numb[15][1500], ab;//���ڰ�����ʱ�併��
int cmp1(int* x, int* y) { return a[ab][*y][0] - a[ab][*x][0]; }
int cmp2(int* x, int* y) { return b[ab][*y][0] - b[ab][*x][0]; }
void checka()
{
	ti[0][10] = a[10][numa[10][0]][0];
	for (int i = 9; i >= 1; i--) ti[0][i] = mymin(ti[0][i], a[i][numa[i][0]][0]);
}
void checkb()
{
	ti[1][10] = b[1][numb[1][0]][0];
	for (int i = 2; i <= 10; i++) ti[1][i] = mymin(ti[1][i], b[i][numb[i][0]][0]);
}
bool oka() { return a[num][numa[num][0]][0] <= mymin(now, ti[0][num] / T); }
//�Ͽ���Ҫ����ʱ�Ѿ����С����ҡ��ֵ�����ʱ�Ρ�
bool okb() { return b[num][numb[num][0]][0] <= mymin(now, ti[1][num] / T); }
void shang()
{
	for (; num <= 10; num++)
	{
		now = myabs(num - last) + time;
		if (c[num] != 0 || (sum < 4 && oka()))
		{
			printf("%d ", num);
			time = now;
			last = num;
		}
		sum -= c[num]; c[num] = 0;//Ҫͣ�������º���
		while (sum < 4 && a[num][numa[num][0]][0] <= now/*��ӵ����*/)
			sum++, c[a[num][numa[num][0]--][1]]++, n--;
		if (sum == 0 && ti[0][num + 1] > time) return;
	}
}
void xia()
{
	for (; num >= 1; num--)
	{
		now = myabs(num - last) + time;
		if (c[num] != 0 || (sum < 4 && okb()))
		{
			printf("%d ", num);
			time = now;
			last = num;
		}
		sum -= c[num]; c[num] = 0;//Ҫͣ�������º���
		while (sum < 4 && b[num][numb[num][0]][0] <= now/*��ӵ����*/)
			sum++, c[b[num][numb[num][0]--][1]]++, n--;
		if (sum == 0 && ti[1][num - 1] > time) return;
	}
}
int main()
{
	sum = time = 0;
	scanf("%d%d", &num, &n);
	last = num;
	for (int i = 1; i <= 10; i++) numa[i][0] = numb[i][0] = c[i] = 0;
	memset(a, 0x7f, sizeof(a));
	memset(b, 0x7f, sizeof(b));
	memset(ti, 0x7f, sizeof(ti));
	for (int i = 1; i <= n; i++)
	{
		int st, ed, t; scanf("%d%d%d", &st, &ed, &t);
		if (st < ed)
				a[st][++numa[st][0]][0] = t, a[st][numa[st][0]][1] = ed,
				numa[st][numa[st][0]]=numa[st][0];
		else b[st][++numb[st][0]][0] = t, b[st][numb[st][0]][1] = ed,
				numb[st][numb[st][0]] = numb[st][0];
	}
	for (ab = 1; ab <= 10; ab++)
	{
		qsort(numa[ab] + 1, numa[ab][0], sizeof(int), cmp1);
		qsort(numb[ab] + 1, numb[ab][0], sizeof(int), cmp2);
	}
	while (n != 0)
	{
		checka();
		checkb();
		if (mymin(ti[0][1], ti[1][10]) > time) time = mymin(ti[0][1], ti[1][10]);
		printf("%d\n", last);
		for (int i = 1; i <= 10; i++) if (a[i][numa[i][0]][0] <= time)
		{
			num = i; 
			shang(); break;
		}
		for (int i = 10; i >=1; i--) if (b[i][numb[i][0]][0] <= time)
		{
			num = i;
			xia(); break;
		}
		printf("%d\n", time);
	}
	return 0;
}
