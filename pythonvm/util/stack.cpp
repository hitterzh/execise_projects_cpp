//
// Created by zhang on 2021/6/22.
//
#include "stack.h"

template<>
void Stack<HiObject *>::oops_do(const OopClosure *f) {
    for (int i = 0; i < _len; I++) {
        f->do_oop(&vector[i]);
    }
}

template<typename T>
void Stack<T>::copy(const Stack<T> *stack) {
    _size = stack -> size();
    _len = stack -> len();

    for (int i = 0; i < _size; ++i) {
        vector[i] = stack -> vector[i];
        
    }
}

template class Stack<Block>;


