#ifndef INCLUDED_ALL
    #define INCLUDED_ALL
    #include <bits/stdc++.h>
#endif

std::vector<int> v;
void insert(int val) {
    v.push_back(val);
}

int get(int pos) {
    return v[pos];
}