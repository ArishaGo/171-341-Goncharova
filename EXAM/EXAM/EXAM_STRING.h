#pragma once
class EXAM_STRING
{
public:
	EXAM_STRING();
	EXAM_STRING(const EXAM_STRING& other); //����������� �����������

	virtual ~EXAM_STRING();

	char get(int i);
	char set(int i, char now);
	int num();
	void add(char j);
	void print();
	void del();


private:
	int a; //������������ ������ ������
	int MAX; //������������ ����� ������
	char *DynString; //������������ ������
	char *new_DynString;
	void grow();

};



