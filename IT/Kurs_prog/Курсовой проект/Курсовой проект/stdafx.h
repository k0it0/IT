#include<conio.h>
#include<fstream>
#include<iostream>
#include<iomanip>
#include <windows.h>
using namespace std;
struct Worker {
	char surname[20]; //�������
	double salary; //��������
	bool be; //�������������� ����. �� ���� ����� ����������
	//���������� �� ���������
};
//������� ������� �� ����� � ������������ �������� ����
void MainMenu(Worker work[], Worker* loc_number[], const int n);
//������� ��������� �������� �� ������, ��������� �������������, ������� ����
//const int size_menu ������������ ��������, ��������������� ����
int EnterMenu(const int size_menu);
//������� ��������� � ���� ������ ����������
void AddMm(Worker work[], Worker* loc_number[], const int n);
//������� ������� �� ���� ����������
void DelMm(Worker* loc_number[], const int n);
//������� �� ����� ���������� � �����������
void InformMm(Worker* loc_number[], const int n);
//��������� ���� ����������� � ����
void SaveMm(Worker work[], const int n);
//��������� ���� ����������� �� ����
bool ExtMm(Worker work[], Worker* loc_number[], const int n);
//���������� ������� ����������� ��� ���������� �� �������
bool SortWork(char str1[], char str2[]);
//������� ��������� ���� �� ���� ��������� � ����. ���������� ������,
//���� �� ���������� �������� ���������
bool ExitMm(bool save);
//������� Worker ����������� ������� ��������
void NullWork(Worker work[], Worker* loc_number[], const int n);
