// LAB8_Home_Dinamic_Array.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>


/*ƒ»Ќјћ»„≈— »… ћј——»¬*/


using namespace std; //позвол€ет использовать имена из пространства имен std


void MATR_SUM(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A) //сложение двух матриц
{
	if (l1 == l5 && l2 == l6) //проверка на соответствие размерам (одинаковые) матриц
	{
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				A[i][j] = 0; //объ€вление итоговой матрицы
				A[i][j] = A1[i][j] + A2[i][j]; //прописываем формулу сложени€ мматриц
			}
		}
	}
	else
	{
		cout << "ERROR MATRICES_SUM" << endl; //вывод при неудачной попытке (матрицы разного размерј)
	}
}

void VECTOR_SUM(int **& B1, int g1, int **& B2, int g2, int **& B) //сложение двух векторов
{
	if (g1 == g2)
	{
		for (int i = 0; i < g1; i++)
		{
			B[0][i] = 0; //объ€вление итогового вектора
			B[0][i] = B1[0][i] + B2[0][i]; //прописываем формулу сложени€ векторов 
		}
	}
	else
	{
		cout << "ERROR VECTORS_SUM" << endl; //вывод при неудачной попытке
	}
}

void MATRIX_MULTIPLY(int **& A1, int l1, int l2, int **& A2, int l5, int l6, int **& A) //умножение матриц
{
	if (l1 == l6)
	{
		for (int i = 0; i < l1; i++)
		{
			for (int j = 0; j < l2; j++)
			{
				A[i][j] = 0; //обнъ€вление итоговой матрицы
				for (int k = 0; k < l2; k++)
					A[i][j] = A[i][j] + A1[i][k] * A2[k][j]; // прописывем формулу умножени€ матриц 
			}
		}
	}
	else
	{
		cout << "ERROR MATRICES_RESULT" << endl; //вывод при неудачной попытке
	}
}

void MATR_ON_VECTOR(int **& A1, int l1, int l2, int **& B1, int g1, int **& B) //умножение матрицы на вектор
{
	if (l2 == g1)
	{
		for (int i = 0; i < l2; i++)
		{
			B[0][i] = 0;
		}
		for (int i = 0; i < l2; i++)
		{
			for (int j = 0; j < g1; j++)
			{
				B[0][i] = B[0][i] + A1[i][j] * B1[0][j]; //прописываем формулу умножение матрицы на вектор
			}
		}
	}
	else
	{
		cout << "ERROR MATR_ON_VECTOR" << endl; //вывод при неудачной попытке
	}
}

void SCALAR_VECTOR(int **& B1, int g1, int **& B2, int g2, int & C) //скал€рное произведение двух векторов
{
	if (g2 == g1)
	{
		C = 0;

		for (int i = 0; i < 3; i++)
		{
			C = C + B1[0][i] * B2[0][i];
		}
	}
	else
	{
		cout << "ERROR SCALAR_VECTOR" << endl; //вывод при неудачной попытке
	}
}

void VECTOR_RESULT(int **& B1, int g1, int **& B2, int g2, int **& B) //векторное произведение двух векторов
{
	if (g1 != 3 || g2 != 3)
	{
		cout << "ERROR VECTOR_RESULT" << endl; //вывод при неудачной попытке
	}
	else {
		if (g1 == g2)
		{
			for (int i = 0; i < g1; i++)
			{
				B[0][i] = B1[0][(i + 1) % 3] * B2[0][(i + 2) % 3] - B1[0][(i + 2) % 3] * B2[0][(i + 2) % 3];

			}
		}
		else
		{
			cout << "ERROR VECTOR_RESULT" << endl; //вывод при неудачной попытке
		}
	}
}

void PRINT_MATR(int **A, int l1, int l2) //вывод итоговой матрицы
{
	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			std::cout << A[i][j] << " \t"; //вывод итоговой матрицы
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PRINT_VECTOR(int **B, int g1) //вывод итогового вектора
{
	for (int i = 0; i < g1; i++)
	{
		std::cout << B[0][i] << " \t"; // вывод итогового вектора
	}
	std::cout << std::endl;
}


int main()
{
	int l1;             //объ€вление всех переменных
	int l2;
	int l3;
	int l4;
	int l5;
	int l6;

	int g2;
	int g1;

	int C;

	cout << "Enter first matrix length " << endl;
	cin >> l3;
	l1 = l3;

	cout << "Enter first matrix width " << endl;
	cin >> l4;
	l2 = l4;

	cout << "Enter second matrix length " << endl;
	cin >> l5;

	cout << "Enter second matrix width " << endl;
	cin >> l6;

	cout << "Enter first vector length " << endl;
	cin >> g1;

	cout << "Enter second vector length " << endl;
	cin >> g2;

	int ** A1 = new int *[l1]; //перва€ матрица
	for (int i = 0; i < l1; i++)
	{
		A1[i] = new int[l2];
	}

	int ** A2 = new int *[l5]; //втора€ матрица
	for (int i = 0; i < l5; i++)
	{
		A2[i] = new int[l6];
	}
	int ** A = new int *[l3]; //матрица-ответ
	for (int i = 0; i < l3; i++)
	{
		A[i] = new int[l4];
	}
	int ** B1 = new int *[1]; //первый вектор
	for (int i = 0; i < 1; i++)
	{
		B1[i] = new int[g1];
	}
	int ** B2 = new int *[1]; //второй вектор
	for (int i = 0; i < 1; i++)
	{
		B2[i] = new int[g2];
	}
	int ** B = new int *[1]; //вектор-ответ
	for (int i = 0; i < 1; i++)
	{
		B[i] = new int[g1];
	}

	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			A1[i][j] = 2;
		}
	}
	for (int i = 0; i < l5; i++)
	{
		for (int j = 0; j < l6; j++)
		{
			A2[i][j] = 2;
		}
	}
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < g1; j++)
		{
			B1[i][j] = 2;
		}
	}
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < g2; j++)
		{
			B2[i][j] = 2;
		}
	}

	MATR_SUM(A1, l1, l2, A2, l5, l6, A);
	if (l1 == l5 && l2 == l6)
	{
		cout << "Summa matrix = " << std::endl;
		PRINT_MATR(A, l1, l2);
	}

	VECTOR_SUM(B1, g1, B2, g2, B);
	if (g1 == g2)
	{
		std::cout << "Summa vectorov = " << std::endl;
		PRINT_VECTOR(B, g1);
	}

	MATRIX_MULTIPLY(A1, l1, l2, A2, l5, l6, A);
	if (l1 == l5 && l2 == l6)
	{
		std::cout << "Proizvedenie matr = " << std::endl;
		PRINT_MATR(A, l1, l2);
	}

	MATR_ON_VECTOR(A1, l1, l2, B1, g1, B);
	if (l2 == g1)
	{
		std::cout << "Proizvedenie matr na vector = " << std::endl;
		PRINT_VECTOR(B, g1);
	}

	SCALAR_VECTOR(B1, g1, B2, g2, C);
	if (g1 == g2)
	{
		std::cout << '\n' << std::endl;
		std::cout << "Skalyarnoe proizvedenie = " << C << std::endl << std::endl;
	}

	VECTOR_RESULT(B1, g1, B2, g2, B);
	if (g1 == 3 && g2 == 3)
	{
		std::cout << "Vectornoe proizvedenie = " << std::endl;
		PRINT_VECTOR(B, g1);
	}

	for (int i = 0; i < l1; i++)
	{
		delete A[i];
	}
	delete[] A;
	for (int i = 0; i < l1; i++)
	{
		delete A1[i];
	}
	delete[] A1;
	for (int i = 0; i < l5; i++)
	{
		delete A2[i];
	}
	delete[] A2;
	for (int i = 0; i < g1; i++)
	{
		delete B[i];
	}
	delete[] B;
	for (int i = 0; i < g1; i++)
	{
		delete B1[i];
	}
	delete[] B1;
	for (int i = 0; i < g2; i++)
	{
		delete B2[i];
	}
	delete[] B2;


	system("pause");
	return 0;
}






