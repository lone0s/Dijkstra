//
// Created by jeune on 22/12/2022.
//
#include <iostream>
#include "DataStructures/T_List.h"

int main() {
    T_List<int> list((size_t)4);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.remove(4);
    return 0;
}
