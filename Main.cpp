#include "stdafx.h"
#include "Cheking.h"
#include "DisplayReadElements.h"
#include "SudokuSolverGenerator.h"


int a[9][9], b[9][9], r[60][2];
int row, col, icount, mode;
char solh;



int main()
{
	SolveGenerate z;
	DisplayAndRead z1;
	int i, j, error;
	char c;
	system("cls");
	printf("\n\n\n\n\t\tEnter '1' to GENERATE SuDoKu Puzzle\n\n\t\tEnter any other key to SOLVE SuDoKu\n\n\n\n\t\tEnter: ");
	scanf("%c", &c);
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
		z.generate();
		if (solh == 'y' || solh == 'Y')
			z1.readvalues();
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				a[i][j] = b[i][j];
		system("cls");
		z1.display();
		getchar();
		getchar();
		exit(0);
	}
read:
	icount = 0;
	row = 0; col = 0;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			a[i][j] = 0;
	for (i = 0; i < 60; i++)
	{
		r[i][0] = 20; r[i][1] = 20;
	}
	system("cls");
	printf("\n\nNow you can type some modificators you want to programme solve ");
	z1.readvalues();
	getchar();
	system("cls");
ask:
	z1.display();
	printf("\n\nEnter 'm' to MODIFY\nEnter 'r' to RE-ENTER\nEnter any other key for SUDOKU Solution: ");
	scanf("%c", &c);
	if (c == 'r' || c == 'R')
	{
		system("cls");
		goto read;
	}
	if (c == 'm' || c == 'M')
	{
		printf("\n\n");
		z1.readvalues();
		system("cls");
		getchar();
		goto ask;
	}
next:
	error = z.solve();
	system("cls");
	z1.display();
	if (error == 0)
		printf("\n\n\n\n\rNO SOLUTION or TOO MANY MODIFICATIONS");
	printf("\n\n\n\n\n\rEnter z to continue and any other key to exit: ");
	scanf("%c", &c);
	if (c == 'c' || c == 'C')
	{
		goto read;
	}
	getchar();
}