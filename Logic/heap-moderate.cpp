// Min Heap
constexpr int MAX = 1000010;

int data[MAX];
int sz = 0;

void insert(int val) {
    data[++sz] = val;
    // Heapify Up
    register int p;
    for(register int i = sz; i > 1; i >>= 1) {
        p = i >> 1;
        if (data[i] < data[p]) {
            data[i] ^= data[p] ^= data[i] ^= data[p];
            continue;
        }
        break;
    }
}

int getMin() {
    int rval = data[1];
    data[1] = data[sz--];

    // Heapify Down
    register int c;
    for(register int i = 1; ;) {
        c = i << 1; // left child
        if (c > sz) break;
        // 우측 자식이 있고 더 작은 경우
        if (c < sz && data[c | 1] < data[c]) c |= 1;
        if (data[c] < data[i]) {
            data[c] ^= data[i] ^= data[c] ^= data[i];
            i = c;
            continue;
        }
        break;
    }

    return rval;
}