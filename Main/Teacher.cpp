#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(string name, int experienceYears) : Person(name), experienceYears(experienceYears)
{
	begin = this;
	next = NULL;
};
Teacher::Teacher(string name, int experienceYears, Teacher* begin) : Person(name), experienceYears(experienceYears), begin { begin }
{
	Teacher* tmp = begin;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = this;
	this->next = NULL;
};
Teacher::~Teacher() {

}
string Teacher::GetName() {
	return name;
}
Teacher* Teacher::GetNext() {
	return next;
}
void Teacher::Show() {
	PrintTitle();
	PrintBody();
	cout << endl;
}
void Teacher::PrintTitle() {
	cout << "���������� � �������������." << endl;
}
void Teacher::PrintBody() {
	Person::PrintBody();
	cout << "����: " << experienceYears << " ���" << endl;
}
void Teacher::ShowList() {
	cout << "�������� ������ ��������������:" << endl;

	Teacher* tmp = begin;
	while (tmp != NULL) {
		tmp->Show();
		tmp = tmp->next;
	}
}