#include "DepartmentHead.h"
#include <iostream>
using namespace std;

int DepartmentHead::count = 0;
DepartmentHead* DepartmentHead::begin = NULL;

DepartmentHead::DepartmentHead(string name, int experienceYears) : Teacher(name, experienceYears)
{

	if (count == 0)
		begin = this;

	DepartmentHead* tmp = begin;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = this;
	this->next = NULL;

	count++;
};
DepartmentHead::~DepartmentHead() {

}
string DepartmentHead::GetName() {
	return Teacher::GetName();
}
void DepartmentHead::SetDepartment(string department) {
	this->department = department;
}
void DepartmentHead::Show() {
	PrintTitle();
	PrintBody();
	cout << endl;
}
void DepartmentHead::PrintTitle() {
	cout << "Информация о зав.кафедры." << endl;
}
void DepartmentHead::PrintBody() {
	Teacher::PrintBody();
	cout << "Кафедра: " << department << endl;
}
void DepartmentHead::ShowList() {
	cout << "Элементы списка преподавателей:" << endl;

	DepartmentHead* tmp = begin;
	while (tmp != NULL) {
		tmp->Show();
		tmp = tmp->next;
	}
}