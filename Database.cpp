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

		cout << "Файл базы водителей не найден!\n";
		cout << "Был создан новый файл - Staffs!\n\n";
		system("pause");
		break;

	case 2:

		system("cls");
		cout << "\n--------------------------------------------\n\n";
		cout << "           Предупреждение!\n\n";
		cout << "Файл с информацией о водителях пуст или отсутствует\n\n";
		cout << "Обратитесь к администратору!\n\n\n";
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
	cout << "| " << setw(4) << "№" << " | " << setw(15) << "ФИО водителя" << " | " << setw(10) << "Номер" << " | " << setw(10) << "Месяц/год" << " | " << setw(15) << "Время работы" << " | " << endl;
	multiPrint('=', 117); cout << endl;
}

Database::Database()
{
}

Database::~Database()
{
}

//Печать строки с информацией о водителе
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


//Метод осуществляет вывод(отрисовку таблицы) в консоль всех водителей
void Database::printAllStaffs() {
	printHeaderStaffs();
	int countStaffs = 1;
	for (auto iterP = liststaffs.begin(); iterP != liststaffs.end(); ++iterP) {
		printRowStaff(&(*iterP), countStaffs);
		countStaffs++;
	}
}

//Просмотр всех водителей
void Database::viewAllStaffs() {
	system("cls");
	cout << "\n----Список всех водителей----\n\n";
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
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	system("cls");
	cout << "\n-----Добавление нового водителя-----\n\n";
	Staff* staff = new Staff();
	staff->enterNewData();
	cout << "ФИО : " + staff->getFullName() << endl;
	cout << "Табельный номер: " + to_string(staff->tabnumber) << endl;
	cout << "Год: " + to_string(staff->year) << endl;
	cout << "Месяц: " + to_string(staff->month) << endl;
	cout << "Количество часов за неделю: " << to_string(staff->hours) << endl;
	//cout << "Количество заказов: " + to_string(staff->order) << endl << endl;
	cout << "Добавить нового водителя (да/нет) - ";
	cin >> command;
	cout << endl;
	//command = from_DOS(command);
	if (command == "да" || command == "y") {
		liststaffs.push_back(*staff);
		addNewStaffInFileDB(staff);
		cout << "Водитель успешно добавлен в базу!\n\n";
		system("pause");
	}
	else {
		delete staff;
		cout << "Отмена добавления водителя.\n\n";
		system("pause");
	}
}


//Удаление водителя по порядковому номеру
void Database::deleteStaff()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	system("cls");

	string StaffNumberForRemove; system("cls");
	cout << "\n-----Удаление водителя из базы-----\n" << endl;
	printAllStaffs();
	cout << "\nВведите  номер водителя для удаления - "; cin >> StaffNumberForRemove;
	int countStaffs = 1;
	for (auto iterP = liststaffs.begin(); iterP != liststaffs.end(); ++iterP) {
		if (to_string(countStaffs) == StaffNumberForRemove) {
			system("cls"); cout << "\nВодитель успешно найден!\n\n";
			printHeaderStaffs();
			printRowStaff(&(*iterP), countStaffs);
			cout << "\n\nУдалить водителя (да/нет) - ";
			cin >> command;
			command = command;
			if (command == "да" || command == "y") {
				liststaffs.erase(iterP);
				saveData();
				cout << "\nВодитель успешно удалён!\n\n";
				system("pause");
				return;
			}
			cout << "\nОтмена удаления!\n\n";
			system("pause");
			return;
		}
		countStaffs++;
	}
	cout << "\nВодителя с таким номером нет в списке!\n\n";
	system("pause");
}

void Database::createDatabaseFile()
{
	string name;

	cout << endl << "------------------- Создание файла ------------------ " << endl;
	cout << "Введите название файла(без типа): ";
	cin >> name;
	ofstream fout(name + ".txt");
	fout << "Файл_создан" << endl;
	cout << "Файл_создан" << endl << endl;
	fout.close();
}

void Database::openFile()
{
	string res;
	string name;
	cout << "Введите название файла(без типа): ";
	cin >> name;
	name += ".txt";
	ifstream fin(name.c_str());

	fin >> res;
	cout << "Файл успешно открыт" << endl;
}




void Database::removeFile()
{
	string name;
	cout << endl << "------------------- Удаление файла ------------------ " << endl;
	cout << "Введите название файла(без типа): ";
	cin >> name;

	name += ".txt";
	if (remove(name.c_str()) != 0)             // удаление файла
	{
		std::cout << "Ошибка удаления файла" << endl << endl;
	}
	else
	{
		std::cout << "Файл успешно удалён" << endl << endl;
	}
}

void Database::editStaff()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода


	string StaffNumberForRemove;
	system("cls");
	cout << "\n-----Изменение водителя из базы-----\n" << endl;
	printAllStaffs();
	cout << "\nВведите номер водителя для изменения - ";
	cin >> StaffNumberForRemove;
	int countStaffs = 1;

	for (auto& iterP : liststaffs)
	{
		if (to_string(countStaffs) == StaffNumberForRemove)
		{
			system("cls");
			cout << "\nВодитель успешно найден!\n\n";

			Staff* staff = new Staff();
			staff->enterNewData();
			cout << "\nВы действительно хотите изменить данные водителя?\n";
			cout << "\nФИО : " + staff->getFullName();
			cout << "\nТабельный номер: " + to_string(staff->getTabnumber());
			cout << "\nГод: " + to_string(staff->getYear());
			cout << "\nМесяц: " + to_string(staff->getMonth());
			cout << "\nКоличество часов: " << to_string(staff->getHours());
			cout << "\nКоличество заказов: " + to_string(staff->getOrder());
			cout << "\n\nИзменить анкету водителя (да/нет) - ";
			cin >> command;
			cout << endl;
			if (command == "да" || command == "y")
			{
				iterP.firstName = staff->firstName;
				iterP.lastName = staff->lastName;
				iterP.patronymic = staff->patronymic;
				iterP.tabnumber = staff->tabnumber;
				iterP.year = staff->year;
				iterP.month = staff->month;
				iterP.hours = staff->hours;
				iterP.order = staff->order;


				cout << "Водитель успешно изменён!\n\n";
				system("pause");
			}
			else {
				delete staff;
				cout << "Отмена изменения водителя.\n\n";
				system("pause");
			}

			saveData();
			system("pause");
			return;
		}
		countStaffs++;
	}
	cout << "\nВодителя с таким номером нет в списке!\n\n";
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
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	string lname;
	cout << "Введите фамилию: ";
	cin >> lname;


	cout << "\n----Список найденных водителей----\n\n";

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
		cout << "Совпадений не найдено" << endl;
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
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	int counter;
	cout << "Введите количество заказов: ";
	cin >> counter;

	cout << "\n----Список найденных водителей----\n\n";

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
		cout << "Совпадений не найдено" << endl;
	}

}

void Database::podschet()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода


	string StaffNumberForRemove;

	double comission;
	double gpribil;
	int nedelcount;

	system("cls");
	cout << "\n-----Подсчёт заработка водителя из базы-----\n" << endl;
	printAllStaffs();
	cout << "\nВведите номер водителя для подсчёта - ";
	cin >> StaffNumberForRemove;
	int countStaffs = 1;

	for (auto& iterP : liststaffs)
	{
		if (to_string(countStaffs) == StaffNumberForRemove)
		{
			system("cls");
			cout << "\nВодитель успешно найден!\n\n";
			cout << "Введите комиссию таксопарка: ";
			cin >> comission;
			cout << "Введите прибыль водителя за час: ";
			cin >> gpribil;
			cout << "Введите количество недель: ";
			cin >> nedelcount;
			cout << "Зарплата водителя за одну неделю составляет: " << iterP.hours * gpribil * (1 - 0.23) * (1 - comission / 100) * nedelcount << endl;
			system("pause");
			return;
		}
	}
	cout << "\nВодителя с таким номером нет в списке!\n\n";
	system("pause");
}
