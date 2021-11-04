/*********************************************************************
** Program name: Lab1
** Filename: determinant.cpp
** Author: Justin Hammel
** Date: 4/10/2017
** Description: This function receives a 2x2 or 3x3 pointer of arrays
**				and the size of the array, either 2, or 3. The 
**				determinant of the matrix is then calculated and 
**				returned as an int value.
*********************************************************************/

#include "determinant.hpp"

int determinant(int** matrix, int size)
{
	int deterValue = 0;

	if (size == 2)
	{
		//parts corespond to equation from mathisfun.com
		//|A| = ad - bc
		int ad, bc = 0;
		ad = (matrix[0][0] * matrix[1][1]);
		bc = (matrix[0][1] * matrix[1][0]);
		deterValue = ad - bc;
	}

	if (size == 3)
	{
		//parts corespond to equation from mathisfun.com
		//|A| = a(ei - fh) - b(di - fg) + c(dh - eg)
		int ei, fh, di, fg, dh, eg = 0;
		ei = (matrix[1][1] * matrix[2][2]);
		fh = (matrix[1][2] * matrix[2][1]);
		di = (matrix[1][0] * matrix[2][2]);
		fg = (matrix[1][2] * matrix[2][0]);
		dh = (matrix[1][0] * matrix[2][1]);
		eg = (matrix[1][1] * matrix[2][0]);
		//these are the three main blocks of the equation
		int first, second, third = 0;
		first = matrix[0][0] * (ei - fh);
		second = matrix[0][1] * (di - fg);
		third = matrix[0][2] * (dh - eg);
		deterValue = first - second + third;
	}

	return deterValue;
}
