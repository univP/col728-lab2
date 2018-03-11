#ifndef STRTAB_H
#define STRTAB_H

#include <string>
#include <list>
#include <iostream>
#include <set>
#include <map>

typedef std::string* Symbol;

class StrTable : public std::map<std::string, Symbol> {
    typedef iterator MapI;
public:
    Symbol add_string(std::string str) {
        MapI it = find(str);

        if (it != end()) {
            return it->second;
        }

        Symbol symbol = new std::string(str);
        insert(std::make_pair(str, symbol));
        return symbol;
    }
};

extern StrTable id_table;
extern StrTable str_table;
extern StrTable int_table;
extern StrTable float_table;

#endif