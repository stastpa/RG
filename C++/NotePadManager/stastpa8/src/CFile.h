#ifndef SRC_CFILE_H
#define SRC_CFILE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @class CFile
 * @brief Class that represents file data
 */
class CFile {
public:

    vector<string> m_tags;

    /**
     * @brief Constructor
     * @param category [in] File category
     * @param name [in] File name
     */
    CFile(string category, string name);

    /**
     * @brief Creates Data in data.txt about the file (category, name, tags)
     * @param cFile [in] File to make data from
     */
    static void CreateFileData(CFile cFile);

    /**
     * @brief Deletes Data in data.txt about the file (category, name, tags)
     * @param key [in] Name of the file
     */
    static void DeleteFileData(string key);

    /**
     * @brief Receives all tags in one string and puts them in separated strings
     * @param tags [in] All tags in one string separated by space
     * @return vector<string>              Returns vector of (separated) tags
     */
    static vector<string> SeparateTags(string tags);

private:

    /** @brief Updates Data in data.txt about the file (category, name, tags) */
    static void UpdateData();

    string m_category;
    string m_name;

};


#endif //SRC_CFILE_H
