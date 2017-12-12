#include "../headers/expertsystem.hpp"

bool    replace_brackets(size_t first, size_t last, size_t index)
{
    string sub;
    size_t replace_len;

    sub = g_rules[index].substr((first + 1), (last - first - 1));
    replace_len = last - first + 1;
    //cout << sub << endl;
    if (sub[2] == '+')
    {
        if (eval_and(sub))
        {
            g_rules[index].replace(first, replace_len, "1");
            return true;
        }
        else
            return false;
    }
    else if (sub[2] == '|')
    {
        if (eval_or(sub))
        {
            g_rules[index].replace(first, replace_len, "1");
            return true;
        }
        else
            return false;
    }
    else if (sub[2] == '^')
    {
        if (eval_xor(sub))
        {
            g_rules[index].replace(first, replace_len, "1");
            return true;
        }
        else
            return false;
    }
    return false;
}

bool    replace_and(size_t first, size_t last, size_t index)
{
    string sub;
    size_t replace_len;

    sub = g_rules[index].substr(first, (last - first + 1));
    replace_len = last - first + 1;
    if (eval_and(sub))
    {
        g_rules[index].replace(first, replace_len, "1");
        return true;
    }
    else
        return false;
    //  g_rules[index].replace(first, replace_len, "0");
}

bool    replace_or(size_t first, size_t last, size_t index)
{
    string sub;
    size_t replace_len;

    sub = g_rules[index].substr(first, (last - first + 1));
    replace_len = last - first + 1;
    if (eval_or(sub))
    {
        g_rules[index].replace(first, replace_len, "1");
        return true;
    }
    else
        return false;
    //    g_rules[index].replace(first, replace_len, "0");
}

bool    replace_xor(size_t first, size_t last, size_t index)
{
    string sub;
    size_t replace_len;

    sub = g_rules[index].substr(first, (last - first + 1));
    replace_len = last - first + 1;
    if (eval_xor(sub))
    {
        g_rules[index].replace(first, replace_len, "1");
        return true;
    }
    else
        return false;
    //    g_rules[index].replace(first, replace_len, "0");
}

bool    replace_not(size_t first, char var, size_t index)
{
    string sub;
    size_t replace_len;

    replace_len = 2;
    if (g_facts.find(var) < g_facts.length())
    {
        g_rules[index].replace(first, replace_len, "0");
        return true;
    }
    else
    {
        g_rules[index].replace(first, replace_len, "1");
        return true;
    }
}