// LAB12_Class.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include "Weapon_class.h"
#include "launcher.h" 

// в stdafx.h собраны файлы, которые не перестраиваются каждый раз при перестройке приложения 

// выделили класс weapon_class в пару файлов h и cpp 
// 1) для улучшения читаемости и удобства навигации в коде 
// 2) для повышения модульности, повторной используемости кода 

// синтаксис : 
// class имя_нового класса : [тип_наследования] имя_родительского_класса1, 
//							[тип_наследования] имя_родительского_класса2 

// доступность свойств и методов базового класса внутри производного класса, 
// даже если они не объявлены в производном 

class assault_rifle : public Weapon_class
{
public: // здесь public влияет на видимость снаружи функции launcher 
	assault_rifle()
	: Weapon_class() // в начале конструктора launcher вызывается конструктор базового класса 
{
		return;
}
	double recoil; // сила отдачи 
};

class soldier
{
public:
	soldier() {};
	int health;
	string name;
};

// множественное наследование 

class combat_unit : public Weapon_class, public soldier
{
public:
	combat_unit()
{

}
};


// ключевое слово this внутри класса означает указатель на самого себя

int main()
{
	assault_rifle obj1;
	obj1.play_animation(); // public свойства и методы заимствуются из базового класса 

						   // у дочернего класса нескольких родителей доступны все их свойства и методы 

	combat_unit obj2;
	obj2.health = 15; // доступны члены одного родительского класса 
	obj2.load(); // доступны члены второго родительского класса 


	getchar();
    return 0;
}

/*
                                        private:	  protected			    public
доступ из тела класса:					открыт			открыт				открыт
доступ из производных классов:			закрыт			открыт				открыт
доступ из внешних функций и классов:	закрыт			закрыт				открыт

*/

/*

БАЗОВЫЙ КЛАСС		РЕЖИМ НАСЛЕДОВАНИЯ			ПРОИЗВОДНЫЙ КЛАСС

ptivate					public					Недоступен
protected			---------------->			protected
public											public

ptivate					protected				Недоступен
protected			---------------->			protected
public											protected

ptivate					private					Недоступен
protected			---------------->			private
public											private


*/