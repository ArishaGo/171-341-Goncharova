// LAB10_DLL.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "LAB10_DLL.h"

//DLL

extern "C" __declspec(dllexport) int fnc2(double p1, char p2)
{
    return p1+ p2;
}

