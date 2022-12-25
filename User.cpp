#include "User.h"
#include <iostream>


using namespace std;

void User::showusermenu()
{
	database.loadDataAboutStaffs();
	while (true)
	{
		cout << "------------------- ���� ������������ ---------------------" << endl;
		cout << "1.����������� ��� ������" << endl;
		cout << "2.��������� ����� ���������" << endl;
		cout << "3.��������� ����������" << endl;
		cout << "0.��������� � ������� ����" << endl;
		cout << "��� �����: ";
		int choise;
		cin >> choise;

		switch (choise)
		{
		case 1:
			database.viewAllStaffs();
			break;
		case 2:
		{
			int menuNumber;
			string enterNumber;
			while (true) {
				system("cls");
				cout << "\n-----���� ������-----\n\n";
				cout << "1.������ ��������� �� �������\n";
				cout << "2.������ ��������� �� ���������� �������\n";
				cout << "0.��������� � ������� ����\n";
				try {
					cout << "\n\n\n������� ����� ����: ";
					cin >> enterNumber;
					menuNumber = stoi(enterNumber);
				}
				catch (...) { menuNumber = 404; }
				switch (menuNumber) {
				case 1:
					//db.viewInogorodStaffs();
					database.viewpofio();
					break;
				case 2:
					//db.viewFoundStaffs();
					database.viewpoorder();
					break;
				case 0:
					return;
				}
			}
		}
		break;
		case 3:
			showMenuSortt();
			break;
		case 0:
			return;
		}
	}
}




bool compar_lname(Staff& a, Staff& b) {
	return a.lastName < b.lastName;
}
bool compar_order(Staff& a, Staff& b)
{
	return a.order < b.order;
}
bool compar_number(Staff& a, Staff& b)
{
	return a.tabnumber < b.tabnumber;
}

void User::showMenuSortt() {
	int menuNumber;
	string enterNumber;

	system("cls");
	while (true)
	{
		cout << "\n-----���� ����������-----\n\n";
		cout << "1.�� �������\n";
		cout << "2.�� ���������� �������\n";
		cout << "3.�� ���������� ������y\n";
		cout << "0.��������� � ������� ����\n";
		try {
			cout << "\n\n\n������� ����� ����: "; cin >> enterNumber;
			menuNumber = stoi(enterNumber);
		}
		catch (...) { menuNumber = 404; }
		switch (menuNumber) {
		case 1:
			database.liststaffs.sort(compar_lname);
			cout << endl << "������ ������������. ��������� � ���� ���������" << endl;
			database.viewAllStaffs();
			break;
		case 2:
			database.liststaffs.sort(compar_order);
			cout << endl << "������ ������������. ��������� � ���� ���������" << endl;
			database.viewAllStaffs();
			break;
		case 3:
			database.liststaffs.sort(compar_number);
			cout << endl << "������ ������������. ��������� � ���� ���������" << endl;
			database.viewAllStaffs();
			break;
		case 0:
			break;
		case 404:
			//printError(1);
			break;
		default:
			//	printError(1);
			break;
		}
	}
}

