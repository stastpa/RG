#include "CFileHandler.h"

CFileHandler::CFileHandler(const string &path)
        : m_file(path, ios::in) {
}

CFileHandler::~CFileHandler() {
    if (m_file.is_open())
        m_file.close();
}

bool CFileHandler::GoodAndOpen() const {
    return m_file.good() && m_file.is_open();
}

bool CFileHandler::Eof() const {
    return m_file.eof();
}

string CFileHandler::ReadLine() {

    string line = "";
    ReadLine(line);
    return line;
}

void CFileHandler::ReadLine(string &str) {
    if (!Eof()) {
        getline(m_file, str);
        // remove Windows \r (carriage return)
        if (str.length() && str.back() == '\r')
            str.pop_back();
    }
}

void CFileHandler::trim(string &s) {
    // start ->
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
                                   return !isspace(ch);
                               }
    ));
    // <- end
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                        return !isspace(ch);
                    }
    ).base(), s.end());
}