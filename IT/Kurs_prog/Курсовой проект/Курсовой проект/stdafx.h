#include<conio.h>
#include<fstream>
#include<iostream>
#include<iomanip>
#include <windows.h>
using namespace std;
struct Worker {
	char surname[20]; //фамилия
	double salary; //зарплата
	bool be; //дополнительное поле. по нему будем определять
	//существует ли структура
};
//функция выводит на экран и обрабатывает основное меню
void MainMenu(Worker work[], Worker* loc_number[], const int n);
//функция проверяет является ли символ, введенный пользователем, пунктом меню
//const int size_menu максимальное значение, предусмотренное меню
int EnterMenu(const int size_menu);
//функция добавляет в базу нового сотрудника
void AddMm(Worker work[], Worker* loc_number[], const int n);
//функция удаляет из базы сотрудника
void DelMm(Worker* loc_number[], const int n);
//выводит на экран информацию о сотрудниках
void InformMm(Worker* loc_number[], const int n);
//сохраняет базу сотрудников в файл
void SaveMm(Worker work[], const int n);
//извлекает базу сотрудников из файл
bool ExtMm(Worker work[], Worker* loc_number[], const int n);
//сравнивает фамилии сотрудников для сортировки по фамилии
bool SortWork(char str1[], char str2[]);
//функция проверяет была ли база сохранена в файл. возвращает истину,
//если ее необходимо повторно сохранить
bool ExitMm(bool save);
//массиву Worker присваиваем нулевые значения
void NullWork(Worker work[], Worker* loc_number[], const int n);
