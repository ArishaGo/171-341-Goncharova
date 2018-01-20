#pragma once
class EXAM_STRING
{
public:
	EXAM_STRING();//вызов конструктора
	EXAM_STRING(const EXAM_STRING& other); //конструктор копирования 1
	EXAM_STRING(const char *copy); //конструктор 2
	EXAM_STRING(const std::string& copy); //конструктор 3

   ~EXAM_STRING();

	char get(int i); //чтение строки
	char insert(int i, char now); //запись элемента строки
	int num(); //размер строки 
	void add(char j); //добавление элемента в конец строки
	void print(); //вывод строки
	void clear(); //удаление строки


private:
	int size; //используемый размер строки
	int MAX; //максимальная длина строки
	char *DynString; //динамичсекий массив (строка)
	char *new_DynString; //новый динамический массив (новая строка)
	void grow(); //увеличение строки


};



