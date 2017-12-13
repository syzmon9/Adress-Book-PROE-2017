#pragma once
#include <iostream>
#include <string>

using namespace std;

class Record
{
public:
	string name, surname, street, houseNumber, postalCode, city;
	int classNumber;

	Record(string, string, string, string, string, string);
	Record();
	~Record();

	friend istream& operator>>(fstream&, Record& t);
};