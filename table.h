#ifndef TABLE_H
#define TABLE_H

#include "list.h"

class Entry {
private:
    int index;
    char* value;
public:
    Entry(int index, char* value);
    int get_index();
    char* get_value();
};

typedef Entry* Symbol;

class Table {
private:
    List<Entry>* table;
    int len;
public:
    Table();
    Symbol add_string(char* value);
    List<Entry>* get_table();
    int get_len();
};

#endif