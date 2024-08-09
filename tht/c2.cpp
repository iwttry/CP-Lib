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

vector<int> g[10009];
int a[1009][1009];
vector<pair<int, int>> ver;
int n = 1;
void b(){
    for (int i=1; i<=501; i++){
        for (int j=1; j<=501; j++){
            a[i][j] = inf - 100000;
            a[i][i] = 0;
        }
    }
    for (int i=1; i<=501; i++){
        a[i][i] = 0;
    }
    for (auto it : ver){
        a[it.first][it.second] = 1;
        a[it.second][it.first] = 1;
    }
    for (auto it : ver){
        for (int i=1; i<=)
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
 
    int n;
    int m;
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ver.push_back({u, v});
    }
    b();
}