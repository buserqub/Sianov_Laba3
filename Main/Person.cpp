#include "Person.h"
#include <iostream>
using namespace std;

int Person::count = 0;
Person* Person::begin = NULL;

Person::Person(string name) : name{ name }
{
	if (count == 0)
		begin = this;

	Person* tmp = begin;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = this;
	this->next = NULL;

	count++;
}
Person::~Person() {

}
string Person::GetName() {
	return name;
}
void Person::SetCount(int number) {
	count = number;
}
int Person::GetCount() {
	return count;
}
void Person::Show() {
	PrintTitle();
	PrintBody();
	cout << endl;
}
void Person::PrintTitle() {
	cout << "Информация о персоне." << endl;
}
void Person::PrintBody() {
	cout << "Имя: " << name << endl;
}
void Person::ShowList() {
	cout << "Элементы списка персон:" << endl;

	Person* tmp = begin;
	while (tmp != NULL) {
		tmp->Show();
		tmp = tmp->next;
	}
}