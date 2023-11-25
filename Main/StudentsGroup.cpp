#include "StudentsGroup.h"
#include <iostream>
using namespace std;

StudentsGroup::StudentsGroup() : Division() {
	begin = NULL;
	next = NULL;
}
StudentsGroup::StudentsGroup(string name, Student* head) : Division(name, head) {
	begin = this;
	next = NULL;
}
StudentsGroup::StudentsGroup(string name, Student* head, StudentsGroup* begin) : Division(name, head), begin{ begin } {
	StudentsGroup* tmp = begin;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = this;
	next = NULL;
}
StudentsGroup::~StudentsGroup() {

}
void StudentsGroup::Show() {
	cout << "Студенческая группа." << endl;
	cout << "\tНомер: " << this->GetName() << endl;
	cout << "\tСтароста: " << this->GetHead()->GetName() << endl;
}
string StudentsGroup::GetName() {
	return this->Division::GetName();
}
Person* StudentsGroup::GetHead() {
	return this->Division::GetHead();
}
StudentsGroup* StudentsGroup::GetNext() {
	return this->next;
}
void StudentsGroup::SetName(string name)
{
	this->Division::SetName(name);
}
void StudentsGroup::SetHead(Person* head)
{
	this->Division::SetHead(head);
}