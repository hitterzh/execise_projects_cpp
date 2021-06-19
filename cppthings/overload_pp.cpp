//
// Created by zhang on 2021/6/19.
//
#include "iostream"

using namespace std;

class Clock
{
private:
    int hour, minute, second;

public:
    Clock(int h = 0, int m = 0, int s = 0);
    void showTime();
    Clock & operator ++();
    Clock operator++(int);
};

Clock::Clock(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void Clock::showTime() {
    cout << hour << ":" << minute << ":" << second << endl;
}

Clock &Clock::operator++() {
    second++;
    if (second >= 60)
    {
        second = second - 60;
        minute ++;
        if (minute >= 60)
        {
            minute -=60;
            hour ++;
            hour = hour%24;
        }
    }

    return *this;
}

Clock Clock::operator++(int) {
    Clock old = *this;
    ++(*this);
    return old;
}

int main()
{
    Clock myclock(23, 59, 59);
    cout << "init time:";
    myclock.showTime();

    cout << "after ++";
    (myclock++).showTime();

    (++myclock).showTime();

    return 0;
    return 0;
}