#include "Scientist.h"

Scientist::Scientist(string Name, string YearOfBirth, string YearOfDeath, string Gender)
{
    name = Name;
    gender = Gender;
    yearOfBirth = YearOfBirth;
    yearOfDeath = YearOfDeath;
}

Scientist::Scientist()
{
    name = "";
    gender = "";
    yearOfBirth = "";
    yearOfDeath = "";
}

string Scientist::getName()
{
    return name;
}

string Scientist::getGender()
{
    return gender;
}

int Scientist::getAge()
{
    return age;
}

string Scientist::getYob()
{
    return yearOfBirth;
}

string Scientist::getYod()
{
    return yearOfDeath;
}

void Scientist::checkAge()
{
    int intYod = stoi(yearOfDeath.c_str());
    int intYob = stoi(yearOfBirth.c_str());

    if (intYod == 0)
    {
        age =  2015 - intYob;
    }
    else
    {
        age = intYod - intYob;
    }
}

ostream& operator <<(ostream& outs, Scientist sci)
{
    outs << "Name: " << sci.getName() << endl;
    outs << "Year of birth: " << sci.getYob() << endl;
    outs << "Year of death: " << sci.getYod() << endl;
    outs << "Gender: " << sci.getGender() << endl;
    outs << "Age: " << sci.getAge() << endl;

    return outs;
}
