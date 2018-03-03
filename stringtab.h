#ifndef SYMTAB_H
#define SYMTAB_H

#include "list.h"

class Entry {
private:
    char* value;
    int index;
public:
    Entry(char* value, int index);
    char* get_string();
    int get_index();
};

typedef Entry* Symbol;

class StringTable {
private:
    List<Entry>* table;
    int len;
public:
    StringTable();
    Symbol add_string(char* value);
    Symbol add_int(int value);
    List<Entry>* get_table();
    int get_len();
};

#endif