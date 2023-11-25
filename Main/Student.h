#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person
{
public:
	Student(string name, int year);
	Student(string name, int year, Student* begin);
	~Student();
	void Show();
	void PrintTitle();
	void PrintBody();
	void ShowList();
protected:
	int year;
	Student* begin;
	Student* next;
};

