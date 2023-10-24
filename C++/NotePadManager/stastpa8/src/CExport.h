#ifndef SRC_CEXPORT_H
#define SRC_CEXPORT_H

#include <string>

using namespace std;


/**
 * @class CExport
 * @brief Class that handles Exporting files
 */
class CExport {
public:
    /**
     * @brief Constructor
     * @param path [in] Path to the folder where our file will be exported
     */
    CExport(string path);

    /**
     * @brief Exports file from the program
     * @param name [in] Name of our file
     */
    void ExportFile(string name);

private:
    string m_path;
};


#endif //SRC_CEXPORT_H
