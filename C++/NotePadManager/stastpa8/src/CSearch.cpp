#include "CSearch.h"

#define RED     "\033[31m"      /* Red */
#define RESET   "\033[0m"

CSearch::~CSearch() {
}


SearchByCategory::SearchByCategory() {
}

SearchByTag::SearchByTag() {
}

void SearchByCategory::containsKey(const string &key, string &res) {
    res = "";
    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");

    for (const auto &category: retval) {
        if (category.m_name == key) {
            for (const auto &file: category.m_files) {
                cout << '\t' << file.second.m_name << '\n';
                res += '\t' + file.second.m_name + '\n';
            }
        }
    }
}

void SearchByCategory::DisplayHelp()
{
    cout << "Category name (press '%' to exit):\n";
}
void SearchByTag::containsKey(const string &key, string &res) {
    res = "";
    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");

    for (const auto &category: retval) {
        for (const auto &file: category.m_files) {
            for (const auto &tag: file.second.m_tags) {
                if (tag == key) {
                    cout << '\t' << file.second.m_name << '\n';
                    res += '\t' + file.second.m_name + '\n';
                }
            }
        }
    }
}

void SearchByTag::DisplayHelp()
{
    cout << "Tag name (press '%' to exit):\n";
}


void CSearch::SearchAllFiles() {
    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");
    cout << "\nAll files:\n";
    for (const auto &category: retval) {
        for (const auto &file: category.m_files) {
            cout << RED << file.second.m_name << RESET << '\n';
        }
    }
}

void CSearch::SearchAll() {
    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");

    for (const auto &category: retval) {
        cout << category.m_name << '\n';
        for (const auto &file: category.m_files) {
            cout << '\t' << file.second.m_name << '\n';
            for (const auto &tag: file.second.m_tags) {
                cout << "\t\t" << tag << '\n';
            }
        }
    }
}

void CSearch::SearchAllCategories() {

    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");
    cout << "\nAll categories:\n";
    for (const auto &category: retval) {
        cout << RED << category.m_name << RESET << '\n';
    }
}

void CSearch::SearchAllTags() {
    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");
    cout << "\nAll tags:\n";
    for (const auto &category: retval) {
        for (const auto &file: category.m_files) {
            for (const auto &tag: file.second.m_tags) {
                cout << RED << tag << RESET <<'\n';
            }
        }
    }
}

void SearchByCategory::SeachAll()
{
    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");
    cout << "\nAll categories:\n";
    for (const auto &category: retval) {
        cout << RED << category.m_name << RESET << '\n';
    }
}

void SearchByTag::SeachAll()
{
    CConfigParser parser;
    auto retval = parser.Parse("./assets/data.txt");
    cout << "\nAll tags:\n";
    for (const auto &category: retval) {
        for (const auto &file: category.m_files) {
            for (const auto &tag: file.second.m_tags) {
                cout << RED << tag << RESET <<'\n';
            }
        }
    }
}