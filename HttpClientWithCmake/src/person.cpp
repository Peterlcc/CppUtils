#include"person.h"
Person::Person(string name,int age)
{
    this->name=name;
    this->age=age;
}

void Person::show(){
    cout<<this->name<<" - "<<age<<endl;
}

Person::~Person()
{
}