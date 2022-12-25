#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "class_Admin.h"
#include <vector>
#include <ctime>
#include <clocale>

using namespace std;

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода


	const time_t tm = time(nullptr);

	char buf[64];
	strftime(buf, std::size(buf), "%d.%m.%Y", localtime(&tm));


	system("color 02");


	cout << "Здравствуйте" << endl;
	cout << "Текущая дата и время: ";
	std::cout << currentDateTime() << std::endl;
	cout << "Разработчики проекта: " << endl;
	cout << "	Коломейчук Арсений Алексеевич " << endl;
	cout << "	Касперович Александр Сергеевич " << endl;
	cout << "	Федосова Людмила Х " << endl;
	cout << "Нажмите любую клавишу, что бы продолжить " << endl;
	char c;
	c = _getch();

	system("color 07");

	system("cls");
	User user;

	string password, login;

	bool l = false;

	Admin admin;
	admin.login = "admin";
	admin.password = "admin";
	admin.admins.push_back(admin);


	vector<User> users;

a:
	cout << endl << "-----Главное меню-----" << endl;
	cout << "Логин(Для выхода нажмите *): ";
	cin >> login;
	if (login == "*")
	{
		return 0;
	}

	cout << "Пароль: ";
	cin >> password;

	for (int i = 0; i < admin.admins.size(); i++)
	{
		if (admin.admins[i].login == login && admin.admins[i].password == password)
		{
			users = admin.startAdmin(users);
			l = true;
		}
	}

	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].admin == true && users[i].login == login && users[i].password == password)
		{
			users = admin.startAdmin(users);
			l = true;
			//goto a;
		}

		if (users[i].login == login && users[i].password == password)
		{
			user.showusermenu();
			l = true;
			//goto a;
		}
	}
	if (l == false)
	{
		cout << "Такой логин не найден" << endl;
		goto a;
	}
	goto a;



}