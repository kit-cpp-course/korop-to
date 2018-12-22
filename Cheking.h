#pragma once
#include "stdafx.h"


class Cheking
{
public:
	int checkmat(int m, int n);

	/*CHEKING ROW FOR MATCHES*/
	int checkrow(int m, int n);

	/*CHEKING COLUMN FOR MATCHES*/
	int checkcolumn(int m, int n);

	/*FUNCTION TO CHECK CONSISTENCY OF AN ELEMENT*/
	int check(int m, int n);
	
	/*CHEAKING THE NUMBER HAS BEEN ALREADY FIXED IN THE TABLE*/
	int isfixed(int count, int m, int n);
};
