#include "stdafx.h"
#include "EXAM_STRING.h"
#include <iostream>

using namespace std;


EXAM_STRING::EXAM_STRING() //создается класс строк
{
	int a = 0; //размер строки
	char *DynString = 0; //пустой массив
	char *new_DynString = 0;

}


EXAM_STRING::EXAM_STRING(const EXAM_STRING& other) //создание строки
{
	a = other.a;
	DynString = new char[a];
	for (int i = 1; i < a; i++)
	{
		DynString[i] = other.DynString[i];
	}
}

char EXAM_STRING::get(int i) //чтение строки
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

char EXAM_STRING::set(int i, char now) //запись элемента строки
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

int EXAM_STRING::num() //размер строки
{
	return 0;
}

void EXAM_STRING::print() //вывод строки
{
	for (int i = 0; i < a; i++)
	{
		cout << get(i) << " ";
	}
}

void EXAM_STRING::add(char j) //добавление элемента в конец строки
{
	if (a + 1 > MAX)
	{
		grow();
	}
	DynString[a] = j;
	a = a + 1;
}

void EXAM_STRING::grow()//увеличение размера строки
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

void EXAM_STRING::del()//очищение строки
{
	a = 0;
}

EXAM_STRING::~EXAM_STRING()
{
	delete[] DynString;
}

