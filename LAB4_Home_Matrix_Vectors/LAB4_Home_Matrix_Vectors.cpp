// LAB4_Home_Matrix_Vectors.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

/*Лабораторная работа № 4*/

// Задачи: 
// 1) сложение матриц
// 2) сложение векторов 
// 3) умножение матриц 
// 4) умножение матрицы на вектор 
// 5) скалярное умножение векторов 
// 6) векторное умножение векторов 
// реализовать программно 

int main()
{
	int MATR_1[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } }; // объявляем матрицу №1

	int MATR_2[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } }; // объявляем матрицу №2

	int MATR_RESULT[3][3] = { { 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 } }; // обявляем итоговую матрицу, в которой будет записан ответ

	int VECTOR_1[1][3] = { 1,2,3 }; // объявляем вектор №1

	int VECTOR_2[1][3] = { 1, 2, 3 }; // объявляем вектор №2 


	int VECTOR_RESULT[1][3] = { 0, 0, 0 }; // объявляем итоговый вектор, в котором будет записан ответ

	int SCALAR_X = 0; // объявляем переменную, в которой будет записано скалярное произведение

	 // СЛОЖЕНИЕ МАТРИЦ (ЗАДАНИЕ №1) 

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
		MATR_RESULT[i][j] = MATR_1[i][j] + MATR_2[i][j]; // прописываем формулу сложения мматриц
}

}

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
	std::cout << MATR_RESULT[i][j] << "\t"; // вывод итоговой матрицы
}
	std::cout << std::endl;
}


	// СЛОЖЕНИЕ ВЕКТОРОВ (ЗАДАНИЕ №2) 

	for (int j = 0; j < 3; j++)
{
		VECTOR_RESULT[0][j] = VECTOR_1[0][j] + VECTOR_2[0][j];  // формула сложения векторов 
}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	std::cout << VECTOR_RESULT[0][i] << '\t'; // вывод итогового вектора 
}
	std::cout << std::endl;


	// УМНОЖЕНИЕ МАТРИЦ (ЗАДАНИЕ №3) 

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
		MATR_RESULT[i][j] = 0;
	for (int k = 0; k < 3; k++)
{
		MATR_RESULT[i][j] = MATR_RESULT[i][j] + MATR_1[i][k] * MATR_2[k][j]; // прописывем формулу умножения матриц 
}
}
}
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{

	std::cout << MATR_RESULT[i][j] << '\t'; // вывод итоговой матрицы 
}
	std::cout << std::endl;
}

	//	УМНОЖЕНИЕ МАТРИЦЫ НА ВЕКТОР (ЗАДАНИЕ №4)  

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++) {

		MATR_RESULT[i][j] = 0;

		MATR_RESULT[i][0] = MATR_RESULT[i][0] + MATR_1[i][j] *VECTOR_1[0][j]; // прописываем формулу умножения матрицы на вектор 
}
}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	std::cout << MATR_RESULT[i][0] << '\t' << std::endl; // вывод итоговой матрицы 
}

	// СКАЛЯРНОЕ УМНОЖЕНИЕ ВЕКТОРОВ (ЗАДАНИЕ №5) 


	for (int j = 0; j < 3; j++)
{

	SCALAR_X = VECTOR_1[1][j] * VECTOR_2[1][j]; // прописываем формулу скалярного умножения векторов 
}


	std::cout << std::endl;
	std::cout << SCALAR_X << std::endl; // вывод скалярного произведения 


     // ВЕКТОРНОЕ УМНОЖЕНИЕ ВЕКТОРОВ (ЗАДАНИЕ №6) 


   for (int i = 0; i < 3; i++) {
	if (i == 0) {
	for (int j = 0; j < 3; j++)
{
		MATR_RESULT[i][j] = 1;
}

}
	else 
{
	if (i == 1) 
{
	for (int j = 0; j < 3; j++) 
{
		MATR_RESULT[i][j] = VECTOR_1[0][j];
}
}
	else 
{
	for (int j = 0; j < 3; j++)
{
		MATR_RESULT[i][j] = VECTOR_2[0][j];
}
}
}
}

	for (int i = 0; i < 3; i++) 
{
	VECTOR_RESULT[0][i] = 0;
}

	std::cout << std::endl;

	VECTOR_RESULT[0][0] = MATR_RESULT[1][1] * MATR_RESULT[2][2] - MATR_RESULT[1][2] * MATR_RESULT[2][1];
	VECTOR_RESULT[0][1] = MATR_RESULT[1][0] * MATR_RESULT[2][2] - MATR_RESULT[1][2] * MATR_RESULT[2][0]; // прописываем формулу векторного умножения векторов 
	VECTOR_RESULT[0][2] = MATR_RESULT[1][0] * MATR_RESULT[2][1] - MATR_RESULT[1][1] * MATR_RESULT[2][0];

	std::cout << VECTOR_RESULT[0][0] << "\n";
	std::cout << VECTOR_RESULT[0][1] << "\n"; // вывод векторного произведения  
	std::cout << VECTOR_RESULT[0][2] << "\n";

	getchar();
    return 0;
}

