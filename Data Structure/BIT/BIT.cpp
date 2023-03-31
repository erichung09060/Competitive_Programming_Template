#define MAXN 100005

typedef struct BIT {
    long long bit[MAXN]={0};
    void update(int x, int val) {
        while (x < MAXN) {
            bit[x] += val;
            x += x & (-x);
        }
    }
    long long query(int x) {
        long long ans = 0;
        while (x) {
            ans += bit[x];
            x -= x & (-x);
        }
        return ans;
    }
} BIT;
