#include "DisplayReadElements.h"
#include "Cheсking.h"


Cheсking z4;
Display z5;
extern int a[9][9], b[9][9], r[81][2];
extern int row, col, icount, mode;
extern char solh;

using namespace std;

void Display::display()
{
	int i, j, k, fixed;
	gotoxy(6, 0);
	for (i = 0; i < 10; i++)
	{
		if (i % 3 == 0)
		{
			system("color 1");
			if (i != 0)
			{
				printf("\n");
			}
			printf("\t\t");
			for (k = 0; k < 45; k++)
			{
				printf("*");
			}
			if (i == 9)
			{
				goto end;
			}
		}
		if (i % 3 != 0)
		{
			system("color 1");
			printf("\n\t\t");
			printf("|\t\t\b|\t\t\b\b|\t\t\t\b\b\b\b|");
			printf("\n\t\t");
		}
		else
			printf("\n\t\t");
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
			{
				if (a[i][j] == 0)
				{
					system("color 1");
					printf("|");
					for (k = 0; k < 4; k++)
					{
						printf(" ");
					}
				}
				else
				{
					system("color 1");
					printf("| ", a[i][j]);
					fixed = z4.isfixed(icount, i, j);
					if (fixed == 1)
					{
						system("color 1");
					}
					else
					{
						system("color 1");
					}
					printf("%d  ", a[i][j]);
				}
			}
			else
			{
				if (a[i][j] == 0)
				{
					for (k = 0; k < 5; k++)
					{
						printf(" ");
					}
				}
				else
				{
					fixed = z4.isfixed(icount, i, j);
					if (fixed == 1)
					{
						system("color 1");
					}
					else
					{
						system("color 1");
					}
					printf("  %d  ", a[i][j]);
				}
			}
		}
		system("color 1");
		printf("\b|");
	}end:;
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);

}

void Read::readvalues()
{
	int i = icount, j, x, y, chek;
	system("cls");
	do
	{
		z5.display();
		printf("\n");
	row:
		printf("\n\nEnter row: ");
		scanf_s("%d", &r[i][0]);
		if (r[i][0] == 0)
		{
			r[i][0] = 100; r[i][1] = 100;
			break;
		}
		if (r[i][0] > 10 || r[i][0] < 0)
		{
			printf("\nInvalid size\nEnter again");
			r[i][0] = 20; r[i][1] = 20;
			getchar();
			goto row;
		}
	column:
		printf("Enter column: ");
		scanf_s("%d", &r[i][1]);
		if (r[i][1] == 0)
		{
			r[i][0] = 100; r[i][1] = 100;
			break;
		}
		if (r[i][1] < 0 || r[i][1]>10)
		{
			printf("\nInvalid size\nEnter again\n\n");
			r[i][0] = 20; r[i][1] = 20;
			getchar();
			goto column;
		}
		r[i][0] = r[i][0] - 1; r[i][1] = r[i][1] - 1;
		x = r[i][0]; y = r[i][1];
		if (solh == 'y' || solh == 'Y')
			for (j = 0; j < icount; j++)
			{
				if (x == r[j][0] && y == r[j][1])
				{
					printf("This location is fixed and cannot be changed");
					goto row;
				}
				else
					r[i][0] = 20; r[i][1] = 20;
			}
	scan:
		printf("Enter the corresponding number: ");
		scanf_s("%d", &a[x][y]);
		if (a[x][y] == 0)
		{
			for (j = 0; j < icount; j++)
			{
				if (x == r[j][0] && y == r[j][1])
				{
					r[j][0] = 20; r[j][1] = 20;
					goto end;
				}
				if (solh == 'y' || solh == 'Y')
				{
					r[i][0] = 20; r[i][1] = 20;
					goto end;
				}
			}
		}
		if (a[x][y] > 9 || a[x][y] <= 0)
		{
			printf("\nNumber out of range\nEnter again\n\n");
			a[x][y] = 0;
			goto scan;
		}
		else
		{
			chek = z4.check(x, y);
			if (chek == 0)
			{
				printf("\nInconsistent number\nEnter again");
				a[x][y] = 0; r[i][0] = 20; r[i][1] = 20;
				goto row;
			}
		}
		if (solh != 'y' && solh != 'Y')
		{
			icount++; i++;
		}
	end:
		system("cls");
	} while (r[i - 1][0] != -1 || r[i - 1][1] != -1);
}
