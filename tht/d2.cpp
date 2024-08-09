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

struct W{
    int a, b, c;
};

vector<W> v;
int ans = 1000000000;

bool cmp(W a, W b){
    if (a.a < b.a) return a.a < b.a;
    if (a.b < b.b) return a.b < b.b;
    return a.c < b.c;
}

void tryy(int x){
    vector<W> tmp = v;
    tmp[x-1].b = 1;
    sort(tmp.begin(), tmp.end(), cmp);
    int ans2 = 0;
    int t = 0;
    for (auto it : tmp){
        // cout << it.a << " " << it.b << " " << it.c << "\n";
        t += it.c;
        ans2 += it.b * it.c;
        ans = min(ans, ans2);
    }
    // cout << ans2 <<  "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}

    int n;
    cin >> n;
    vector<W> ttt;
    for (int i=1; i<=n; i++){
        ttt.push_back({0, 0, 0});
    }
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        ttt[i].a = x;
    }
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        ttt[i].b = x;
    }
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        ttt[i].c = x;
    }
    for (auto it : ttt){
        v.push_back(it);
    }
    for (int i=1; i<=n; i++){
        tryy(i);
    }
    cout << ans;
}