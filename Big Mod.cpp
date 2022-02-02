#include <bits/stdc++.h>

using namespace std;

#define MAX 12345678
#define ll long long

//*******SIEVE***********//
/*
vector<ll> primes;
bitset<MAX> bs;
// ll ar[MAX];
void sieve() {
    bs.set();
    for (int i = 4; i <= MAX; i += 2) bs[i] = 0;
    bs[0] = bs[1] = 0;
    primes.push_back(2);
    for (ll i = 3; i <= 99999; i += 2) {
        if (bs[i]) {
            // ar[i] = i;
            for (ll j = i * i; j <= MAX; j += i) {
                bs[j] = 0;
                // ar[j]++;
            }
            // primes.push_back(i);
        }
    }
    for(int i=3; i<=MAX; i+=2) {
        if(bs[i]) primes.push_back(i);
    }
}
*/

// Big Mod
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

int main() {
    ll b,p,m;
    while(cin>>b>>p>>m) {
        ll ans = binpow(b,p,m);
        cout<<ans<<endl;
    }
}
