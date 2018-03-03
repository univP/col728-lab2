#ifndef TABLE_H
#define TABLE_H

#include "list.h"

class Entry {
private:
    int index;
    std::string str;
public:
    Entry(int index, std::string str);
    int get_index();
    std::string get_str();
};

typedef Entry* Symbol;

class Table {
private:
    List<Entry>* table;
    int len;
public:
    Table();
    Symbol add_string(std::string str);
    List<Entry>* get_table();
    int get_len();
};

extern Table id_table;
extern Table str_table;
extern Table int_table;

#endif