#include "CExport.h"
#include "CMenu.h"
#include <fstream>
#include <iostream>
#include <ios>

using namespace std;

CExport::CExport(string path) {
    m_path = path;
}


void CExport::ExportFile(string name) {
    string file = "./examples/" + name;
    ifstream in(file, ios::in | ios::binary);
    if (!in) {
        cerr << "File does not exist!\n";
        return;
    }
    ofstream out(m_path + name, ios::out | ios::binary);
    if (!out) {
        cerr << "Path does not exist!\n";
        return;
    }
}
