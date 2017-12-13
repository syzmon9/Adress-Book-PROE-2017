#include "record.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Record::Record(string name, string surname, string street, string houseNumber, string postalCode, string city)
{
	this->name = name;
	this->surname = surname;
	this->street = street;
	this->houseNumber = houseNumber;
	this->postalCode = postalCode;
	this->city = city;
}

Record::Record() : name(""), surname(""), street(""), houseNumber(""), postalCode(""), city("")
{
	classNumber = 0;
}

Record::~Record()
{
}

istream& operator >>(fstream& inputFile, Record& t)
{
	int nextObjStart = 0;// (t.classNumber - 1) * 6 + 1;
	int currentLine = 1;
	string lineFromFile;

	//while (getline(inputFile, lineFromFile))
	{
		//if (currentLine == nextObjStart) 
		getline(inputFile, lineFromFile);
			t.name = lineFromFile;
		//if (currentLine == nextObjStart + 1) 
			getline(inputFile, lineFromFile);
			t.surname = lineFromFile;
		//if (currentLine == nextObjStart + 2) 
			getline(inputFile, lineFromFile);
			t.street = lineFromFile;
		//if (currentLine == nextObjStart + 3) 
			getline(inputFile, lineFromFile);
			t.houseNumber = lineFromFile;
		//if (currentLine == nextObjStart + 4)
			getline(inputFile, lineFromFile);
			t.postalCode = lineFromFile;
		//if (currentLine == nextObjStart + 5) 
			getline(inputFile, lineFromFile);
			t.city = lineFromFile;
		currentLine++;
	}

	return inputFile;
}
