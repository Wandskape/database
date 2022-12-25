#include "class_Admin.h"
#include <iostream>
#include "Database.h"
//#include "User.h"

using namespace std;


/*
Admin::~Admin()
{
}
*/

Admin::Admin()
{
}



string Admin::from_DOS(string DOS_string) {
	char buf[50];
	OemToCharA(DOS_string.c_str(), buf);
	return buf;
}

void Admin::printError(int error) {
	switch (error)
	{
	case 1:
		cout << "\n\n����� ������� ��� � ����!";
		cout << "\n\n����������� ��� ���.\n\n";
		system("pause");
		break;
	}
}

vector<User> Admin::startAdmin(vector<User> users)
{
	int menuNumber; string enterNumber;

	db.loadDataAboutStaffs();




	while (true)
	{
		//	system("cls");
		cout << "\n-----���� ��������������-----\n\n";
		cout << "1.������ � �� ���������\n";
		cout << "2.������ � ������ ��\n";
		cout << "3.���������� �������� �������� �������������\n"; //��������, y������, ���������������, ����������� ���
		cout << "0.����� � ������� ����\n";
		try {
			cout << "\n\n\n������� ����� ����: "; cin >> enterNumber;
			menuNumber = stoi(enterNumber);
		}
		catch (...) { menuNumber = 404; }

		switch (menuNumber) {
		case 1:
			showMenuStaff();
			break;
		case 2:
			showMenuFileBD();
			break;
		case 3:
		{
			while (true)
			{
				int ch;
				cout << "------------------ ���������� �������� �������� �������������------------------" << endl;
				cout << "1.����������� ������� ������" << endl;
				cout << "2.������� ������� ������" << endl;
				cout << "3.������������� ������� ������" << endl;
				cout << "4.�������� ������� ������" << endl;
				cout << "0.�����" << endl;
				cout << "��� �����: ";
				cin >> ch;

				switch (ch)
				{
				case 1:
				{
					for (int i = 0; i < users.size(); i++)
					{
						cout << "�����: " << users[i].login << endl;
						cout << "������: " << users[i].password << endl << endl;
					}
					break;
				}
				case 2:
				{
					cout << "������� ����� ������� ������, ������� ����� �������: ";
					string login;
					bool t = false;

					cin >> login;


					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].login == login)
						{
							users.erase(users.begin() + i);
							t = true;
							cout << "������� ������" << endl;
						}
					}

					if (!t)
					{
						cout << "����� �� ������" << endl;
					}
					break;
				}
				case 3:
				{
					cout << "������� ����� ������� ������, ������� ����� ��������: ";
					string login;
					bool t = false;

					cin >> login;

					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].login == login)
						{
							cout << "�����: ";
							cin >> users[i].login;
							cout << "������: ";
							cin >> users[i].password;

							t = true;

						}
					}

					if (!t)
					{
						cout << "����� �� ������" << endl;
					}
					break;
				}
				case 4:
				{
					User us;
					cout << "�����(1/0): ";
					string tmp;
					cin >> tmp;
					us.admin = stoi(tmp);
					//cin >> us.admin;
					cout << "�����: ";
					cin >> us.login;
					cout << "������: ";
					cin >> us.password;

					bool t = false;

					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].login == us.login)
						{
							cout << "����� ����� ��� ����������" << endl;
							t = true;
						}
					}


					for (int i = 0; i < admins.size(); i++)
					{
						if (admins[i].login == us.login)
						{
							cout << "����� ����� ��� ����������" << endl;
							t = true;
						}
					}

					if (t == false)
					{
						users.push_back(us);
					}
					break;
				}
				case 0:
					break;
				}


				if (ch == 0)
				{
					break;
				}
			}

			break;
		}
		case 0:
			return users;
		case 4:
			return users;
		case 404:
			printError(1);
			break;
		default:
			printError(1);
			break;
		}
	}
}



void Admin::showMenuStaff() {
	int menuNumber;
	string enterNumber;
	while (true)
	{
		system("cls");
		cout << "\n-----���� ������ �� ������� ���������-----\n\n";
		cout << "1.�������� ���� ���������\n";
		cout << "2.�������� ������ ��������\n";
		cout << "3.������������� ���������� � ��������\n";
		cout << "4.������� ��������\n";
		cout << "5.����� ��������\n";
		cout << "6.���������� ���������\n";
		cout << "7.���������� ��������� ��������\n";
		cout << "0.��������� � ������� ����\n";
		try {
			cout << "\n\n\n������� ����� ����: ";
			cin >> enterNumber;
			menuNumber = stoi(enterNumber);
		}
		catch (...) { menuNumber = 404; }
		switch (menuNumber)
		{
		case 1:
			db.viewAllStaffs();
			break;
		case 2:
			db.addNewStaff();
			break;
		case 3:
			db.editStaff();
			break;
		case 4:
			db.deleteStaff();
			break;
		case 5:
			showMenuSearch();
			break;
		case 6:
			showMenuSort();
			break;
		case 7:
			db.podschet();
			break;
		case 0:
			break;
		case 404:
			printError(1);
			break;
		default:
			printError(1);
			break;
		}

		if (menuNumber == 0)
		{
			break;
		}
	}
}


void Admin::showMenuFileBD() {
	int menuNumber;
	string enterNumber;
	while (true) {
		//system("cls");
		cout << "\n-----���� ������ � ������ ��-----\n\n";
		cout << "1.������� ����\n";
		cout << "2.������� ����\n";
		cout << "3.������� ����\n";
		cout << "0.��������� � ������� ����\n";
		try {
			cout << "\n\n\n������� ����� ����: ";
			cin >> enterNumber;
			menuNumber = atoi(enterNumber.c_str());
		}
		catch (...) { menuNumber = 404; }
		switch (menuNumber) {
		case 1:
			db.createDatabaseFile();;
			break;
		case 2:
			db.openFile();
			break;
		case 3:
			db.removeFile();
			break;
		case 0:
			return;
		case 404:
			printError(1);
			break;
		default:
			printError(1);
			break;
		}
	}
}
void Admin::showMenuSearch() {
	int menuNumber;
	string enterNumber;
	while (true) {
		system("cls");
		cout << "\n-----���� ������-----\n\n";
		cout << "1.������ ��������� �� �������\n";
		cout << "2.������ ��������� �� ���������� �������\n";
		cout << "0.��������� � ������� ����\n";
		try {
			cout << "\n\n\n������� ����� ����: "; cin >> enterNumber;
			menuNumber = stoi(enterNumber);
		}
		catch (...) { menuNumber = 404; }
		switch (menuNumber) {
		case 1:
			//db.viewInogorodStaffs();
			db.viewpofio();
			break;
		case 2:
			//db.viewFoundStaffs();
			db.viewpoorder();
			break;
		case 0:
			return;
		case 404:
			printError(1);
			break;
		default:
			printError(1);
			break;
		}
	}
}

//������� ��������� �� �������, ���������� �������, �� ���������� ������//

bool comparer_lname(Staff& a, Staff& b) {
	return a.lastName < b.lastName;
}
bool comparer_order(Staff& a, Staff& b)
{
	return a.order < b.order;
}
bool comparer_number(Staff& a, Staff& b)
{
	return a.tabnumber < b.tabnumber;
}
void Admin::showMenuSort() {
	int menuNumber;
	string enterNumber;

	system("cls");
	while (true) {
		cout << "\n-----���� ����������-----\n\n";
		cout << "1.�� �������\n";
		cout << "2.�� ���������� �������\n";
		cout << "3.�� ���������� �����y\n";
		cout << "0.��������� � ������� ����\n";
		try {
			cout << "\n\n\n������� ����� ����: "; cin >> enterNumber;
			menuNumber = stoi(enterNumber);
		}
		catch (...) { menuNumber = 404; }
		switch (menuNumber) {
		case 1:
			db.liststaffs.sort(comparer_lname);
			cout << endl << "������ ������������" << endl;
			db.viewAllStaffs();
			break;
		case 2:
			db.liststaffs.sort(comparer_order);
			cout << endl << "������ ������������" << endl;
			db.viewAllStaffs();
			break;
		case 3:
			db.liststaffs.sort(comparer_number);
			cout << endl << "������ ������������" << endl;
			db.viewAllStaffs();
			break;
		case 0:
			return;
		case 404:
			printError(1);
			break;
		default:
			printError(1);
			break;
		}
	}
}

void Admin::showMenuEditStaff()
{

}
