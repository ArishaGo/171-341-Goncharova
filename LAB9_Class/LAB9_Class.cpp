// LAB9_Class.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream> 
#include "Weapon_class.h"


// ������������ ������ � 9 
// ������ � �������


//����� - ��� ������, ������������ ��� ����� ��������������� ������ �����, ���������� �� ������ ������(��������) � ������� �� �� ���������(������) 
//�������� - ���������� � ������ 
//����� - ������� � ������ 
//������ - ��������� ������, ��� ���������� � ������������ ������


/* ������
����� ������
int ����� ���������� �������
int ������� ��������
double ���������
double ��������� ��������
double ���
bool oprics
bool loaded

������� ������� (����� ���������� ������� -> max)
������� ��������� �������� ()
������� ������� (��� - 1 ������, �������� ��������, ����� ���������� ������� - 1, ...)
*/

/*
����������� ���������������� ��� ������ - �����
class ���_������ {

private:
int �����_����������_�������;
int �������_�������� = 30; - ��������, ���������� ��� �������� �������
public:
double ��������� = 1500;
double ���������_��������;
double ���;
bool optics;
bool loaded;

���_������(��� ��������� ��� ��������); - ��, ��� � ������� �������
������� (���������);
���������_��������(���������);
�������(���������);
}


...

���_������ weapon1;
���_������ * weapon2 = new ���_������();

...

weapon1.�������_�������� = 60; // ���������� ���������� ��� ����������, ��� ������� ������������ "."
weapon1.�������(���������);

weapon2-> �������_�������� = 100; // ���� ������ ���������� �� ������, ��� ������� ������������ "->"
weapon2->�������(���������);
*/

/*
������ � ������� ����� ����� ������ ��� �������� �� ������ �������� �����,
����� ���������� � �������� ���� ��� ����� ���� � ���������� ����������� � ���������
*/

/*
����������� � ���������� - ������������� ������� �������, ������� �����������
�������������, ��������������, ��� �������� � �������� �������

��� ������������ ��������� � ������ ������, ��� ����������� ���������� � ������ ~���_������()
*/

/*
�������� � ������ ������ ����� 3 ������������� �������: private, public � protected
�������� � ������ public ����� ���������� ����� �������
�������� � ����� private ����� ���������� ������ �������� ������ �������
protected ���� ���� ����� ������� ������� � ����� ������� � ���� "������������"

*/

using namespace std;

class Weapon_class // ������������ ���������� � ������������ ��� � ���� �� ����� (�� �������� �����)
{
public:

Weapon_class() // � ������������ ���������� ������������� ������� ������ � ������ ��������� ��������� ��������
{
weight = 3.5;
cartridges = capacity;
cout << "Weapon_class()" << endl;
}
private:
int cartridges; // �����_����������_�������
int capacity = 30; // �������_��������
public:
double range = 1500; // ���������
double velocity; // ���������_��������
double weight; // ���
bool optics;
bool loaded;

void load() // �����������
{
cartridges = capacity;
}

void play_animation();

void shot()
{
return;
}

~Weapon_class() // ����������
{
cout << "~Weapon_class()" << endl;
}
};


void Weapon_class::play_animation() // �����, ������������ ��� ������, ���������� � ���_������::
{
return;
}

void fnc1()
{
	cout << "fnc1" << endl;
	int a;
	double b;
	Weapon_class weapon;
	cout << "fnc1 return" << endl;
	// ��� ��� ������� ���������� ������� weapon 
	return;
	// pop 
	// pop 
	// pop 
}

int main()
{
	Weapon_class weapon1; // ���� ������ ���������� � �� ����� ����������� ������ ���� ������ �� ����� ���������� ����� 
						  // weapon1.cartridges = 1e06; // � private �����������, ��� �������, �������� � ������, 
						  // ����������� �� ���������� �������� �������, ������ � ������� ���������� ������������ ����� ������� 
						  // ��������� ���������� ������ �������, ������� � ������ ���������� � �������� �������� � ������� 
						  // ��������� ������� ������, �������������� �������������� �������� � ����������� 
	weapon1.load(); // ������� load �� ����������� ������� ��������� ��� ������� �������� 
	Weapon_class * weapon2 = new Weapon_class(); // ���� ������ ����������� ������ ���� ������ �� ����� ���������� ����� 

	delete weapon2; // ����� ���������� ���������� weapon1 

					// ������ ������� 
					// push 10 
					// push 5 
					// push ret_addr  

	fnc1();

	getchar();
    return 0;
}

int main()
{

Weapon_class weapon1; // ���� ������ ���������� � �� ����� ����������� ������ ���� ������ �� ����� ���������� ����� 
					  // weapon1.cartridges = 1e06; // � private �����������, ��� �������, �������� � ������, 
					  // ����������� �� ���������� �������� �������, ������ � ������� ���������� ������������ ����� ������� 
					  // ��������� ���������� ������ �������, ������� � ������ ���������� � �������� �������� � ������� 
					  // ��������� ������� ������, �������������� �������������� �������� � ����������� 
weapon1.load(); // ������� load �� ����������� ������� ��������� ��� ������� �������� 
Weapon_class * weapon2 = new Weapon_class(); // ���� ������ ����������� ������ ���� ������ �� ����� ���������� ����� 

delete weapon2; // ����� ���������� ���������� weapon1 

				// ������ ������� 
				// push 10 
				// push 5 
				// push ret_addr  

fnc1();

getchar();
return 0;
}

// � ++ ���� �������� ������ ������, ���: 
// 1) ����������� ������������� ����������� ����� ������������ � ����������� (��� ������ ������������) 
// 2) �������������� ���������� ������� � ������� ������� 


// ������� 
// 1) ������� ����� ��� ������� � �������. ����� ������ ����� private-������, �������� ������� ��� ������ 
// 2) ������� � ������ ������ �� 2 ������������: 
//		��� ���������� (���������������� ������� ������ ������) 
//		� ���������� - �������� (���������� �������� ��������� � ��������-������� ������) 
// 3) ����������� ���������� ����� ������� ��� ����� ������ 
// 4) �������� ����� � *.h-����� � ��������������� ���������, � ������ ������� *.cpp-����� � ��� �� ��������� 
