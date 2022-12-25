#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "Staff.h"
#include <list>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

class Database
{
private:
	string command;



	string from_DOS(string DOS_string);

	void printError(int error);

	void multiPrint(char simbol, int count);

	void printAllStaffs();

	void addNewStaffInFileDB(Staff* PtrStaff);

public:
	list<Staff> liststaffs;

	Database();

	~Database();

	void printRowStaff(Staff* PtrStaff, int countStaffs);

	void loadDataAboutStaffs();

	void saveData();

	void viewAllStaffs();

	void payment();

	void addNewStaff();

	void deleteStaff();

	void createDatabaseFile();

	void openFile();

	void removeFile();

	void editStaff();

	void viewpofio();

	void viewpoorder();

	void printstaffspofio();

	void printstaffspoorder();

	void printHeaderStaffs();

	void podschet();
};


#endif DATABASE_H
