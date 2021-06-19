//
// Created by zhang on 2021/6/19.
//
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Person
{
    double salary;
    char *name;
};

class SalaryManage
{
    Person *emploee;
    int max;
    int n;

public:
    SalaryManage(int m = 0)
    {
       max = m;
       n = 0;
       emploee = new Person[max];
    }

    double &operator [] (char *name)
    {
        Person *p;
        for (p = emploee; p < emploee + n; p++)
            if (strcmp(p->name, name) == 0)
                return p ->salary;
        p = emploee + n++;
        p->name = new char[strlen(name) + 1];
        p->salary = 0;
        return p->salary;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
            cout << emploee[i].name << "  " << emploee[i].salary << endl;

    }

    ~SalaryManage()
    {
        // mem leak
        delete emploee;
    }
};

int main()
{
    SalaryManage s(3);
    s["davaid"] = 2111.1;
    s["eric"] = 232.3;

    s.display();
}