/*________________________Bismillahir Rahmanir Rahim___________________
                                                                      |
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
#define sf(v)                   for(auto &it:v) cin>>it
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
vii G[105];
int dist[105];
void bfs(int n) {
    dist[n] = 0;
    queue<int> q; q.push(n);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto it: G[cur]) {
            if(dist[cur]+1 > dist[it]) {
                dist[it] = dist[cur]+1;
                q.push(it);
            }
        }
    }
}
int main()
{
    //AHNAF;
    int n;int ca = 0;
    while(scanf("%d",&n)) {
        if(n == 0) break;
        memset(dist, 0, sizeof(dist));
        int start; scanf("%d", &start);
        for(int i=0; i<105; i++) G[i].clear();
        int u,v;
        while(scanf("%d%d",&u, &v)) {
            if(u+v==0) break;
            G[u].pb(v);
        }
        bfs(start);
        int mx = -1, ind = -1;
        for(int i=1; i<=n; i++) {
            if(dist[i] > mx) {
                mx = dist[i];
                ind = i;
            }
        }
        //"Case "<<++ca<<": The longest path from "<<start<<" has length "<<mx<<", finishing at "<<ind<<"."<<endl;
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++ca, start, mx, ind);
    }
}


