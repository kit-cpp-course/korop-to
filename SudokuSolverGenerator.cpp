#include "SudokuSolverGenerator.h"
#include "Cheсking.h"
#include "DisplayReadElements.h"


Cheсking z6;
Solve z7;
Display z8;
extern int a[9][9], b[9][9], r[81][2];
extern int row, col, icount, mode;
extern char solh;

int  m = 0, n = 0, number = 0, c = 0, fixed = 0;
int v, i, z, x, count = 1, fix, error;
char choice;

int Solve::solve()
{
	mainallot();
	backadjust();
	return(1);
}

void Generate::generate()
{
	gen();
	allot();
}

int Solve::mainallot()
{
	for (m = row; m < 9; m++)
	{
		n = col;
		while (n < 9)
		{
			number = 1;
			fixed = z6.isfixed(icount, m, n);
			if (fixed == 0)
			{
			allot:
				a[m][n] = number;
				c = z6.check(m, n);
				if (c == 0)
				{
					number++;
					if (number > 9)
					{
						a[m][n] = 0;
						if (n == 0)
						{
							row = m - 1; col = 8;
							if (row < 0)								return(0);
							backadjust();
						}
						else
						{
							row = m; col = n - 1;
							if (row < 0 || col < 0)								return(0);
							backadjust();
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
}
int Solve::backadjust()
{
	fixed = z6.isfixed(icount, row, col);
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
				if (row < 0)					return(0);
				backadjust();
			}
			else
			{
				col--;
				if (col < 0)					return(0);
				backadjust();
			}
		}
		c = z6.check(row, col);
		if (c == 0)
			goto allot1;
		else
		{
			if (col == 8)
			{
				row++;
				if (row > 8)					return(0);
				col = 0;
				mainallot();
			}
			else
			{
				col++;
				if (col > 8)					return(0);
				mainallot();
			}
		}
	}
	else
	{
		if (col == 0)
		{
			row--; col = 8;
			if (row < 0)				return(0);
			backadjust();
		}
		else
		{
			col--;
			if (col < 0)				return(0);
			backadjust();
		}
	}
	return(1);
}
void Generate::gen()
{
generate:
	for (z = 0; z < 9; z++)
	{
		for (x = 0; x < 9;x++)
		{
			a[z][x] = 0;
		}
	}
	for (i = 0; i < 81; i++)
	{
		r[i][0] = 20; r[i][1] = 20;
	}
	system("cls");
	printf("\n\n\n\n\t\tEnter your choice of difficulty");
	printf("\n\n\n\t\t1.VERY EASY\n\n\t\t2.EASY\n\n\t\t3.MEDIUM\n\n\t\t4.HARD\n\n\n\t\tENTER: ");
	scanf_s("%c", &choice);
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
}
void Generate::allot()
{
	for (count = 1; count < 10; count++)
	{
	choose:
		z = rand() % 9; x = rand() % 9;
		fixed = z6.isfixed(icount, z, x);
		if (fixed == 1)			goto choose;
		r[count][0] = z; r[count][1] = x;
	allot:
		a[m][n] = 1 + rand() % 9;
		if (a[z][x] == 0)			goto allot;
		v = z6.check(m, n);
		if (v == 0)			goto allot;
	}
	icount = count;
	error = z7.solve();
	for (z = 0; z < 9; z++)
	{
		for (x = 0; x < 9; x++)
		{
			b[z][x] = a[z][x];
		}
	}
	row = 0; col = 0;
	for (i = 0; i < 81; i++)
	{
		r[i][0] = 20; r[i][1] = 20;
		if (error == 0)			gen();
		for (count = 0; count < mode / 2; count++)
		{
		choose2:
			z = rand() % 9; x = rand() % 5;
			fixed = z6.isfixed(count, z, x);
			if (fixed == 1)				goto choose2;
			r[count][0] = z; r[count][1] = x;
			r[count + mode / 2][0] = 8 - z;
			r[count + mode / 2][1] = 8 - x;
		}
		for (z = 0; z < 9; z++)
		{
			for (x = 0; x < 9; x++)
			{
				fixed = z6.isfixed(mode, z, x);
				if (fixed != 1)
					a[z][x] = 0;
			}
		}
		icount = mode;
		system("cls");
		z8.display();
		getchar();
		printf("\n\n\nEnter 'y' to solve by yourself\nEnter 's' for solution\nEnter 'm' to generate more sudoku puzzles");
		printf("\nAnd any other key to exit: ");
		scanf_s("%c", &solh);
		if (solh == 'y' || solh == 'Y' || solh == 's' || solh == 'S')			return;
		getchar();
		if (solh == 'm' || solh == 'M')			gen();
		exit(0);
	}
}
