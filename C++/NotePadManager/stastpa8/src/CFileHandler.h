#pragma once

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @class CFileHandler
 * @brief Class used mostly with CConfigParser to safely retrieve data from "data.txt"
 */
class CFileHandler {
public:

    /**
     * @brief Constructor
     * @param path [in] File path
     */
    CFileHandler(const string &path);

    /** @brief default destructor */
    ~CFileHandler();

    /**
     * @brief Checks if m_file is good and open
     * @return bool
     *                true = Good and open
     *                false = Not good and/or not open
     */
    bool GoodAndOpen() const;

    /**
     * @brief Checks if there are no more data to be read from an input file stream
     * @return bool
     *                true = There are no more data to be read from an input file stream
     *                false = There are data to be read from an input file stream
     */
    bool Eof() const;

    string ReadLine();

    /**
     * @brief Reads line from file and saves it into string
     * @param str [in]/[out] Stores line
     */
    void ReadLine(string &str);

    /**
     * @brief Trims line buffer
     * @param s [in]/[out] Line to be trimmed
     */
    static void trim(string &s);

private:

    ifstream m_file;
};