// LAB_18_Class.cpp: ���������� ����� ����� ��� ����������� ����������.
//

//��������� ������

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <string.h>
#include <cmath>
#include <exception>
//STD - ����������� ���������� ����� �++
//������� print_f, getchar, fopen, read - �� ������ ����������
//[C++] -> [STD] -> [OC]

//STL - standart template library (template -������)
//��� ���������� STD, ��������� ��������� ������
//� ������� �� ������ � ����
//������ �� STL ������������ cout, cin, fstream, ifstream, ofstream
//���������� array, vector, list, map
//����������,
//��������� sort, copy � �.�.

// stad ::array
//������������� ������� ���������� �����, �������� ��������
// std::vector

//std::list

//std::map


int main()
{
	// stad ::array
	//������������� ������� ���������� �����, �������� ��������
	std::array<double, 10>double_array1 ; //������, ����������� �� ������� std::array <> , ��������������� ������
	double_array1[5] = 10, 5;
	double_array1.fill(0.0);
	int array_kength = double_array1.size();
	//double_array1. swap () ������� ��� ������ ����� ���������� ���� ��������
	std::sort(double_array1.begin(), double_array1.end());
	std::array <double, 10> double_array2 = {0};
	std::copy(double_array2.begin(), double_array2.end(), double_array2.begin());


	//��� �������� ��������� ��������
	std::array <std::array<int, 3>, 3> mat33;

	//�������� - ������, ����������� �� ������� ������� ������� ��� ������
   //"����������" ������� ����������-��������
  //����� ��� ����� �������� STL 
	std::array <double, 10>::iterator array_iterator;

	// std::vector
	//������������� ���������� ������ � ������������� ��������
	//��� ��������� ��� �����
	//����� ������� � std::vector �� ����������� �������� std::string
	//�������� ����������
	//������ ��� ��� ���������� ����� vector ����������� � �� ����� ������� ����� � �������� ���� ������
	//������ �����������
	//�������� ������������
	//������ �������������� ������ �������� �� ������
	//[�����_1 + i]
	//�����
	//������ �������, � ������� ���� ���������� - ���������

	std::vector<long long> long_vector = { 10, 15, 20 };

	std::cout << "vector<> = ";
	for (long long value : long_vector)
		std::cout <<'\t' << value;
	std::cout << std::endl;

	long_vector.push_back(25);
	long_vector.push_back(30);

	std::cout << "vector after push()";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;

	//����� � std::vector ������������� ���� ���������� std::array:
	//������, ����������, ���������, �����������, ����� � �.�

	std::sort(long_vector.begin(), long_vector.end());
	std::cout << "vector after sort()";
		for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;
	
	long_vector[2] = 11;


	//������� � ������
	long_vector.insert(long_vector.begin() + 1, 100500/*� ������� ������� ����� �������� ���������*/);
	std::cout << "vector after insert()";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;
	//std::list
	//��� ��������: ������� � ���������� ������ ������������ �������, ��� � vector
	//� ������ - ���������, ������ ��� ������ �� 1-�� �������� - ��� ���������
	//��� ��� ��� ������� i-���� �������� (����������� ��� ������ ��) ���������� ������ �� ������� �� 1-�� ��������

	//�������� � ������� �� array � vector �� �������� ���������� �������� � ������,
	// �������� std::list ������������ ���������� ���������, ���������� ���� � ������
	//�����������, ������� ��� ������
	//[null|������|���������] --->[���������|������|���������]
	
	//                                      /
	//                                    /
	//                                  /
	//                                /
	//                              /
	//                     [���������|������|���������]�--->[���������|������|null]

	std::list <char> char_list = { 'b' };
	char_list.push_front('a'); //������� ����� ������ ���������
	char_list.push_back('c'); //������� ����� ����������
	
	for ( char ch : char_list)
	{ 
	std::cout << ch << std::endl;
}

	//���� ����� ������� � �� �������� ������������ ������
	class sample_class
	{
		int a;
		double b;
	};
	//������ ����� ���������� �� �������� ������
	std::list <sample_class> obj_list1;
	//� ��������� ������ �� ���������� �� �������
	std::list <sample_class> obj_list2;

	//std::map
	//������� �� ��� "����" - "��������"
	//�������� "Tu-154" - "5000", "B777" - "6000", "A320" - "6500"
	std::map<std::string, double> plane_and_range =
	{ {"Tu-154" , 5000} , { "B777" , 6000 }, { "A320" , 6500 } };
	plane_and_range.insert(std::pair<std::string, double>("A380", 10000.0));

std::cout << "The range of Boeing 777 is" <<  plane_and_range["B777"] << std::endl;
std::cout << "The range of A380 is" << plane_and_range["A380"] << std::endl;


     double d_array[5] = { 1, 2, 3 , 4, 5 };
     int i = 60000;
	 try // � try ���������� ���, ������������ ��������� ������� ����������:
		 //�������, �� ���������� ������� � ������, ������, ����������� � �.�
		 // ������, ����������� ���������� � �������
		 //
	 { 
     d_array[i] = 15;
	 throw 1;
     }
	 catch (std::exception& ex)
	 {
		 std::cout << ex.what() << std::endl;
	 }
	 catch (...)
	{
		 std::cerr << "Error in \"d_array[i] = 15\"" << std::endl;
	 }
	getchar();
    return 0;
}

//� ���� �� ����� ����, ����������� ��� ������� ������������ ���������� ��
//����-������������(�� ������ ������ ��� ������ ��������� ������, ������� ���������� ������������, 
//������ ������ � ������ ������� ������������� ����� �������, ��� � ������ ������� ���������� ������� ������
//����� ���������� ��� ����� � �����������
// - ����������, �������� � ������� ���������� (SCRUM, Waterfall, Agile, ...)
// - �������� ����������� ����������
// - ������������� � ����������� ����������
