#include "Department.h"
#include <iostream>
using namespace std;

Department::Department() : Division()
{
	studGroupBegin = NULL;
	teacherBegin = NULL;
	begin = this;
	next = NULL;
}
Department::Department(string name, DepartmentHead* head, StudentsGroup* studGroupBegin, Teacher* teacherBegin) : Division(name, head), studGroupBegin{ studGroupBegin }, teacherBegin{ teacherBegin } {
	head->SetDepartment(this->name);
	begin = this;
	next = NULL;
}
Department::Department(string name, DepartmentHead* head, StudentsGroup* studGroupBegin, Teacher* teacherBegin, Department* begin) : Division(name, head), studGroupBegin{ studGroupBegin }, teacherBegin{ teacherBegin }, begin { begin } {
	head->SetDepartment(this->name);
	Department* tmp = begin;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = this;
	next = NULL;
}
Department::~Department() {

}
void Department::Show() {
	cout << "Кафедра." << endl;
	cout << "\tНазвание: " << this->GetName() << endl;
	cout << "\tРуководитель: " << this->GetHead()->GetName() << endl;
}
string Department::GetName() {
	return this->Division::GetName();
}
Person* Department::GetHead() {
	return this->Division::GetHead();
}
StudentsGroup* Department::GetStudGroupBegin() {
	return studGroupBegin;
}
Teacher* Department::GetTeacherBegin() {
	return teacherBegin;
}
Department* Department::GetNext() {
	return this->next;
}
void Department::SetName(string name)
{
	this->Division::SetName(name);
}
void Department::SetHead(Person* head)
{
	this->Division::SetHead(head);
}