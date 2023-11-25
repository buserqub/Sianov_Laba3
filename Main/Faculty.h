#pragma once
#include <iostream>
#include "Division.h"
#include "Department.h"
using namespace std;

class Faculty : Division {
public:
	Faculty();
	Faculty(string name, Person* head, Department* depBegin);
	~Faculty();
	string GetName();
	Person* GetHead();
	Department* GetDepBegin();
	void SetName(string name);
	void SetHead(Person* person);
	void Show() override;
protected:
	Department* depBegin;
};