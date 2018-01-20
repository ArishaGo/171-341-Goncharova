// EXAM1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "EXAM_STRING.h"

using namespace std;



int main()
{
	EXAM_STRING STROCA1;

	while (1)
	{
		for (int i = 0; i < 1000; ++i)
		{
			STROCA1.add('a');
		}
		STROCA1.print();
		cout << endl;
		STROCA1.del();
	}
	STROCA1.add('b');
	STROCA1.print();

	system("pause");
	return 0;
}



