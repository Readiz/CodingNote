bool isPrime(int v) {
    for(register int i = 2; i * i <= v; ++i) {
        if (v % i == 0) return false;
    }
    return true;
}