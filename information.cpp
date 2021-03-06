#include "information.h"
#include <iostream>
using namespace std;

Information::Information()
{

}
//This function print out the opening instructions
void Information::displayOpening(){
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl
         << "- - - - - - - - - - - - - - Welcome - - - - - - - - - - - - - - -" << endl
         << "  This program keeps information about computer scientists " << endl
         << "       You can add  or remove a scientist from the list" << endl
         << "   You can change the order in which the list is diplayed" << endl
         << "              And you can search through the list  " << endl;
}


 // This function askes for the first choices
void Information::instructions(vector<Scientist>& vec){
    cout << endl << "What do you want to do? " << endl
         << "Press 1 to make changes to the list." << endl
         << "Press 2 to display the list." << endl
         << "Press 3 to search." << endl
         << "Press 4 to quit and save."<< endl;

    choices(vec);
}


// let the user pick the choices and calls the next function
void Information::choices(vector<Scientist>& vec){
    char number;
    cin >> number;
    cout << endl;
    switch (number) {
    case'1':
        choiceChange(vec);
        break;
    case'2':
        choiceSort(vec);
        break;
    case'3':
        choiceSearch(vec);
         break;
    case'4':
        {
            return;
        }
    default:{
        cout << "This is invalid choice!! " << endl;
        choices(vec);
        break;}
    }
}


// If the users wants to change something this function askes what kind of change
void Information::choiceChange(vector<Scientist>& vec){
    cout << "Here you can add or remove from the list." << endl
         << "Press 1 to add a person." << endl
         << "Press 2 to delete." << endl
         << "Press 3 to go back." << endl;
    addDelete(vec);
}


// If the user wants to see the hole list, this function askes in what way
void Information::choiceSort(vector<Scientist>& vec){
    cout << "How do you want the list to be displayed?" << endl
         << "Press 1 for alphabetical order A-Z." << endl
         << "Press 2 for reverse alphabetical order Z-A." << endl
         << "Press 3 to order by birth year (ascending)." << endl
         << "Press 4 to order by birth year (descending)." << endl
         << "Press 5 to arrange by gender." << endl
         << "Press 6 to go back."  << endl;
    order(vec);
}


// If the user wants to search for something this function askes what to search for
void Information::choiceSearch(vector<Scientist>& vec){
    cout << "What do you want to search for?" << endl
         << "Press 1 to search by name." << endl
         << "Press 2 to search by birth year." << endl
         << "Press 3 to search by age." << endl
         << "Press 4 to search by gender." << endl
         << "Press 5 if you want to go back." << endl;
    search(vec);
}


// If the user wants to add, delete og change anything he pickes one here
void Information::addDelete(vector<Scientist>& vec){
    Service serv;
    char number;
    string nameToDelete = "";
    cin >> number;
    cout << endl;
    switch (number) {
        case'1':{
            addScientist(vec);
            cout << endl << "--Scientist added to database!--" << endl;
            instructions(vec);
            break;}
        case'2':
            cout << "Enter the full name of a scientist to remove:" << endl;
            cin.ignore(4, '\n');
            getline(cin, nameToDelete);
            serv.deleteScientist(vec, nameToDelete);
            cout << nameToDelete << " has now been removed." << endl;
            instructions(vec);
            break;
        case'3':
            instructions(vec);
            break;
        default:
            cout << "This is invalid choice! Please try again!" << endl;
            addDelete(vec);
            break;
        }
    }


// If the user wants to sort the list he tells the program in what kind of way here.
void Information::order(vector<Scientist> vec)
{
    Service serv;
    char number;
    vector<string> temp;
    cin >> number;
    cout << endl;
    switch (number) {
    case'1':
        cout << "List sorted in alphabetical order:" << endl;
        temp = serv.sortVector(vec, false, 1);
        matchName(vec, temp);
        instructions(vec);
        break;
    case'2':
        cout << "List sorted in reverse alphabetical order:" << endl;
        temp = serv.sortVector(vec, true, 2);
        matchName(vec, temp);
        instructions(vec);
        break;
    case'3':
        cout << "List sorted ascendingly by year of birth:" << endl;
        temp = serv.sortVector(vec, false, 3);
        matchYob(vec, temp);
        instructions(vec);
        break;
    case'4':
        cout << "List sorted descendingly by year of birth:" << endl;
        temp = serv.sortVector(vec, true, 4);
        matchYob(vec, temp);
        instructions(vec);
        break;
    case'5':
        cout << "List sorted by gender (Female first):" << endl;
        temp = serv.sortVector(vec, false, 5);
        matchGender(vec, temp, 0);
        instructions(vec);
        break;
    case'6':
        instructions(vec);
        break;
    default:
        cout << "This is invalid choice " << endl;
        order(vec);
        break;
    }
}


//If the user wants to search for something, he pickes the way here
void Information::search(vector<Scientist> vec)
{
    Service serv;
    char number;
    vector<string> temp;
    string searchStr;
    cin >> number;
    cout << endl;
    switch (number) {
    case'1':
        cout << "Enter a name to search for: " << endl;
        cin >> searchStr;
        cout << endl << "Search results: " << endl;
        temp = serv.search(vec, searchStr, 1);
        matchName(vec, temp);
        instructions(vec);
        break;
    case'2':
        cout << "Enter a year of birth to search for: " << endl;
        cin >> searchStr;
        cout << endl << "Search results: " << endl;
        temp = serv.search(vec, searchStr, 2);
        matchYob(vec, temp);
        instructions(vec);
        break;
    case'3':                                         // VIRKAR EKKI, VANTAR matchAge()
        cout << "Enter an age to search for: " << endl;
        cin >> searchStr;
        cout << endl << "Search results: " << endl;
        temp = serv.search(vec, searchStr, 3);
        matchAge(vec, temp);
        instructions(vec);
        break;
    case'4':
        cout << "Enter either 'M' or 'F' to search by gender:" << endl;
        cin >> searchStr;
        cout << endl << "Search results: " << endl;
        temp = serv.search(vec, searchStr, 4);
        matchGender(vec, temp, 1);
        instructions(vec);
        break;
    case'5':
        instructions(vec);
        break;
    default:
        cout << endl << "This is invalid choice!" << endl;
        search(vec);
        break;
    }

}


// gives the instructions about adding a scientist
void Information::addScientist(vector<Scientist>& vec){
    Service serv;
    cout << "Enter information about the computer scientist whom you wish to add" << endl;
    cout << "If he/she is still alive put in '0' in 'Year of death'" << endl;
    cout << "In gender, enter 'M' for male or 'F' for female"<< endl;

    serv.addScientist(vec);
}

// Prints out the scientists
void Information::displayAll(vector<Scientist> vec){
    cout << endl;
    for(unsigned int i = 0; i < vec.size(); i++){
        cout << vec[i];
        cout << endl;}
}
// Match the search/sorted name vector to vector of Scientists
void Information::matchName(vector<Scientist> sc, vector<string> str)
{
    if (str.empty())
    {
        cout << endl << "Your search string did not match any name!" << endl;
        return;
    }
    for(size_t i = 0; i < str.size(); i++)
    {
        for (size_t j = 0; j < sc.size(); j++)
        {
            size_t found = str[i].find(sc[j].getName());
            if (found != -1)
            {
                cout << sc[j] << endl;
            }
        }
    }
}


// Match the search/sorted year of birth vector to vector of Scientists
void Information::matchYob(vector<Scientist> sc, vector<string> str)
{
    if (str.empty())
    {
        cout << endl << "Your search string did not match any name!" << endl;
        return;
    }
    for(size_t i = 0; i < str.size(); i++)
    {
        for (size_t j = 0; j < sc.size(); j++)
        {
            size_t found = str[i].find(sc[j].getYob());
            if (found != -1)
            {
                cout << sc[j] << endl;
            }
        }
    }
}

// Match the search/sorted gender vector to vector of Scientists
void Information::matchGender(vector<Scientist> sc, vector<string> str, int sortORfind)
{
    if (str.empty())
    {
        cout << endl << "Your search string did not match any gender!" << endl;
        return;
    }
    if (sortORfind)
    {
        for (size_t i = 0; i < sc.size(); i++)
        {
            if (sc[i].getGender().find(str[0]) == 0)
            {
                cout << endl << sc[i] << endl;
            }
        }
    }


    else if(!sortORfind)
    {
        for(size_t i = 0; i < sc.size(); i++)
        {
            for (size_t j = 0; j < str.size(); j++)
            {
                if (sc[i].getGender().compare(str[j]) == 0)
                {
                    cout << sc[j] << endl;
                }
            }
        }
    }
}


// Match the search/sorted age vector to vector of Scientists
void Information::matchAge(vector<Scientist> sc, vector<string> str)
{
    if (str.empty())
    {
        cout << endl << "Your search string did not match any age!" << endl;
        return;
    }
    for(size_t i = 0; i < str.size(); i++)
    {
        for (size_t j = 0; j < sc.size(); j++)
        {
            string age = static_cast<ostringstream*>( &(ostringstream() << sc[j].getAge()) )->str();
            if (str[i].compare(age) == 0)
            {
                cout << sc[j] << endl;
            }
        }
    }
}

