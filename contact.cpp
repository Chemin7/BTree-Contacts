#include "contact.h"
#include <iostream>
#include <regex>

using namespace std;

Contact::Contact() {
    }
void Contact::setId(int i){
    id=i;
}

void Contact::setName(string n) {

    regex reg("([A-Z]|[a-z]| )+");

    while(!validate(n,reg)) {
        cout<<"Introduce un nombre valido: ";
        cin.sync();
        getline(cin, n);
        }

    name=n;


    }

void Contact::setAddress(string a) {
    regex reg("([A-Z]|[a-z]| )+");
    //regex reg("([A-Z]|[a-z]| )+\d{3,4}");

    while(!validate(a,reg)) {
        cout<<"Introduce una direccion valida: ";
        cin.sync();
        getline(cin, a);
        }


    address = a;
    }

void Contact::setEmail(string e) {
    regex reg("^[a-zA-Z0-9.!#$%&’*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$");

    while(!validate(e,reg)) {
        cout<<"Introduce un email valido: ";
        cin.sync();
        getline(cin, e);
        }


    email = e;
    }

int Contact::getId(){
    return id;
}

string Contact::getName() {
    return name;
    }

string Contact::getAddress() {
    return address;
    }

string Contact::getEmail() {

    return email;
    }



bool Contact::validate(std::string str, std::regex reg) {

    if(regex_match(str,reg))
        return true;
    else
        return false;
    }
bool Contact::operator <(const Contact& c) const {
    return  this->id < c.id ? true : false;
    }

bool Contact::operator<=(const Contact& c) const {
    return this->id < c.id and this->id == c.id ? true : false;
    }

bool Contact::operator>(const Contact& c) const {
    return !(*this <= c) ? true : false;
    }

bool Contact::operator>=(const Contact& c) const{
    return !(*this < c) ? true : false;
    }


bool Contact::operator==(const Contact& c) const {
    return this->id == c.id ? true:false;
    }

bool Contact::operator!=(const Contact& c) const
{
    return !(*this == c) ? true : false;
}
ostream& operator<< (ostream& os, const Contact& c){
    os<< c.id<<", '  ";
    return os;
};
