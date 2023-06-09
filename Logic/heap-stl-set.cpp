#include "../Util/rheader.cpp"
// Min Heap
std::multiset<int> pq;

void insert(int val) {
    pq.insert(val);
}

int getMin() {
    auto it = pq.begin();
    int r = *it;
    pq.erase(it);
    return r;
}
