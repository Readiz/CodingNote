// Min Heap
constexpr int MAX = 1000010;

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
    register int val = data[sz];
    register int r = data[1];
    data[sz--] = data[1];

    // Heapify Down
    // 적어도 왼쪽 자식을 포함하고 &&
    // 오른쪽 자식도 포함하면서 && 오른쪽이 더 조건에 부합하면 c | 1을 사용한다.
    // 그리고 자식이 최종적으로 부모보다 작으면, swap
    for(; c <= sz && data[c |= (c < sz && data[c | 1] < data[c])] < val; c <<= 1) {
        data[c >> 1] = data[c];
    }
    data[c >> 1] = val;

    return r;
}