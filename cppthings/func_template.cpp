//
// Created by zhang on 2021/6/19.
//

#include <cstring>
#include <iostream>
#include "vector"
#include "cstdlib"
#include "string"
#include "stdexcept"
using namespace std;


template<typename T>
inline T const& mymax(T const &a, T const & b)
{
    return a < b ? b : a;
}

template <class T>
class Stack {
private:
    vector<T> elems;

public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const{
        return elems.empty();
    };

};

template<class T>
void Stack<T>::push(const T &elem) {
    elems.push_back(elem);
}

template<class T>
void Stack<T> ::pop() {
    if (elems.empty())
        throw out_of_range("stack pop: empty stack");

    elems.pop_back();
}

template<class T>
T Stack<T>::top() const {
    if (elems.empty())
        throw out_of_range("stack pop: empty stack");

    return elems.back();
}

void test()
{
    try {
        Stack<int> intstack;
        Stack<string> strstack;

        intstack.push(7);
        cout << intstack.top() << endl;

        strstack.push("helloworld");
        cout << strstack.top() << endl;
    }
    catch (exception const & e) {
        cerr << "exception: " << e.what() << endl;
        return;
    }
}

void dyn_arr()
{
    char *s;
    const char *consts;
    s = new char[strlen(consts) + 1];
}


int main()
{
    int j = 32;
    int i = 33;

    cout << "max(j, i) = " << mymax(j, i) << endl;

    double f1 = 11.1;
    double f2 = 12.1;

    cout << "max(f1, f2) = " << mymax(f1, f2) << endl;

    test();

    return 0;
}