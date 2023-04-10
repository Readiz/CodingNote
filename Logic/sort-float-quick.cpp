float *mdata;

void qSort(int s, int e) {
    if (s >= e) return;
    register int l = s;
    register int r = e;
    register float pivot = mdata[(s+e)>>1]; // must be copied.
    register float tmp;

    while (l < r) {
        while(mdata[l] < pivot) ++l;
        while(pivot < mdata[r]) --r;
        if (l > r) break;
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
    qSort(0, size - 1);
}