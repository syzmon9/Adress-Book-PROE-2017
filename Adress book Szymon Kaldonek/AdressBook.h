#pragma once
#include <iostream>
#include <string>
#include "Record.h"
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

template<typename T>
class AdressBook
{
	vector<T> RecordContainer;
	int tableCap;

public:
	AdressBook();
	int getVectorCap();
	bool addRecord(const Record& newRecord);
	Record getRecord(int);
	void deleteRecord();
	void searchRecord();
	bool readFromFile();
	bool saveToFile();
	void editRecord();

	template<typename T>
	friend ostream& operator<< (ostream& out, const AdressBook<T>&);

	~AdressBook();
};

//std::ostream& operator<<(std::ostream&, const Record& t);

#include "AdressBook.cpp"