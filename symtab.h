#ifndef SYMTAB_H
#define SYMTAB_H

#include "strtab.h"

template <class SYM, class DAT>
class SymTable {
    typedef std::map<SYM, DAT> Scope;
    typedef typename Scope::iterator MapI;
    typedef std::list<Scope*> ScopeList;
    typedef typename ScopeList::iterator ListI;
private:
    ScopeList tbl;
public:
    void enter_scope() {
        tbl.push_back(new Scope());
    }

    void exit_scope() {
        assert(tbl.size());
        tbl.pop_back();
    }

    void insert(SYM sym, DAT* dat) {
        assert(tbl.size());
        Scope* scope = tbl.back();
        assert(scope->find(sym) == scope->end());
        scope->insert(std::make_pair(sym, dat));
    }
    
    DAT* lookup(SYM sym) {
        for (ListI lit = tbl.rbegin(); lit != tbl.rend(); lit++) {
            Scope* scope = *lit;
            MapI sit = scope->find(sym);

            if (sit != scope->end()) {
                return sit->second;
            }
        }

        return NULL;
    }

    DAT* probe(SYM sym) {
        assert(tbl.size());
        Scope* scope = tbl.back();
        MapI sit = scope->find(sym);

        if (sit != scope->end()) {
            return sit->second;
        }

        return NULL;
    }
};

#endif