#include "CMenu.h"
#include "CFunctionality.h"
#include <iostream>
#include <string>


using namespace std;


CMenu::CMenu()
{
    m_Functionality.reserve(8);
    m_Functionality.push_back(new NewFile(1));
    m_Functionality.push_back(new EditFile(2));
    m_Functionality.push_back(new ReadFile(3));
    m_Functionality.push_back(new DeleteFile(4));
    m_Functionality.push_back(new SearchFile(5));
    m_Functionality.push_back(new ImportFile(6));
    m_Functionality.push_back(new ExportFile(7));
    m_Functionality.push_back(new ListAll(8));

}

CMenu::~CMenu() {
    for (auto *val: m_Functionality)
        delete val;
}


void CMenu::DisplayMenu() {
    cout << "\n   MAIN MENU\n";
    for(auto * val : m_Functionality)
    {
        val->DisplayMenu();
    }
    cout << m_Functionality.size() + 1 <<". exit \n";
    cout << "Enter your choice(1-" << m_Functionality.size()+1 <<"):";
}



void CMenu::CreateMenu() {
    while ( !GetDone() ) {
        DisplayMenu();
        unsigned int choice;
        cin >> choice;
        if (cin.eof()) {
            m_Done = true;
            break;
        }

        CFunctionality::MakeSpace();
        if(choice == m_Functionality.size()+1)
        {
            cout << "Have a great day :)\n";
            return;
        }
        if(choice > 0 && choice <= m_Functionality.size())
        {
            m_Functionality.at(choice-1)->Execute(m_LastRes);
        }
    }
}