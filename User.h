#pragma once
#include <iostream>
#include <string>
#include "Database.h"

using namespace std;

class User
{
public:
	string password;
	string login;
	bool admin;

	Database database;
	void showusermenu();
	void showMenuSortt();
};
