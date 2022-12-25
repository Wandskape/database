#include "Database.h"
#include <iostream>

using namespace std;

string Database::from_DOS(string DOS_string) {
	char buf[50];
	OemToCharA(DOS_string.c_str(), buf);
	return buf;
}

void Database::printError(int error)
{
	switch (error)
	{
	case 1:

		cout << "���� ���� ��������� �� ������!\n";
		cout << "��� ������ ����� ���� - Staffs!\n\n";
		system("pause");
		break;

	case 2:

		system("cls");
		cout << "\n--------------------------------------------\n\n";
		cout << "           ��������������!\n\n";
		cout << "���� � ����������� � ��������� ���� ��� �����������\n\n";
		cout << "���������� � ��������������!\n\n\n";
		cout << "Code Error 2, File Staffs is not found!" << endl;
		cout << "\n--------------------------------------------\n\n";
		system("pause");
		break;
	}
}

void Database::multiPrint(char simbol, int count)
{
	for (int i = 0; i < count; ++i)
	{
		cout << simbol;
	}
}


void Database::printHeaderStaffs() {
	multiPrint('=', 117); cout << endl;
	cout << "| " << setw(4) << "�" << " | " << setw(15) << "��� ��������" << " | " << setw(10) << "�����" << " | " << setw(10) << "�����/���" << " | " << setw(15) << "����� ������" << " | " << endl;
	multiPrint('=', 117); cout << endl;
}

Database::Database()
{
}

Database::~Database()
{
}

//������ ������ � ����������� � ��������
void Database::printRowStaff(Staff* PtrStaff, int countStaffs) {
	cout << "| " << setw(4) << countStaffs << " | "
		<< setw(15) << (*PtrStaff).getShortFullName() << " | "
		<< setw(10) << (*PtrStaff).getTabnumber() << " | "
		<< setw(10) << (*PtrStaff).getFullDate() << " | "
		<< setw(15) << (*PtrStaff).getHours() << " | " << endl;
	//<< setw(18) << (*PtrStaff).getOrder() << " | " 
	multiPrint('-', 117);
	cout << endl;
}

void Database::loadDataAboutStaffs() {
	string lastName, firstName, patronymic;
	string number;
	string day;
	string month;
	string year;
	string hour;
	string order;

	ifstream file("Staffs");
	if (file.is_open())
	{
		while (file)
		{
			file >> lastName >> firstName >> patronymic >> number >> day >> month >> year >> hour >> order;
			if (file.eof()) break;
			Staff Staff(lastName, firstName, patronymic, atoi(number.c_str()), atoi(month.c_str()), atoi(year.c_str()), atof(hour.c_str()), atoi(order.c_str()));
			liststaffs.push_back(Staff);
		}
	}
	else {
		printError(2);
	}
	file.close();
}


void Database::addNewStaffInFileDB(Staff* PtrStaff) {
	ifstream file("Staffs");
	if (file.is_open()) {
		file.close();
		ofstream addInFile("Staffs", ios_base::app);
		addInFile << (*PtrStaff).getLastName() << " " << (*PtrStaff).getFirstName() << " "
			<< (*PtrStaff).getPatronymic() << " " << (*PtrStaff).getTabnumber() << " "
			<< " " << (*PtrStaff).getMonth() << " "
			<< (*PtrStaff).getYear() << " " << (*PtrStaff).getHours() << " "
			<< (*PtrStaff).getOrder() << endl;
		addInFile.close();
	}
	else {
		printError(1);
		ofstream newFile("Staffs", ios_base::app);
		newFile << (*PtrStaff).getLastName() << " " << (*PtrStaff).getFirstName() << " "
			<< (*PtrStaff).getPatronymic() << " " << (*PtrStaff).getTabnumber() << " "
			<< " " << (*PtrStaff).getMonth() << " "
			<< (*PtrStaff).getYear() << " " << (*PtrStaff).getHours() << " "
			<< (*PtrStaff).getOrder() << endl;
		newFile.close();
	}
}

void Database::saveData() {
	ofstream file("Staffs");
	for (auto iterP = liststaffs.begin(); iterP != liststaffs.end(); ++iterP) {
		file << (*iterP).getLastName() << " " << (*iterP).getFirstName() << " "
			<< (*iterP).getPatronymic() << " " << (*iterP).getTabnumber() << " "
			<< " " << (*iterP).getMonth() << " "
			<< (*iterP).getYear() << " " << (*iterP).getHours() << " "
			<< (*iterP).getOrder() << endl;
	}
	file.close();
}


//����� ������������ �����(��������� �������) � ������� ���� ���������
void Database::printAllStaffs() {
	printHeaderStaffs();
	int countStaffs = 1;
	for (auto iterP = liststaffs.begin(); iterP != liststaffs.end(); ++iterP) {
		printRowStaff(&(*iterP), countStaffs);
		countStaffs++;
	}
}

//�������� ���� ���������
void Database::viewAllStaffs() {
	system("cls");
	cout << "\n----������ ���� ���������----\n\n";
	printAllStaffs();
	cout << "\n\n";
	system("pause");
}

void Database::payment()
{
}


void Database::addNewStaff()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	system("cls");
	cout << "\n-----���������� ������ ��������-----\n\n";
	Staff* staff = new Staff();
	staff->enterNewData();
	cout << "��� : " + staff->getFullName() << endl;
	cout << "��������� �����: " + to_string(staff->tabnumber) << endl;
	cout << "���: " + to_string(staff->year) << endl;
	cout << "�����: " + to_string(staff->month) << endl;
	cout << "���������� ����� �� ������: " << to_string(staff->hours) << endl;
	//cout << "���������� �������: " + to_string(staff->order) << endl << endl;
	cout << "�������� ������ �������� (��/���) - ";
	cin >> command;
	cout << endl;
	//command = from_DOS(command);
	if (command == "��" || command == "y") {
		liststaffs.push_back(*staff);
		addNewStaffInFileDB(staff);
		cout << "�������� ������� �������� � ����!\n\n";
		system("pause");
	}
	else {
		delete staff;
		cout << "������ ���������� ��������.\n\n";
		system("pause");
	}
}


//�������� �������� �� ����������� ������
void Database::deleteStaff()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	system("cls");

	string StaffNumberForRemove; system("cls");
	cout << "\n-----�������� �������� �� ����-----\n" << endl;
	printAllStaffs();
	cout << "\n�������  ����� �������� ��� �������� - "; cin >> StaffNumberForRemove;
	int countStaffs = 1;
	for (auto iterP = liststaffs.begin(); iterP != liststaffs.end(); ++iterP) {
		if (to_string(countStaffs) == StaffNumberForRemove) {
			system("cls"); cout << "\n�������� ������� ������!\n\n";
			printHeaderStaffs();
			printRowStaff(&(*iterP), countStaffs);
			cout << "\n\n������� �������� (��/���) - ";
			cin >> command;
			command = command;
			if (command == "��" || command == "y") {
				liststaffs.erase(iterP);
				saveData();
				cout << "\n�������� ������� �����!\n\n";
				system("pause");
				return;
			}
			cout << "\n������ ��������!\n\n";
			system("pause");
			return;
		}
		countStaffs++;
	}
	cout << "\n�������� � ����� ������� ��� � ������!\n\n";
	system("pause");
}

void Database::createDatabaseFile()
{
	string name;

	cout << endl << "------------------- �������� ����� ------------------ " << endl;
	cout << "������� �������� �����(��� ����): ";
	cin >> name;
	ofstream fout(name + ".txt");
	fout << "����_������" << endl;
	cout << "����_������" << endl << endl;
	fout.close();
}

void Database::openFile()
{
	string res;
	string name;
	cout << "������� �������� �����(��� ����): ";
	cin >> name;
	name += ".txt";
	ifstream fin(name.c_str());

	fin >> res;
	cout << "���� ������� ������" << endl;
}




void Database::removeFile()
{
	string name;
	cout << endl << "------------------- �������� ����� ------------------ " << endl;
	cout << "������� �������� �����(��� ����): ";
	cin >> name;

	name += ".txt";
	if (remove(name.c_str()) != 0)             // �������� �����
	{
		std::cout << "������ �������� �����" << endl << endl;
	}
	else
	{
		std::cout << "���� ������� �����" << endl << endl;
	}
}

void Database::editStaff()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������


	string StaffNumberForRemove;
	system("cls");
	cout << "\n-----��������� �������� �� ����-----\n" << endl;
	printAllStaffs();
	cout << "\n������� ����� �������� ��� ��������� - ";
	cin >> StaffNumberForRemove;
	int countStaffs = 1;

	for (auto& iterP : liststaffs)
	{
		if (to_string(countStaffs) == StaffNumberForRemove)
		{
			system("cls");
			cout << "\n�������� ������� ������!\n\n";

			Staff* staff = new Staff();
			staff->enterNewData();
			cout << "\n�� ������������� ������ �������� ������ ��������?\n";
			cout << "\n��� : " + staff->getFullName();
			cout << "\n��������� �����: " + to_string(staff->getTabnumber());
			cout << "\n���: " + to_string(staff->getYear());
			cout << "\n�����: " + to_string(staff->getMonth());
			cout << "\n���������� �����: " << to_string(staff->getHours());
			cout << "\n���������� �������: " + to_string(staff->getOrder());
			cout << "\n\n�������� ������ �������� (��/���) - ";
			cin >> command;
			cout << endl;
			if (command == "��" || command == "y")
			{
				iterP.firstName = staff->firstName;
				iterP.lastName = staff->lastName;
				iterP.patronymic = staff->patronymic;
				iterP.tabnumber = staff->tabnumber;
				iterP.year = staff->year;
				iterP.month = staff->month;
				iterP.hours = staff->hours;
				iterP.order = staff->order;


				cout << "�������� ������� ������!\n\n";
				system("pause");
			}
			else {
				delete staff;
				cout << "������ ��������� ��������.\n\n";
				system("pause");
			}

			saveData();
			system("pause");
			return;
		}
		countStaffs++;
	}
	cout << "\n�������� � ����� ������� ��� � ������!\n\n";
	system("pause");
}

void Database::viewpofio()
{
	system("cls");
	printstaffspofio();
	cout << "\n\n";
	system("pause");
}


void Database::printstaffspofio()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

	string lname;
	cout << "������� �������: ";
	cin >> lname;


	cout << "\n----������ ��������� ���������----\n\n";

	printHeaderStaffs();
	int countStaffs = 1;
	for (auto iterP = liststaffs.begin(); iterP != liststaffs.end(); ++iterP)
	{
		if ((*iterP).getLastName() == lname)
		{
			printRowStaff(&(*iterP), countStaffs);
		}

		countStaffs++;
	}

	if (countStaffs == 1)
	{
		cout << "���������� �� �������" << endl;
	}

}



void Database::viewpoorder()
{
	system("cls");

	printstaffspoorder();


	cout << "\n\n";
	system("pause");
}

void Database::printstaffspoorder()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

	int counter;
	cout << "������� ���������� �������: ";
	cin >> counter;

	cout << "\n----������ ��������� ���������----\n\n";

	printHeaderStaffs();
	int countStaffs = 1;
	for (auto iterP = liststaffs.begin(); iterP != liststaffs.end(); ++iterP)
	{
		if ((*iterP).getOrder() == counter)
		{
			printRowStaff(&(*iterP), countStaffs);
		}

		countStaffs++;
	}

	if (countStaffs == 1)
	{
		cout << "���������� �� �������" << endl;
	}

}

void Database::podschet()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������


	string StaffNumberForRemove;

	double comission;
	double gpribil;
	int nedelcount;

	system("cls");
	cout << "\n-----������� ��������� �������� �� ����-----\n" << endl;
	printAllStaffs();
	cout << "\n������� ����� �������� ��� �������� - ";
	cin >> StaffNumberForRemove;
	int countStaffs = 1;

	for (auto& iterP : liststaffs)
	{
		if (to_string(countStaffs) == StaffNumberForRemove)
		{
			system("cls");
			cout << "\n�������� ������� ������!\n\n";
			cout << "������� �������� ����������: ";
			cin >> comission;
			cout << "������� ������� �������� �� ���: ";
			cin >> gpribil;
			cout << "������� ���������� ������: ";
			cin >> nedelcount;
			cout << "�������� �������� �� ���� ������ ����������: " << iterP.hours * gpribil * (1 - 0.23) * (1 - comission / 100) * nedelcount << endl;
			system("pause");
			return;
		}
	}
	cout << "\n�������� � ����� ������� ��� � ������!\n\n";
	system("pause");
}
