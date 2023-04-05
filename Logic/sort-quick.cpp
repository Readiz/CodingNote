int *mdata;

void qSort(int s, int e) {
    if (s >= e) return;
    register int l = s;
    register int r = e;
    int pivot = mdata[(s+e)>>1]; // must be copied.

    while (l < r) {
        while(mdata[l] < pivot) ++l;
        while(pivot < mdata[r]) --r;
        if (l > r) break;
        if (mdata[l] != mdata[r])
            mdata[l] ^= mdata[r] ^= mdata[l] ^= mdata[r];
        ++l; --r;
    }
    
    qSort(s, r);
    qSort(l, e);
}

void sort(int data[], int size) {
    mdata = data;
    qSort(0, size - 1);
}