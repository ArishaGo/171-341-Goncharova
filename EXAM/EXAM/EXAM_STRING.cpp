#include "stdafx.h"
#include "EXAM_STRING.h"
#include <iostream>

using namespace std;


EXAM_STRING::EXAM_STRING() //��������� ����� �����
{
	int a = 0; //������ ������
	char *DynString = 0; //������ ������
	char *new_DynString = 0;

}


EXAM_STRING::EXAM_STRING(const EXAM_STRING& other) //�������� ������
{
	a = other.a;
	DynString = new char[a];
	for (int i = 1; i < a; i++)
	{
		DynString[i] = other.DynString[i];
	}
}

char EXAM_STRING::get(int i) //������ ������
{
	if ((DynString != 0) && (i < a))
	{
		return DynString[i];
	}
	else
	{
		return 0;
	}
}

char EXAM_STRING::set(int i, char now) //������ �������� ������
{
	if ((DynString != 0) && (i < a))
	{
		DynString[i] = now;
	}
	else
	{
		return 0;
	}
}

int EXAM_STRING::num() //������ ������
{
	return 0;
}

void EXAM_STRING::print() //����� ������
{
	for (int i = 0; i < a; i++)
	{
		cout << get(i) << " ";
	}
}

void EXAM_STRING::add(char j) //���������� �������� � ����� ������
{
	if (a + 1 > MAX)
	{
		grow();
	}
	DynString[a] = j;
	a = a + 1;
}

void EXAM_STRING::grow()//���������� ������� ������
{
	new_DynString = new char[2 * MAX + 1];

	for (int i = 0; i < MAX; i++)
	{
		new_DynString[i] = DynString[i];
	}
	delete[] DynString;

	DynString = new_DynString;

	MAX = 2 * MAX + 1;
}

void EXAM_STRING::del()//�������� ������
{
	a = 0;
}

EXAM_STRING::~EXAM_STRING()
{
	delete[] DynString;
}

