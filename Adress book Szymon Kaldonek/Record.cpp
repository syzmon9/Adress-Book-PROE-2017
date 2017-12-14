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

}

Record::~Record()
{

}

istream& operator >>(fstream& inputFile, Record& t)
{
	int nextObjStart = 0;
	int currentLine = 1;
	string lineFromFile;

	{
		getline(inputFile, lineFromFile);
		t.name = lineFromFile;
		getline(inputFile, lineFromFile);
		t.surname = lineFromFile;
		getline(inputFile, lineFromFile);
		t.street = lineFromFile;
		getline(inputFile, lineFromFile);
		t.houseNumber = lineFromFile;
		getline(inputFile, lineFromFile);
		t.postalCode = lineFromFile;
		getline(inputFile, lineFromFile);
		t.city = lineFromFile;
		currentLine++;
	}
	return inputFile;
}
