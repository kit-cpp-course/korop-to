#include "stdafx.h"
#include "Cheсking.h"
#include "DisplayReadElements.h"
#include "SudokuSolverGenerator.h"

int a[9][9], b[9][9], r[81][2];
int row, col, icount, mode;
char solh;

int main()
{
	Solve z;
	Generate z1;
	Read z2;
	Display z3;
	int i, j, error;
	char c;
	system("cls");
	printf("\n\n\n\n\t\tEnter '1' to GENERATE SuDoKu Puzzle\n\n\t\tEnter any other key to SOLVE SuDoKu\n\n\n\n\t\tEnter: ");
	scanf_s("%c", &c);
	system("cls");	
	printf("\n\n\t\t\tHOW TO ENTER ELEMENTS\n");
	printf("\n\n1.Enter the elements by specifying the row and column number of\n  corresponding location");
	printf("\n\n2.Each row and column start from 1 and end at 9 (not from 0 to 8)");
	printf("\n\n3.After finishing entering the elements, enter zeroes (0)\n  for row or column");
	printf("\n\n4.If an element entered in a wrong location has to be deleted,\n  enter zero in that location");
	printf("\n\n\n\n\t\t\t  Enter 'ENTER' to continue");
	getchar();
	if (c == '1')
	{		
		getchar();	
		z1.generate();
		if (solh == 'y' || solh == 'Y')			z2.readvalues();
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				a[i][j] = b[i][j];
			}
		}
		system("cls");
		z3.display();
		getchar();
		getchar();
		exit(0);
	}
read:
	icount = 0;
	row = 0; col = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < 81; i++)
	{
		r[i][0] = 20; r[i][1] = 20;
	}
	system("cls");
	printf("\n\nNow you can type some modificators you want to programme solve ");
	z2.readvalues();
	getchar();
	system("cls");
ask:
	z3.display();
	printf("\n\nEnter 'm' to MODIFY\nEnter 'r' to RE-ENTER\nEnter'ENTER' for SUDOKU Solution: ");
	scanf_s("%c", &c);
	if (c == 'r' || c == 'R')
	{
		system("cls");
		goto read;
	}
	if (c == 'm' || c == 'M')
	{
		printf("\n\n");
		z2.readvalues();
		system("cls");
		getchar();
		goto ask;
	}
next:
	error = z.solve();
	system("cls");
	z3.display();
	if (error == 0)		printf("\n\n\n\n\rNO SOLUTION or TOO MANY MODIFICATIONS");
	printf("\n\n\n\n\n\rEnter c to continue and any other key to exit: ");
	scanf_s("%c", &c);
	if (c == 'c' || c == 'C')
	{
		goto read;
	}
	getchar();
}
