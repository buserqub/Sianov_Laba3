#include "Faculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty() : Division() {
	depBegin = NULL;
}
Faculty::Faculty(string name, Person* head, Department* depBegin) : Division(name, head), depBegin{ depBegin } {
	//Department* tmp = depBegin;
	//while (tmp != NULL) {
	//	tmp.
	//}
}
Faculty::~Faculty() {

}
void Faculty::Show() {
	cout << "Факультет." << endl;
	cout << "\tНазвание: " << this->GetName() << endl;
	cout << "\tРуководитель: " << this->GetHead()->GetName() << endl;
}
string Faculty::GetName() {
	return this->Division::GetName();
}
Person* Faculty::GetHead() {
	return this->Division::GetHead();
}
Department* Faculty::GetDepBegin() {
	return this->depBegin;
}
void Faculty::SetName(string name)
{
	this->Division::SetName(name);
}
void Faculty::SetHead(Person* head)
{
	this->Division::SetHead(head);
}