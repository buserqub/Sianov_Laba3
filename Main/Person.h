#pragma once
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name);
	~Person();
	string GetName();
	static void SetCount(int number);
	static int GetCount();
	void Show();
	void PrintTitle();
	void PrintBody();
	static void ShowList();
	static Person* begin;
	Person* next;
protected:
	string name;
	static int count;
};