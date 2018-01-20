#pragma once
class EXAM_STRING
{
public:
	EXAM_STRING();//����� ������������
	EXAM_STRING(const EXAM_STRING& other); //����������� ����������� 1
	EXAM_STRING(const char *copy); //����������� 2
	EXAM_STRING(const std::string& copy); //����������� 3

   ~EXAM_STRING();

	char get(int i); //������ ������
	char insert(int i, char now); //������ �������� ������
	int num(); //������ ������ 
	void add(char j); //���������� �������� � ����� ������
	void print(); //����� ������
	void clear(); //�������� ������


private:
	int size; //������������ ������ ������
	int MAX; //������������ ����� ������
	char *DynString; //������������ ������ (������)
	char *new_DynString; //����� ������������ ������ (����� ������)
	void grow(); //���������� ������


};



