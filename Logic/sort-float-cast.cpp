constexpr int MAX = 1000010;
long long ref[MAX];
float* mdata;

void qSort(int s, int e) {
    if (s >= e) return;
    register int l = s;
    register int r = e;
    register long long pivot = ref[(s+e)>>1]; // must be copied.
    register float tmp;
    register long long ltmp;

    while (l < r) {
        while(ref[l] < pivot) ++l;
        while(pivot < ref[r]) --r;
        if (l > r) break;

        ltmp = ref[l];
        ref[l] = ref[r];
        ref[r] = ltmp;

        tmp = mdata[l];
        mdata[l] = mdata[r];
        mdata[r] = tmp;

        ++l; --r;
    }
    
    qSort(s, r);
    qSort(l, e);
}

void sort(float data[], int size) {
    mdata = data;
    for(register int i = 0; i < size; ++i) ref[i] = (double)data[i] * 100000;
    qSort(0, size - 1);
}