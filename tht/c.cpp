// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;
// bool mem1;
// void clockt(){
// 	bool mem2;
// 	cerr << "\nMemory Cost: " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB" << "\n";
// 	cerr << "Time Cost: " << clock() * 1000. / CLOCKS_PER_SEC << "MS" << "\n";
// }

vector<vector<int>> g1(N);

struct Edge{
    int v;
    int w;
};

struct Node{
    int u;
    int D_u;
};

struct cmp{
    bool operator () (const Node a, const Node b){
        return a.D_u > b.D_u;
    }
};

vector<Edge> E[100009];
vector<Edge> E2[100009];
vector<int> tmp(1009, inf - 10000000);
vector<vector<int>> d(1009, tmp);
vector<vector<int>> d2(1009, tmp);
vector<int> trace(100009, -1);
vector<vector<int>> shortest_path(int s){
    vector<bool> P(100009, 0);
    priority_queue<Node, vector<Node>, cmp> pq;
    d[s][s] = 0;
    pq.push({s, d[s][s]});
    while (!pq.empty()){
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (P[u]) continue;
        P[u] = 1;
        for (auto e : E[u]){
            int v = e.v;
            int w = e.w;
            if (d[s][v] > d[s][u] + w){
                d[s][v] = d[s][u] + w;
                pq.push({v, d[s][v]});
                trace[v] = u;
            }
        }
    }
    return d;
}
vector<vector<int>> shortest_path2(int s){
    vector<bool> P(100009, 0);
    priority_queue<Node, vector<Node>, cmp> pq;
    d2[s][s] = 0;
    pq.push({s, d2[s][s]});
    while (!pq.empty()){
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (P[u]) continue;
        P[u] = 1;
        for (auto e : E2[u]){
            int v = e.v;
            int w = e.w;
            if (d2[s][v] > d2[s][u] + w){
                d2[s][v] = d2[s][u] + w;
                pq.push({v, d2[s][v]});
                trace[v] = u;
            }
        }
    }
    return d;
}
int f[1002][1002];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}

    int n;
    cin >> n;
    int m1;
    cin >> m1;
    for (int i=1; i<=m1; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back({v, 1});
        E[v].push_back({u, 1});
    }
    for (int i=1; i<=n; i++)
    shortest_path(i);
    for (int i=1; i<=10; i++){
        // cout << d[1][i] << "\n";
    }
    
    cin >> m1;
    for (int i=1; i<=m1; i++){
        int u, v;
        cin >> u >> v;
        E2[u].push_back({v, 1});
        E2[v].push_back({u, 1});
    }
    for (int i=1; i<=n; i++)
    shortest_path2(i);
    for (int i=1; i<=10; i++){
        // cout << d2[1][i] << "\n";
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            ans += max(d[i][j], d2[i][j]);
            // cout << f[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << ans;
}