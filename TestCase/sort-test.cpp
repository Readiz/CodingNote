#include "../Util/rheader.cpp"

namespace bubble {
    #include "../Logic/sort-bubble.cpp"
}
namespace insertion {
    #include "../Logic/sort-insertion.cpp"
}
namespace insertion2 {
    #include "../Logic/sort-insertion2.cpp"
}
namespace quick {
    #include "../Logic/sort-quick.cpp"
}
namespace merge {
    #include "../Logic/sort-merge.cpp"
}
namespace merge2 {
    #include "../Logic/sort-merge2.cpp"
}
namespace bucket {
    #include "../Logic/sort-bucket.cpp"
}
namespace float_quick {
    #include "../Logic/sort-float-quick.cpp"
}
namespace float_cast {
    #include "../Logic/sort-float-cast.cpp"
}

constexpr int sizemax = 1000000;
int originalData[sizemax];
int ans[sizemax];
int mData[sizemax];
float fOriginalData[sizemax];
float fdata[sizemax];
float fans[sizemax];

// 테스트의 시작
void sort_test() {
    clock_t s, e;
    bool testValidationResult;

    int size = 10000;
    printf("N^2 logic TEST SIZE: %d\n", size);
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
    if (testValidationResult) printf("INSERTION SORT 2 VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);




    size = 1000000;
    printf("\n-\n");
    printf("ADVANCED TEST SIZE: %d\n", size);
    printf("\n");

    for(register int i = 0; i < size; ++i) {
        ans[i] = originalData[i] = rand_int_30bit();
    }

    s = clock();
    std::sort(ans, ans + size);
    e = clock();
    printf("STD::SORT - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

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

    // MERGE SORT 2 TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    merge2::sort(mData, size);
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
    if (testValidationResult) printf("MERGE SORT 2 VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

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



    size = 1000000;
    printf("\n-\n");
    printf("FLOAT TEST SIZE: %d\n", size);
    printf("\n");

    for(register int i = 0; i < size; ++i) {
        fans[i] = fOriginalData[i] = rand_float();
    }

    std::sort(fans, fans + size);

    // STD SORT TEST
    for(register int i = 0; i < size; ++i) {
        fdata[i] = fOriginalData[i];
    }
    s = clock();
    float_quick::sort(fdata, size);
    e = clock();
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (fans[i] != fdata[i]) {
            testValidationResult = false;
            printf("%d - ANS: %f vs RET: %f\n", i, fans[i], fdata[i]);
            break;
        }
    }
    if (testValidationResult) printf("STD SORT VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // BIT SORT TEST
    for(register int i = 0; i < size; ++i) {
        fdata[i] = fOriginalData[i];
    }
    s = clock();
    float_cast::sort(fdata, size);
    e = clock();
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (fans[i] != fdata[i]) {
            testValidationResult = false;
            printf("%d - ANS: %f vs RET: %f\n", i, fans[i], fdata[i]);
            break;
        }
    }
    if (testValidationResult) printf("CAST SORT VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);


}
