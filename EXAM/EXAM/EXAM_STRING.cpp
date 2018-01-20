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
	size = other.size;
	DynString = new char[size];
	for (int i = 1; i < size; i++)
	{
		DynString[i] = other.DynString[i];
	}
}

char EXAM_STRING::get(int i) //������ ������
{
	if ((DynString != 0) && (i < size))
	{
		return DynString[i];
	}
	else
	{
		return 0;
	}
}

char EXAM_STRING::insert(int i, char now) //������ �������� ������
{
	if ((DynString != 0) && (i < size))
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

EXAM_STRING::EXAM_STRING(const char* copy) //����������� �� ������� char
{
size = 0;

//��������� ������ �������� ������

while (copy[size] != 0)
{
	size++;
}
MAX = size;
DynString = new char[MAX];

//�������� �������� ������

for (int i = 0; i < size; i++)

	DynString[i] = copy[i];
}

EXAM_STRING::EXAM_STRING(const std::string& copy) //����������� �� std::string (�����������2)
{
//�������� ����������� ������ ��� ������
MAX = copy.size();
size = MAX;
DynString = new char [MAX];

//�������� �������� ������
for (int i = 0; i < copy.size(); i++);
{
	DynString[i] = copy[i];
}
}


void EXAM_STRING::print() //����� ������
{
	for (int i = 0; i < size; i++)
	{
		cout << get(i) << " ";
	}
}

void EXAM_STRING::add(char j) //���������� �������� � ����� ������
{
	if (size + 1 > MAX)
	{
		grow();
	}
	DynString[size] = j;
	size = size + 1;
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

void EXAM_STRING::clear()//�������� ������
{
	size = 0;
}

EXAM_STRING::~EXAM_STRING()
{
	delete[] DynString;
}

