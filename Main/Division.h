#pragma once
#include <iostream>
#include "Object.h"
#include "Person.h"
using namespace std;

class Division : Object {
public:
	Division();
	Division(string name, Person* head);
	~Division();
	string GetName();
	Person* GetHead();
	void SetName(string name);
	void SetHead(Person* person);
	void Show() override;
	/*void Insert(Object* obj);*/
protected:
	string name;
	Person* head;
};