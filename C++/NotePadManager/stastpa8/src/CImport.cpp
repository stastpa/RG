#include "CImport.h"
#include "CMenu.h"
#include <fstream>
#include <iostream>
#include <ios>
#include <cstdio>

using namespace std;

CImport::CImport(string path) {
    m_path = path;
}

void CImport::ImportFile(string filename) {
    ifstream in(m_path, ios::in | ios::binary);
    if (!in) {
        cerr << "Path does not exist!\n";
        return;
    }
    ofstream out("./examples/" + filename, ios::out | ios::binary);
}