#include "../Util/rheader.cpp"

namespace mvector {
    #include "../Logic/darray-vector.cpp"
}
namespace custom {
    #include "../Logic/darray-custom.cpp"
}

constexpr int size = 1000000;
int originalData[size];
int ans[size];
int mData[size];

// 테스트의 시작
void darray_test() {
    clock_t s, e;
    bool testValidationResult;

    printf("TEST SIZE: %d\n", size);
    printf("\n", size);

    for(register int i = 0; i < size; ++i) {
        ans[i] = originalData[i] = rand_int_30bit();
    }

    // VECTOR TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    for(register int i = 0; i < size; ++i) {
        mvector::insert(mData[i]);
    }
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (ans[i] != mvector::get(i)) {
            testValidationResult = false;
            printf("%d - ANS: %d vs RET: %d\n", i, ans[i], mvector::get(i));
            break;
        }
    }
    e = clock();
    if (testValidationResult) printf("VECTOR VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // CUSTOM VECTOR TEST
    for(register int i = 0; i < size; ++i) {
        mData[i] = originalData[i];
    }
    s = clock();
    for(register int i = 0; i < size; ++i) {
        custom::insert(mData[i]);
    }
    // Validation
    testValidationResult = true;
    for(register int i = 0; i < size; ++i) {
        if (ans[i] != custom::get(i)) {
            testValidationResult = false;
            printf("%d - ANS: %d vs RET: %d\n", i, ans[i], custom::get(i));
            break;
        }
    }
    e = clock();
    if (testValidationResult) printf("CUSTOM VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);
}
