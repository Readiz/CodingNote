#include "../Util/rheader.cpp"

std::vector<int> getPrimes(int MAX) {
    std::vector<int> primes;
    std::vector<int> sp(MAX + 1, 0); // smallest prime

    // 1 ~ MAX까지의 소수의 수를 구한다.
    // 결과는 prime 배열에 저장됨

    for(register int i = 2; i <= MAX; ++i) {
        if (sp[i] == 0) primes.push_back(i);
        for(auto& p: primes) {
            if (i*p > MAX) break;
            sp[i*p] = p;
            if (i % p == 0) break; // 이미 채로 걸러졌음
        }
    }

    return primes;
}