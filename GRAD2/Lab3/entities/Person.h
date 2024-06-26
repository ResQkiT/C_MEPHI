#pragma once
#include <string>

class Person
{
protected:
    std::string name;
    std::string surname;
    std::string email;

public:
    Person();
    Person(std::string name, std::string surname);
    Person(std::string name, std::string surname, std::string email);
    ~Person();
    
    std::string& get_name();
    std::string& get_surname();
    std::string& get_email();
    
    Person & operator=(Person & other); 
};