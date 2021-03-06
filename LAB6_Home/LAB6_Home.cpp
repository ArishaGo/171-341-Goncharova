// LAB6_Home.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream> 

//������������ ������ � 6

 // ������: 
// 1) �������� ������
// 2) �������� �������� 
// 3) ��������� ������ 
// 4) ��������� ������� �� ������  
// 5) ��������� ��������� �������� 
// 6) ��������� ��������� �������� 
// 7) ����� ������� � ������� ������� 
// ����������� ���������� 

int MATR_1[3][3] = { { 1, 2, 3 },
{ 4, 5, 6 },  // ��������� ������� �1
{ 7, 8, 9 } };

int MATR_2[3][3] = { { 1, 2, 3 },
{ 4, 5, 6 },  // ��������� ������� �2
{ 7, 8, 9 } };


int MATR_RESULT[3][3] = { { 0, 0, 0 },
{ 0, 0, 0 },  //�������� �������� �������, � ������� ����� ������� �����
{ 0, 0, 0 } };

int VECTOR_1[1][3] = { 1, 2, 3 }; // ��������� ������ �1

int VECTOR_2[1][3] = { 1, 2, 3 }; // ��������� ������ �2


int VECTOR_RESULT[1][3] = { 0, 0, 0 }; // ��������� �������� ������

int SCALAR_X = 0; // ���������� ����������, � ������� ����� �������� ��������� ������������

void MATR_SUM(int(&MATR_RESULT)[3][3], int const MATR_1[3][3], int const MATR_2[3][3]) // �������, ��������� ����� ������
{
	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
		MATR_RESULT[i][j] = MATR_1[i][j] + MATR_2[i][j]; // ����������� ������� �������� ������
}

}
}
void VECTOR_SUM(int(&VECTOR_RESULT)[1][3], int const VECTOR_1[1][3], int const VECTOR_2[1][3]) // �������, ��������� ����� �������� 
{
	for (int i = 0; i < 3; i++)
{
		VECTOR_RESULT[0][i] = 0;
		VECTOR_RESULT[0][i] = VECTOR_1[0][i] + VECTOR_2[0][i];  //����������� ������� �������� �������� 
}
}

void MATR_X(int(&MATR_RESULT)[3][3], int const MATR_1[3][3], int const MATR_2[3][3]) // ������, �������� ��� ��������� ������ 
{

    for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
		MATR_RESULT[i][j] = 0;
	for (int k = 0; k < 3; k++)
{
		MATR_RESULT[i][j] = MATR_RESULT[i][j] + MATR_1[i][k] * MATR_2[k][j]; // �������� ������� ��� ��������� ������ 
}
}
}
}

void MATR_X_VECTOR(int(&VECTOR_RESULT)[1][3], int const (*MATR_1)[3], int const VECTOR_1[1][3]) // ������� ��� ��������� ������� �� ������ 
{

	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++) {
	VECTOR_RESULT[i][j] = 0;
}
}
	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
		VECTOR_RESULT[0][i] = VECTOR_RESULT[0][i] + MATR_1[i][j] * VECTOR_1[0][j]; //�������� ������� ��������� ������� �� ������ 
}
}
}

void SCALAR_X_VECTOR(int(&SCALAR_X), int VECTOR_1[1][3], int VECTOR_2[1][3]) // ������� ��� ���������� ��������� �������� 
{
	for (int j = 0; j < 3; j++)
{
		SCALAR_X = SCALAR_X + VECTOR_1[0][j] * VECTOR_2[0][j]; //�������� ������� ��� ���������� ��������� �������� 
}
}

void VECTOR_X_VECTOR(int(&VECTOR_RESULT)[1][3], int const VECTOR_1[1][3], int const VECTOR_2[1][3]) // ������� ��� ���������� �������� �������� 
{
   for (int i = 0; i < 3; i++) {	// ��������� ��������� �������� 
	if (i == 0) {
	for (int j = 0; j < 3; j++) {
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

	for (int i = 0; i < 3; i++) {
		VECTOR_RESULT[0][i] = 0;
}
	for (int i = 2; i > -1; i--)
{
	(i == 0) ?
	(VECTOR_RESULT[0][i] = MATR_RESULT[1][(i + 1) / 3] * MATR_RESULT[2][i + 1] - MATR_RESULT[1][i + 1] * MATR_RESULT[2][(i + 1) / 3])
			:
	(VECTOR_RESULT[0][i] = MATR_RESULT[1][(i + 1) / 3] * MATR_RESULT[2][2] - MATR_RESULT[1][2] * MATR_RESULT[2][(i + 1) / 3]);
}

}


void vivodMATR(int MATR_RESULT[3][3]) // ������� ��� ������ �������� ������� 
{
	for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
{
	std::cout << MATR_RESULT[i][j] << "\t"; // ����� �������� ������� 
}
	std::cout << std::endl;
}
	std::cout << std::endl;
}


void vivodVECTOR(int VECTOR_RESULT[1][3]) // ������� ��� ������ ��������� ������� 
{
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
{
	std::cout << VECTOR_RESULT[0][i] << '\t'; // ����� ��������� ������� 
}
	std::cout << std::endl;
	std::cout << std::endl;
}
int main()
{
	MATR_SUM(MATR_RESULT, MATR_1, MATR_2); // ����� ������� ��� ����� ������ 
	vivodMATR(MATR_RESULT); // ����� ������� ��� ������ �������� 

	VECTOR_SUM(VECTOR_RESULT, VECTOR_1,VECTOR_2);  // ����� ������� ��� ����� �������� 
	vivodVECTOR( VECTOR_RESULT); // ����� ������� ��� ������ ��������� �������  


	MATR_X(MATR_RESULT, MATR_1,MATR_2); // ����� ������� ��� ������������ ������ 
	vivodMATR(MATR_RESULT); // ����� ������� ��� ������ ��������� ������� 


	MATR_X_VECTOR(VECTOR_RESULT, MATR_1, VECTOR_1); // ����� ������� ��� ������������ ������� �� ������ 
	vivodVECTOR(VECTOR_RESULT); // ����� ������� ��� ������ ��������� ������� 


	SCALAR_X_VECTOR(SCALAR_X, VECTOR_1, VECTOR_2); // ����� ������� ��� ���������� ������������ �������� 
	std::cout << SCALAR_X << std::endl; // ����� ������� ��� ������ ���������� ������������ 



	VECTOR_X_VECTOR(VECTOR_RESULT, VECTOR_1, VECTOR_2); // ����� ������� ��� ���������� ������������ �������� 
	vivodVECTOR(VECTOR_RESULT); // ����� ������� ��� ������ ��������������� ������� 

	getchar();
    return 0;
}

// GIT - ��� ������� ���������� �������� ������.��������� ������������ �� ���� ���������� ���������� �� ����� �������� ������.���������: 
// 1. ��������� ������ �������� ��������� ������ (������)
// 2. ������������ � ���������� �������, ������� ������ ������ 
// 3. ��������� �������� � ��������� ���������� (������������) 
// 4. �������� ������� ��������� ��������� ������ 
// GIT � ������ ������� ������� �� ����������� ������ � �� ����������������� ���������� ������� (�� �������) 
// � ���� ������ GIT ��������� ���������, ���������� �������� ������� � ���������� ������ ������ �� ��������� ����� ��� �������� 
// � ��������� ���������, �������� ������������ � ����� ������ 
// ��� ������������ �������� ��������� ������������ ��� �������� ��������� ������ 

/*
������ ������ � GIT

1) ������ ������ - ������������� �����������:

CD <����� *.sln �������>
git init

cd: - change directory (�� ������� ����)

������� ����� ������� ���������� master

���������� ������� ����� .git, ��� � ����� �������� ������� ��������� � ���������

2) �� ��������� git ����� ����������� ������� ������ ���� � ���������� ������������:
txt, cpp, h, hpp, hxx, c
py, xml, html
������ � ����������� ����� ��������� �������� � ����� �������� � �������
������� git ��� �� ���������
��� ����� ����� ��������������� ��������

git add <���_�����>

��������� �������� ���� ����� � ����������� 1 ���
������������� �� ������� ��������� ����������� �����,
��������� � ������������� ������������ �����:
*.exe, *.lib, *.dll, *.pch, *.ipch, *.db, *.pdb � ��.
�� ������� ��������� ������� ����� /x86, /x64, /release, /debug.

3) ������������� ������ (������) ������ ������

git commit -m"����������� � ������"

���� ����������� ������ ����������.

4) ��� ������������� � �������� ������������
�����
-����������� ��������� � ���������
-��������� ����� ���������

git remote add <�������_���������> <������>

5) � ����� ������ ����� ���������� ������ ����������� �����

git status

6) �������� ������� �� ����� �������

git <���_�������> --help

7) ����� �������������� ����� �����:

1. git add <����� ���>
2. !!! � ��������� �������, ����� git status ����� missing: <������_���_�����>
git delete -cached <������_���_�����>

8) ��� ��������� ����������� ������� ����� ����������� TortoiseGit -
���������� ���������� Windoes, ����������� ����������� ������� ��� ���������� �������������


9) ��������� ����� ���˨����� ����������� ��������  GIT CLONE � http:// ...
1) � ������ ���� -  GIT CLONE
2) � ���� ������������ ������ � �����
3) ����� ������ �������� ��������� git commit � ������� �� ��������� git push
*/

