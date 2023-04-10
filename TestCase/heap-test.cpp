#include "../Util/rheader.cpp"

namespace stl_pq {
    #include "../Logic/heap-stl-pq.cpp"
}
namespace naive {
    #include "../Logic/heap-naive.cpp"
}
namespace fast {
    #include "../Logic/heap-fast.cpp"
}
constexpr int size = 200000;
int originalData[size];
int ans[size];
int mData[size];
int tmp[size];

// 테스트의 시작
void heap_test() {
    clock_t s, e;
    bool testValidationResult;

    printf("TEST SIZE: %d\n", size);
    printf("\n");

    for(register int i = 0; i < size; ++i) {
        originalData[i] = rand_int_30bit();
    }

    // Make answer with STL PQ
    for(register int i = 0; i < size; ++i) {
        stl_pq::insert(originalData[i]);
    }
    for(register int i = 0; i < size; ++i) {
        ans[i] = stl_pq::getMin();
    }

    // STL PQ TEST
    s = clock();
    for(register int i = 0; i < size; ++i) {
        stl_pq::insert(originalData[i]);
    }
    for(register int i = 0; i < size; ++i) {
        mData[i] = stl_pq::getMin();
    }
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
    if (testValidationResult) printf("STL PQ VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // NAIVE PQ TEST
    s = clock();
    for(register int i = 0; i < size; ++i) {
        naive::insert(originalData[i]);
    }
    for(register int i = 0; i < size; ++i) {
        mData[i] = naive::getMin();
    }
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
    if (testValidationResult) printf("NAIVE PQ VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // FAST PQ TEST
    s = clock();
    for(register int i = 0; i < size; ++i) {
        fast::insert(originalData[i]);
    }
    for(register int i = 0; i < size; ++i) {
        mData[i] = fast::getMin();
    }
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
    if (testValidationResult) printf("FAST PQ VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);


}
