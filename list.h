#ifndef LIST_H
#define LIST_H

#include <string>

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

#endif