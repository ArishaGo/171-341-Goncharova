// LAB7_Class.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream> 


//��� ���������� ������� ��������� ������ ������� ���������� � �������� ������ (stak overflow) 
//�������� ������ ����������, ��� ������������ ������������� ���� ������������� 
// ����������� ��������, ���������� � �������� ������, ����������� � �������� �����������

using namespace std;

void fnc1() // ������� ��� ������������ ����� 
{
	int b[1000][1000] = { 0 };
	b[1][1] = 0;
	cout << "Stack overflow" << endl;
	return;
}

int main()
{
	int l1 = 10, l2 = 15;
	// int arr[l1][l2] = { 0 }; - � ����� ���������� ������ ��������� 

	// �������� ������ ����������, ��� ������������ ������������� ���� ������������� (stack overflow) 
	// ����������� ��������, ���������� � �������� ������, ����������� � �������� ����������� 
	// int b[1000][1000] = { 0 }; - �������� ������������ ����� 

	// ��� ������������� ��������� ���������������� ������ �� (heap - "����") 
	// ����������� ������������ ����������� �� ���������� 
	// ���������_��_��� ���_���������� = new ���; 
	// ��� 
	// ��� * ���_���������� = new ���; 
	// ������ � ������������ ������� ���������� ����� ��������� 

	// ������������ 
	// 1) �������� ������� ������ ������, ������� ����� 
	// 2) ������ �������� � �������� ������ ����� ���������� � ������ �� ����� ������ ���������� 
	// �����������: 
	// ���� ��������� ������������� ��� ���������� ������, 
	// �� ��������� ������������ ������ ��������� ��������� � ����� ������ ����� ������������� 
	// ������ ���� ����������� � ������� ��������� delete: 
	// delete ���_����������; 

	int * ptr_int = new int; // � ���������������� ������ ��������� ����, 
							 // �������� � int � ��������� �� ���� ������������ � ���������� 

							 // ����� ������ ������ 
	for (int i = 0; i < 10000; i++)
{

		// 1) ������ ����� � ����� ��������� ����� ��������� 
		// 2)���������� ���� new long long;  � ���� (���������������� ������), ����������� � ���� ��������� 
		// 3) �������� ��������� b �������� 
		// 4) � ���� ���������� �������� ��� �� 
		// 5) ��� ��������� ������ ���������� ����� ���� 

	long long * b = new long long;

		//��������� ������ �������� � ���������� 
	delete b; // ������� ���� ������, ���� �� ������� ��������� �� �� 
}

	// ���� ���������� new/delete - ��� ���� �� ������������ C++ ������������ � 

	// � ������������ ������ ����� ���������� ������ ���������� ������� 
	// ��� * ���_��������� = new ��� [������]; 
	// ��������� ��������� ������� � ������� ������ 
	// delete[] ���_���������; 

	for (int i = 0; i < l1; i++)
{
		// ��� ��������� ���������� ������� ������� ��������� ���������� ������, ���������� ��������� �� ������ ������� (������) 

		// ����� �������� ����������� ����������� 

	int ** dynamic2Darray = new int *[l1];
		// ����� ���������� ���� ������ ��� ������ ������ � ��������� �� �� ������������ � ���������� ������ ���������� 
	for (int i = 0; i < l1; i++)
{
	dynamic2Darray[i] = new int[l2]; // dynamic2Darray[i] ����� ��� int* 
	for (int j = 0; j < l2; j++)
{
	dynamic2Darray[i][j] = i;
}
}

		// ������������� ������ � �������� ������� 

	for (int i = 0; i < l1; i++)
{
	delete[] dynamic2Darray[i]; // dynamic2Darray[i] ����� ��� int* 
}
	delete[] dynamic2Darray;
}

	// ����������� ������� ������������� ����� � �������� ������ ���� ����� ����������� �������� ������ 
	// ������������ - ��� (��� �� �������� ����� ��� ��������� ������, ��� ��� � ����� ����������, 
	// � ����� �������� ����� ����������, ���) 

	int fixed_array[3][3] = { { 10, 20, 30 },
	{ 40, 50, 60 },
	{ 70, 80, 90 } };

	cout << endl;
	cout << "ARRAY IN DYNAMIC MEMORY:" << endl;
	cout << "*** dynamic2Darray[0] ***" << endl;
	cout << "Adress" << '\t\t\t' << "Value" << endl;
	cout << "-----------------------------" << endl;

	for (int * pointer = &fixed_array[0][0] - 4;
		pointer < &fixed_array[0][0] + 8;
		pointer++)
{
		//cout << /*���������*/ << '\t' << /*��������*/ << endl; 
		cout << "0x" << pointer << '\t' << *pointer << endl;
}

	getchar();
    return 0;
}

