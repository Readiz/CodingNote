#include "../Util/rheader.cpp"
// Min Heap
std::priority_queue<int, std::vector<int>, std::greater<>> pq;

void insert(int val) {
    pq.push(val);
}

int getMin() {
    int r = pq.top();
    pq.pop();
    return r;
}