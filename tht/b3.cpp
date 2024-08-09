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
const int inf2 = 1e15;
// bool mem1;
// void clockt(){
// 	bool mem2;
// 	cerr << "\nMemory Cost: " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB" << "\n";
// 	cerr << "Time Cost: " << clock() * 1000. / CLOCKS_PER_SEC << "MS" << "\n";
// }

int b(int x){
    int a, b, c;
    int n = 0;
    if(x){
        a = x & -x;
        b = x + a;
        c = x ^ b;
        c = (c)/a;
        c >>= 2;
        n = b | c;
    }
    return n;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
 
    int T;
    cin >> T;
    while (T--){
        int x, k;
        cin >> x >> k;
        bool flag = 0;
        for (int i=1; i<=k; i++){
            x = b(x);
            if (x > inf2){
                flag = 1;
            }
        }
        if (flag) cout << -1 <<"\n";
        else
        cout << x << "\n";
    }
    
}