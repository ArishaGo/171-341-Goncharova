#pragma once
class EXAM_STRING
{
public:
	EXAM_STRING();
	EXAM_STRING(const EXAM_STRING& other); //конструктор копирования

	virtual ~EXAM_STRING();

	char get(int i);
	char set(int i, char now);
	int num();
	void add(char j);
	void print();
	void del();


private:
	int a; //используемый размер строки
	int MAX; //максимальная длина строки
	char *DynString; //динамичсекий массив
	char *new_DynString;
	void grow();

};



