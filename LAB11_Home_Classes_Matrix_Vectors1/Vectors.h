#pragma once
#include "Matrix.h"
class Vectors : public Matrix
	{
private:

	int l1 = 1;
	int l2;
	int ** B1;

public:
	//Vectors(int **B1, int g1);

	//Vectors();

	void VECTOR_RESULT(Vectors B1, Vectors B2, Vectors B);

	//~Vectors();
};

