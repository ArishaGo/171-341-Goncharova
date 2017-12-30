// LAB16_Class.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <string> 
#include <fstream>
#include <bitset>

using namespace std;
/*������ � �����*/


// ������ ������� �-���� ������������ �� ���� ������ �������� � ������� ���������� 

char cstr1[] = "C-style string1";
char cstr2[] = { 'C', '-', 's', 't', 'y', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '2', '\0' };

// ������� ��� ������ � �-�������� 

// ����� �� ������ printf(char[], , ,) 

// � ������� printf ����� �� ������ �������� ������� ������ 
// �� � ����������� � ��� ������ ����������, ������� �������������� �� 
// � ���������� ��� � �������� �������������� 
// �������������� printf("������� %s ������ %f", ��������1, ��������2")

// �������, ���� ����� ������������� ���������, ������������ � ������� ������ 
// �������� % 

// �������� �������� �������������� ������ �� ������� ������� � ������� http://www.cplusplus.com/reference/cstdio/printf/
// �������� ��������� �� ��� 
// %f - �������� �������������� �� ����� %f, ����������� � ���� ����� � ��������� ������ 
// %s - �������� ������������� �� ����� %s ��� ������ 
// %d - �������� ������������� �� ����� %d ��� ����� ����� 
// %e - �������� ������������� �� ����� %e ��� ����� � ���������������� ���� 

// ����������� ����� strcat(*char, *char) 
// ����������� �� ����� ������ � ������ strcpy()
// ��������� strcmp()
// ����� ������ strlen() 


// � ����������� ���������� �++ ������ �������� ��������������� � ����� std::string,
// � ������� ��� �� ������� ����� ����������������� ������ ���������, 
// � ��� �������� ����������� ��������� 

std::string cppstr1 = " C++ - style string ";
std::string cppstr2 = " C++ - style string ";

int main()
{
	printf(cstr1);
	printf("\n\n"); // � ������� ���������� ������ char (� ��� ������� �������� ���������� �� ����� ������ ������� �������),
					// ���� ��������� *char 

	printf("Insert double: %f,\n"
		"insert long long: %d,\n" // ����� ����� 
		"insert string: %s,\n"
		"insert exponential: %e,\n" // �������� - ������� ����� ����� >=1 � <2, ��������� �� 10^exponenta
		"insert double with precision: %10.2f\n" // 10�2 - 10 ������ ���� �� ������� � 2 ����� ����� ������� 
		"*ERROR insert long long as double: %10.2f\n" // ������! �������� ���������� ���� 
		"*ERROR insert double as int: %010d\n", // ������! �������� ���������� ����� 
		1000.15,
		132456789,
		"string =)",
		1123456.1123456,
		1.1123456,
		(long long)10000);

	// ��������� 
	int i = strcmp(cstr1, cstr2);
	printf_s("Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, i);
	cout << "Instead of strcmp() use (cppstr1 == cppstr2) = " << (cppstr1 == cppstr2) << endl << endl; // ������ ��������� ����� �� �++ 

																									   // ����� ������ 
	int lngth = strlen(cstr1);
	printf_s("Result of strlen(%s) = %d\n", cstr1, lngth);
	cout << "Instead of strlen() use std::string.length():\t" << cppstr1.length() << endl << endl;


	//����������� �� ����� ������ � ������ 
	char cstr3[255];
	strcpy_s(cstr3, 255, cstr2); // ��������� ������������� ����� �������� ����������� ������� strcpy_s()
	printf_s("Result of strcpy(%s, %s)\n", cstr3, cstr2);
	cppstr2 = cppstr1;
	cout << "Instead of strcpy() use operator =:\t" << cppstr2 << endl << endl;


	// ����������� ����� 
	strcat_s(cstr3, 255, cstr1);
	cout << "Result of strcat(cstr2, cstr1) = " << cstr3 << endl;
	cout << "Instead of strcat() use operator +:\t" << (cppstr1 + cppstr2) << endl << endl;

	// std::fstream - ���������� ����� ��� ����� (������ �� �����) � ��� ������ (������ � ����) 
	// std::ifstream - ����� ��� ����� (������ �� �����) 
	// std::ofstream - ����� ��� ������ (������ � ����) 
	// ���������� cout - ������, ���������������� ��� ������ �� ������� 
	// fstream �������� �������, ��������������� ��� �����/������ ��/� ���� 

	fstream fs;
	fs.open("Some text file.txt", // ��� �������� ����� ���������� ������� ��� ����� 
								  // � ����� ����� ��������: � ����������� ��� ���, ��� ������/��� ������/ ��� ������ � �.�. 
		std::fstream::in // ����������� ����� ������ �� ����� 
		| std::fstream::out // ����������� ����� ������ � ���� 
							//| std::fstream::app // app = append ����������� ����� � ������� � ����� ����� 
		| std::fstream::trunc); // trunc = truncate - ����� � ����������� ����� �����


								// ����� �� ������� � ��� ����������� ���������� ������������ ��� auto: 
								// � ����������� �� ������ ����� ��������� ���������� ��� ��������� ��� 
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

