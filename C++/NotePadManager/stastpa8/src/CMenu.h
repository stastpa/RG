#ifndef SRC_CMENU_H
#define SRC_CMENU_H

#include "CFileManager.h"
#include "CFunctionality.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @class CMenu
 * @brief Class that represents Main Menu
 */
class CMenu {
public:
    /** @brief Constructor, stores CMenu options into m_Functionality vector */
    CMenu();
    /** @brief Destructor, deletes m_Functionality contents */
    ~CMenu();


    /** @brief Displays main menu options */
    void DisplayMenu();

    /** @brief Initializes menu */
    void CreateMenu();

    /** @brief Returns m_Done */
    bool GetDone()
    {
        return m_Done;
    }

private:
    bool m_Done = false;
    string m_LastRes;
    vector<CFunctionality*> m_Functionality;
};

#endif //SRC_CMENU_H
