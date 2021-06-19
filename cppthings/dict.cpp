//
// Created by zhang on 2021/6/19.
//
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main(int argc, char const * argv[])
{
    map<const char*, const char*> mp;
    map<const char * , const char*>::iterator iter;
    const char *key[] = {"img", "system", "ip"};
    const char *value[] = {"d:/a.img", "win7", "192.168.1.100"};

    // 1. insert by make_pair
    for (int i = 0; i < sizeof(key); i++)
    {
        mp.insert(make_pair(key[i], value[i]));
    }

    // 2. insert by []
    mp["addr"] = "China";

    // for each
    for (iter = mp.begin(); iter != mp.end(); iter++) {
        cout << "first = " << iter->first << " second = " << iter -> second << endl;
    }

    // lookup
    iter = mp.find("img");
    if (iter != mp.end()) {
        cout << "found " << iter->first << " value = " << iter -> second << endl;
        mp.erase(iter);
    }

    return 0;
}

