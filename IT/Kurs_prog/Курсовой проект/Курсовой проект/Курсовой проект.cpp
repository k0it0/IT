﻿// Курсовой проект.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "stdafx.h"
int main()
{
system("chcp 1251");
system("cls");
const int n=100;
//объявляем массив структур типа Worker
Worker work [n];
//объявляем массив указателей на структуры типа Worker для последующей
//сортировки миссива структур Worker
Worker *number [n];
//объявленному массиву Worker присваиваем нулевые значения
NullWork(work,number,n);
enum CHOISE_MMD {create_mmd=1,extract_mmd,exit_mmd};
int point_mmd;
do{
cout<<"----------------------------------"<<endl;
cout<<" МЕНЮ "<<endl;
cout<<"----------------------------------" << endl << endl;
cout<<"1: Создать новую базу сотрудников;"<<endl<<endl;
cout<<"2: Открыть существующую базу;"<<endl<<endl;
cout<<"3: Выход из программы;"<<endl<<endl;
cout<<"----------------------------------"<<endl<<endl;
point_mmd=EnterMenu(exit_mmd);
switch(point_mmd){
case 0:
break;
case create_mmd: //создаем новую базу
MainMenu(work, number,n);
break;
case extract_mmd: //извлекаем существующую базу из файла
if(!ExtMm(work,number,n))break;
MainMenu(work, number,n);
break;
case exit_mmd:
break;
}
}while(point_mmd!=exit_mmd);
return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
