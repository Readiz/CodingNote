void sort(int data[], int size) {
    register int i;
    register int j;
    register int k;
    // a b c d e f k
    // a ~ f는 정렬된 상태, k를 어디에 삽입할지 본다.
    for(i = 1; i < size; ++i) {
        k = data[i];
        // d[j-1] < d[j] 여야하는데 뒤집혀있으면 swap
        for(j = i - 1; j >= 0 && data[j] > k; --j) {
            data[j+1] = data[j];
        }
        data[j+1] = k;
    }
}
