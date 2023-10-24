#ifndef SRC_CSEARCH_H
#define SRC_CSEARCH_H

#include "CConfigParser.h"
#include <iostream>
#include <list>

using namespace std;

/**
 * @class CSearch
 * @brief Class that handles searching for files, tags etc.
 */
class CSearch {

public:

    /** @brief Default constructor */
    CSearch() = default;

    /** @brief Default destructor */
    virtual ~CSearch();


    /** @brief Searches and lists all file names */
    static void SearchAllFiles();


    /** @brief Searches and lists all file names, categories, tags */
    static void SearchAll();


    /** @brief Searches and lists all tags */
    static void SearchAllTags();


    /** @brief Searches and lists all categories */
    static void SearchAllCategories();

    /**
     * @brief Function that is inherited by other classes
     * @param key [in] Expression to be found
     * @param res [in/out] Search result
     */
    virtual void containsKey(const string &key, string &res) = 0;

    /** @brief Displays instructional message */
    virtual void DisplayHelp() = 0;

    /** @brief Searches and lists all tags or categories */
    virtual void SeachAll() = 0;
};

/**
 * @class SearchByTag
 * @brief Class derived from CSearch class, handles only tag search
 */
class SearchByTag : public CSearch {
public:

    SearchByTag();

    void containsKey(const string &key, string &res) override;

    void DisplayHelp() override;
    /** @brief Searches and lists all tags */
    void SeachAll();
};

/**
 * @class SearchByCategory
 * @brief Class derived form CSearch class, handles only category search
 */
class SearchByCategory : public CSearch {
public:

    SearchByCategory();

    void containsKey(const string &key, string &res) override;

    void DisplayHelp() override;
    /** @brief Searches and lists all categories */
    void SeachAll();
};

#endif //SRC_CSEARCH_H
