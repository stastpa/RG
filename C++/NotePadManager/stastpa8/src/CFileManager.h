#ifndef SRC_CFILEMANAGER_H
#define SRC_CFILEMANAGER_H

#include "CFile.h"
#include "CConfigParser.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @class CFileManager
 * @brief Class that handles operations with files
 */
class CFileManager {
public:

    /** @brief Displays file content */
    static void ReadFile();

    /**
     * @brief Creates new file
     * @param filename [in] File name
     * @param extension [in] File extension (.txt or .col)
     */
    static void CreateFile(string filename, string extension);

    /** @brief Function to modify file */
    static void EditFile();

    /** @brief Function to delete file */
    static void DeleteFile();
};

#endif //SRC_CFILEMANAGER_H
