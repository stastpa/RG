#pragma once

#include "CFileHandler.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

/**
 * @struct TFile
 * @brief Represents Files and their tags
 */
struct TFile {
    string m_name;
    set<string> m_tags;
};
/**
 * @struct TCategory
 * @brief Represents categories and their files
 */
struct TCategory {
    string m_name;
    map<string, TFile> m_files;
};

/**
 * @class CConfigParser
 * @brief Class that parses data from "data.txt"
 */
class CConfigParser {
public:
    /** @brief Default constructor */
    CConfigParser() = default;

    /**
     * @brief Parses data form file given by path
     * @param path [in] Path to file with data (data.txt)
     * @return vector<TCategory>              Returns Categories(connected with their files and thus their tags)
     */
    vector<TCategory> Parse(string path);

private:

    enum ELineType {
        CATEGORY = 0,
        FILE,
        TAG,
        INVALID
    };

    /**
     * @brief Reads categories and stores them into Vector
     * @param vec [in/out] Vector of Categories
     */
    void ReadCategory(vector<TCategory> &vec);

    /**
     * @brief Reads files and stores them into Vector
     * @param files [in,out] Vector of file
     */
    void ReadFile(vector<TFile> &files);

    /**
     * @brief Reads tags of given file (inserts tags to struct file form line buffer)
     * @param file [in] File that "owns" those tags
     */
    void ReadTag(TFile &file);

    /**
     * @brief Clears vector of files and stores file names under category
     * @param files [in]/[out] Vector of files
     * @param category [in]/[out] Category
     */
    void DumpFiles(vector<TFile> &files, TCategory &category);

    /**
     * @brief Resolves what enum is on the line
     * @return ELineType              Returns what is on the line (Tag, File, Category or invalid)
     */
    ELineType LineType() const;

    string m_line_buffer;
    ELineType m_prev_type = ELineType::INVALID;
};