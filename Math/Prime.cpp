vector<bool> isPrime(MAXN, true);
vector<int> Prime;

void Sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (isPrime[i]) {
            Prime.push_back(i);
            for (int j = i * i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
