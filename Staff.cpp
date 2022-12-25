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
		cout << "\n������� ������� - ";
		cin >> lastName;
		cout << "������� ��� - ";
		cin >> firstName;
		cout << "������� �������� - ";
		cin >> patronymic;
		cout << "\n������� ��������� ����� - ";
		cin >> ttabnumber;
		tabnumber = atoi(ttabnumber.c_str());
		cout << "\n������� ���  - ";
		cin >> tmpyear;
		year = atoi(tmpyear.c_str());
		cout << "\n������� �����  - ";
		cin >> tmpmonth;
		month = atoi(tmpmonth.c_str());
		cout << "\n������� ���������� ����� - ";
		cin >> tmphours;
		hours = atoi(tmphours.c_str());
		cout << "\n������� ���������� ������� - ";
		cin >> tmporder;
		order = atoi(tmporder.c_str());
	}
	catch (...) {
		system("cls");
		cout << "\n\n-----������!-----\n";
		cout << "\n��� �� ����� ��������� ��������� �������!\n";
		cout << "��������� ������������ �������� ������ � ���������� ��� ���!\n\n";
		system("pause");
		system("cls");
	}

}