// LAB16_Class.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <string> 
#include <fstream>
#include <bitset>

using namespace std;
/*СТРОКИ И ФАЙЛЫ*/


// Строки старого С-типа представляют из себя массив символов с нулевым окончанием 

char cstr1[] = "C-style string1";
char cstr2[] = { 'C', '-', 's', 't', 'y', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '2', '\0' };

// функции для работы с С-строками 

// вывод на печать printf(char[], , ,) 

// с помощью printf можно не просто печатать готовую строку 
// но и подставлять в нее другие переменные, попутно преобразовывая их 
// в символьный вид и применяя форматирование 
// форматирование printf("базовая %s строка %f", параметр1, параметр2")

// позиции, куда будут подставляться параметры, обозначаются в базовой строке 
// символом % 

// значение символов форматирования берётся из таблицы справки к функции http://www.cplusplus.com/reference/cstdio/printf/
// значение некоторых из них 
// %f - параметр представляется на место %f, оформленное в виде числа с плавающей точкой 
// %s - параметр подставляется на место %s как строка 
// %d - параметр подставляется на место %d как целое число 
// %e - параметр подставляется на место %e как число в экспоненциальном виде 

// объединение строк strcat(*char, *char) 
// копирование из одной строки в другую strcpy()
// сравнение strcmp()
// длина строки strlen() 


// в стандартной библиотеке С++ массив символов инкапсуллирован в класс std::string,
// в который так же собраны самые частоиспользуемые методы обработки, 
// и для которого перегружены операторы 

std::string cppstr1 = " C++ - style string ";
std::string cppstr2 = " C++ - style string ";

int main()
{
	printf(cstr1);
	printf("\n\n"); // в функцию передается массив char (а имя массива является указателем на самый первый элемент массива),
					// либо указатель *char 

	printf("Insert double: %f,\n"
		"insert long long: %d,\n" // целое число 
		"insert string: %s,\n"
		"insert exponential: %e,\n" // мантисса - дробное число между >=1 и <2, умноженое на 10^exponenta
		"insert double with precision: %10.2f\n" // 10ю2 - 10 пустых мест до запятой и 2 знака после запятой 
		"*ERROR insert long long as double: %10.2f\n" // ошибка! неверное приведение типа 
		"*ERROR insert double as int: %010d\n", // ошибка! неверное приведение типов 
		1000.15,
		132456789,
		"string =)",
		1123456.1123456,
		1.1123456,
		(long long)10000);

	// сравнение 
	int i = strcmp(cstr1, cstr2);
	printf_s("Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, i);
	cout << "Instead of strcmp() use (cppstr1 == cppstr2) = " << (cppstr1 == cppstr2) << endl << endl; // аналог сравнения строк на С++ 

																									   // длина строки 
	int lngth = strlen(cstr1);
	printf_s("Result of strlen(%s) = %d\n", cstr1, lngth);
	cout << "Instead of strlen() use std::string.length():\t" << cppstr1.length() << endl << endl;


	//копирование из одной строки в другую 
	char cstr3[255];
	strcpy_s(cstr3, 255, cstr2); // требуется использование более сложного безопасного аналога strcpy_s()
	printf_s("Result of strcpy(%s, %s)\n", cstr3, cstr2);
	cppstr2 = cppstr1;
	cout << "Instead of strcpy() use operator =:\t" << cppstr2 << endl << endl;


	// объединение строк 
	strcat_s(cstr3, 255, cstr1);
	cout << "Result of strcat(cstr2, cstr1) = " << cstr3 << endl;
	cout << "Instead of strcat() use operator +:\t" << (cppstr1 + cppstr2) << endl << endl;

	// std::fstream - уникальный класс для ввода (чтения из файла) и для вывода (запись в файл) 
	// std::ifstream - класс для ввода (чтения из файла) 
	// std::ofstream - класс для вывода (запись в файл) 
	// аналогично cout - потоку, предназначенному для вывода на консоль 
	// fstream является потоком, предназначенным для ввода/вывода из/в файл 

	fstream fs;
	fs.open("Some text file.txt", // при открытии файла необходимо указать имя файла 
								  // а также режим открытия: с перезаписью или без, для чтения/для записи/ оба режима и т.д. 
		std::fstream::in // добавляется режим вывода из файла 
		| std::fstream::out // добавляется режим записи в файл 
							//| std::fstream::app // app = append добавляется режим с записью в конец файла 
		| std::fstream::trunc); // trunc = truncate - режим с перезаписью всего файла


								// чтобы не вникать в тип стандартной библиотеки используется тип auto: 
								// в зависимости от правой части выражения компилятор сам подбирает тип 
	auto fstream_mode = std::fstream::in | std::fstream::out | std::fstream::app;
	cout << "std::fstream::in | std::fstream::out | std::fstream::app = " << std::bitset<8>(fstream_mode) << endl;
	fs << 1000.15 << endl
		<< 132456789 << endl
		<< "string =)" << endl
		<< 1123456.1123456 << endl
		<< 1.1123456 << endl
		<< (long long)1000 << endl
		<< 10.5 << endl;
	fs.close();

	getchar();
    return 0;
}

