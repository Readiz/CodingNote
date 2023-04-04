#ifndef INCLUDED_ALL
    #define INCLUDED_ALL
    #include <bits/stdc++.h>
#endif

struct DArray {
    int *d;
    int capa;
    int sz;
    DArray() {
        capa = 10;
        sz = 0;
        d = new int[capa];
    }
    void push_back(int v) {
        if (sz < capa) {
            d[sz++] = v;
            return;
        }
        int *cpy;
        register int i;
        capa <<= 1;
        cpy = new int[capa];
        for(i = 0; i < sz; ++i) {
            cpy[i] = d[i];
        }
        delete[] d;
        d = cpy;
        d[sz++] = v;
    }
    int get(int p) {
        return d[p];
    }
};

DArray v;
void insert(int val) {
    v.push_back(val);
}

int get(int pos) {
    return v.get(pos);
}