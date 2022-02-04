#include <bits/stdc++.h>

using namespace std;

#define MAX 100000007
#define ll long long

//*******SIEVE***********//

vector<pair<int, int> > primes;
bitset<MAX> bs;
vector<ll> lucky;
void sieve() {
    bs.set();
    for (int i = 4; i <= MAX; i += 2) bs[i] = 0;
    bs[0] = bs[1] = 0;
    for (ll i = 3; i <= 9999; i += 2) {
        if (bs[i]) {
            for (ll j = i * i; j <= MAX; j += i) {
                bs[j] = 0;
            }
            // primes.push_back(i);
        }
    }
    for(ll i=3; i<=MAX; i+=2) {
        if(bs[i] && bs[i+2]) primes.push_back(make_pair(i, i+2));
    }

}



int main()
{
    sieve(); int ca = 0;
    int n;
    while(cin>>n) {
        cout<<"("<<primes[n-1].first<<","<<" "<<primes[n-1].second<<")"<<endl;
    }
}
