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

void udal(int &m, tv *&n, int &m1)
{
	if ((m1 == 1) && (m != 0))
	{
		int a = 0;
		printf("Which note about TV you want to delete?\n");
		cin >> a;
		while ((a < 1) || (a > m))
		{
			printf("Error! Try again...\n");
			cin >> a;
		}
		tv *j = new tv[m - 1];
		for (int i = 0; i <= m - 1; i++)
		{
			if (i < a - 1)
			{
				j[i] = n[i];
			}
			if (i > a - 1)
			{
				j[i - 1] = n[i];
			}
		}
		delete[] n;
		n = j;
		m--;
		printf("Ready!\n");
	}
	else
	{
		printf("No data found!\n");
	}
	system("pause");
	system("cls");
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

void load(int &m1, tv *&n, int &m)
{
	int a = 0;
	ifstream fin("info.txt");
	fin >> a;
	if (a == 0)
	{
		printf("No saved data found!\n");
		system("pause");
		system("cls");
		return;
	}
	if (m1 == 0)
	{
		n = new tv[a];
		for (int i = 0; i < a; i++)
		{
			fin >> n[i].maker;
			fin >> n[i].diag;
			fin >> n[i].color;
			fin >> n[i].price;
		}
		m1 = 1;
		m = a;
	}
	else
	{
		tv *t = new tv[m + a];
		for (int i = 0; i < m; i++)
		{
			t[i] = n[i];
		}
		delete[] n;
		n = t;
		for (int i = 0; i < a; i++)
		{
			fin >> n[m + i].maker;
			fin >> n[m + i].diag;
			fin >> n[m + i].color;
			fin >> n[m + i].price;
		}
		m += a;
	}
	fin.close();
	printf("Load successful!\n");
	system("pause");
	system("cls");
}

void save(int m, tv *n, int m1)
{
	if ((m1 == 1) && (m != 0))
	{
		ofstream fout("info.txt");
		fout << m << "\n";
		for (int i = 0; i < m; i++)
		{
			fout << n[i].maker << "\n";
			fout << n[i].diag << "\n";
			fout << n[i].color << "\n";
			fout << n[i].price << "\n";
		}
		fout.close();
		printf("Save successful!\n");
	}
	else
	{
		printf("Nothing to save!\n");
	}
	system("pause");
	system("cls");
}

int main()
{
	tv *n = NULL;
	int st = 0, m = 0, m1 = 0;
	while (st != 7)
	{
		printf("1.Enter new TV\n2.Delete any note\n3.Printing all TV\n4.Sort notes\n5.Load data\n6.Save data\n7.Exit.\n");
		scanf_s("%d", &st);
		while ((st < 1) || (st > 7))
		{
			printf("Error! Try again...\n");
			scanf_s("%d", &st);
		}
		system("cls");
		switch (st)
		{
		case 1: vvod(m, n, m1); break;
		case 2: udal(m, n, m1); break;
		case 3: print(m, n); break;
		case 4: sort(n, m, m1); break;
		case 5: load(m1, n, m); break;
		case 6: save(m, n, m1); break;
		case 7:
			if (m1 == 1)
			{
				printf("All data will be erased. Save before exit?\n1.Yes\n2.No,exit\n3.Cancel\n");
				cin >> st;
				while ((st < 1) || (st > 3))
				{
					printf("Error! Try again...\n");
					cin >> st;
				}
				switch (st)
				{
				case 1:
				{
					save(m, n, m1);
					delete[] n;
					return 0;
				}
				case 2:
				{
						st = 7;
						delete[] n;
						return 0;
				}
				case 3:
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
