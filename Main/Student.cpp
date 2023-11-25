#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string name, int year) : Person(name), year{ year }
{
	begin = this;
	next = NULL;
}
Student::Student(string name, int year, Student* begin) : Person(name), year{ year }, begin { begin }
{
	Student* tmp = begin;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = this;
	next = NULL;
}
Student::~Student() {

}
void Student::Show() {
	PrintTitle();
	PrintBody();
	cout << endl;
}
void Student::PrintTitle() {
	cout << "Информация о преподавателе." << endl;
}
void Student::PrintBody() {
	Person::PrintBody();
	cout << "Курс: " << year << "-й" << endl;
}
void Student::ShowList() {
	cout << "Элементы списка преподавателей:" << endl;

	Student* tmp = begin;
	while (tmp != NULL) {
		tmp->Show();
		tmp = tmp->next;
	}
}