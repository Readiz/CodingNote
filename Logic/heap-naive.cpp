// Min Heap
constexpr int MAX = 200010;

int data[MAX];
int sz = 0;

void insert(int val) {
    data[++sz] = val;
    // Heapify Up
    for(register int i = sz; i > 1; i >>= 1) {
        int p = i >> 1;
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
    for(register int i = 1; ;) {
        int l = i << 1;
        int r = l | 1;

        if (l > sz) break;
        if (l == sz) {
            if (data[l] < data[i]) {
                data[i] ^= data[l] ^= data[i] ^= data[l];
                i = l;
                continue;
            }
        }
        if (data[l] < data[i] || data[r] < data[i]) {
            if (data[l] < data[r]) {
                data[i] ^= data[l] ^= data[i] ^= data[l];
                i = l;
            } else {
                data[i] ^= data[r] ^= data[i] ^= data[r];
                i = r;
            }
            continue;
        }
        break;
    }

    return rval;
}