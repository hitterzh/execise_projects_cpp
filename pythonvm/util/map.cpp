//
// Created by zhang on 2021/6/22.
//

#include "map.h"


template <typename K, typename V>
Map<K, V>::Map() {
    _entries = new MapEntry<K, V>[8];
    _length = 8;
    _size = 0;
}

template<typename K, typename V>
MapEntry<K, V>::MapEntry(const MapEntry<K, V> &entry) {
   _k = entry._k;
   _v = entry._v;
}





