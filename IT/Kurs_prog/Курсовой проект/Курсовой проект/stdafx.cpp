#include "stdafx.h"
#include<iostream>
using namespace std;
void MainMenu(Worker work[], Worker* loc_number[], const int n) {
	bool save = false; //��� ����������� ����� �� ����� ���������� ����
	enum CHOISE_MM { add_mm = 1, del_mm, inform_mm, save_mm, exit_mm };
	int point_mm;
	do {
		cout<<"------------------------------" << endl;
		cout<<"�������� ����" <<endl;
		cout << "------------------------------" << endl << endl;
			cout<<"1: �������� ���������� � ����;" << endl<<endl;
			cout<<"2: ������� ���������� �� ����;" << endl<<endl;
			cout<<"3: ���������� � �����������;" << endl<<endl;
			cout<<"4: ��������� ���� �����������;" << endl<<endl;
			cout<<"5: �����;" << endl<<endl;
			cout<<"------------------------------" << endl<<endl;
			point_mm = EnterMenu(exit_mm);
		switch (point_mm) {
		case 0:
			break;
		case add_mm:
			AddMm(work, loc_number, n);
			save = false;
			break;
		case del_mm:
			DelMm(loc_number, n);
			save = false;
			break;
		case inform_mm:
			InformMm(loc_number, n);
			break;
		case save_mm:
			save = true;
			SaveMm(work, n);
			break;
		case exit_mm:
			if (ExitMm(save)) point_mm = 0;
			break;
		}
	} while (point_mm != exit_mm);
	NullWork(work, loc_number, n);
	system("cls");
	return;
}
int EnterMenu(const int size_menu) {
	int i = 0;
	char ent[20];
	//���������� ���������� �� ��� �������, ��������� �������������, � ���� ������, ��� ����- //������� �����������,
	// �������� �� �� ������
	cin>>ent;
		i = atoi(&ent[0]);
	if ((i < 1) || (i > size_menu)) {
		cout<<ent<<" -�� �������� ������� ����. ��� ����������� ������� ����� ������� "; // ��� ��������--------------------
		_getch();
		i = 0;
	}
	system("cls");
	return i;
}
void AddMm(Worker work[], Worker* loc_number[], const int n) {
	Worker* work_buf = 0;
	//������ ���������� ���� bool ��� ����������� ���� �� ��������� ����� � ���� ������
	bool place = false;
	int i = 0, k = 0;
	for (i = 0; i < n; i++) {
		if (work[i].be == false) {
			place = true; //����� ����
			break;
		}
	}
	//�� ����� ����� for ���������� place = true � ��� ������ ���� � ���� ���� ����� //��� ���� ������ �����.
	//� ���� ������ ������� ����� loc_number [0]==0
	if (!place) {
		cout<<"���������� ���������� ����������.���� ������������!"<<endl;
		_getch();
		system("cls");
		return;
	}
	//-----------------------------------------------------------------------------
	cout<<"������� ������� ��������� : ";
		cin>>work [i].surname;
		cout<<"������� �������� ��������� : ";
		cin>>work [i].salary;
		work[i].be = true;
	//���������� ���������� ������� ����������
	for (i = 1; i < n - 1; i++) {
		for (k = 0; k < n - i; k++) {
			if (SortWork((*loc_number[k]).surname, (*loc_number[k + 1]).surname) && ((*loc_number[k + 1]).be == true)) {
				work_buf = loc_number[k];
				loc_number[k] = loc_number[k + 1];
				loc_number[k + 1] = work_buf;
			}
		}
	}
	system("cls");
	return;
}
bool SortWork(char str1[], char str2[]) {
	int i = 0;
	do {
		if (str1[i] > str2[i]) {
			return true;
			break;
		}
		else if (str1[i] < str2[i]) break;
		i++;
	} while ((str1[i] != '\0') && (str2[i] != '\0'));
	return false;
}
void DelMm(Worker* loc_number[], const int n) {
	bool is = false;
	char del_surname[20];
	unsigned int i = 0, k = 0;
	cout<<"������� ������� ����������, �������� ������ ������� �� ���� : ";
		cin>>del_surname;
		do {
			if ((*loc_number[i]).be) { //����� ����� ���������� �� �������
				for (k = 0; k < strlen(del_surname); k++) {
					if (del_surname[k] != (*loc_number[i]).surname[k]) {
						is = false; //� ������ ������������ ����� �����
						break;
					}
					else is = true; //is=true � ������� �������
				}
				if (is) break;
			}
			i++;
		} while (static_cast<int>(i) < n);
		if (!is) {
			cout<<"���������� �� �������" << del_surname << "� ���� �� ���������� ";
				_getch();
			cout<<endl;
		}
		if (is) {
			strcpy_s((*loc_number[i]).surname, "0");
			(*loc_number[i]).salary = 0;
			(*loc_number[i]).be = false;
		}
		system("cls");
}
void SaveMm(Worker work[], const int n) {
	char name[20];
	cout<<"������� ��� ����� � ������� �� ������ ��������� ���� ����������� : ";
		cin>>name;
		ofstream fptr(name);
	for (int i = 0; i < n; i++) {
		if (work[i].be) {
			fptr.write(reinterpret_cast<char*>(&work[i].be), sizeof(bool));
			fptr.write(work[i].surname, 20);
			fptr.write(reinterpret_cast<char*>(&work[i].salary), sizeof(double));
		}
	}
	fptr.close();
	system("cls");
	return;
}
bool ExtMm(Worker work[], Worker* loc_number[], const int n) {
	Worker* work_buf = 0;
	char data_base[20];
	cout<<"������� ��� �����, � ������� ���������� ���� ����������� : ";
		cin>>data_base;
		ifstream fptr;
	fptr.open(data_base);
	if (!fptr) {
		cout<<"���� ����������� � ������ " <<data_base<< " �� ����������! "<<endl;
			_getch();
		system("cls");
		return false;
	}
	for (int i = 0; i < n; i++) {
		fptr.read(reinterpret_cast<char*>(&work[i].be), sizeof(bool));
		fptr.read(work[i].surname, 20);
		fptr.read(reinterpret_cast<char*>(&work[i].salary), sizeof(double));
	}
	fptr.close();
	//���������� ���������� ������� ����������
	for (int i = 1; i < n - 1; i++) {
		for (int k = 0; k < n - i; k++) {
			if (SortWork((*loc_number[k]).surname, (*loc_number[k + 1]).surname) && ((*loc_number[k + 1]).be == true)) {
				work_buf = loc_number[k];
				loc_number[k] = loc_number[k + 1];
				loc_number[k + 1] = work_buf;
			}
		}
	}
	system("cls");
	return true;
}
bool ExitMm(bool save) {
	if (!save) {
		enum CHOISE_EM { back_em = 1, output_em };
		int point_em;
		cout<<"���� ����������� �� ���� ��������� � ����."<<
			endl<<" ��� ������ �� ��������� �� ������ �������� ������!"<<endl<<endl;
			do {
				cout<<"------------------"<<endl<<endl;
					cout<<"1: �����; "<<endl<<endl;
					cout<<"2: �����; "<<endl<<endl;
					cout<<"------------------"<<endl<<endl;
					point_em = EnterMenu(output_em);
				switch (point_em) {
				case 0:
					break;
				case back_em:
					return true; //�����
				case output_em:
					return false; //�����
				}
			} while (!point_em);
	}
	return false;
}
void InformMm(Worker* loc_number[], const int n) {
	double total = 0, max = 0;
	int k;
	enum CHOISE_MM { out_im = 1, total_im, max_im, exit_im };
	int point_im;
	do {
		cout<<"---------------------------------- - "<<endl;
		cout<<" ���� "<<endl;
		cout<<"---------------------------------- - "<<endl<<endl;
			cout<<"1: ����� ����������� �� �����; "<<endl<<endl;
			cout<<"2: ��������� ��������� �����������; " << endl << endl;
			cout<<"3: ��������� � ���������� ���������; " << endl << endl;
			cout<<"4: �����; " << endl << endl;
			cout<<"---------------------------------- - " << endl << endl;
			point_im = EnterMenu(exit_im);
		switch (point_im) {
		case 0:
			break;
		case out_im:
			cout<<endl<<endl<<"-------------------------------------- - "<<endl;
			cout<<" ������� | �������� "<<endl;
			cout<<"-------------------------------------- - "<<endl<<endl;
				for (int i = 0; i < n; i++) {
					if ((*loc_number[i]).be == false) continue;
					cout.setf(ios::left);
					cout<<setw(20)<<(*loc_number[i]).surname<<setw(20)<<(*loc_number[i]).salary<<endl; // ������� �����
				}
			cout<<"-------------------------------------- - "<<endl<<endl;
				_getch();
			break;
		case total_im:
			for (int i = 0; i < n; i++) {
				if ((*loc_number[i]).be == false) continue;
				total += (*loc_number[i]).salary;
			}
			cout<<endl<<endl<<"--------------------------------------------"<<endl;
			cout<<" ��������� ��������� ����������� = "<<total<<endl;
				cout<<"--------------------------------------------"<<endl;
			total = 0;
			_getch();
			break;
		case max_im:
			for (int i = 0; i < n; i++) {
				if ((*loc_number[i]).be == false) continue;
				if ((*loc_number[i]).salary > max) {
					max = (*loc_number[i]).salary;
					k = i;
				}
			}
			cout<<endl<<endl<<"-------------------------------------- - "<<endl;
			cout<<" ��������� � ���������� ��������� : "<<endl;
			cout<<"-------------------------------------- - "<<endl;
			cout<<" ������� | �������� "<<endl;
			cout<<"-------------------------------------- - "<<endl;
			for (int i = 0; i < n; i++) {
				if ((*loc_number[i]).salary == max) {
					cout.setf(ios::left);
					cout<<setw(20)<<(*loc_number[i]).surname<<setw(20)<<(*loc_number[i]).salary<<endl;
				}
			}
			cout<<"-------------------------------------- - "<<endl;
			_getch();
			break;
		case exit_im:
			break;
		}
		system("cls");
	} while (point_im != exit_im);
	return;
}
void NullWork(Worker work[], Worker* loc_number[], const int n) {
	//������������ ������� Worker ����������� ������� ��������
	for (int i = 0; i < n; i++) {
		strcpy_s(work[i].surname, "0");
		work[i].salary = 0;
		work[i].be = false;
		loc_number[i] = &work[i];
	}
	return;
}
