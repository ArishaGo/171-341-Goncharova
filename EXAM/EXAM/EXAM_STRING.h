#pragma once
class EXAM_STRING
{
public:
	EXAM_STRING();//����� ������������
	EXAM_STRING(const EXAM_STRING& other); //����������� ����������� 1
	EXAM_STRING(const char *copy); //����������� 2
	//EXAM_STRING(const std::string& copy); //����������� 3
	EXAM_STRING(int num, int col); // ������� � �������� ������� �������� � ���������� ���������� �������� 
		                         //� ��������� ����� ������ �� ��������� ���������� ��������

   ~EXAM_STRING();

	char get(int i); //������ ������
	char insert(int i, char now); //������ �������� ������
	int raz(); //������ ������ 
	void add(char j); //���������� �������� � ����� ������
	void print(); //����� ������
	void clear(); //�������� ������
	char cut(int num, int col);

private:
	int size; //������������ ������ ������
	int MAX; //������������ ����� ������
	char *DynString; //������������ ������ (������)
	char *new_DynString; //����� ������������ ������ (����� ������)
	void grow(); //���������� ������


};



