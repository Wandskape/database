#include "User.h"
#include <iostream>


using namespace std;

void User::showusermenu()
{
	database.loadDataAboutStaffs();
	while (true)
	{
		cout << "------------------- Меню пользователя ---------------------" << endl;
		cout << "1.Просмотреть все данные" << endl;
		cout << "2.Выполнить поиск водителей" << endl;
		cout << "3.Выполнить сортировку" << endl;
		cout << "0.Вернуться в главное меню" << endl;
		cout << "Ваш выбор: ";
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
				cout << "\n-----Меню поиска-----\n\n";
				cout << "1.Список водителей по фамилии\n";
				cout << "2.Список водителей по количеству заказов\n";
				cout << "0.Вернуться в главное меню\n";
				try {
					cout << "\n\n\nВведите номер меню: ";
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
		cout << "\n-----Меню сортировки-----\n\n";
		cout << "1.По фамилии\n";
		cout << "2.По количеству заказов\n";
		cout << "3.По табельному номеруy\n";
		cout << "0.Вернуться в главное меню\n";
		try {
			cout << "\n\n\nВведите номер меню: "; cin >> enterNumber;
			menuNumber = stoi(enterNumber);
		}
		catch (...) { menuNumber = 404; }
		switch (menuNumber) {
		case 1:
			database.liststaffs.sort(compar_lname);
			cout << endl << "Список отсортирован. Перейдите в меню просмотра" << endl;
			database.viewAllStaffs();
			break;
		case 2:
			database.liststaffs.sort(compar_order);
			cout << endl << "Список отсортирован. Перейдите в меню просмотра" << endl;
			database.viewAllStaffs();
			break;
		case 3:
			database.liststaffs.sort(compar_number);
			cout << endl << "Список отсортирован. Перейдите в меню просмотра" << endl;
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

