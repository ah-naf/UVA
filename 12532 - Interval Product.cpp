/*________________________Bismillahir Rahmanir Rahim___________________
|                                                                      |
|                    /\     |     | |\    |     /\     |-------        |
|                   /  \    |     | | \   |    /  \    |               |
|                  /----\   |-----| |  \  |   /----\   |-----          |
|                 /      \  |     | |   \ |  /      \  |               |
|                /        \ |     | |    \| /        \ |               |
|                     14th batch CSE , ID : 12008029                   |
|                     Comilla University                               |
|                     Email : sheikhahnafshifat@gmail.com              |
|______________________________________________________________________*/
#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
#define ll                      long long
#define MAX                     1000007
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define vii                     vector<int>
#define vll                     vector<long long>
#define vp                      vector<pair<ll, ll> >
#define v_min(a)                *min_element(a.begin(),a.end())
#define v_max(a)                *max_element(a.begin(),a.end())
#define v_sum(a)                accumulate(a.begin(),a.end(),0)
#define un(a)                   a.erase(unique(a.begin(),a.end()),a.end())
#define SORT(a)                 sort(a.begin(),a.end())
#define AHNAF                   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define YES                     cout<<"YES"<<endl
#define NO                      cout<<"NO"<<endl
#define testcase(t)             int t;cin>>t;while(t--)
#define reverse(a)              reverse(a.begin(),a.end())
#define ff                      first
#define ss                      second
#define print(a)                for(auto it: a) cout<<it<<" "
#define all(a)                  a.begin(),a.end()
#define sf(v)                   for(auto &it: v) cin>>it
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
bool checkbit(int mask,int bit) {
    return mask & (1<<bit);
}
int setbit(int mask,int bit) {
    return mask | (1<<bit) ;
}
int clearbit(int mask,int bit) {
    return mask & ~(1<<bit);
}
int togglebit(int mask,int bit) {
    return mask ^ (1<<bit);
}
//--------------------------------------------------------------//
struct segtree {

    int sizee;
    vector<int> val;
    vector<int> operation;

    void init(int n) {
        sizee = 1;
        while(sizee < n) sizee *= 2;
        val.assign(2 * sizee, 0);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                val[x]=a[lx];// sum and minimum
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        val[x] = val[2 * x + 1] * val[2 * x + 2]; // sum
        //val[x] = min(val[2 * x + 1], val[2 * x + 2]); // minimum
    }

    void build(vector<int> &a) {
        build(a, 0, 0, sizee);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            val[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            update(i, v, 2 * x + 1, lx, m);
        } else {
            update(i, v, 2 * x + 2, m, rx);
        }
        val[x] = val[2 * x + 1] * val[2 * x + 2];
    }

    void update(int i, int v) {
        update(i, v, 0, 0, sizee);
    }

    int prod(int l, int r, int x, int lx, int rx) {
        if(lx >= r || l >= rx) return 1;
        if(lx >= l && rx <= r) return val[x];
        int m = (lx + rx) / 2;
        int p1 = prod(l, r, 2 * x + 1, lx, m);
        int p2 = prod(l, r, 2 * x + 2, m, rx);
        return p1 * p2;
    }

    int prod(int l, int r) {
        return prod(l, r, 0, 0, sizee);
    }
};


int main() {
    AHNAF;
    int n,q;
    while(cin>>n>>q) {
        vii v(n);
        for(int i=0; i<n; i++) {
            cin>>v[i];
            if(v[i] > 0) v[i] = 1;
            else if(v[i] < 0) v[i] = -1;
            else v[i] = 0;
        }
        segtree st; st.init(n); st.build(v);
        while(q--) {
            char op;cin>>op;
            switch(op) {
            case 'C':
                int i, v;cin>>i>>v; i--;
                if(v > 0) v = 1;
                else if(v < 0) v = -1;
                else v = 0;
                st.update(i, v);
                break;
            case 'P':
                int l, r;cin>>l>>r;l--;
                int ans = st.prod(l, r);
                if(ans > 0) cout<<"+";
                else if(ans < 0) cout<<"-";
                else cout<<"0";
                break;
            }
        }
        cout<<endl;
    }
}
