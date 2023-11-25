#include "Division.h"
#include <iostream>
using namespace std;

Division::Division() {
	name = "";
	head = NULL;
}
Division::Division(string name, Person* head) : name{ name }, head{ head } {

}
Division::~Division() {

}
void Division::Show() {
	cout << "Подразделение." << endl;
	cout << "\tНазвание: " << this->GetName() << endl;
	cout << "\tРуководитель: " << this->GetHead() << endl;
}
string Division::GetName() {
	return name;
}
Person* Division::GetHead() {
	return head;
}
void Division::SetName(string name)
{
	this->name = name;
}
void Division::SetHead(Person* head)
{
	this->head = head;
}