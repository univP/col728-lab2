#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "c.tab.hpp"

extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;

static void usage()
{
    printf("Usage: cc <prog.c>\n");
}

/*--------------------------------------------------.
|   Section 1: Main control flow of the program.    |
`--------------------------------------------------*/

#include "tree.h"
extern "C" ast_program* root;

int
main(int argc, char **argv)
{
    if (argc != 2) {
        usage();
        exit(1);
    }
    char const *filename = argv[1];
    yyin = fopen(filename, "r");
    assert(yyin);
    int ret = yyparse();
    printf("retv = %d\n", ret);
    exit(0);
}

/*----------------------------------------------.
|   Section 2 : Symbol definitions of tree.h    |
`----------------------------------------------*/

ast_program::ast_program(List<ast_external_declaration>* external_declarations)
        : external_declarations (external_declarations) {}


/*--------------------------------------------------.
|   Section 3 : Symbol definitions for stringtab.h  |
`--------------------------------------------------*/

Entry::Entry(int index, std::string str): index(index), str(str) {}

int Entry::get_index() { return index; }

std::string Entry::get_str() { return str; }

Table::Table(): table(NULL), len(0) {}

Symbol Table::add_string(std::string str) {
    for (List<Entry>* l = table; l; l = l->get_tail()) {
        if (l->get_head()->get_str() == str) {
            return l->get_head();
        }
    }

    Symbol symbol = new Entry(len++, str);
    table = new List<Entry>(symbol, table);
    return symbol;
}

List<Entry>* Table::get_table() {
    return table;
}

int Table::get_len() {
    return len;
}

/*----------------------------------------------.
|   Section 4 : Symbol definitions of list.h    |
`----------------------------------------------*/

template <class T>
int list_len(List<T>* list) {
    if (list == NULL) {
        return 0;
    } else {
        return 1 + list_len(list->get_tail());
    }
}

// Elements of first come at the head end of the list.
template <class T>
List<T>* list_append(List<T>* first, List<T>* second) {
    if (first == NULL) {
        return second;
    } else {
        return new List<T>(first->get_head(), list_append(first->get_tail(), second));
    }
}