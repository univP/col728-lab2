#ifndef LIST_H
#define LIST_H

#include "string.h"

// Simple definition of a list.
template <class T>
class List {
private:
    T* head;
    List<T>* tail;
public:
    List(T* head, List<T>* tail) : head(head), tail(tail) {}
    T* get_head() { return head; }
    List<T>* get_tail() { return tail; }
};

// List methods.
template <class T>
int list_len(List<T>* list);

template <class T>
List<T>* list_append(List<T>* first, List<T>* second);

#endif