constexpr int MAX = 1000010;
unsigned int ref[MAX];
unsigned int* mdata;
void qSort(int s, int e) {
    if (s >= e) return;
    register int l = s;
    register int r = e;
    register unsigned int pivot = ref[(s+e)>>1]; // must be copied.

    while (l < r) {
        while(ref[l] < pivot) ++l;
        while(pivot < ref[r]) --r;
        if (l > r) break;
        if (ref[l] != ref[r]) {
            mdata[l] ^= mdata[r] ^= mdata[l] ^= mdata[r];
            ref[l] ^= ref[r] ^= ref[l] ^= ref[r];
        }
        ++l; --r;
    }
    
    qSort(s, r);
    qSort(l, e);
}

void sort(float data[], int size) {
    mdata = (unsigned int*) data;
    register int i;
    register unsigned int mask;

    // 값 변경: 양수 -> 0x80000000 을 붙임 = 더 크게
    //          음수 -> 양수로 변경
    for(i = 0; i < size; ++i) {
        mask = (int)mdata[i] >> 31;
        // 음수 | 양수
        ref[i] = (mask & -(int)mdata[i]) | (~mask & (mdata[i] | 0x80000000));
    }

    qSort(0, size - 1);
}
