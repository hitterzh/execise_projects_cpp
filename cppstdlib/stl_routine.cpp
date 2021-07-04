//
// Created by zhang on 2021/6/30.
//
#include <iostream>
#include <vector>

using namespace std;

int vector_example()
{
    vector<int> col;

    for (int i = 0; i <= 6; i++)
    {
        col.push_back(i);
    }

    for (int i = 0; i < col.size(); i++)
    {
        cout << col[i] << ' ';
    }

    cout << endl;

    return 0;
}

#include "deque"

void dq_example()
{
    deque<float> col;

    for (int i = 0; i <= 6; i++)
    {
        col.push_back(i);
        col.push_front(i);
    }

    for (int i = 0; i < col.size(); i++)
    {
        cout << col[i] << ' ';
    }

    cout << endl;
}

#include "list"
void list_example()
{
    list<char> col;

    for (char val = 'a'; val < 'z'; val++)
    {
        col.push_front(val);
        col.push_back(val);
    }

    while (! col.empty())
    {
        cout << col.front() << ' ';
        col.pop_front();
    }

    list<char>::const_iterator pos;
    for (pos = col.begin(); pos != col.end(); pos++)
    {
        cout<<*pos<<" ";
    }
    cout << endl;
}

#include "set"

void set_example()
{
    typedef std::set<int> Intset;
    Intset col;

    col.insert(5);
    col.insert(1);
    col.insert(4);
    col.insert(5);
    col.insert('d');
    col.insert(1);

    Intset::iterator pos;
    for (pos = col.begin(); pos != col.end(); pos++)
    {
        cout << * pos << "<str_space>";
    }

    cout << endl;

}

#include "map"
void multimap_example()
{
    //typedef multimap<int, string> intstrmap;
    typedef map<int, string> intstrmap;

    intstrmap col;
    col.insert(make_pair(5, "eric"));
    col.insert(make_pair(1, "leng"));
    col.insert(make_pair(3, "eric"));

    col.insert(make_pair(5, "what"));

    intstrmap::iterator pos;
    for (pos = col.begin(); pos != col.end(); pos++)
    {
        cout << pos->second << " ";
    }

    //col["eric"] = "dsaf";
    col[12] = "aa";
}

#include "algorithm"

void algo_test()
{
    vector<int> col;
    vector<int>::iterator pos;

    col.push_back(2);
    col.push_back(3);
    col.push_back(8);
    col.push_back(6);
    col.push_back(1);
    col.push_back(2);
    col.push_back(2);

    pos = min_element(col.begin(), col.end());
    cout << *pos << "<str_space>";

    pos = max_element(col.begin(), col.end());
    cout << *pos << "<str_space>";


    sort(col.begin(), col.end());
    cout << *pos << "<str_space>";

    pos = find(col.begin(), col.end(), 3);

    reverse(pos, col.end());

    for (pos = col.begin(); pos != col.end(); ++pos)
    {
        cout << * pos << "<str_space>";
    }

}

void sizetest()
{
    vector<int> col2;
    list<int> col1;

    col1.resize(13);

    for (int i = 0; i < 9; i++)
    {
        col1.push_back(i);
    }

    col2.resize(col1.size());

    copy(col1.begin(), col1.end(), col2.begin());
    cout << col1.size();
    cout << col2.size();
    cout << endl;
    cout << col2.capacity();
    deque<int> col3(col1.size());
    copy(col1.begin(), col1.end(), col3.begin());
    cout << col3.size();

}

void itertest()
{
    list<int> col;

    for (int i = 0; i < 9; ++i)
    {
        col.push_back(i);
    }

    vector<int> col1;

    copy(col.begin(), col.end(), back_inserter(col1));
    //copy(col.begin(), col.end(), front_inserter(col1));

    deque<int> col2;
    copy(col.begin(), col.end(), front_inserter(col2));

    set<int> col3;
    copy(col.begin(), col.end(), inserter(col3, col3.begin()));
}

#include "iostream"
#include "iterator"
void removetest()
{
    list<int> col;

    for (int i = 0; i < 6; i++)
    {
        col.push_back(i);
        col.push_front(i);
    }

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    list<int>::iterator end = remove(col.begin(), col.end(), 3);

    cout << "number of removed elements:" << distance(end, col.end()) << endl;

    col.erase(end, col.end());

    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void memberremove()
{
    list<int> col;

    for (int i = 0; i < 6; i++)
    {
        col.push_back(i);
        col.push_front(i);
    }

    col.erase(remove(col.begin(), col.end(), 3));
    col.remove(4);
    copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

//self def generic func
template<typename T>
inline void printelements(const T &col, const char *optstr="")
{
    typename T::const_iterator pos;

    cout << optstr;
    for (pos = col.begin(); pos != col.end(); ++pos)
    {
        cout << *pos << " ";

    }
    cout << endl;
}

void vectortest()
{
    vector<int> c;
    c.capacity();
    c.reserve(10);
    c.front() = 100;


    vector<int> col;
    col.push_back(1);
    col.push_back(3);
    col.push_back(2);
    col.push_back(6);
    col.push_back(1);
    col.push_back(3);
    col.push_back(2);

    col.erase(remove(col.begin(), col.end(), 2), col.end());

}

void vecttest()
{
    vector<string> sent;
    //sent.reserve(5);
    cout << sent.capacity() << " ";

    sent.push_back("eric");
    cout << sent.capacity() << " ";
    sent.push_back("is");
    cout << sent.capacity() << " ";
    sent.push_back("lenged");
    cout << sent.capacity() << " ";
    sent.push_back("dary");
    cout << sent.capacity() << " ";
    sent.push_back("11");

    cout << sent.size() << " ";
    cout << sent.capacity() << " ";
    cout << sent.max_size() << " ";

    copy(sent.begin(), sent.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    swap(sent[1], sent[3]);
    sent.insert(find(sent.begin(), sent.end(), "dary"), "beforedary ");
    sent.back()="2222";

    copy(sent.begin(), sent.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    sort(sent.begin(), sent.end());

    copy(sent.begin(), sent.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cout << sent.size() << " ";
    cout << sent.capacity() << " ";
    cout << sent.max_size() << " ";


}

void listtest()
{
    list<int> col;
    list<int> col2;

    for (int i = 0; i < 6; i++) {
        col.push_back(i);
        col2.push_front(i);
    }

    col2.splice(find(col2.begin(), col2.end(), 3), col);


}

void settest() {
    set<int> c;
    c.insert(1);
    c.insert(1);
    c.insert(1);
    c.insert(2);
    c.insert(4);
    c.insert(5);
    c.insert(6);

    cout << "lowbound3 " << *c.lower_bound(3) << endl;
    cout << "upperbound3 " << *c.upper_bound(3) << endl;
    cout << "equalrange3 " << *c.equal_range(3).first << " " <<
         *c.equal_range(3).second << endl;


    typedef set<int, greater<int> > intset;

    intset col1;

    col1.insert(4);
    col1.insert(3);
    col1.insert(5);
    col1.insert(1);
    col1.insert(6);
    col1.insert(4);
    col1.insert(2);
    col1.insert(5);
    col1.insert(4);

    intset::iterator pos;
    for (pos = col1.begin(); pos != col1.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;

    pair<intset::iterator, bool> status = col1.insert(4);

    if (status.second) {
        cout << "4 inserted as element " << distance(col1.begin(), status.first) + 1
             << endl;
    } else {
        cout << "4 already exists" << endl;
    }


    pair<intset::iterator, bool> st = col1.insert(9);

    if (st.second) {
        cout << "9 inserted as element " << distance(col1.begin(), st.first) + 1
             << endl;
    } else {
        cout << "9 already exists" << endl;
    }

    intset col2(col1.begin(), col1.end());

    copy(col2.begin(), col2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    col2.erase(col2.begin(), col2.find(3));

    int num;
    num = col2.erase(5);
    cout << num << " elements removed" << endl;
}

void maptest()
{
    typedef map<string, float> strfloat;

    strfloat stocks;

    stocks["basf"] = 1.23;
    stocks["apple"] = 2.23;
    stocks["micro"] = 6.23;
    stocks["gg"] = 2.23;
    stocks["fb"] = 9.23;

    strfloat::iterator pos;
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock:" << pos->first << endl;
        cout << "price:" << pos -> second << endl;
    }

    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        pos -> second *= 2;
    }

    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock:" << pos->first << endl;
        cout << "price:" << pos->second << endl;
    }

    stocks["vo"] = stocks["fb"];

    stocks.erase("fb");
    stocks.erase("afadsfa");
    stocks["vo"] = stocks["eric"];

    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock:" << pos->first << endl;
        cout << "price:" << pos->second << endl;
    }

}

int main()
{
    //vector_example();
    //dq_example();
    //list_example();
    //set_example();
    //multimap_example();
    //algo_test();
    //sizetest();
    //itertest();
    //removetest();
    //memberremove();
    //vecttest();
    //settest();
    maptest();
}

