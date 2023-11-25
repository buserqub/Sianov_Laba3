#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Teacher : public Person
{
public:
	Teacher(string name, int experienceYears);
	Teacher(string name, int experienceYears, Teacher* begin);
	~Teacher();
	string GetName();
	Teacher* GetNext();
	void Show();
	void PrintTitle();
	void PrintBody();
	void ShowList();
protected:
	Teacher* begin;
	Teacher* next;
	int experienceYears;
};

