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
	cout << "���������� � �������������." << endl;
}
void Student::PrintBody() {
	Person::PrintBody();
	cout << "����: " << year << "-�" << endl;
}
void Student::ShowList() {
	cout << "�������� ������ ��������������:" << endl;

	Student* tmp = begin;
	while (tmp != NULL) {
		tmp->Show();
		tmp = tmp->next;
	}
}