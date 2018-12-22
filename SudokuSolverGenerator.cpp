#include "SudokuSolverGenerator.h"
#include "Cheking.h"
#include "DisplayReadElements.h"


Cheking x2;
DisplayAndRead y1;
extern int a[9][9], b[9][9], r[60][2];
extern int row, col, icount, mode;
extern char solh;

int SolveGenerate::solve()
{	
	int  m = 0, n = 0, number, c, fixed;

mainallot:

	for (m = row; m < 9; m++)
	{
		n = col;
		while (n < 9)
		{
			number = 1;
			fixed = x2.isfixed(icount, m, n);
			if (fixed == 0)
			{
			allot:
				a[m][n] = number;
				c = x2.check(m, n);
				if (c == 0)
				{
					number++;
					if (number > 9)
					{
						a[m][n] = 0;
						if (n == 0)
						{
							row = m - 1; col = 8;
							if (row < 0)
								return(0);
							goto backadjust;
						}
						else
						{
							row = m; col = n - 1;
							if (row < 0 || col < 0)
								return(0);
							goto backadjust;
						}
					}
					goto allot;
				}
			}
			n++;
			if (n > 8)
				col = 0;
		}
	}
	return(1);

backadjust:

	fixed = x2.isfixed(icount, row, col);
	if (fixed == 0)
	{
		number = a[row][col];
	allot1:
		number++;
		a[row][col] = number;
		if (number > 9)
		{
			a[row][col] = 0;
			if (col == 0)
			{
				row--; col = 8;
				if (row < 0)
					return(0);
				goto backadjust;
			}
			else
			{
				col--;
				if (col < 0)
					return(0);
				goto backadjust;
			}
		}
		c = x2.check(row, col);
		if (c == 0)
			goto allot1;
		else
		{
			if (col == 8)
			{
				row++;
				if (row > 8)
					return(0);
				col = 0;
				goto mainallot;
			}
			else
			{
				col++;
				if (col > 8)
					return(0);
				goto mainallot;
			}
		}
	}
	else
	{
		if (col == 0)
		{
			row--; col = 8;
			if (row < 0)
				return(0);
			goto backadjust;
		}
		else
		{
			col--;
			if (col < 0)
				return(0);
			goto backadjust;
		}
	}
}

void SolveGenerate::generate()
{	
	int c, i, m, n, count = 1, fixed, error;
	char choice;
	srand(time(0));
generate:
	for (m = 0; m < 9; m++)
		for (n = 0; n < 9; n++)
			a[m][n] = 0;
	for (i = 0; i < 60; i++)
	{
		r[i][0] = 20; r[i][1] = 20;
	}
	system("cls");
	printf("\n\n\n\n\t\tEnter your choice of difficulty");
	printf("\n\n\n\t\t1.VERY EASY\n\n\t\t2.EASY\n\n\t\t3.MEDIUM\n\n\t\t4.HARD\n\n\n\t\tENTER: ");
	scanf("%c", &choice);
	switch (choice)
	{
	case '1': mode = 34 + rand() % 4;
		break;
	case '2': mode = 29 + rand() % 4;
		break;
	case '3': mode = 27 + rand() % 2;
		break;
	case '4': mode = 25 + rand() % 2;
		break;
	default: getchar();
		goto generate;
	}
	a[0][0] = 1 + rand() % 8; r[0][0] = 0; r[0][1] = 0;
	for (count = 1; count < 10; count++)
	{
	choose:
		m = rand() % 9; n = rand() % 9;
		fixed = x2.isfixed(icount, m, n);
		if (fixed == 1)
			goto choose;
		r[count][0] = m; r[count][1] = n;
	allot:
		a[m][n] = 1 + rand() % 9;
		if (a[m][n] == 0)
			goto allot;
		c = x2.check(m, n);
		if (c == 0)
			goto allot;
	}
	icount = count;
	error = solve();
	for (m = 0; m < 9; m++)
		for (n = 0; n < 9; n++)
			b[m][n] = a[m][n];
	row = 0; col = 0;
	for (i = 0; i < 60; i++)
	{
		r[i][0] = 20; r[i][1] = 20;
	}
	if (error == 0)
		goto generate;
	for (count = 0; count < mode / 2; count++)
	{
	choose2:
		m = rand() % 9; n = rand() % 5;
		fixed = x2.isfixed(count, m, n);
		if (fixed == 1)
			goto choose2;
		r[count][0] = m; r[count][1] = n;
		r[count + mode / 2][0] = 8 - m;
		r[count + mode / 2][1] = 8 - n;
	}
	for (m = 0; m < 9; m++)
		for (n = 0; n < 9; n++)
		{
			fixed = x2.isfixed(mode, m, n);
			if (fixed != 1)
				a[m][n] = 0;
		}
	icount = mode;
	system("cls");
	y1.display();
	getchar();
	printf("\n\n\nEnter 'y' to solve by yourself\nEnter 's' for solution\nEnter 'm' to generate more sudoku puzzles");
	printf("\nAnd any other key to exit: ");
	scanf("%c", &solh);
	if (solh == 'y' || solh == 'Y' || solh == 's' || solh == 'S')
		return;
	getchar();
	if (solh == 'm' || solh == 'M')
		goto generate;
	exit(0);
}