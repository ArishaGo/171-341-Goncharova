// LAB_18_Class.cpp: определяет точку входа для консольного приложения.
//

//СТРУКТУРЫ ДАННЫХ

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <string.h>
#include <cmath>
#include <exception>
//STD - стандартная библиотека языка С++
//функции print_f, getchar, fopen, read - из данной библиотеки
//[C++] -> [STD] -> [OC]

//STL - standart template library (template -шаблон)
//это расширение STD, сдержащее структуры данных
//и функции по работе с ними
//именно из STL подключаются cout, cin, fstream, ifstream, ofstream
//контейнеры array, vector, list, map
//интераторы,
//алгоритмы sort, copy и т.д.

// stad ::array
//инкапсулирует массивы неизменной длины, является шаблоном
// std::vector

//std::list

//std::map


int main()
{
	// stad ::array
	//инкапсулирует массивы неизменной длины, является шаблоном
	std::array<double, 10>double_array1 ; //объект, построенный из шаблона std::array <> , инкапсулирующий массив
	double_array1[5] = 10, 5;
	double_array1.fill(0.0);
	int array_kength = double_array1.size();
	//double_array1. swap () фугкция для обмена между содержимым двух массивов
	std::sort(double_array1.begin(), double_array1.end());
	std::array <double, 10> double_array2 = {0};
	std::copy(double_array2.begin(), double_array2.end(), double_array2.begin());


	//для создания двумерных массивов
	std::array <std::array<int, 3>, 3> mat33;

	//итератор - объект, ссылающийся на элемент массива вектора или списка
   //"улучшенный" вариант переменной-счетчика
  //нужен для связи шаблонов STL 
	std::array <double, 10>::iterator array_iterator;

	// std::vector
	//инкапсулирует одномерный массив и предоставляет средства
	//для изменения его длины
	//очень близким к std::vector по функционалу является std::string
	//ОСНОВНОЙ НЕДОСТАТОК
	//каждый раз при увеличении длины vector запрашивает у ОС новую область памти и копирует туда старую
	//старую освобождает
	//ОСНОВНОЕ ПРЕИМУЩЕСТВО
	//доступ осуществляется быстро напрямую по адресу
	//[адрес_1 + i]
	//ВЫВОД
	//доступ быстрый, а вставка илил увеличение - медленное

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

	//также у std::vector присутствувют весь функционал std::array:
	//размер, сортировка, инераторы, копирование, обмен и т.д

	std::sort(long_vector.begin(), long_vector.end());
	std::cout << "vector after sort()";
		for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;
	
	long_vector[2] = 11;


	//вставка в вектор
	long_vector.insert(long_vector.begin() + 1, 100500/*с помощью шаблоно можно вставить несколько*/);
	std::cout << "vector after insert()";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout << std::endl;
	//std::list
	//все наоборот: вставка и увеличение списка производится быстрее, чем в vector
	//а доступ - медленнее, причем чем дальше от 1-го элемента - тем МЕДЛЕННЕЕ
	//так как для доступа i-тому элементу (определения его адреса ОП) необходимо пройти по цепочке от 1-го элемента

	//хранится в отличие от array и vector не является компактным массивом в памяти,
	// элемнеты std::list представлены отдельными объектами, связанными друг с другом
	//указателями, которые они хранят
	//[null|данные|указатель] --->[указатель|данные|указатель]
	
	//                                      /
	//                                    /
	//                                  /
	//                                /
	//                              /
	//                     [указатель|данные|указатель]Б--->[указатель|данные|null]

	std::list <char> char_list = { 'b' };
	char_list.push_front('a'); //вставка перед первым элементом
	char_list.push_back('c'); //вставка после последнего
	
	for ( char ch : char_list)
	{ 
	std::cout << ch << std::endl;
}

	//если класс простой и не содержит динамических данных
	class sample_class
	{
		int a;
		double b;
	};
	//список можно составлять из объектов класса
	std::list <sample_class> obj_list1;
	//в противном случае из указателей на объекте
	std::list <sample_class> obj_list2;

	//std::map
	//состоит из пар "ключ" - "значение"
	//например "Tu-154" - "5000", "B777" - "6000", "A320" - "6500"
	std::map<std::string, double> plane_and_range =
	{ {"Tu-154" , 5000} , { "B777" , 6000 }, { "A320" , 6500 } };
	plane_and_range.insert(std::pair<std::string, double>("A380", 10000.0));

std::cout << "The range of Boeing 777 is" <<  plane_and_range["B777"] << std::endl;
std::cout << "The range of A380 is" << plane_and_range["A380"] << std::endl;


     double d_array[5] = { 1, 2, 3 , 4, 5 };
     int i = 60000;
	 try // в try помещается код, потенциально способный вызвать исключения:
		 //функции, не получающие доступа к файлам, портам, устройствам и т.д
		 // фукции, неправильно работающие с памятью
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

//в курс не вошли темы, необходимые для штатной коммерческой разработки ПО
//юнит-тестирование(на каждый модуль или проект создается проект, который производит тестирование, 
//причем сборка и запуск решения настраивается таким образом, что в превую очередь собирается базовый проект
//затем собирается код теста и запускается
// - технологии, процессы и шаблоны разработки (SCRUM, Waterfall, Agile, ...)
// - создание графических приложений
// - многопоточные и асинхронные приложения
