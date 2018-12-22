#include "Cheking.h"

extern int a[9][9], b[9][9], r[60][2];
extern int row, col, icount, mode;
extern char solh;

int Cheking::checkmat(int m, int n)
{
	int x, y;
	for (x = (m / 3) * 3; x < ((m / 3) * 3 + 3); x++)
		for (y = (n / 3) * 3; y < ((n / 3) * 3 + 3); y++)
		{
			if (m != x && n != y)
				if (a[m][n] == a[x][y])
					return(0);
		}
	return(1);
}

int Cheking::checkrow(int m, int n)
{
	int x;
	for (x = 0; x < 9; x++)
	{
		if (x != n)
			if (a[m][n] == a[m][x])
				return(0);
	}
	return(1);
}

int Cheking::checkcolumn(int m, int n)
{
	int x;
	for (x = 0; x < 9; x++)
	{
		if (x != m)
			if (a[m][n] == a[x][n])
				return(0);
	}
	return(1);
}

int Cheking::check(int m, int n)
{
	int c;
	c = checkmat(m, n);
	if (c == 1)
		c = c * checkrow(m, n);
	else
		return(c);
	if (c == 1)
		c = c * checkcolumn(m, n);
	else
		return(c);
	return(c);
}

int Cheking::isfixed(int count, int m, int n)
{
	int i;
	for (i = 0; i < count; i++)
		if (m == r[i][0] && n == r[i][1])
			return(1);
	return(0);
}
