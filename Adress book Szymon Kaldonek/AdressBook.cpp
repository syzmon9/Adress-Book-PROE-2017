#include "AdressBook.h"

using namespace std;

AdressBook::AdressBook()
{
	tableCap = 0;
}


int AdressBook::getVectorCap()
{
	return RecordContainer.size();
}

bool AdressBook::addRecord(const Record& newRecord)
{
	try
	{
		RecordContainer.push_back(newRecord);
		tableCap++;
		return 1;
	}
	catch (const exception&)
	{
		return 0;
	}
}

AdressBook::~AdressBook()
{

}

ostream& operator <<(ostream& output, const Record& t)
{
	output << t.name << " " << t.surname << " | " << t.street << " " << t.houseNumber << "  " << t.postalCode << " " << t.city << endl;
	return output;
}

ostream& operator<<(ostream& out, const AdressBook& ph)
{
	if (ph.tableCap != 0)
	{
		for (int i = 0; i < ph.tableCap; i++)
		{
			out << ph.RecordContainer[i];
		}
		return out;
	}
	else cout << endl << "There is no records in adress book. Add some records choosing option 2." << endl;
}

Record AdressBook::getRecord(int i)
{
	return RecordContainer[i];
}

bool AdressBook::readFromFile()
{
	int fileLines = 0;
	string line;
	fstream myfile("save.txt");
	while (getline(myfile, line))
		++fileLines;
	int recordNumber = fileLines / 6;

	fstream file;
	file.open("save.txt", ios::in);

	Record temp;
	for (int i = 0; i < recordNumber; i++)
	{
		if (file.good() == false)
		{
			cout << "Reading records from database failed." << endl;
		}
		
		file >> temp;
		addRecord(temp);

	}
	file.close();
	return 1;
}

bool AdressBook::saveToFile()
{
	ofstream ofs("save.txt", ios::out | ios::trunc);

	try
	{
		for (int i = 0; i < getVectorCap(); ++i)
		{
			ofs << RecordContainer[i].name << endl;
			ofs << RecordContainer[i].surname << endl;
			ofs << RecordContainer[i].street << endl;
			ofs << RecordContainer[i].houseNumber << endl;
			ofs << RecordContainer[i].postalCode << endl;
			ofs << RecordContainer[i].city << endl;
		}
		cout << "Save to file successful. Have a nice day!" << endl;
		getchar();
		return 1;
	}
	catch (const std::exception&)
	{
		cout << "Cannot save records to file due to file error." << endl;
		cout << "If there was added records, all of them could not be saved." << endl;
		getchar();
		return 0;
	}
}

void AdressBook::searchRecord()
{
	cout << endl << "------ Searching ------" << endl;
	cout << "I want to search by: " << endl;
	cout << "1. Name " << endl;
	cout << "2. Surname" << endl;
	cout << "3. Street" << endl;
	cout << "4. House number" << endl;
	cout << "5. Postal code " << endl;
	cout << "6. City					";
	int searchBy;
	cin >> searchBy;
	string search;
	int counter = 0;
	switch (searchBy)
	{
	case 1:
	{
		cout << "Enter name: ";
		cin >> search;
		cout << "- - - - - - - - - - " << endl;
		for (int i = 0; i < getVectorCap(); i++)
		{
			if (RecordContainer[i].name == search)
			{
				cout << RecordContainer[i];
				counter++;
			}
		}
		if (counter == 0) cout << endl << "No records found." << endl;
		getchar();
		break;
	}
	case 2:
	{
		cout << "Enter surname: ";
		cin >> search;
		cout << "- - - - - - - - - - " << endl;
		for (int i = 0; i < getVectorCap(); i++)
		{
			if (RecordContainer[i].surname == search)
			{
				cout << RecordContainer[i];
				counter++;
			}
		}
		if (counter == 0) cout << endl << "No records found." << endl;
		getchar();
		break;
	}
	case 3:
	{
		cout << "Enter street: ";
		cin >> search;
		cout << "- - - - - - - - - - " << endl;
		for (int i = 0; i < getVectorCap(); i++)
		{
			if (RecordContainer[i].street == search)
			{
				cout << RecordContainer[i];
				counter++;
			}
		}
		if (counter == 0) cout << endl << "No records found." << endl;
		getchar();
		break;
	}
	case 4:
	{
		cout << "Enter house number: ";
		cin >> search;
		cout << "- - - - - - - - - - " << endl;
		for (int i = 0; i < getVectorCap(); i++)
		{
			if (RecordContainer[i].houseNumber == search)
			{
				cout << RecordContainer[i];
				counter++;
			}
		}
		if (counter == 0) cout << endl << "No records found." << endl;
		getchar();
		break;
	}
	case 5:
	{
		cout << "Enter postal code: ";
		cin >> search;
		cout << "- - - - - - - - - - " << endl;
		for (int i = 0; i < getVectorCap(); i++)
		{
			if (RecordContainer[i].postalCode == search)
			{
				cout << RecordContainer[i];
				counter++;
			}
		}
		if (counter == 0) cout << endl << "No records found." << endl;
		getchar();
		break;
	}
	case 6:
	{
		cout << "Enter city: ";
		cin >> search;
		cout << "- - - - - - - - - - " << endl;
		for (int i = 0; i < getVectorCap(); i++)
		{
			if (RecordContainer[i].city == search)
			{
				cout << RecordContainer[i];
				counter++;
			}
		}
		if (counter == 0) cout << endl << "No records found." << endl;
		getchar();
		break;
	}
	default:
		break;
	}

}

string EditHelper(string &str)
{
	string endEdition;
	cin >> str;
	cout << "Do you want to edit something else in this record? y/n ";
	cin >> endEdition;
	while (endEdition != "y" && endEdition != "n")
	{
		cout << "There is no option like this. Try again: ";
		cin >> endEdition;
	}

	return endEdition;
}

void AdressBook::editRecord()
{
	cout << endl << "------ Editing records ------" << endl;
	cout << "Search contact to edit by surname: ";
	string search;
	int counter = 0;
	cin >> search;
	cout << "- - - - - - - - - - " << endl;
	for (int i = 0; i < getVectorCap(); i++)
	{
		if (RecordContainer[i].surname == search)
		{
			cout << RecordContainer[i] << endl;;
			cout << "Do you want to edit this record? y/n ";
			string editThis;
			cin >> editThis;
			while (editThis != "y" && editThis != "n")
			{
				cout << "There is no option like this. Try again: ";
				cin >> editThis;
			}
			if (editThis == "y")
			{
				string endEdition = "y", temp;

				while (endEdition == "y")
				{
					int whatEdit;
					cout << "What do you want to edit?";
					cout << "I want to edit: " << endl;
					cout << "1. Name " << endl;
					cout << "2. Surname" << endl;
					cout << "3. Street" << endl;
					cout << "4. House number" << endl;
					cout << "5. Postal code " << endl;
					cout << "6. City					";
					cin >> whatEdit;
					switch (whatEdit)
					{
					case 1:
					{
						cout << "Enter new name: ";
						endEdition = EditHelper(RecordContainer[i].name);
						break;
					}
					case 2:
					{
						cout << "Enter new surname: ";
						cin >> temp;
						RecordContainer[i].surname = temp;
						cout << "Do you want to edit something else in this record? y/n ";
						cin >> endEdition;
						while (endEdition != "y" && endEdition != "n")
						{
							cout << "There is no option like this. Try again: ";
							cin >> endEdition;
						}
						break;
					}
					case 3:
					{
						cout << "Enter new street: ";
						cin >> temp;
						RecordContainer[i].street = temp;
						cout << "Do you want to edit something else in this record? y/n ";
						cin >> endEdition;
						while (endEdition != "y" && endEdition != "n")
						{
							cout << "There is no option like this. Try again: ";
							cin >> endEdition;
						}
						break;
					}
					case 4:
					{
						cout << "Enter new house number: ";
						cin >> temp;
						RecordContainer[i].houseNumber = temp;
						cout << "Do you want to edit something else in this record? y/n ";
						cin >> endEdition;
						while (endEdition != "y" && endEdition != "n")
						{
							cout << "There is no option like this. Try again: ";
							cin >> endEdition;
						}
						break;
					}
					case 5:
					{
						cout << "Enter new postal code: ";
						cin >> temp;
						RecordContainer[i].postalCode = temp;
						cout << "Do you want to edit something else in this record? y/n ";
						cin >> endEdition;
						while (endEdition != "y" && endEdition != "n")
						{
							cout << "There is no option like this. Try again: ";
							cin >> endEdition;
						}
						break;
					}
					case 6:
					{
						cout << "Enter new city: ";
						cin >> temp;
						RecordContainer[i].city = temp;
						cout << "Do you want to edit something else in this record? y/n ";
						cin >> endEdition;
						while (endEdition != "y" && endEdition != "n")
						{
							cout << "There is no option like this. Try again: ";
							cin >> endEdition;
						}
						break;
					}
					default:
					{
						cout << "The option does not exist. Try again.";
						break;
					}
					}
				}
			}
			counter++;
		}
	}
}

void AdressBook::deleteRecord()
{
	cout << endl << "------ Deleting records ------" << endl;
	cout << "Search contact to delete by surname: ";
	string search;
	int counter = 0;
	cin >> search;
	cout << "- - - - - - - - - - " << endl;
	for (int i = 0; i < getVectorCap(); i++)
	{
		if (RecordContainer[i].surname == search)
		{
			cout << RecordContainer[i] << endl;;
			cout << "Do you want to delete this record? y/n ";
			string deleteThis;
			cin >> deleteThis;
			while (deleteThis != "y" && deleteThis != "n")
			{
				cout << "There is no option like this. Try again: ";
				cin >> deleteThis;
			}
			if (deleteThis == "y")
			{
				RecordContainer.erase(RecordContainer.begin()+i);
			}
			counter++;
		}
	}
	if (counter == 0) cout << endl << "No records found." << endl;
}