#include "../Util/rheader.cpp"

std::vector<int> getPrimes(int MAX) {
    std::vector<int> primes;
    std::vector<int> isNotPrime(MAX + 1, 0); // memo

    // 1 ~ MAX까지의 소수의 수를 구한다.
    // 결과는 prime 배열에 저장됨

    for(register int i = 2; i <= MAX; ++i) {
        if (isNotPrime[i] == 0) primes.push_back(i);
        for(register int j = 2; j * i <= MAX; ++j) {
            isNotPrime[i * j] = 1;
        }
    }

    return primes;
}