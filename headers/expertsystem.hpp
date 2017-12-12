#ifndef __ES_H
#define __ES_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//rules.cpp
void    read_rules();
//bool    find_symbol(string rule);
bool    rules_final();

//replace.cpp
bool    replace_brackets(size_t first, size_t last, size_t index);
bool    replace_and(size_t first, size_t last, size_t index);
bool    replace_not(size_t first, char var, size_t index);
bool    replace_or(size_t first, size_t last, size_t index);
bool    replace_xor(size_t first, size_t last, size_t index);

//main.cpp
string  ft_strtrim(const string str);
bool    readfile(string file);
bool    check_facts(char query);
void    check_query();

//eval.cpp
bool    eval_and(string sub);
bool    eval_or(string sub);
bool    eval_xor(string sub);

//replace_final.cpp
bool    replace_brackets_final(size_t first, size_t last, size_t index);
bool    replace_and_final(size_t first, size_t last, size_t index);
bool    replace_or_final(size_t first, size_t last, size_t index);
bool    replace_xor_final(size_t first, size_t last, size_t index);
bool    replace_not_final(size_t first, char var, size_t index);

extern vector <string> g_rules;
extern string g_facts;
extern string g_queries;
extern string g_not_true;

#endif