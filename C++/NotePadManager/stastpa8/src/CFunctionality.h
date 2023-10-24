#ifndef SRC_CFUNCTIONALITY_H
#define SRC_CFUNCTIONALITY_H

#include "CSearch.h"
#include <string>

using namespace std;


/**
 * @class CFunctionality
 * @brief Class from which are derived other classes, with functionalities
 */
class CFunctionality {
public:
    /**
     * @brief Constructor, stores option to m_choice
     * @param choice [in] Functionality to be executed
     */
    CFunctionality(unsigned int choice);

    /** @brief Default destructor */
    virtual ~CFunctionality() = default;

    /** @brief Displays options for specific functionality */
    virtual void DisplayMenu() = 0;

    /**
     * @brief Executes functionality
     * @param lastRes [in/out] Last search result
     */
    virtual void Execute(string &lastRes) = 0;

    static void MakeSpace();

protected:
    /**
     * @brief Prints last search result
     * @param lastRes [in/out] Last search result
     */
    static void PrintLast(string &lastRes);

    int m_choice;
};

//Polymorphism
/**
 * @class NewFile
 * @brief Class that represents option to create new file
 */
class NewFile : public CFunctionality {
public:
    NewFile(unsigned int choice);

    void DisplayMenu() override;

    void Execute(string &lastRes) override;

private:
    /**
     * @brief Opens another Menu
     * @param extension [in] File extension
     */
    void CreateNewFile(string extension);
};

/**
 * @class EditFile
 * @brief Class that represents option to edit file
 */
class EditFile : public CFunctionality {
public:
    EditFile(unsigned int choice);

    void DisplayMenu() override;

    void Execute(string &lastRes) override;
};

/**
 * @class ReadFile
 * @brief Class that represents option to read file in 2 formates
 */
class ReadFile : public CFunctionality {
public:
    ReadFile(unsigned int choice);

    void DisplayMenu() override;

    void Execute(string &lastRes) override;
};

/**
 * @class DeleteFile
 * @brief Class that represents option to delete file
 */
class DeleteFile : public CFunctionality {
public:
    DeleteFile(unsigned int choice);

    void DisplayMenu() override;

    void Execute(string &lastRes) override;
};

/**
 * @class SearchFile
 * @brief Class that represents option to search file by some criteria
 */
class SearchFile : public CFunctionality {
public:
    SearchFile(unsigned int choice);

    ~SearchFile();

    void DisplayMenu() override;

    void Execute(string &lastRes) override;

private:
    /**
     * @brief Searches Categories or Tags
     * @param lastRes [in/out] File extension
     * @param search [in] Search criteria
     */
    void SearchCT(string &lastRes, CSearch *search);

    SearchByTag *m_tagSearch;
    SearchByCategory *m_catSearch;
};

/**
 * @class ImportFile
 * @brief Class that represents option to import file
 */
class ImportFile : public CFunctionality {
public:
    ImportFile(unsigned int choice);

    void DisplayMenu() override;

    void Execute(string &lastRes) override;
};

/**
 * @class ExportFile
 * @brief Class that represents option to export file
 */
class ExportFile : public CFunctionality {
public:
    ExportFile(unsigned int choice);

    void DisplayMenu() override;

    void Execute(string &lastRes) override;
};

/**
 * @class ListAll
 * @brief Class that represents option to list all attributes, such as tags, categories...
 */
class ListAll : public CFunctionality {
public:
    ListAll(unsigned int choice);

    void DisplayMenu() override;

    void Execute(string &lastRes) override;
};

#endif //SRC_CFUNCTIONALITY_H
