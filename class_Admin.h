#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Database.h"
#include <vector>
#include "User.h"

using namespace std;

class Admin {
private:
	string familia;
	string name;


	void printError(int error);

	string from_DOS(string DOS_string);


public:

	string password;
	string login;

	vector<Admin> admins;
	Database db;

	int itog;
	int n;
	int size;

	Admin();

	//~Admin();


	const string get_familia() const { return familia; }
	const string get_name() const { return name; }
	const string get_password() const { return password; }
	const string get_login() const { return login; }


	//	void sravn();//функция сравнивает значения проинициализированных данных и введённые пользоваптелем
	//	void print();
	void showMenuStaff();
	void showMenuFileBD();

	void showMenuSearch();

	void showMenuSort();

	void showMenuEditStaff();

	vector<User> startAdmin(vector<User> users);

};




