/*
Projekt Ksiazka adresowa

wykona³: Szymon Ka³donek
Politechnika Warszawska 
wydzia³ Elektroniki i Technik Informacyjnych

*/

#include <iostream>
#include <string>
#include "Record.h"
#include "AdressBook.h"

using namespace std;

int main()
{
	bool flag = 1;
	AdressBook<Record> adressBook;
	adressBook.readFromFile();
	int option;
	while (flag == 1)
	{
		cout << endl << "------ Adress Book ------" << endl;
		cout << "What do you want to do? Enter one of those numbers: " << endl;
		cout << "1. Show records" << endl;
		cout << "2. Add new record" << endl;
		cout << "3. Search record" << endl;
		cout << "4. Delete records" << endl;
		cout << "5. Edit records" << endl;
		cout << "6. Exit program				";
		cin >> option;
		switch (option)
		{
		case 1:	//wyswietlanie rekordow
		{
			cout << endl << "------ All records ------" << endl;
			cout << adressBook << endl;
			break;
		}
		case 2:	//dodawanie rekordu
		{
			cout << "\n------ Adding a record ------" << endl;
			string tempName, tempSurname, tempStreet, tempHouseNumber, tempPostal, tempCity;
			cout << "Enter name: ";
			cin >> tempName;
			//getline(cin, tempName);
			cout << "Enter surname: ";
			//getline(cin, tempSurname);
			cin >> tempSurname;
			cout << "Enter street: ";
			//getline(cin, tempStreet);
			cin >> tempStreet;
			cout << "Enter house number: ";
			//getline(cin, tempHouseNumber);
			cin >> tempHouseNumber;
			cout << "Enter postal code: ";
			//getline(cin, tempPostal);
			cin >> tempPostal;
			cout << "Enter city: ";
			//getline(cin, tempCity);
			cin >> tempCity;
			Record record(tempName, tempSurname, tempStreet, tempHouseNumber, tempPostal, tempCity);
			if (adressBook.addRecord(record) == 1)
				cout << "Record added sucesfully" << endl;
			else
				cout << "Error. Record was not added." << endl;
			break;
		}
		case 3: //wyszukiwanie
		{
			cout << endl;
			adressBook.searchRecord();
			cout << endl;
			break;
		}
		case 4:	//kasowanie elementu
		{
			adressBook.deleteRecord();
			break;
		}
		case 5:	//zakonczenie programu
		{
			adressBook.editRecord();
			break;
		}
		case 6:	//zakonczenie programu
		{
			adressBook.saveToFile();
			flag = 0;
			break;
		}
		}
	}
	return 0;
}