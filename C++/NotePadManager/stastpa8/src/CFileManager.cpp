#include "CMenu.h"
#include "CFileManager.h"
#include "CFile.h"
#include "CSearch.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>

#define RESET     "\033[0m"
#define BLACK     "\033[30m"      /* Black */
#define RED       "\033[31m"      /* Red */
#define GREEN     "\033[32m"      /* Green */
#define YELLOW    "\033[33m"      /* Yellow */
#define BLUE      "\033[34m"      /* Blue */
#define MAGENTA   "\033[35m"      /* Magenta */
#define CYAN      "\033[36m"      /* Cyan */
#define WHITE     "\033[37m"      /* White */
#define BALDstart "\e[1m"         /* BALD */
#define BALDend   "\e[0m"         /* NoMoreBALD */
#define UNDERLINE "\033[4m"       /* underline */


using namespace std;


void CFileManager::ReadFile() {
    CSearch::SearchAllFiles();
    string filename;
    cout << "File name [NO EXTENSION] (press '%' to exit):\n";
    cin >> filename;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (filename == "%") {
        return;
    }
    CSearch::SearchAllFiles();
    cout << "File extension [WITH DOT] (press '%' to exit):\n";
    string extension;
    cin >> extension;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (extension == "%") {
        return;
    }
    char backToMenu;
    if (extension == ".col") {
        CFunctionality::MakeSpace();
        ifstream file("./examples/" + filename + extension); //open file
        if (!file) {
            cerr << "Could not open the file!\n";
            return;
        }

        string text;
        cout << "File name: " << filename << "\nMode: Read\n" << "Press ANY KEY to quit \n" << "____________________\n\n\n";
        while (getline(file, text)) {
            char color = text[0];
            if (color == '1') {
                text.erase(0, 1);
                cout << BLACK << text << "\n"; //display
                cout << RESET;
            } else if (color == '2') {
                text.erase(0, 1);
                cout << RED << text << "\n"; //display
                cout << RESET;
            } else if (color == '3') {
                text.erase(0, 1);
                cout << GREEN << text << "\n"; //display
                cout << RESET;
            } else if (color == '4') {
                text.erase(0, 1);
                cout << YELLOW << text << "\n"; //display
                cout << RESET;
            } else if (color == '5') {
                text.erase(0, 1);
                cout << BLUE << text << "\n"; //display
                cout << RESET;
            } else if (color == '6') {
                text.erase(0, 1);
                cout << MAGENTA << text << "\n"; //display
                cout << RESET;
            } else if (color == '7') {
                text.erase(0, 1);
                cout << CYAN << text << "\n"; //display
                cout << RESET;
            } else if (color == '8') {
                text.erase(0, 1);
                cout << WHITE << text << "\n"; //display
                cout << RESET;
            } else if (color == '*') {
                text.erase(0, 1);
                cout << BALDstart << text << BALDend << "\n"; //display
            }  else if (color == '\t') {
                text.erase(0, 1);
                cout << UNDERLINE << text << RESET << "\n"; //display
            }  else
                cout << RESET << text << "\n";
        }
        cin >> backToMenu;
        if (cin.eof()) {
            throw runtime_error("EOF");
        }
            CFunctionality::MakeSpace();
            return;
    }
    else {
        CFunctionality::MakeSpace();
        ifstream file("./examples/" + filename + extension); //open file
        if (!file) {
            cerr << "Could not open the file!\n";
            return;
        }

        string text;
        cout << "File name: " << filename << "\nMode: Read\n" << "Press ANY KEY to quit \n" << "____________________\n\n\n";
        while (getline(file, text)) {
            cout << text << "\n"; //display
        }
        cin >> backToMenu;
        if (cin.eof()) {
            throw runtime_error("EOF");
        }
        CFunctionality::MakeSpace();
        return;
    }
}

void CFileManager::CreateFile(string filename, string extension) {
    string category;
    string name = filename + extension;
    string tags;

    CFunctionality::MakeSpace();
    cout << "Add CATEGORY: ";
    cin >> category;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    CFunctionality::MakeSpace();
    cout << "Add TAGS (separated by space, ended with~): ";
    getline(cin, tags, '~');
    if (cin.eof()) {
        throw runtime_error("EOF");
    }

    CFile newFile(category, name);
    newFile.m_tags = CFile::SeparateTags(tags);
    CFile::CreateFileData(newFile);
    ofstream file("./examples/" + name);
    file.close();


}

void CFileManager::EditFile() {
    string filename;
    CSearch::SearchAllFiles();
    cout << "File to be edited (press '%' to exit):\n";
    cin >> filename;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (filename == "%") {
        return;
    }
    ifstream file("./examples/" + filename);
    if (!file) {
        cerr << "Could not open the file!\n";
        return;
    }
    string s = "nano ./examples/" + filename;
    system(s.c_str());
}

void CFileManager::DeleteFile() {
    CSearch::SearchAllFiles();
    cout << "File to be deleted (press '%' to exit):\n";
    string filename;
    cin >> filename;
    if (cin.eof()) {
        throw runtime_error("EOF");
    }
    if (filename == "%") {
        return;
    }

    int result = remove(("./examples/" + filename).c_str());
    CFile::DeleteFileData(" " + filename);
    // check if file has been deleted successfully
    if (result != 0) {
        CFunctionality::MakeSpace();
        // print error message
        cerr << "File not found\n";
        return;
    } else {
        cout << "File deleted successfully\n";
        return;
    }
}