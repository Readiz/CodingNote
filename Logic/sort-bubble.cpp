void sort(int data[], int size) {
    register int i;
    register int j;

    for(i = 0; i < size; ++i) {
        for(j = i + 1; j < size; ++j) {
            if (data[i] > data[j])
                data[i] ^= data[j] ^= data[i] ^= data[j];
        }
    }
	
}