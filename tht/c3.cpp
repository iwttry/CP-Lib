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

int D[1009][1009];
int D2[1009][1009];
void floydWarshall(int n) {

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (D[u][v] > D[u][k] + D[k][v]) {
                    D[u][v] = D[u][k] + D[k][v];
                    // cout << u << " " << v << " " << D[u][v] << "\n";
                }
            }
        }
    }
}

void floydWarshall2(int n) {

    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (D2[u][v] > D2[u][k] + D2[k][v]) {
                    D2[u][v] = D2[u][k] + D2[k][v];
                    // cout << u << " " << v << " " << D[u][v] << "\n";
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
 
    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            D[i][j] = 1000000000000;
        }
    }

    for (int i=1; i<=n; i++){
        D[i][i] = 0;
    }
    for (int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        D[u][v] = 1;
        D[v][u] = 1;
    }
    floydWarshall(n);
    cin >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            D2[i][j] = 1000000000000;
        }
    }

    for (int i=1; i<=n; i++){
        D2[i][i] = 0;
    }
    for (int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        D2[u][v] = 1;
        D2[v][u] = 1;
    }
    floydWarshall2(n);
    int ans = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            ans += max(D[i][j], D2[i][j]);
        }
        // cout << "\n";
    }
    cout << ans;
}