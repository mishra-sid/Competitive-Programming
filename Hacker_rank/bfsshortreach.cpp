/*
  Template by Siddhartha Mishra(sid_m97)
*/

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((long long) (x).size())
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define FOR(i,a,b) for(long long i = (a); i <= (b); i++)
#define rrep(i, n) for (long long i = (n) - 1; i >= 0; i--)
#define fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll inf = 1e18; 
const double eps = 1e-9;
const double pi = acos(-1.0);
const ll  MOD =  1e9+7;

/* important functions */
ll mod(ll a,ll b=MOD)
{ return (a%b+b)%b; }


ll xdiv(ll a,ll b)
{
  if(a%b == 0) return a/b;
  else return a/b + 1;
}

ll gcd(ll a, ll b) {
  ll r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

ll powmod(ll base, ll exp ,ll mod=MOD) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}

ll inv(ll a, ll m = MOD)
{
    return powmod(a, m-2,m);
}

void prnt(auto beg, auto end){
  for(auto it = beg; it != end; it++) cout<<*it<<" ";
  cout<<endl;
}

/* Declare variables here*/
ll T;
int n,m;

/* user define functions specific to problem */
void bfs(vector<vector <int>> g,int n, int s)
{
    queue<int> q;
    q.push(s);
    vector<bool> used(n);
    vector<int> d(n), p(n);
    used[s] = true;
    p[s] = -1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i=0;i < g[v].size();i++)
        {
            int to = g[v][i];
            if(!used[to])
            {
                used[to] = true;
                q.push(to);
                d[to] = d[v]+6;
                p[to] = v;
            }
        }
    }
    
    rep(i,n){
        if(i != s){
            if(!used[i]) cout<<"-1 ";
            else cout<<d[i]<<" ";
        }
    }
    cout<<endl;
}


/* solve here */
void solve()
{
   cin>>n>>m;
   vector< vector<int> > g(n);
   rep(i,m){
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
   }
   int s;
   cin>>s;
   s--;
   bfs(g,n,s);

}

/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
  cin>>T;
  while(T--)
  solve();
  
  return 0;
}
