// LAB12_Class.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream> 
#include "Weapon_class.h"
#include "launcher.h" 

// � stdafx.h ������� �����, ������� �� ��������������� ������ ��� ��� ����������� ���������� 

// �������� ����� weapon_class � ���� ������ h � cpp 
// 1) ��� ��������� ���������� � �������� ��������� � ���� 
// 2) ��� ��������� �����������, ��������� �������������� ���� 

// ��������� : 
// class ���_������ ������ : [���_������������] ���_�������������_������1, 
//							[���_������������] ���_�������������_������2 

// ����������� ������� � ������� �������� ������ ������ ������������ ������, 
// ���� ���� ��� �� ��������� � ����������� 

class assault_rifle : public Weapon_class
{
public: // ����� public ������ �� ��������� ������� ������� launcher 
	assault_rifle()
	: Weapon_class() // � ������ ������������ launcher ���������� ����������� �������� ������ 
{
		return;
}
	double recoil; // ���� ������ 
};

class soldier
{
public:
	soldier() {};
	int health;
	string name;
};

// ������������� ������������ 

class combat_unit : public Weapon_class, public soldier
{
public:
	combat_unit()
{

}
};


// �������� ����� this ������ ������ �������� ��������� �� ������ ����

int main()
{
	assault_rifle obj1;
	obj1.play_animation(); // public �������� � ������ ������������ �� �������� ������ 

						   // � ��������� ������ ���������� ��������� �������� ��� �� �������� � ������ 

	combat_unit obj2;
	obj2.health = 15; // �������� ����� ������ ������������� ������ 
	obj2.load(); // �������� ����� ������� ������������� ������ 


	getchar();
    return 0;
}

/*
                                        private:	  protected			    public
������ �� ���� ������:					������			������				������
������ �� ����������� �������:			������			������				������
������ �� ������� ������� � �������:	������			������				������

*/

/*

������� �����		����� ������������			����������� �����

ptivate					public					����������
protected			---------------->			protected
public											public

ptivate					protected				����������
protected			---------------->			protected
public											protected

ptivate					private					����������
protected			---------------->			private
public											private


*/