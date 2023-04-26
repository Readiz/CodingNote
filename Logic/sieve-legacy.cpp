#include "../Util/rheader.cpp"

std::vector<int> getPrimes(int MAX) {
    std::vector<int> primes;
    std::vector<int> isNotPrime(MAX + 1, 0); // memo

    // 1 ~ MAX까지의 소수의 수를 구한다.
    // 결과는 prime 배열에 저장됨

    for(register int i = 2; i * i <= MAX; ++i) {
        if (isNotPrime[i] == 0) {
            for(register int j = i * i; j <= MAX; j += i) {
                isNotPrime[j] = 1;
            }
        }
    }

    for(register int i = 2; i <= MAX; ++i) {
        if (isNotPrime[i] == 0) {
            primes.push_back(i);
        }
    }

    return primes;
}