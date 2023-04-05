constexpr int MAX = 1000000;
// 21억
// 2100000000
int cnt1[100001];
int acc[100001];
int cnt2[100001];
int tmp[MAX];
void sort(int data[], int size) {
    register int i;
    register int j;
    for(i = 0; i < 100000; ++i) {
        cnt1[i] = cnt2[i] = 0;
    }

    // 하위 부터 bucket
    for(i = 0; i < size; ++i) {
        cnt1[data[i] % 100000]++;
    }
    acc[0] = 0;
    for(i = 0; i < 100000; ++i) {
        acc[i+1] = acc[i] + cnt1[i];
    }
    for(i = 0; i < size; ++i) {
        tmp[acc[data[i] % 100000]++] = data[i];
    }

    // 상위 bucket
    for(i = 0; i < size; ++i) {
        cnt2[tmp[i] / 100000]++;
    }
    acc[0] = 0;
    for(i = 0; i < 100000; ++i) {
        acc[i+1] = acc[i] + cnt2[i];
    }
    for(i = 0; i < size; ++i) {
        data[acc[tmp[i] / 100000]++] = tmp[i];
    }
}