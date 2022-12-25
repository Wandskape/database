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
		cout << "\n\nТакой команды нет в меню!";
		cout << "\n\nПопытайтесь ещё раз.\n\n";
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
		cout << "\n-----Меню администратора-----\n\n";
		cout << "1.Работа с БД водителей\n";
		cout << "2.Работа с файлом БД\n";
		cout << "3.Управление учетными записями пользователей\n"; //добавить, yдалить, отредактировать, просмотреть все
		cout << "0.Выход в главное меню\n";
		try {
			cout << "\n\n\nВведите номер меню: "; cin >> enterNumber;
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
				cout << "------------------ Управление учётными записями пользователей------------------" << endl;
				cout << "1.Просмотреть учётные записи" << endl;
				cout << "2.Удалить учётную запись" << endl;
				cout << "3.Редактировать учётную запись" << endl;
				cout << "4.Добавить учётную запись" << endl;
				cout << "0.Выход" << endl;
				cout << "Ваш выбор: ";
				cin >> ch;

				switch (ch)
				{
				case 1:
				{
					for (int i = 0; i < users.size(); i++)
					{
						cout << "Логин: " << users[i].login << endl;
						cout << "Пароль: " << users[i].password << endl << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Введите логин учётной записи, которую нужно удалить: ";
					string login;
					bool t = false;

					cin >> login;


					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].login == login)
						{
							users.erase(users.begin() + i);
							t = true;
							cout << "Аккаунт удален" << endl;
						}
					}

					if (!t)
					{
						cout << "Логин не найден" << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Введите логин учётной записи, которую нужно изменить: ";
					string login;
					bool t = false;

					cin >> login;

					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].login == login)
						{
							cout << "Логин: ";
							cin >> users[i].login;
							cout << "Пароль: ";
							cin >> users[i].password;

							t = true;

						}
					}

					if (!t)
					{
						cout << "Логин не найден" << endl;
					}
					break;
				}
				case 4:
				{
					User us;
					cout << "Админ(1/0): ";
					string tmp;
					cin >> tmp;
					us.admin = stoi(tmp);
					//cin >> us.admin;
					cout << "Логин: ";
					cin >> us.login;
					cout << "Пароль: ";
					cin >> us.password;

					bool t = false;

					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].login == us.login)
						{
							cout << "Такой логин уже существует" << endl;
							t = true;
						}
					}


					for (int i = 0; i < admins.size(); i++)
					{
						if (admins[i].login == us.login)
						{
							cout << "Такой логин уже существует" << endl;
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
		cout << "\n-----Меню работы со списком водителей-----\n\n";
		cout << "1.Просмотр всех водителей\n";
		cout << "2.Добавить нового водителя\n";
		cout << "3.Редактировать информацию о водителе\n";
		cout << "4.Удалить водителя\n";
		cout << "5.Поиск водителя\n";
		cout << "6.Сортировка водителей\n";
		cout << "7.Рассчитать заработок водителя\n";
		cout << "0.Вернуться в главное меню\n";
		try {
			cout << "\n\n\nВведите номер меню: ";
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
		cout << "\n-----Меню работы с файлом БД-----\n\n";
		cout << "1.Создать файл\n";
		cout << "2.Открыть файл\n";
		cout << "3.Удалить файл\n";
		cout << "0.Вернуться в главное меню\n";
		try {
			cout << "\n\n\nВведите номер меню: ";
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
		cout << "\n-----Меню поиска-----\n\n";
		cout << "1.Список водителей по фамилии\n";
		cout << "2.Список водителей по количеству заказов\n";
		cout << "0.Вернуться в главное меню\n";
		try {
			cout << "\n\n\nВведите номер меню: "; cin >> enterNumber;
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

//Функции сравнения по фамилии, количеству заказов, по табельному номеру//

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
		cout << "\n-----Меню сортировки-----\n\n";
		cout << "1.По фамилии\n";
		cout << "2.По количеству заказов\n";
		cout << "3.По табельному номерy\n";
		cout << "0.Вернуться в главное меню\n";
		try {
			cout << "\n\n\nВведите номер меню: "; cin >> enterNumber;
			menuNumber = stoi(enterNumber);
		}
		catch (...) { menuNumber = 404; }
		switch (menuNumber) {
		case 1:
			db.liststaffs.sort(comparer_lname);
			cout << endl << "Список отсортирован" << endl;
			db.viewAllStaffs();
			break;
		case 2:
			db.liststaffs.sort(comparer_order);
			cout << endl << "Список отсортирован" << endl;
			db.viewAllStaffs();
			break;
		case 3:
			db.liststaffs.sort(comparer_number);
			cout << endl << "Список отсортирован" << endl;
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
