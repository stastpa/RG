#include "CFile.h"
#include "CConfigParser.h"
#include <iostream>

using namespace std;

CFile::CFile(string category, string name) {
    m_category = category;
    m_name = name;
}

vector<string> CFile::SeparateTags(string tags) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != tags.size()) {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != tags.size() && isspace(tags[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j)is a space
        while (j != tags.size() && !isspace(tags[j]))
            j++;
        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and taking j - i chars
            ret.push_back(tags.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

void CFile::CreateFileData(CFile cFile) {
    ofstream file;
    file.open("./assets/data.txt", ios::out | ios::app);
    file << cFile.m_category << "\n";
    file << " " << cFile.m_name << "\n";
    for (size_t i = 0; i != cFile.m_tags.size(); ++i)
        file << "  " << cFile.m_tags[i] << "\n";
    file.close();
}

void CFile::DeleteFileData(string key) {
    string line;
    ifstream fin;
    string path = "./assets/data.txt";

    fin.open(path);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    ofstream temp;
    temp.open("./assets/temp.txt");

    while (getline(fin, line)) {
        // write all lines to temp other than the line marked for erasing
        if (line != key)
            temp << line << endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char *p = path.c_str();
    remove(p);
    rename("./assets/temp.txt", p);

    UpdateData();
}

void CFile::UpdateData() {
    string line;
    ifstream fin;
    string path = "./assets/data.txt";

    fin.open(path);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    ofstream temp;
    temp.open("./assets/temp.txt");

    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");

    for (const auto &category: retval) {
        temp << category.m_name << '\n';
        for (const auto &file: category.m_files) {
            temp << " " << file.second.m_name << '\n';
            for (const auto &tag: file.second.m_tags) {
                temp << "  " << tag << '\n';
            }
        }
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char *p = path.c_str();
    remove(p);
    rename("./assets/temp.txt", p);
}