#include "stdafx.h"
#include "Vectors.h"
#include <iostream>

using namespace std;

void Vectors::VECTOR_RESULT(Vectors obj1, Vectors obj2, Vectors obj3){
	int g1 = obj1.l2;
	int g2 = obj2.l2;
	if (g1 != 3 || g2 != 3) 
	{
		cout << "ERROR VECTOR" << endl; 
	}
	else 
	{
		if (g1 == g2)
		{
			for (int i = 0; i < g1; i++)
			{
				obj3.B1[0][i] = obj1.B1[0][(i + 1) % 3] * obj2.B1[0][(i + 2) % 3] - obj1.B1[0][(i + 2) % 3] * obj2.B1[0][(i + 2) % 3];

			}
		}
		else 
		{
			cout << "ERROE VECTOR" << endl;
		}
	}
}

