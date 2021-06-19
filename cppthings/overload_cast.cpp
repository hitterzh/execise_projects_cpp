//
// Created by zhang on 2021/6/19.
//

#include <iostream>
using namespace std;

class Circle {
private:
    double x, y, z;
public:
    Circle(double xx, double yy, double zz)
    {
        x = xx;
        y = yy;
        z = zz;
    }
    operator int() {return int(z);}
    operator double() {
        return z;
    }
    operator float() { return (float) z;}
    void operator ()(int a, int b, int c) {x = a; y = b; z = c;}
};

int main()
{
    Circle c(1, 2, 3);

    int r = c;
    double rr = c;
    float rrr = c;
    c(2, 3, 4);

    return 0;
}