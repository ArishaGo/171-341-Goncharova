// LAB13_Class.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


// ПЕРЕГРУЗКА ФУНКЦИЙ, МЕТОДОВ И ОПЕРАТОРОВ 
// перегрузка - объявление нескольких функций (а также методов классов и операторов, которые тоже 
// являются функциями) с одинаковыми именами, но разным набором аргументов. 


using namespace std;


int fnc1(double p1, char p2)
{
	cout << "fnc1(double, char)" << endl;
	return p1 + p2;
}

/* также различие функций по одному выходному параметру не является перегрузкой:
double fnc1(double p1, char p2)
{
cout << "fnc1(double, char)" << endl;
return p1 + p2;
}
*/


/*  для компилятора критерием является сигнатура функции - имя + последовательность аргументов + их типы
даже если аргументы имеют разные названия, но типы и последовательность одинаковые
компиляторсчитает такой случай не перегрузкой, а повторным объявлением, что является ошибкой:

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

// метоады класса перегружаются точно так же, как и обычные функции 
class sample_class {
public:

	int property1; // property - свойство (англ.) 
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

	// БИНАРНЫЙ ОПЕРАТОР: 

	// бинарные операторы записываются все класса, так как результат не обязательно 
	// записывается в один из операндов, а может записываться в 
	// некий третий объект 

	//sample_class operator + (sample_class & lhs, // left hand side 
	//							sample_class & rhs) // right hand side 
	//{
	//	return; 
	//}


	// УНАРНЫЙ ОПЕРАТОР: 

	// результат записывается в тот же самый объект, 
	// для которого вызван оператор, поэтому унарный оператор стоит отнести 
	// к методам класса 

	sample_class & operator += (const sample_class & operand)
		// здесь const - "защита от забывчивости" - не даёт изменить внутри метода операнд,
		// который по логике и не должен меняться 
{
		property1 = property1 + operand.property1;
		this->property2 = this->property2 + operand.property2; // с this - эффект не меняется 
		return (*this);
}


	/* общий синтаксис перегрузки операторов:

	тип operator символ_оператора (тип имя_параметра, тип имя_парамента, ...)
	{

	}*/

	sample_class & operator -= (const sample_class & operand);
};
// операторы перегружаются для нестандартных, пользовательских типов, классов 
// для которых 




sample_class & sample_class::operator -= (const sample_class & operand) // 
																		// здесь const - "защита от забывчивости" - не даёт изменить внутри метода операнд,
																		// который по логике и не должен меняться 
{
	property1 = property1 - operand.property1;
	this->property2 = this->property2 - operand.property2; // с this - эффект не меняется 
	return (*this);
}

sample_class operator + (const sample_class & lhs, // left hand side 
	const sample_class & rhs) // right hand side 
{
	sample_class result; // создать новый объект для записи результатов 

						 // собственно, сложнее 
	result.property1 = lhs.property1 + lhs.property1;
	result.property2 = lhs.property2 + lhs.property2;

	return result;
}

ostream & operator << (ostream & os, // левосторонний оператор, cout
	sample_class & rhs) // правосторонний оператор, собственно, то, что выводится 
{
	os << "samplle_class: " << endl;
	os << "\tproperty1 = " << rhs.property1 << ";" << endl;
	os << "\tproperty2 = " << rhs.property2 << ";" << endl;
	return os;
}

int main() // !!! ФУНКЦИЯ MAIN НЕ МОЖЕТ БЫТЬ ПЕРЕГРУЖЕНА 
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

	/*obj1 = obj1 * obj2;  - по умолчанию оператор не знает, что делать при вызове оператора умножения ("*") */

	// применение и проверка работы оператора "+=" 
	cout << "*** before use of += " << endl;
	cout << "obj1.property1 = " << obj1.property1 << endl;
	cout << "obj1.property2 = " << obj1.property2 << endl;

	obj1 += obj2;
	cout << "*** after use of += " << endl;
	cout << "obj1.property1 = " << obj1.property1 << endl;
	cout << "obj1.property2 = " << obj1.property2 << endl;

	// применение и проверка работы оператора "-=" 
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

- Перегруженные функции имеют одинаковые именя на уровне исходных кодов, для компилятора и в бинарнике - это разные
функции с разными адресами
- Компилятор принимает решение, какую из перегрузок вызывать на месте, при вызове, по составу и типу параметров,
которые передал программист
- Служебное слово operator
- Унарные операторы перегружаются внутри класса в виде методов, бинарные - снаружи, в виде отдельных функций


*/

/*
ЗАДАНИЕ
для классов векторов и матриц опеределить
операторыя "+" х2 (для двух векторов и для двух матриц), "-" х2(для двух векторов и для двух матриц),
"*" х3 (матрица х матрица, матрица х вектор, вектор х вектор (скалярное)), "<<"

*/


/*
Высокоуровневая работа компиллятора С++:
1. прописывание кода по передаче параметров функций в стек перед вызовом
и очистка стека после вызова
2. автоматический вызов конструктора и деструктора
3. передача указателя для this внутри методов классов
*/
