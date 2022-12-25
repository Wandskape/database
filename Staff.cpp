#include "Staff.h"
#include <stdio.h>
#include <string>


using namespace std;

Staff::Staff() {}

Staff::Staff(string lastName, string firstName, string patronymic, int tabnumber, int month, int year, double hours, int order) {
	this->lastName = lastName;
	this->firstName = firstName;
	this->patronymic = patronymic;
	this->tabnumber = tabnumber;
	this->month = month;
	this->year = year;
	this->hours = hours;
	this->order = order;
}

Staff::~Staff() {}

string Staff::from_DOS(string DOS_string) {
	char buf[100];
	OemToCharA(DOS_string.c_str(), buf);
	return buf;
}

string Staff::getLastName() { return lastName; }

string Staff::getFirstName() { return firstName; }

string Staff::getPatronymic() { return patronymic; }

int Staff::getTabnumber() { return tabnumber; }

int Staff::getMonth() { return month; }

int Staff::getYear() { return year; }

double Staff::getHours() { return hours; }

int Staff::getOrder() { return order; }

string Staff::getFullName() {
	return lastName + " " + firstName + ". " + patronymic + ".";
}

string Staff::getShortFullName() {
	return lastName + " " + firstName[0] + "." + patronymic[0] + ".";
}

string Staff::getFullDate()
{
	return to_string(month) + "/" + to_string(year);
}

void Staff::setFullName(string lastName, string firstName, string patronymic) {
	this->lastName = lastName;
	this->firstName = firstName;
	this->patronymic = patronymic;
}

void Staff::setFullDate(int month, int year)
{
	this->month = month;
	this->year = year;
}

void Staff::setTabnumber(int tabnumber) { this->tabnumber = tabnumber; }

void Staff::setHours(int hours) { this->hours = hours; }

void Staff::setOrder(int order) { this->order = order; }

void Staff::enterNewData() {
	string tmpmonth;
	string tmpyear;
	string ttabnumber;
	string tmphours;
	string tmporder;

	try {
		cout << "\nВведите фамилию - ";
		cin >> lastName;
		cout << "Введите имя - ";
		cin >> firstName;
		cout << "Введите отчество - ";
		cin >> patronymic;
		cout << "\nВведите табельный номер - ";
		cin >> ttabnumber;
		tabnumber = atoi(ttabnumber.c_str());
		cout << "\nВведите год  - ";
		cin >> tmpyear;
		year = atoi(tmpyear.c_str());
		cout << "\nВведите месяц  - ";
		cin >> tmpmonth;
		month = atoi(tmpmonth.c_str());
		cout << "\nВведите количество часов - ";
		cin >> tmphours;
		hours = atoi(tmphours.c_str());
		cout << "\nВведите количество заказов - ";
		cin >> tmporder;
		order = atoi(tmporder.c_str());
	}
	catch (...) {
		system("cls");
		cout << "\n\n-----ОШИБКА!-----\n";
		cout << "\nГод не может содержать строковые символы!\n";
		cout << "Проверьте корректность введённых данных и попробуйте ещё раз!\n\n";
		system("pause");
		system("cls");
	}

}