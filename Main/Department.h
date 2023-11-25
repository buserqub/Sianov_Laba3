#pragma once
#include <iostream>
#include "Division.h"
#include "Teacher.h"
#include "DepartmentHead.h"
#include "StudentsGroup.h"
using namespace std;

class Department : Division {
public:
	Department();
	Department(string name, DepartmentHead* head, StudentsGroup* studBegin, Teacher* teacherBegin);
	Department(string name, DepartmentHead* head, StudentsGroup* studBegin, Teacher* teacherBegin, Department* begin);
	~Department();
	string GetName();
	Person* GetHead();
	Department* GetNext();
	StudentsGroup* GetStudGroupBegin();
	Teacher* GetTeacherBegin();
	void SetName(string name);
	void SetHead(Person* head);
	void Show() override;
protected:
	StudentsGroup* studGroupBegin;
	Teacher* teacherBegin;
	Department* begin;
	Department* next;
};

