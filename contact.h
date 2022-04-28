#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
#include <string>
#include <regex>
#include <iostream>
class Contact{
private:

    int id;
    std::string name;
    std::string address;
    std::string email;

    bool validateName(std::string);
    bool validateAddress(std::string);
    bool validateEmail(std::string);
    bool validate(std::string,std::regex);
public:
    Contact();

    void setName(std::string);
    void setAddress(std::string);
    void setEmail(std::string);
    void setId(int);
    std::string getName();
    std::string getAddress();
    std::string getEmail();
    int getId();

    bool operator < (const Contact&) const;
     bool operator > (const Contact&) const;
     bool operator <= (const Contact&) const;
     bool operator >= (const Contact&) const;
     bool operator == (const Contact&) const;
     bool operator != (const Contact&) const;

     friend std::ostream& operator<<(std::ostream& os, const Contact&);



};

#endif // CONTACT_H_INCLUDED
