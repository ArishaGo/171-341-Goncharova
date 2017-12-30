// LAB13_Class.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>


// ���������� �������, ������� � ���������� 
// ���������� - ���������� ���������� ������� (� ����� ������� ������� � ����������, ������� ���� 
// �������� ���������) � ����������� �������, �� ������ ������� ����������. 


using namespace std;


int fnc1(double p1, char p2)
{
	cout << "fnc1(double, char)" << endl;
	return p1 + p2;
}

/* ����� �������� ������� �� ������ ��������� ��������� �� �������� �����������:
double fnc1(double p1, char p2)
{
cout << "fnc1(double, char)" << endl;
return p1 + p2;
}
*/


/*  ��� ����������� ��������� �������� ��������� ������� - ��� + ������������������ ���������� + �� ����
���� ���� ��������� ����� ������ ��������, �� ���� � ������������������ ����������
����������������� ����� ������ �� �����������, � ��������� �����������, ��� �������� �������:

int fnc1(double a, char b)
{
cout << "fnc1(double, char)" << endl;
return a - b;
}
*/


int fnc1(int p1, short p2)
{
	cout << "fnc1(int, short)" << endl;
	return p1 + p2;
}

int fnc1(long long p1, long long p2)
{
	cout << "fnc1(long long, long long)" << endl;
	return p1 + p2;
}

// ������� ������ ������������� ����� ��� ��, ��� � ������� ������� 
class sample_class {
public:

	int property1; // property - �������� (����.) 
	double property2;

	int fnc1(double p1, char p2)
{
		cout << "sample_class::fnc1(double, char)" << endl;
		return p1 + p2;
}

	int fnc1(int p1, short p2)
{
		cout << "sample_class::fnc1(int, short)" << endl;
		return p1 + p2;
}

	// �������� ��������: 

	// �������� ��������� ������������ ��� ������, ��� ��� ��������� �� ����������� 
	// ������������ � ���� �� ���������, � ����� ������������ � 
	// ����� ������ ������ 

	//sample_class operator + (sample_class & lhs, // left hand side 
	//							sample_class & rhs) // right hand side 
	//{
	//	return; 
	//}


	// ������� ��������: 

	// ��������� ������������ � ��� �� ����� ������, 
	// ��� �������� ������ ��������, ������� ������� �������� ����� ������� 
	// � ������� ������ 

	sample_class & operator += (const sample_class & operand)
		// ����� const - "������ �� ������������" - �� ��� �������� ������ ������ �������,
		// ������� �� ������ � �� ������ �������� 
{
		property1 = property1 + operand.property1;
		this->property2 = this->property2 + operand.property2; // � this - ������ �� �������� 
		return (*this);
}


	/* ����� ��������� ���������� ����������:

	��� operator ������_��������� (��� ���_���������, ��� ���_���������, ...)
	{

	}*/

	sample_class & operator -= (const sample_class & operand);
};
// ��������� ������������� ��� �������������, ���������������� �����, ������� 
// ��� ������� 




sample_class & sample_class::operator -= (const sample_class & operand) // 
																		// ����� const - "������ �� ������������" - �� ��� �������� ������ ������ �������,
																		// ������� �� ������ � �� ������ �������� 
{
	property1 = property1 - operand.property1;
	this->property2 = this->property2 - operand.property2; // � this - ������ �� �������� 
	return (*this);
}

sample_class operator + (const sample_class & lhs, // left hand side 
	const sample_class & rhs) // right hand side 
{
	sample_class result; // ������� ����� ������ ��� ������ ����������� 

						 // ����������, ������� 
	result.property1 = lhs.property1 + lhs.property1;
	result.property2 = lhs.property2 + lhs.property2;

	return result;
}

ostream & operator << (ostream & os, // ������������� ��������, cout
	sample_class & rhs) // �������������� ��������, ����������, ��, ��� ��������� 
{
	os << "samplle_class: " << endl;
	os << "\tproperty1 = " << rhs.property1 << ";" << endl;
	os << "\tproperty2 = " << rhs.property2 << ";" << endl;
	return os;
}

int main() // !!! ������� MAIN �� ����� ���� ����������� 
{
	double a = 10.5;
	char b = 15;
	int c = 1000;
	short d = 101325;
	long long e = 1;

	fnc1(a, b);

	fnc1(e, e);
	fnc1(c, d);

	sample_class obj1, obj2;
	obj1.fnc1(a, b);
	obj1.fnc1(c, d);

	obj1.property1 = 11;
	obj1.property2 = 10, 5;
	obj2.property1 = 111;
	obj2.property2 = 101.5;

	/*obj1 = obj1 * obj2;  - �� ��������� �������� �� �����, ��� ������ ��� ������ ��������� ��������� ("*") */

	// ���������� � �������� ������ ��������� "+=" 
	cout << "*** before use of += " << endl;
	cout << "obj1.property1 = " << obj1.property1 << endl;
	cout << "obj1.property2 = " << obj1.property2 << endl;

	obj1 += obj2;
	cout << "*** after use of += " << endl;
	cout << "obj1.property1 = " << obj1.property1 << endl;
	cout << "obj1.property2 = " << obj1.property2 << endl;

	// ���������� � �������� ������ ��������� "-=" 
	cout << "*** before use of -= " << endl;
	cout << "obj1.property1 = " << obj1.property1 << endl;
	cout << "obj1.property2 = " << obj1.property2 << endl;

	obj1 += obj2;
	cout << "*** after use of -= " << endl;
	cout << "obj1.property1 = " << obj1.property1 << endl;
	cout << "obj1.property2 = " << obj1.property2 << endl;



	/*cout << obj1;
	cout << obj1 + obj2;*/

	getchar();
    return 0;
}
//---------------------------------------------------------------------------------------------------------

/*

- ������������� ������� ����� ���������� ����� �� ������ �������� �����, ��� ����������� � � ��������� - ��� ������
������� � ������� ��������
- ���������� ��������� �������, ����� �� ���������� �������� �� �����, ��� ������, �� ������� � ���� ����������,
������� ������� �����������
- ��������� ����� operator
- ������� ��������� ������������� ������ ������ � ���� �������, �������� - �������, � ���� ��������� �������


*/

/*
�������
��� ������� �������� � ������ �����������
���������� "+" �2 (��� ���� �������� � ��� ���� ������), "-" �2(��� ���� �������� � ��� ���� ������),
"*" �3 (������� � �������, ������� � ������, ������ � ������ (���������)), "<<"

*/


/*
��������������� ������ ������������ �++:
1. ������������ ���� �� �������� ���������� ������� � ���� ����� �������
� ������� ����� ����� ������
2. �������������� ����� ������������ � �����������
3. �������� ��������� ��� this ������ ������� �������
*/
