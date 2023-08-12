/* Shubhodip Pal*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include<ext/pd_ds/tree_policy.hpp>
#define ll long long int
const ll M = 998244353;
const ll N = 1e9 + 7;
const ll NN = 1e6 + 7;
const int p = 31;
#define f(a, b, c) for (int a = b; a < c; a++)
#define rf(a, b, c) for (int a = b; a >= c; a--)
#define vl vector<ll>
#define vs vector<string>
#define vpp vector<pair<ll, ll>>
#define pll pair<ll, ll>
#define vll vector<pll>
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define pb push_back
#define ltransfr(str) transform(str.begin(), str.end(), str.begin(), ::tolower)
#define utransfr(str) transform(str.begin(), str.end(), str.begin(), ::toupper)
#define PI 3.1415926535897932384626433832795
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define R return
#define C continue
#define bpc(x) __builtin_popcountll(x)
// vector<ll>factorial(1e6+1);
using namespace std;
using namespace __gnu_pbds;
ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    ll res = a * (b / g);
    return res;
}
ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
ll binExp(ll a, ll b, ll m = M)
{
    a = a % m;
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll m = M)
{
    a = a % m;
    return binExp(a, m - 2, m);
} // only for prime m
ll mod_add(ll a, ll b, ll m = M)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m = M)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m = M)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m = M)
{
    a = a % m;
    ll binv = mod_inv(b, m);
    return (((a * binv) % m) + m) % m;
}
// ll facto(ll n , ll m=N){ ll ans=1;  while(n) { ans*=n ; n--; ans%=m; } return ans;}
// ll facto(){factorial[1]=1;for(ll i=2;i<1e6+1;i++) {factorial[i]=(factorial[i-1]*i)%N;}}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order , order_of_key

bool prime(int a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void dfs(int node, vector<int> adj[], int vis[], vector<int> &v)
{
    vis[node] = 1;
    v.pb(node);
    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            dfs(x, adj, vis, v);
        }
    }
}
vl pr_factors;
void sieve(int n)
{
    bool prime[n + 1];
    for (int i = 0; i < n; i++)
    {
        prime[i] = true;
    }
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            pr_factors.pb(p);
}
bool isPalindrome(string s, int i)
{
    if (i > s.size() / 2)
    {
        return true;
    }
    return s[i] == s[s.size() - i - 1] && isPalindrome(s, i + 1);
}
bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
ll mod(ll a)
{
    if (a >= 0)
    {
        return a % N;
    }
    else
    {
        ll d = abs(a) / N;
        return (N * (d + 1) + a) % N;
    }
}

void solve()
{   
    string s;
    cin>>s;
    vector<ll>v(s.size());
    bool f=0;
    for(int i=0;i<s.size();i++){
        v[i]=(s[i]-'0');
        if(v[i]>4) f=1;
    }
    if(f==0){
        cout<<s<<endl;
        return;
    }
    int j=0;
   int k=-1;
    for(int i=0;i<v.size();i++){
     if(v[i]>4){
        j=i;
        break;
     }
    }
    for(int i=j-1;i>=0;i--){
       if(v[i]<4){
        k=i;
        break;
       }
    }
   if(k==-1){
    cout<<1;
    for(int i=0;i<s.size();i++){
        cout<<0;
    }
    cout<<endl;
   }
   else{
    for(int i=0;i<s.size();i++){
        if(i<k){
            cout<<v[i];
        }
        else if(i==k){
            cout<<v[i]+1;
        }
        else{
            cout<<0;
        }
    }
    cout<<endl;
   }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // facto();
    ll t = 1;
    cin >> t;
    ll a = 1;

    while (t--)
    { // cout << flush ;
        // cout<<"Case "<<a<<": ";
        solve();
        // a++;
    }
    return 0;
}