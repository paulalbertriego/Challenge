#include "StringHelper.h"

vector<string> StringHelper::split(const string& t_words, char t_delim)
{
    istringstream  stream(t_words);
    string item;
    vector<string> elem;
    while (getline(stream, item, t_delim))
        elem.push_back(item);

    return elem;
}
