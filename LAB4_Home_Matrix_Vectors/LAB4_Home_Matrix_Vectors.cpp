// LAB4_Home_Matrix_Vectors.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

/*������������ ������ � 4*/

// ������: 
// 1) �������� ������
// 2) �������� �������� 
// 3) ��������� ������ 
// 4) ��������� ������� �� ������ 
// 5) ��������� ��������� �������� 
// 6) ��������� ��������� �������� 
// ����������� ���������� 

int main()
{
	int MATR_1[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } }; // ��������� ������� �1

	int MATR_2[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } }; // ��������� ������� �2

	int MATR_RESULT[3][3] = { { 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 } }; // �������� �������� �������, � ������� ����� ������� �����

	int VECTOR_1[1][3] = { 1,2,3 }; // ��������� ������ �1

	int VECTOR_2[1][3] = { 1, 2, 3 }; // ��������� ������ �2 


	int VECTOR_RESULT[1][3] = { 0, 0, 0 }; // ��������� �������� ������, � ������� ����� ������� �����

	int SCALAR_X = 0; // ��������� ����������, � ������� ����� �������� ��������� ������������

	 // �������� ������ (������� �1) 

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
		MATR_RESULT[i][j] = MATR_1[i][j] + MATR_2[i][j]; // ����������� ������� �������� �������
}

}

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
	std::cout << MATR_RESULT[i][j] << "\t"; // ����� �������� �������
}
	std::cout << std::endl;
}


	// �������� �������� (������� �2) 

	for (int j = 0; j < 3; j++)
{
		VECTOR_RESULT[0][j] = VECTOR_1[0][j] + VECTOR_2[0][j];  // ������� �������� �������� 
}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	std::cout << VECTOR_RESULT[0][i] << '\t'; // ����� ��������� ������� 
}
	std::cout << std::endl;


	// ��������� ������ (������� �3) 

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
		MATR_RESULT[i][j] = 0;
	for (int k = 0; k < 3; k++)
{
		MATR_RESULT[i][j] = MATR_RESULT[i][j] + MATR_1[i][k] * MATR_2[k][j]; // ���������� ������� ��������� ������ 
}
}
}
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{

	std::cout << MATR_RESULT[i][j] << '\t'; // ����� �������� ������� 
}
	std::cout << std::endl;
}

	//	��������� ������� �� ������ (������� �4)  

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++) {

		MATR_RESULT[i][j] = 0;

		MATR_RESULT[i][0] = MATR_RESULT[i][0] + MATR_1[i][j] *VECTOR_1[0][j]; // ����������� ������� ��������� ������� �� ������ 
}
}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	std::cout << MATR_RESULT[i][0] << '\t' << std::endl; // ����� �������� ������� 
}

	// ��������� ��������� �������� (������� �5) 


	for (int j = 0; j < 3; j++)
{

	SCALAR_X = VECTOR_1[1][j] * VECTOR_2[1][j]; // ����������� ������� ���������� ��������� �������� 
}


	std::cout << std::endl;
	std::cout << SCALAR_X << std::endl; // ����� ���������� ������������ 


     // ��������� ��������� �������� (������� �6) 


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
	VECTOR_RESULT[0][1] = MATR_RESULT[1][0] * MATR_RESULT[2][2] - MATR_RESULT[1][2] * MATR_RESULT[2][0]; // ����������� ������� ���������� ��������� �������� 
	VECTOR_RESULT[0][2] = MATR_RESULT[1][0] * MATR_RESULT[2][1] - MATR_RESULT[1][1] * MATR_RESULT[2][0];

	std::cout << VECTOR_RESULT[0][0] << "\n";
	std::cout << VECTOR_RESULT[0][1] << "\n"; // ����� ���������� ������������  
	std::cout << VECTOR_RESULT[0][2] << "\n";

	getchar();
    return 0;
}

