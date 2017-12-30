// LAB10_DLL.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "LAB10_DLL.h"

//DLL

extern "C" __declspec(dllexport) int fnc2(double p1, char p2)
{
    return p1+ p2;
}

