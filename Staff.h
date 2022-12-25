#pragma once
#ifndef STAFF_H
#define STAFF_H

#include "iostream"
#include "windows.h"
#include <stdlib.h>

using namespace std;

class Staff {

public:
	string lastName, firstName, patronymic;
	int tabnumber;
	int month;
	int year;
	double hours;
	int order;
	Staff();

	Staff(string lastName, string firstName, string patronymic, int tabnumber, int month, int year, double hours, int order);

	~Staff();

	string getLastName();

	string getFirstName();

	string getPatronymic();

	int getTabnumber();

	int getMonth();

	int getYear();

	double getHours();

	int getOrder();

	string getFullName();

	string getShortFullName();

	string getFullDate();

	string from_DOS(std::string DOS_string);

	void setFullName(string lastName, string firstName, string patronymic);

	void setFullDate(int month, int year);

	void setTabnumber(int tabnumber);

	void setOrder(int order);

	void setHours(int hours);

	void Order(int order);

	void enterNewData();

};

#endif STAFF_H