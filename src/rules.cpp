#include "../headers/expertsystem.hpp"
/*
bool        find_symbol(string rule)
{
    if (rule.find("(") < rule.length() ||
        rule.find(")") < rule.length() ||
        rule.find("!") < rule.length() ||
        rule.find("+") < rule.length() ||
        rule.find("|") < rule.length() ||
        rule.find("^") < rule.length())
        return true;
    else
        return false;
}
*/
bool         rules_final()
{
    size_t num_rules;
    size_t first;
    size_t last;
    size_t sym;
    bool changed;

    changed = false;
    num_rules = g_rules.size();
    for (size_t i = 0; i < num_rules; i++)
    {
            if (g_rules[i].find("(") < g_rules[i].find("=") &&
                g_rules[i].find(")") < g_rules[i].find("="))
            {
                first = g_rules[i].find("(");
                last = g_rules[i].find(")");
                if (replace_brackets_final(first, last, i))
                    changed = true;
            }
            else if ((first = g_rules[i].find("!")) < g_rules[i].find("="))
            {
                last = first + 1;
                if (replace_not_final(first, g_rules[i][last], i))
                    changed = true;
            }
            else if ((sym = g_rules[i].find("+")) < g_rules[i].find("="))
            {
                first = sym;
                last = sym;
                while (first > 0 && (g_rules[i][first] < 65 || g_rules[i][first] > 90)
                        && g_rules[i][first] != '1' && g_rules[i][first] != '0')
                    first--;
                while (g_rules[i][last] != '=' && (g_rules[i][last] < 65 || g_rules[i][last] > 90)
                        && g_rules[i][last] != '1' && g_rules[i][last] != '0')
                    last++;
                if (replace_and_final(first, last, i))
                    changed = true;
            }
            else if ((sym = g_rules[i].find("|")) < g_rules[i].find("="))
            {
                first = sym;
                last = sym;
                while (first > 0 && (g_rules[i][first] < 65 || g_rules[i][first] > 90)
                        && g_rules[i][first] != '1' && g_rules[i][first] != '0')
                    first--;
                while (g_rules[i][last] != '=' && (g_rules[i][last] < 65 || g_rules[i][last] > 90)
                        && g_rules[i][last] != '1' && g_rules[i][last] != '0')
                    last++;
                if (replace_or_final(first, last, i))
                    changed = true;
            }
            else if ((sym = g_rules[i].find("^")) < g_rules[i].find("="))
            {
                first = sym;
                last = sym;
                while (first > 0 && (g_rules[i][first] < 65 || g_rules[i][first] > 90))
                    first--;
                while (g_rules[i][last] != '=' && (g_rules[i][last] < 65 || g_rules[i][last] > 90))
                    last++;
                if (replace_xor_final(first, last, i))
                    changed = true;
            }
            else if (g_rules[i][0] == '1' && g_rules[i][1] == ' ' &&
                (g_rules[i][2] == '<' || g_rules[i][2] == '='))
            {
                first = g_rules[i].find(">");
                while (g_rules[i][first])
                {
                    if (g_rules[i][first] >= 65 && g_rules[i][first] <= 90)
                    {
                        if (!(g_facts.find(char(g_rules[i][first])) < g_facts.length()))
                        {
                            g_facts = g_facts + g_rules[i][first];
                            changed = true;
                        }
                    }
                    first++;
                }
            }
            first = 0;
            while (g_rules[i][first] && g_rules[i][first] != '=')
            {
                if (g_facts.find(char(g_rules[i][first])) < g_facts.length())
                {
                    g_rules[i][first] = '1';
                    changed = true;
                }
                first++;
            }
    }
    return (changed);
}

void         read_rules()
{
    size_t num_rules;
    size_t first;
    size_t last;
    size_t sym;
    bool changed;

    changed = false;
    num_rules = g_rules.size();
    for (size_t i = 0; i < num_rules; i++)
    {
            if (g_rules[i].find("(") < g_rules[i].find("=") &&
                g_rules[i].find(")") < g_rules[i].find("="))
            {
                first = g_rules[i].find("(");
                last = g_rules[i].find(")");
                if (replace_brackets(first, last, i))
                    changed = true;
            }
            else if ((first = g_rules[i].find("!")) < g_rules[i].find("="))
            {
                last = first + 1;
                if (replace_not(first, g_rules[i][last], i))
                    changed = true;
            }
            else if ((sym = g_rules[i].find("+")) < g_rules[i].find("="))
            {
                first = sym;
                last = sym;
                while (first > 0 && (g_rules[i][first] < 65 || g_rules[i][first] > 90)
                        && g_rules[i][first] != '1' && g_rules[i][first] != '0')
                    first--;
                while (g_rules[i][last] != '=' && (g_rules[i][last] < 65 || g_rules[i][last] > 90)
                        && g_rules[i][last] != '1' && g_rules[i][last] != '0')
                    last++;
                if (replace_and(first, last, i))
                    changed = true;
            }
            else if ((sym = g_rules[i].find("|")) < g_rules[i].find("="))
            {
                first = sym;
                last = sym;
                while (first > 0 && (g_rules[i][first] < 65 || g_rules[i][first] > 90)
                        && g_rules[i][first] != '1' && g_rules[i][first] != '0')
                    first--;
                while (g_rules[i][last] != '=' && (g_rules[i][last] < 65 || g_rules[i][last] > 90)
                        && g_rules[i][last] != '1' && g_rules[i][last] != '0')
                    last++;
                if (replace_or(first, last, i))
                    changed = true;
            }
            else if ((sym = g_rules[i].find("^")) < g_rules[i].find("="))
            {
                first = sym;
                last = sym;
                while (first > 0 && (g_rules[i][first] < 65 || g_rules[i][first] > 90))
                    first--;
                while (g_rules[i][last] != '=' && (g_rules[i][last] < 65 || g_rules[i][last] > 90))
                    last++;
                if (replace_xor(first, last, i))
                    changed = true;
            }
            else if (g_rules[i][0] == '1' && g_rules[i][1] == ' ' &&
                (g_rules[i][2] == '<' || g_rules[i][2] == '='))
            {
                first = g_rules[i].find(">");
                while (g_rules[i][first])
                {
                    if (g_rules[i][first] >= 65 && g_rules[i][first] <= 90)
                    {
                        if (!(g_facts.find(char(g_rules[i][first])) < g_facts.length()))
                        {
                            g_facts = g_facts + g_rules[i][first];
                            changed = true;
                        }
                    }
                    first++;
                }
            }
            first = 0;
            while (g_rules[i][first] && g_rules[i][first] != '=')
            {
                if (g_facts.find(char(g_rules[i][first])) < g_facts.length())
                {
                    g_rules[i][first] = '1';
                    changed = true;
                }
                first++;
            }
    }
    if (changed)
        read_rules();
    if (rules_final())
        read_rules();
}