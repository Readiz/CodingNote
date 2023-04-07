#include "../Util/rheader.cpp"

float getRndFloat() {
    return (float)((rand() % 20000) - 10000 + (rand() % 10000) / 10000.0);
}

#define FSZ 50000

float arr[FSZ];
float arr2[FSZ];
float _arr[FSZ];


void naiveFloatSort(float arr[], int sz) {
    register int i;
    register int j;

    for(i = 0; i < sz; ++i) {
        for(j = i + 1; j < sz; ++j) {
            if (arr[i] > arr[j]) {
                float tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void myFloatSort(float arr[], int sz) {
    unsigned int* marr = (unsigned int*) arr;
    register int i;
    register int j;
    constexpr unsigned int MSB = 1U << 31;
    for(i = 0; i < sz; ++i) {
        for(j = i + 1; j < sz; ++j) {
            unsigned int fhexi = marr[i];
            unsigned int fhexj = marr[j];
            unsigned int iMSB = fhexi & MSB;
            unsigned int jMSB = fhexj & MSB;

            if (iMSB < jMSB) { // 양수 -> 음수
                marr[i] ^= marr[j] ^= marr[i] ^= marr[j];
                continue;
            } else if (iMSB < jMSB) continue;

            // 부호 같은 case
            if (iMSB > 0) {
                // 둘다 음수
                if (fhexi < fhexj) {
                    marr[i] ^= marr[j] ^= marr[i] ^= marr[j];
                }
            } else {
                // 둘다 양수
                if (fhexi > fhexj) {
                    marr[i] ^= marr[j] ^= marr[i] ^= marr[j];
                }
            }
        }
    }
}

void myFloatSort2(float arr[], int sz) {
    unsigned int* marr = (unsigned int*) arr;
    register int i;
    register int j;
    constexpr unsigned int MSB = 1U << 31;
    register int cntNeg = 0;
    for(i = 0; i < sz; ++i) {
        if (arr[i] < 0) cntNeg++;
    }

    register int p1 = 0;
    register int p2 = cntNeg;
    for(i = 0; i < sz; ++i) {
        if (arr[i] > 0) {

        }
    }

    // 음수 range | 양수 range
    // 음수 range sort 후 양수 range sort
    // 음수 range는 작아지는 방향
    // 양수 range는 커지는 방향
    // 으로 sort 하면 됨.

    for(i = 0; i < sz; ++i) {
        for(j = i + 1; j < sz; ++j) {
            unsigned int fhexi = marr[i];
            unsigned int fhexj = marr[j];
            unsigned int iMSB = fhexi & MSB;
            unsigned int jMSB = fhexj & MSB;

            if (iMSB < jMSB) { // 양수 -> 음수
                marr[i] ^= marr[j] ^= marr[i] ^= marr[j];
                continue;
            } else if (iMSB < jMSB) continue;

            // 부호 같은 case
            if (iMSB > 0) {
                // 둘다 음수
                if (fhexi < fhexj) {
                    marr[i] ^= marr[j] ^= marr[i] ^= marr[j];
                }
            } else {
                // 둘다 양수
                if (fhexi > fhexj) {
                    marr[i] ^= marr[j] ^= marr[i] ^= marr[j];
                }
            }
        }
    }
}

int main() {
    register int i;
    clock_t s, e;

    for(i = 0; i < FSZ; ++i) {
        arr2[i] = arr[i] = _arr[i] = getRndFloat();
    }

    s = clock();
    naiveFloatSort(arr, FSZ);
    e = clock();
    printf("Naive Sort: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // for(i = 0; i < FSZ; ++i) {
    //     printf("%f ", arr[i]);
    // }
    // printf("\n");


    s = clock();
    myFloatSort2(arr2, FSZ);
    e = clock();
    printf("Float Sort: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    for(i = 0; i < FSZ; ++i) {
        if (arr[i] != arr[i]) {
            printf("SORT FAIL!\n");
            break;
        }
    }
    printf("SORT & VALIDATION END\n");

    return 0;
}
