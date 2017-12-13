/*
Projekt Ksiazka adresowa

wykona³: Szymon Ka³donek
nr albumu: 295037

*/

#include <iostream>
#include <string>
#include "Record.h"
#include "AdressBook.h"

using namespace std;

int main()
{
	bool flag = 1;
	AdressBook adressBook;
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
			cout << "Enter surname: ";
			cin >> tempSurname;
			cout << "Enter street: ";
			cin >> tempStreet;
			cout << "Enter house number: ";
			cin >> tempHouseNumber;
			cout << "Enter postal code: ";
			cin >> tempPostal;
			cout << "Enter city: ";
			cin >> tempCity;
			Record record(tempName, tempSurname, tempStreet, tempHouseNumber, tempPostal, tempCity);
			/*Record r1("Donata", "Blokesz", "Opawska", "21/9", "47-400", "Raciborz");
			Record r2("Szymon", "Kaldonek", "Lazurowa", "183/51", "01-479", "Warszawa");
			phoneBook.addRecord(r1);
			phoneBook.addRecord(r2);*/
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