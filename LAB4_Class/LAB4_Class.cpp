// LAB4_Class.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	int matrix1[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } }; // ���������� ������� (1)

	int matrix2[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } }; // ���������� ������� (2) 

	int matrix_result[3][3] = { { 0, 0, 0 },
	{ 0, 0, 0 },
	{ 0, 0, 0 } }; // ��������� �������������� ������� (� �� ����� ������� �����) 

	int vector1[1][3] = { 1,2,3 }; // ���������� ������� (1) 

	int vector2[1][3] = { 1, 2, 3 }; // ���������� ������� (2) 


	int vector_result[1][3] = { 0, 0, 0 }; // ���������� ��������������� ������� (� ���� ����� ������� �����) 

	int scalar_mult = 0; // ���������� ���������� (� ��� ����� ������� ����� ����������� ������������) 

	// �������� ������ (������� �1) 

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
	matrix_result[i][j] = matrix1[i][j] + matrix2[i][j]; // ������� �������� ������
}

}

   for (int i = 0; i < 3; i++)
{
   for (int j = 0; j < 3; j++)
{
	std::cout << matrix_result[i][j] << "\t"; // ����� �������������� �������
}
	std::cout << std::endl;
}


	// �������� �������� (������� �2) 

	for (int j = 0; j < 3; j++)
{
	vector_result[0][j] = vector1[0][j] + vector2[0][j];  // ������� �������� �������� 
}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	std::cout << vector_result[0][i] << '\t'; // ����� ��������������� ������� 
}
	std::cout << std::endl;


	// ��������� ������ (������� �3) 

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
	matrix_result[i][j] = 0;
	for (int k = 0; k < 3; k++)
{
	matrix_result[i][j] = matrix_result[i][j] + matrix1[i][k] * matrix2[k][j]; // ������� ��������� ������ 
}
}
}
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{

 std::cout << matrix_result[i][j] << '\t'; // ����� �������������� ������� 
}
		std::cout << std::endl;
}

	//	��������� ������� �� ������ (������� �4)  

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
	matrix_result[i][j] = 0;

 matrix_result[i][0] = matrix_result[i][0] + matrix1[i][j] * vector1[0][j]; // ������� ��������� ������� �� ������ 
}
}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
{
	std::cout << matrix_result[i][0] << '\t' << std::endl; // ����� �������������� ������� 
}

	// ��������� ��������� �������� (������� �5) 


	for (int j = 0; j < 3; j++)
{

	scalar_mult = vector1[1][j] * vector2[1][j]; // ������� ���������� ��������� �������� 
}


	std::cout << std::endl;
	std::cout << scalar_mult << std::endl; // ����� ���������� ������������ 
							
	// ��������� ��������� �������� (������� �6) 

	for (int i = 0; i < 3; i++) {
	if (i == 0) {
	for (int j = 0; j < 3; j++) {
	matrix_result[i][j] = 1;
}

}
	else {
	if (i == 1) 
{
	for (int j = 0; j < 3; j++) 
{
    matrix_result[i][j] = vector1[0][j];
}
}
	else 
{
	for (int j = 0; j < 3; j++) 
{
 matrix_result[i][j] = vector2[0][j];
}
}
}
}

	for (int i = 0; i < 3; i++) {
	vector_result[0][i] = 0;
}

	std::cout << std::endl;

	vector_result[0][0] = matrix_result[1][1] * matrix_result[2][2] - matrix_result[1][2] * matrix_result[2][1];
	vector_result[0][1] = matrix_result[1][0] * matrix_result[2][2] - matrix_result[1][2] * matrix_result[2][0]; // ������� ���������� ��������� �������� 
	vector_result[0][2] = matrix_result[1][0] * matrix_result[2][1] - matrix_result[1][1] * matrix_result[2][0];

	std::cout << vector_result[0][0] << "\n";
	std::cout << vector_result[0][1] << "\n"; // ����� ���������� ������������  
	std::cout << vector_result[0][2] << "\n";

	getchar();
    return 0;
}

