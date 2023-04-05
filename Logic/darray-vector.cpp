#include "../Util/rheader.cpp"

std::vector<int> v;
void insert(int val) {
    v.push_back(val);
}

int get(int pos) {
    return v[pos];
}