// Min Heap
constexpr int MAX = 200010;

int data[MAX];
int sz = 0;

void insert(int val) {
    // Heapify Up
    register int i = ++sz;
    register int p;
    for(; i > 1; i >>= 1) {
        p = i >> 1;
        if (val >= data[p]) break;
        data[i] = data[p];
    }
    data[i] = val;
}

int getMin() {
    register int c = 2;
    register int nd = data[sz];
    register int r = data[1];
    data[sz--] = data[1];

    // Heapify Down
    for(; c <= sz && data[c += (c < sz && data[c | 1] < data[c])] < nd; c <<= 1) {
        data[c >> 1] = data[c];
    }
    data[c >> 1] = nd;

    return r;
}