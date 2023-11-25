#pragma once
#include <iostream>
#include "Division.h"
#include "Student.h"
using namespace std;

class StudentsGroup : Division {
public:
	StudentsGroup();
	StudentsGroup(string name, Student* head);
	StudentsGroup(string name, Student* head, StudentsGroup* begin);
	~StudentsGroup();
	string GetName();
	Person* GetHead();
	StudentsGroup* GetNext();
	void SetName(string name);
	void SetHead(Person* head);
	void Show() override;
protected:
	StudentsGroup* begin;
	StudentsGroup* next;
};
