#pragma once
#include <iostream>
#include "Teacher.h"
using namespace std;

class DepartmentHead : public Teacher
{
public:
	DepartmentHead(string name, int experienceYears);
	~DepartmentHead();
	string GetName();
	void SetDepartment(string department);
	void Show();
	void PrintTitle();
	void PrintBody();
	static void ShowList();
	static DepartmentHead* begin;
	DepartmentHead* next;
protected:
	string department;
	static int count;
};

