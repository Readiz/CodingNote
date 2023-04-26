#include "../Util/rheader.cpp"
#include "../Util/rmath.cpp"

namespace linear {
    #include "../Logic/sieve-linear.cpp"
}
namespace legacy {
    #include "../Logic/sieve-legacy.cpp"
}

constexpr int size = 5000000;

// 테스트의 시작
void sieve_test() {
    clock_t s, e;
    int vp;
    bool testValidationResult;

    printf("TEST SIZE: %d\n", size);
    printf("\n");


    // legacy sieve test
    s = clock();
    std::vector<int> legacy_res;
    legacy_res = legacy::getPrimes(size);
    e = clock();
    // Validation
    vp = 0;
    testValidationResult = true;
    for(register int i = 2; i <= size; ++i) {
        if (isPrime(i)) {
            if (legacy_res[vp++] != i) {
                testValidationResult = false;
                printf("%d - ANS: %d vs RET: %d\n", i, i, legacy_res[vp - 1]);
                break;
            }
        }
    }
    if (vp != legacy_res.size()) testValidationResult = false;
    if (testValidationResult) printf("LEGACY SIEVE VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);

    // linear sieve test
    s = clock();
    std::vector<int> linear_res;
    linear_res = linear::getPrimes(size);
    e = clock();
    // Validation
    vp = 0;
    testValidationResult = true;
    for(register int i = 2; i <= size; ++i) {
        if (isPrime(i)) {
            if (linear_res[vp++] != i) {
                testValidationResult = false;
                printf("%d - ANS: %d vs RET: %d\n", i, i, linear_res[vp - 1]);
                break;
            }
        }
    }
    if (vp != linear_res.size()) testValidationResult = false;
    if (testValidationResult) printf("LINEAR SIEVE VALIDATION RESULT - PASS! - Time: %d ms\n", (e - s) * 1000 / CLOCKS_PER_SEC);
}
