#ifndef INCLUDED_ALL
    #define INCLUDED_ALL
    #include <bits/stdc++.h>
    #include "../Util/rand.cpp"
#endif

namespace bubble {
    #include "../sort-bubble.cpp"
}
namespace insertion {
    #include "../sort-insertion.cpp"
}
namespace insertion2 {
    #include "../sort-insertion2.cpp"
}
namespace quick {
    #include "../sort-quick.cpp"
}
namespace merge {
    #include "../sort-merge.cpp"
}
namespace bucket {
    #include "../sort-bucket.cpp"
}

constexpr int size = 50000;
int originalData[size];
int ans[size];
int mData[size];

// 테스트의 시작
void sort_test() {
    clock_t s, e;
    bool testValidationResult;

    printf("TEST SIZE: %d\n", size);
    printf("\n", size);

    for(register int i = 0; i < size; ++i) {
        ans[i] = originalData[i] = rand_int_30bit();
    }

    s = clock();
    std::sort(ans, ans + size);
    e = clock();
    printf("STD::SORT - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // BUBBLE SORT TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    bubble::sort(mData, size);
    e = clock();
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (ans[i] != mData[i]) {
            testValidationResult = false;
            printf("%d - ANS: %d vs RET: %d\n", i, ans[i], mData[i]);
            break;
        }
    }
    if (testValidationResult) printf("BUBBLE SORT VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // INSERTION SORT TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    insertion::sort(mData, size);
    e = clock();
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (ans[i] != mData[i]) {
            testValidationResult = false;
            printf("%d - ANS: %d vs RET: %d\n", i, ans[i], mData[i]);
            break;
        }
    }
    if (testValidationResult) printf("INSERTION SORT VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // INSERTION2 SORT TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    insertion2::sort(mData, size);
    e = clock();
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (ans[i] != mData[i]) {
            testValidationResult = false;
            printf("%d - ANS: %d vs RET: %d\n", i, ans[i], mData[i]);
            break;
        }
    }
    if (testValidationResult) printf("INSERTION2 SORT VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // QUICK SORT TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    quick::sort(mData, size);
    e = clock();
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (ans[i] != mData[i]) {
            testValidationResult = false;
            printf("%d - ANS: %d vs RET: %d\n", i, ans[i], mData[i]);
            break;
        }
    }
    if (testValidationResult) printf("QUICK SORT VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // MERGE SORT TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    merge::sort(mData, size);
    e = clock();
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (ans[i] != mData[i]) {
            testValidationResult = false;
            printf("%d - ANS: %d vs RET: %d\n", i, ans[i], mData[i]);
            break;
        }
    }
    if (testValidationResult) printf("MERGE SORT VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // BUCKET SORT TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    bucket::sort(mData, size);
    e = clock();
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (ans[i] != mData[i]) {
            testValidationResult = false;
            printf("%d - ANS: %d vs RET: %d\n", i, ans[i], mData[i]);
            break;
        }
    }
    if (testValidationResult) printf("BUCKET SORT VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);
}
