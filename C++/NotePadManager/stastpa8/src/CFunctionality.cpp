
#include "CFunctionality.h"
#include "CFileManager.h"
#include "CSearch.h"
#include "CImport.h"
#include "CExport.h"
#include <iostream>

#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */

using namespace std;

void CFunctionality::PrintLast(string &lastRes)
{
    cout << "Your last Search:\n";
    cout << GREEN << lastRes << RESET << endl;
}


void CFunctionality::MakeSpace() {
    cout << "\n\n";
}

CFunctionality::CFunctionality(unsigned int choice)
{
    m_choice = choice;
}

NewFile::NewFile(unsigned int choice) : CFunctionality(choice) {
}

ReadFile::ReadFile(unsigned int choice) : CFunctionality(choice) {
}

EditFile::EditFile(unsigned int choice) : CFunctionality(choice) {
}

DeleteFile::DeleteFile(unsigned int choice) : CFunctionality(choice) {
}

ImportFile::ImportFile(unsigned int choice) : CFunctionality(choice) {
}

ExportFile::ExportFile(unsigned int choice) : CFunctionality(choice) {
}

SearchFile::SearchFile(unsigned int choice) : CFunctionality(choice) {
    m_catSearch = new SearchByCategory();
    m_tagSearch = new SearchByTag();
}

ListAll::ListAll(unsigned int choice) : CFunctionality(choice) {
}

void NewFile::DisplayMenu()
{
    cout << m_choice << ". CREATE NEW FILE\n";
}

void EditFile::DisplayMenu()
{
    cout << m_choice << ". EDIT FILE\n";
}

void ReadFile::DisplayMenu()
{
    cout << m_choice << ". READ FILE\n";
}

void DeleteFile::DisplayMenu()
{
    cout << m_choice << ". DELETE FILE\n";
}

void SearchFile::DisplayMenu()
{
    cout << m_choice << ". SEARCH FILE\n";
}

void ImportFile::DisplayMenu()
{
    cout << m_choice << ". IMPORT FILE\n";
}

void ExportFile::DisplayMenu()
{
    cout << m_choice << ". EXPORT FILE\n";
}

void ListAll::DisplayMenu()
{
    cout << m_choice << ". LIST ALL\n";
}

void NewFile::Execute(string &lastRes) {
    char choice;
    cout << "    SELECT TYPE\n";
    cout << " 1. .txt\n";
    cout << " 2. .col \n";
    cout << " 3. back \n";

    cout << "Enter your choice(1-3):";
    cin >> choice;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    MakeSpace();
    switch (choice) {
        case '1':
            CreateNewFile(".txt");
            break;
        case '2':
            CreateNewFile(".col");
            break;
        case '3':
            break;
        default:
            break;
    }
}

void NewFile::CreateNewFile(string extension) {
    string create;
    cout << "File to be created [NO EXTENSION] (press '%' to exit):\n";
    cin >> create;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (create == "%") {
        return;
    }
    char slash = '/';
    if (create.find(slash) != string::npos) {
        cerr << "/ is not allowed in filename \n";
        return;
    }
    CFileManager::CreateFile(create, extension);
}

void EditFile::Execute(string &lastRes) {
    PrintLast(lastRes);
    CFileManager::EditFile();
}

void ReadFile::Execute(string &lastRes) {
    PrintLast(lastRes);
    CFileManager::ReadFile();
}

void DeleteFile::Execute(string &lastRes) {
    PrintLast(lastRes);
    CFileManager::DeleteFile();
}

void SearchFile::Execute(string &lastRes) {
    cout << "\n    Search by:\n";
    cout << " 1. CATEGORY\n";
    cout << " 2. TAGS\n";
    cout << " 3. back\n";
    cout << "Enter your choice(1-3):";
    char choice;
    cin >> choice;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }

    switch (choice) {
        case '1':
            MakeSpace();
            SearchCT(lastRes, m_catSearch);
            break;
        case '2':
            MakeSpace();
            SearchCT(lastRes, m_tagSearch);
            break;
        case '3':
            MakeSpace();
            break;
        default:
            MakeSpace();
            return;
    }
}

void SearchFile::SearchCT(string &lastRes, CSearch * search) {
    search->SeachAll();
    search->DisplayHelp();
    string cat;
    cin >> cat;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (cat == "%") {
        return;
    }
    search->containsKey(cat, lastRes);
}

void ImportFile::Execute(string &lastRes) {
    string path;
    MakeSpace();
    cout << "Insert file path (press '%' to exit):\n";
    cin >> path;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (path == "%") {
        return;
    }
    cout << "\nWhat name should the File have( press '%' to exit): ";
    string filename;
    cin >> filename;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (filename == "%") {
        return;
    }

    CImport import(path);
    import.ImportFile(filename);

    string category;
    string tags;

    MakeSpace();
    cout << "Add CATEGORY: ";
    cin >> category;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    MakeSpace();
    cout << "Add TAGS (separated by space, ended with~): ";
    getline(cin, tags, '~');
    if (cin.eof()) {
        throw runtime_error("EOF");
    }

    CFile newFile(category, filename);
    newFile.m_tags = CFile::SeparateTags(tags);
    CFile::CreateFileData(newFile);
}

void ExportFile::Execute(string &lastRes) {
    string path;
    MakeSpace();
    PrintLast(lastRes);
    cout << "Insert folder path (press '%' to exit):\n";
    cin >> path;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (path == "%") {
        return;
    }
    CSearch::SearchAllFiles();
    cout << "\nName of the file to be exported( press '%' to exit):\n";
    string filename;
    cin >> filename;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (filename == "%") {
        return;
    }
    CSearch::SearchAllFiles();
    CExport exportf(path);
    exportf.ExportFile(filename);
}


void ListAll::Execute(string &lastRes) {
    cout << "\n    Search all:\n";
    cout << " 1. CATEGORIES\n";
    cout << " 2. FILES\n";
    cout << " 3. TAGS\n";
    cout << " 4. ALL\n";
    cout << " 5. exit\n";
    cout << "Enter your choice(1-5):";
    char choice;
    cin >> choice;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }

    switch (choice) {
        case '1':
            MakeSpace();
            CSearch::SearchAllCategories();
            break;
        case '2':
            MakeSpace();
            CSearch::SearchAllFiles();
            break;
        case '3':
            MakeSpace();
            CSearch::SearchAllTags();
            break;
        case '4':
            MakeSpace();
            CSearch::SearchAll();
            break;
        case '5':
            MakeSpace();
            break;
        default:
            MakeSpace();
            return;
    }
}

SearchFile::~SearchFile()
{
    delete m_catSearch;
    delete m_tagSearch;
}