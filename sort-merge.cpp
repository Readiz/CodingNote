int *mdata;

constexpr int MAX = 1000000;
int tmp[MAX];
// [s, e)
void mergeSort(int s, int e) {
    if (e - s < 2) return; // 0개, 1개는 skip

    int mid = (s+e) >> 1;
    mergeSort(s, mid);
    mergeSort(mid, e);

    register int p = s;
    register int q = mid;
    register int k = s;
    for(; p < mid && q < e;++k) {
        if (mdata[p] < mdata[q]) {
            tmp[k] = mdata[p++];
        } else {
            tmp[k] = mdata[q++];
        }
    }
    for(; p < mid; ++p, ++k) {
        tmp[k] = mdata[p];
    }
    for(; q < e; ++q, ++k) {
        tmp[k] = mdata[q];
    }
    for(register int i = s; i < e; ++i) {
        mdata[i] = tmp[i];
    }
}

void sort(int data[], int size) {
    mdata = data;
    mergeSort(0, size);
}