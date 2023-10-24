#ifndef SRC_CIMPORT_H
#define SRC_CIMPORT_H

#include <string>

using namespace std;

/**
 * @class CImport
 * @brief Class that handles Importing files
 */
class CImport {
public:
    /**
     * @brief Constructor
     * @param path [in] Path to the file to be imported
     */
    CImport(string path);

    /**
     * @brief Imports file to the program
     * @param filename [in] New name (can be the same as old)
     */
    void ImportFile(string filename);


private:
    string m_path;
};


#endif //SRC_CIMPORT_H
