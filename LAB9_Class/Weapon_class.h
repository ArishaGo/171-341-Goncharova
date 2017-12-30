#pragma once

#include <iostream> 

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

	void shot();

	~Weapon_class(); // ����������
};


