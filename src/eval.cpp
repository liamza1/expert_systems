#include "../headers/expertsystem.hpp"

bool    eval_and(string sub)
{
    char first;
    char second;
    size_t sub_len;

    first = '0';
    second = '0';
    sub_len = sub.length();
    for (size_t i = 0; sub[i]; i++)
    {
        if ((sub[i] >= 65 && sub[i] <= 90) || sub[i] == '1')
        {
            if (first == '0')
                first = sub[i];
            else if (second == '0')
                second = sub[i];
            else
                cout << "Too many variables in expression: " << sub << endl;
        }
    }
    if ((g_facts.find(first) < g_facts.length() || first == '1') &&
        (g_facts.find(second) < g_facts.length() || second == '1'))
        return true;
    else
        return false;
}

bool    eval_or(string sub)
{
    char first;
    char second;
    size_t sub_len;

    first = '0';
    second = '0';
    sub_len = sub.length();
    for (size_t i = 0; sub[i]; i++)
    {
        if ((sub[i] >= 65 && sub[i] <= 90) || sub[i] == '1')
        {
            if (first == '0')
                first = sub[i];
            else if (second == '0')
                second = sub[i];
            else
                cout << "Too many variables in expression: " << sub << endl;
        }
    }
    if ((g_facts.find(first) < g_facts.length() || first == '1') ||
        (g_facts.find(second) < g_facts.length() || second == '1'))
        return true;
    else
        return false;
}

bool    eval_xor(string sub)
{
    char first;
    char second;
    size_t sub_len;

    first = '0';
    second = '0';
    sub_len = sub.length();
    for (size_t i = 0; sub[i]; i++)
    {
        if ((sub[i] >= 65 && sub[i] <= 90) || sub[i] == '1')
        {
            if (first == '0')
                first = sub[i];
            else if (second == '0')
                second = sub[i];
            else
                cout << "Too many variables in expression: " << sub << endl;
        }
    }
    if ((g_facts.find(first) < g_facts.length() || first == '1') ^
        (g_facts.find(second) < g_facts.length() || second == '1'))
        return true;
    else
        return false;
}