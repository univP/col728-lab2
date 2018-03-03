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


/*----------------------------------------------.
|   Section 3 : Symbol definitions of list.h    |
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