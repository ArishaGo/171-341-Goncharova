#pragma once
class Matrix
{
private:
	int l1;
	int l2;

public:
	int ** A;
	int ll1;
	int ll2;
	Matrix();
	Matrix(int l1, int l2);
	Matrix(int **A, int l3, int l4);
	Matrix MULTIPLY(Matrix obj1, Matrix obj2);
	Matrix SUM(Matrix obj1, Matrix obj2);
	Matrix SUBSTRACTION(Matrix obj1, Matrix obj2);
	void vyvod(Matrix obj3);

	~Matrix();
};
