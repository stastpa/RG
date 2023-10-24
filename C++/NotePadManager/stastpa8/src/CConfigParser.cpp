#include "CConfigParser.h"

vector<TCategory> CConfigParser::Parse(string path) {
    CFileHandler config(path);

    vector<TCategory> retval;
    vector<TFile> file_buffer;

    while (config.GoodAndOpen() && !config.Eof()) {
        config.ReadLine(m_line_buffer);

        ELineType type = LineType();

        if (type == ELineType::INVALID)
        {
             continue;
        }
        // first valid type has to be category by definition
        if (m_prev_type == ELineType::INVALID && type != ELineType::CATEGORY)
        {
            cout << "data file has been corrupted, exiting...\n";
            throw runtime_error("malformed data");
        }

        CFileHandler::trim(m_line_buffer);

        switch (type) {
            case ELineType::CATEGORY:
                if (file_buffer.size() && retval.size())
                    DumpFiles(file_buffer, retval.back());

                ReadCategory(retval);
                break;
            case ELineType::FILE:
                ReadFile(file_buffer);
                break;
            case ELineType::TAG:
                if (file_buffer.size())
                    ReadTag(file_buffer.back());
                break;
            case ELineType::INVALID:
            default:
                continue;
        }

        m_prev_type = type;
    }

    if (file_buffer.size() && retval.size())
        DumpFiles(file_buffer, retval.back());

    for (size_t i = 0; i < retval.size();) {
        if (retval[i].m_files.empty()) {
            retval.erase(retval.begin() + i);
        } else
            i++;
    }

    return retval;
}

void CConfigParser::ReadCategory(vector<TCategory> &vec) {
    TCategory category = {
            m_line_buffer,
            {}
    };
    vec.push_back(category);
}

void CConfigParser::ReadFile(vector<TFile> &files) {
    TFile file = {
            m_line_buffer,
            {}
    };
    files.push_back(file);
}

void CConfigParser::ReadTag(TFile &file) {
    file.m_tags.insert(m_line_buffer);
}

void CConfigParser::DumpFiles(vector<TFile> &files, TCategory &category) {
    for (const auto &file: files)
        category.m_files.insert({file.m_name, file});
    files.clear();
}

CConfigParser::ELineType CConfigParser::LineType() const {
    // zero length of config file is forbidden (empty line)
    if (m_line_buffer.length() == 0)
        return ELineType::INVALID;

    // "School"
    if (m_line_buffer[0] != ' ')
        return ELineType::CATEGORY;

    // " ", invalid case
    if (m_line_buffer.length() == 1)
        return ELineType::INVALID;

    // " my-file.txt", good
    if (m_line_buffer[1] != ' ')
        return ELineType::FILE;

    // "  ", invalid case
    if (m_line_buffer.length() == 2)
        return ELineType::INVALID;

    // "   .*", two space, one whitespace, considered as invalid format
    if (isspace(m_line_buffer[2]))
        return ELineType::INVALID;

    // yay, it's a tag
    return ELineType::TAG;
}
