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
	size = other.size;
	DynString = new char[size];
	for (int i = 1; i < size; i++)
	{
		DynString[i] = other.DynString[i];
	}
}

char EXAM_STRING::get(int i) //чтение строки
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

char EXAM_STRING::insert(int i, char now) //запись элемента строки
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

int EXAM_STRING::num() //размер строки
{
	return 0;
}

EXAM_STRING::EXAM_STRING(const char* copy) //копирование из массива char
{
size = 0;

//вычисляем длинку исходной строки

while (copy[size] != 0)
{
	size++;
}
MAX = size;
DynString = new char[MAX];

//копируем исходную строку

for (int i = 0; i < size; i++)

	DynString[i] = copy[i];
}

EXAM_STRING::EXAM_STRING(const std::string& copy) //копирование из std::string (конструктор2)
{
//выделяем необходимый размер для работы
MAX = copy.size();
size = MAX;
DynString = new char [MAX];

//копируем исходную строку
for (int i = 0; i < copy.size(); i++);
{
	DynString[i] = copy[i];
}
}


void EXAM_STRING::print() //вывод строки
{
	for (int i = 0; i < size; i++)
	{
		cout << get(i) << " ";
	}
}

void EXAM_STRING::add(char j) //добавление элемента в конец строки
{
	if (size + 1 > MAX)
	{
		grow();
	}
	DynString[size] = j;
	size = size + 1;
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

void EXAM_STRING::clear()//очищение строки
{
	size = 0;
}

EXAM_STRING::~EXAM_STRING()
{
	delete[] DynString;
}

