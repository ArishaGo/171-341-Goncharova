// LAB11_Home_Classes_Matrix_Vectors1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h" 
#include "Vectors.h"

using namespace std;


Matrix operator + (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);
	return result.SUM(lhs, rhs);
}

Matrix operator - (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);

	return result.SUBSTRACTION(lhs, rhs);

}

Matrix operator * (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);

	return result.MULTIPLY(lhs, rhs);
}

ostream & operator << (ostream & os,
	Matrix & rhs)
{
	rhs.vyvod(rhs);
	return os;
}

int main()
{
	Matrix obj1;
	Matrix obj2;

	for (int i = 0; i < obj1.ll1; i++)
	{
		for (int j = 0; j < obj1.ll2; j++)
		{
			obj1.A[i][j] = 2;
		}
	}
	for (int i = 0; i < obj2.ll1; i++)
	{
		for (int j = 0; j < obj2.ll2; j++)
		{
			obj2.A[i][j] = 4;
		}
	}
	cout << "MULTIPLY" << (obj1 * obj2);
	cout << "SUM" << (obj1 + obj2);
	cout << "SUBSTRACTION" << (obj1 - obj2);
	system("pause");
    return 0;
}

