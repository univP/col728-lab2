#ifndef SYMTAB_H
#define SYMTAB_H

#include "table.h"

template <class SYM, class DAT>
class SymtabEntry {
private:
    SYM id;
    DAT *info;
public:
    SymtabEntry(SYM x, DAT *y) : id(x), info(y) {}
    SYM get_id() const    { return id; }
    DAT *get_info() const { return info; }
};

template <class SYM, class DAT>
class SymbolTable {
    typedef SymtabEntry<SYM,DAT> ScopeEntry;
    typedef List<ScopeEntry> Scope;
    typedef List<Scope> ScopeList;
private:
    ScopeList  *tbl;
public:
    SymbolTable(): tbl(NULL) {}

    void enterscope() {
        tbl = new ScopeList((Scope *) NULL, tbl);
    }

    void exitscope() {
        assert(tbl != NULL);
        tbl = tbl->get_tail();
    }

    ScopeEntry *addid(SYM s, DAT *i) {
        assert(tbl != NULL);
        ScopeEntry * se = new ScopeEntry(s,i);
        tbl = new ScopeList(new Scope(se, tbl->get_head()), tbl->get_tail());
        return(se);
    }
    
    DAT * lookup(SYM s) {
        for(ScopeList* i = tbl; i; i = i->get_tail()) {
            for(Scope* j = i->get_head(); j; j = j->get_tail()) {
                if (s == j->get_head()->get_id()) {
                    return j->get_head()->get_info();
                }
            }
        }

        return NULL;
    }

    DAT *probe(SYM s) {
        assert(tbl != NULL);

        for(Scope* i = tbl->get_head(); i; i = i->get_tail()) {
            if (s == i->get_head()->get_id()) {
                return(i->get_head()->get_info());
            }
        }

        return NULL;
    }

    void print_tbl(std::ostream& s) {
        for(ScopeList* i = tbl; i; i = i->get_tail()) {
            s << "\nScope: " << std::endl;

            for(Scope* j = i->get_head(); j; j = j->get_tail()) {
                s << "  " << j->get_head()->get_id() << std::endl;
            }
        }
    }
 
};

#endif