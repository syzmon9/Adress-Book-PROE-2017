#pragma once
#include <iostream>
#include <string>
#include "Record.h"
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

class AdressBook
{
	vector<Record> RecordContainer;
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

	friend std::ostream& operator<<(std::ostream&, const AdressBook& t);

	~AdressBook();
};

std::ostream& operator<<(std::ostream&, const Record& t);
