int *mdata;

constexpr int MAX = 1000000;
int tmp[MAX];
// [s, e]
void mergeSort(int s, int e) {
    if (s == e) return;

    int mid = (s+e) >> 1;
    mergeSort(s, mid);
    mergeSort(mid + 1, e);

    register int l = s;
    register int r = mid + 1;

    for(register int i = s; i <= e; ++i)
        // mdata[l] <= mdata[r] 에서 등호가 있어야 stable sort 이다.
        tmp[i] = e < r || (l <= mid && mdata[l] <= mdata[r]) ? mdata[l++] : mdata[r++];
    for(register int i = s; i <= e; ++i)
        mdata[i] = tmp[i];
}

void sort(int data[], int size) {
    mdata = data;
    mergeSort(0, size - 1);
}