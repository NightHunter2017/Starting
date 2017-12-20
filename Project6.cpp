// Project6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"
#include "math.h"
#include "fstream"

using namespace std;

struct tv
{
	char maker[100];
	float diag;
	char color[100];
	float price;
};

void vvod(int &m, tv *&n, int &m1)
{
	if (m1 == 0)
	{
		n = new tv[m + 1];
		m1 = 1;
	}
	else
	{
		tv *t = new tv[m + 1];
		for (int i = 0; i < m; i++)
		{
			t[i] = n[i];
		}
		delete[] n;
		n = t;
	}
	printf("Enter maker of TV\n");
	cin >> n[m].maker;
	printf("Enter diagonal of TV (in inches)\n");
	cin >> n[m].diag;
	while (n[m].diag < 0)
	{
		printf("Error! Try again...\n");
		cin >> n[m].diag;
	}
	printf("Enter color of TV\n");
	cin >> n[m].color;
	printf("Enter price of TV (in RUB)\n");
	cin >> n[m].price;
	while (n[m].price < 0)
	{
		printf("Error! Try again...\n");
		cin >> n[m].price;
	}
	printf("Ready!\n");
	system("pause");
	system("cls");
	m++;
	return;
}

void print(int m, tv *&n)
{
	for (int i = 0; i < m; i++)
	{
		if (n[i].diag <= 14)
		{
			printf("%d TV:\n\nMaker: %s\nDiagonal: %.2f inches\nColor: %s\nPrice: %.2f RUB\nCan be placed in small room: Yes\n\n", i + 1, n[i].maker, n[i].diag, n[i].color, n[i].price);
		}
		else
		{
			printf("%d TV:\n\nMaker: %s\nDiagonal: %.2f inches\nColor: %s\nPrice: %.2f RUB\nCan be placed in small room: No\n\n", i + 1, n[i].maker, n[i].diag, n[i].color, n[i].price);
		}
	}
	system("pause");
	system("cls");
	return;
}

void sort(tv *&n, int m, int m1)
{
	if ((m1 == 1) && (m != 0))
	{
		int a = 0, a1 = 0;
		printf("1.Sort by maker.\n2.Sort by diagonal.\n3.Sort by color.\n4.Sort by price.\n5.Sort by possibility of placing in small room.\n6.Back.\n");
		cin >> a;
		while ((a < 1) || (a > 6))
		{
			printf("Error! Try again...\n");
			cin >> a;
		}
		if ((a >= 1) && (a <= 5))
		{
			printf("1.Sort descendingly\n2.Sort ascendingly\n");
			cin >> a1;
			while ((a1 < 1) || (a1>2))
			{
				printf("Error! Try again...\n");
				cin >> a1;
			}
		}
		switch (a)
		{
		case 1:
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++)
				{
					if (((i < j) && (pow(-1, a1)*strcmp(n[i].maker, n[j].maker) > 0)) || ((i > j) && (pow(-1, a1)*strcmp(n[i].maker, n[j].maker) < 0)))
					{
						tv r = n[i];
						n[i] = n[j];
						n[j] = r;
					}
				}
		}break;
		case 2:
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++)
				{
					if (((i < j) && (pow(-1, a1)*n[i].diag > pow(-1, a1)*n[j].diag)) || ((i > j) && (pow(-1, a1)*n[i].diag < pow(-1, a1)*n[j].diag)))
					{
						tv r = n[i];
						n[i] = n[j];
						n[j] = r;
					}
				}
		}break;
		case 3:
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++)
				{
					if (((i < j) && (pow(-1, a1)*strcmp(n[i].color, n[j].color) > 0)) || ((i > j) && (pow(-1, a1)*strcmp(n[i].color, n[j].color) < 0)))
					{
						tv r = n[i];
						n[i] = n[j];
						n[j] = r;
					}
				}
		}break;
		case 4:
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++)
				{
					if (((i < j) && (pow(-1, a1)*n[i].price > pow(-1, a1)*n[j].price)) || ((i > j) && (pow(-1, a1)*n[i].price < pow(-1, a1)*n[j].price)))
					{
						tv r = n[i];
						n[i] = n[j];
						n[j] = r;
					}
				}
		}break;
		case 5:
		{
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++)
				{
					if (((i < j) && (pow(-1, a1)*n[i].diag > pow(-1, a1) * 14) && (pow(-1, a1)*n[j].diag <= pow(-1, a1) * 14)) || ((i > j) && (pow(-1, a1)*n[i].diag <= pow(-1, a1) * 14) && (pow(-1, a1)*n[j].diag > pow(-1, a1) * 14)))
					{
						tv r = n[i];
						n[i] = n[j];
						n[j] = r;
					}
				}
		}break;
		case 6:break;
		}
		if (a != 6)
		{
			printf("Ready!\n");
			system("pause");
		}
	}
	else
	{
		printf("No data found!\n");
		system("pause");
	}
	system("cls");
	return;
}

int main()
{
	tv *n = NULL;
	int st = 0, m = 0, m1 = 0;
	while (st != 4)
	{
		printf("1.Enter new TV\n2.Printing all TV\n3.Sort notes\n4.Exit.\n");
		scanf_s("%d", &st);
		while ((st < 1) || (st > 4))
		{
			printf("Error! Try again...\n");
			scanf_s("%d", &st);
		}
		system("cls");
		switch (st)
		{
		case 1: vvod(m, n, m1); break;
		case 2: print(m, n); break;
		case 3: sort(n, m, m1); break;
		case 4:
			if (m1 == 1)
			{
				printf("All data will be erased. Exit?\n1.Yes\n2.No\n");
				cin >> st;
				while ((st < 1) || (st > 2))
				{
					printf("Error! Try again...\n");
					cin >> st;
				}
				switch (st)
				{
				case 1:
				{
					delete[] n;
					st = 4;
				}
				case 2:
				{
						st = 0;
				}
			system("cls");
				}
			}
			break;
		}
	}
	return 0;
}