#include "../headers/expertsystem.hpp"

vector <string> g_rules;
string g_facts;
string g_queries;
string g_not_true;

string  ft_strtrim(const string str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (str.substr(first, (last - first + 1)));
}

bool    readfile(string file)
{
    string temp;
    size_t found;

    ifstream reader(file);
    if (!reader)
    {
        cout << "Unable to read file\n";
        return false;
    }
    while (getline(reader, temp))
    {
        if (temp[0] == '=')
        {
            found = temp.find("#");
            temp = temp.substr(0, found);
            temp = ft_strtrim(temp);
            g_facts = temp.substr(1, temp.length() - 1);
        }
        else if (temp[0] == '?')
        {
            found = temp.find("#");
            temp = temp.substr(0, found);
            temp = ft_strtrim(temp);
            g_queries = temp.substr(1, temp.length() - 1);
        }
        else if ((temp[0] >= 65 && temp[0] <= 90) ||
                    temp[0] == '!' || temp[0] == '(')
        {
            found = temp.find("#");
            temp = temp.substr(0, found);
            temp = ft_strtrim(temp);
            g_rules.push_back(temp);
        }
    }
    return true;
}

bool    check_facts(char query)
{
    const char *strptr;

    strptr = g_facts.c_str();
    if (strchr(strptr, query))
        return true;
    else
        return false;
}

void    check_query()
{
    size_t query_len;

    query_len = g_queries.size();
    //cout << "Query_len: " << query_len << endl;
    for (size_t i = 0; i < query_len; i++)
    {
        if (check_facts(g_queries[i]))
            cout << g_queries[i] << " : True\n";
        else
            cout << g_queries[i] << " : False\n";
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./expert input_file.txt\n";
        return (0);
    }
    if (!readfile(argv[1]))
        return (0);
    
    int i = g_facts.size();
    cout << "Size facts: " << i << endl;
    cout << "Facts given: " << g_facts << endl;
    read_rules();
    cout << "Facts: " << g_facts << endl;
    cout << "Query: " << g_queries << endl;
    cout << "Processed rules: \n";
    for (size_t j = 0; j < g_rules.size(); j++)
        cout << "Rules: " << g_rules[j] << endl;
    check_query();
    return (0);
}