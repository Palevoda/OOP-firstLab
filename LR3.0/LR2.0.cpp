//В соответствии со своим вариантом разработать программу для данных, приведенных в таблице ниже.Определить структурированный тип, 
//разработать меню для работы с массивом структур.
//В программу должны войти функции :
//	ввод элементов структуры с клавиатуры;
//	вывод элементов структуры в консольное окно;
//	удаление заданной структурированной переменной;
//	поиск информации;
//	запись информации в файл;
//	чтение данных из файла.
//Клиенты банка.Ф.И.О., тип счета(срочный, льготный и т.д.), номер счета, сумма на счете, дата последнего изменения.Выбор по номеру счета.

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstdlib>

using namespace std;
void funswitch();
int index = 0;

struct bank 
{
	char Name[50];
	char Sorname[50];
	char SecondName[50];
	char type[10];
	int label;
	int ballance = 0;
	char dateofchange[12];
};



bank listOfCustomers[1000];
void getDATA()
{
	ifstream findex("index.txt");
	ifstream fName("Name.txt");
	ifstream fSorname("Sorname.txt");
	ifstream fSecondName("SecondName.txt");
	ifstream ftype("type.txt");
	ifstream flabel("label.txt");
	ifstream fballance("ballance.txt");
	ifstream fdateofchange("dateofchange.txt");

	findex >> ::index;

	for (int i = 0; i <= index; i++)
	{
		fName >> listOfCustomers[i].Name;
		fSorname >> listOfCustomers[i].Sorname;
		fSecondName >> listOfCustomers[i].SecondName;
		ftype >> listOfCustomers[i].type;
		flabel >> listOfCustomers[i].label;
		fballance >> listOfCustomers[i].ballance;
		fdateofchange >> listOfCustomers[i].dateofchange;
	}

	findex.close();
	fName.close();
	fSorname.close();
	fSecondName.close();
	ftype.close();
	flabel.close();
	fballance.close();
	fdateofchange.close();
	
}










void addCustomer()
{
	fstream fName("Name.txt", ios::app);
	fstream fSorname("Sorname.txt", ios::app);
	fstream fSecondName("SecondName.txt", ios::app);
	fstream ftype("type.txt", ios::app);
	fstream flabel("label.txt", ios::app);
	fstream fballance("ballance.txt", ios::app);
	fstream fdateofchange("dateofchange.txt", ios::app);
	fstream findex("index.txt");
	findex >> index; 
	findex.close();
	//findex.seekg(0, ios::beg);
	
	cout << "Вы " << index << " клиент в банке!" << endl;
	cout << "Введите ваше имя: ";	cin >> listOfCustomers[index].Name; cout << endl;
	cout << "Введите вашу фамилию: ";	cin >> listOfCustomers[index].Sorname; cout << endl;
	cout << "Введите ваше отчество: ";	cin >> listOfCustomers[index].SecondName; cout << endl;
	cout << "Введите тип счета(fast/lg): ";	cin >> listOfCustomers[index].type; cout << endl;
	cout << "Введите дату: ";	cin >> (listOfCustomers[index].dateofchange); cout << endl;


	listOfCustomers[index].label = index;
	listOfCustomers[index].ballance = 0;

	cout << "Поздравляем, теперь в клиент банка!" << endl << endl;
	cout << "Информация о вашем счете" << endl;

	cout << "Ваше имя: ";	cout << listOfCustomers[index].Name << endl;
	fName << listOfCustomers[index].Name << endl;
	cout << "Ваше отчество: ";	cout << listOfCustomers[index].SecondName << endl;
	fSecondName << listOfCustomers[index].SecondName << endl;
	cout << "Ваша фамилия: ";	cout << listOfCustomers[index].Sorname << endl;
	fSorname << listOfCustomers[index].Sorname << endl;
	cout << "Тип счета: ";	cout << listOfCustomers[index].type << endl;
	ftype << listOfCustomers[index].type << endl;
	cout << "Номер счета: ";	cout << listOfCustomers[index].label << endl;
	flabel << listOfCustomers[index].label << endl;
	cout << "Начальная сумма: ";	cout << listOfCustomers[index].ballance << endl;
	fballance << listOfCustomers[index].ballance << endl;
	cout << "Дата последнего изменения: ";	cout << listOfCustomers[index].dateofchange << endl;
	fdateofchange << listOfCustomers[index].dateofchange << endl;


	index++;
	fstream findex1("index.txt");
	
	findex1 << index;
	findex1.close();
	fName.close();
	fSorname.close();
	fSecondName.close();
	ftype.close();
	flabel.close();
	fballance.close();
	fdateofchange.close();
	funswitch();

	

	
}

void checkCustomer()
{
	int num;
	cout << "Введите номер вашего счета: "; cin >> num; cout << endl;
	cout << "Информация о клиенте с номером счета: " << num << endl << endl;

	
	
	cout << listOfCustomers[num].Name << " " << listOfCustomers[num].SecondName << " " << listOfCustomers[num].Sorname << endl;
	cout << "Тип счета: ";	cout << listOfCustomers[num].type << endl;
	cout << "Номер счета: ";	cout << listOfCustomers[num].label << endl;
	cout << "Сумма на счете: ";	cout << listOfCustomers[num].ballance << endl;
	cout << "Дата последнего изменения: ";	cout << listOfCustomers[num].dateofchange << endl;

	funswitch();
}

void deleteCustomer()
{
	int num = 0; 
	

	cout << "Введите номер счета клиента, которого нужно удалить: "; cin >> num; cout << endl;


	if (num != 999)
	{
		for (num; num < ::index; num++)
		{
			listOfCustomers[num] = listOfCustomers[num + 1];

		}
		cout << "Данные удалены" << endl;
	}
	::index--;
	ofstream findex("index.txt");
	ofstream fName("Name.txt");
	ofstream fSorname("Sorname.txt");
	ofstream fSecondName("SecondName.txt");
	ofstream ftype("type.txt");
	ofstream flabel("label.txt");
	ofstream fballance("ballance.txt");
	ofstream fdateofchange("dateofchange.txt");

	

	for (int i = 0; i <= index; i++)
	{
		fName << listOfCustomers[i].Name << endl;
		fSorname << listOfCustomers[i].Sorname << endl;
		fSecondName << listOfCustomers[i].SecondName << endl;
		ftype << listOfCustomers[i].type << endl;
		flabel << listOfCustomers[i].label << endl;
		fballance << listOfCustomers[i].ballance << endl;
		fdateofchange << listOfCustomers[i].dateofchange << endl;
	}

	findex.close();
	fName.close();
	fSorname.close();
	fSecondName.close();
	ftype.close();
	flabel.close();
	fballance.close();
	fdateofchange.close();
	

	funswitch();


	
	
}

void funswitch()
{
	int choice;
	cout << "Банк приветствует вас! \nВыберите интересующую вас услугу. \n\n";
	cout << "Добавить клиента - введите 1: " << endl;
	cout << "Показать информацию о клиенте - введите 2: " << endl;
	cout << "Удалить клиента - введите 3: " << endl;
	cout << "Введите номер выбранной услуги: "; cin >> choice; cout << endl;

	switch (choice)
	{
	case 1: addCustomer(); break;
	case 2: checkCustomer(); break;
	case 3: deleteCustomer(); break;
	default: {exit(0); cout << "Вы все сломали"; break; }
	}
}

int main()
{
	getDATA();
	funswitch();


	return 0;

}
