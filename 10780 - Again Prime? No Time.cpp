#include <bits/stdc++.h>

using namespace std;

#define MAX 1234567
#define ll long long

//*******SIEVE***********//

vector<ll> primes;
bitset<MAX> bs;
// ll ar[MAX];
void sieve() {
    bs.set();
    for (int i = 4; i <= MAX; i += 2) bs[i] = 0;
    bs[0] = bs[1] = 1;
    primes.push_back(2);
    for (ll i = 3; i <= 9999; i += 2) {
        if (bs[i]) {
            // ar[i] = i;
            for (ll j = i * i; j <= MAX; j += i) {
                bs[j] = 0;
                // ar[j]++;
            }
            // primes.push_back(i);
        }
    }
    for (int i = 3; i <= MAX; i += 2) {
        if (bs[i]) primes.push_back(i);
    }
}

// Big Mod
/*
ll binpow(ll b, ll p, ll m) {
    long long res = 1;
    while (p > 0) {
        if (p & 1)
            res = (res * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }
    return res;
}
*/

map<int, int> giveFactorFact(int n) {
    map<int, int> v;
    for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
        int p = primes[i];
        int cnt = 0;
        while (n / p) {
            cnt += (n / p);
            p *= primes[i];
        }
        v[primes[i]] = cnt;
    }
    return v;
}

map<int, int> giveFactor(int n) {
    map<int, int> v;
    for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
        int cnt = 0;
        while (n % primes[i] == 0) {
            cnt++;
            n /= primes[i];
        }
        if (cnt) v[primes[i]] = cnt;
    }
    if (n > 1) v[n]++;
    return v;
}

int main() {
    int ca = 0;
    int t;
    sieve();
    cin >> t;
    while (t--) {
        map<int, int> first, second;
        int n, m;
        cin >> m >> n;
        first = giveFactorFact(n);
        second = giveFactor(m);
        int i;
        for(i=1; ; i++) {
            bool chk = false;
            for(auto it=second.begin(); it!=second.end(); it++) {
                if((it -> second * i) > first[it -> first]) {chk = true; break;}

            }
            if(chk) break;
        }
        cout<<"Case "<<++ca<<":"<<endl;
        if(i - 1 <= 0) cout<<"Impossible to divide"<<endl;
        else cout<<i-1<<endl;
    }
}
