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

int bbrute(int x){
    if (x == 0)
        return 0;
    // unsigned int b = __builtin_ctzll(x);
    int b = __builtin_popcountll(x);
    for (int i=x+1; i<=100000000000000; i++){
        int c = __builtin_popcountll(i);
        if (b == c) return i;
    }
    return 1;
}

int b(int x){

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
 
    int T;
    cin >> T;
    while(T--){
        int x, k;
        cin >> x >> k;
        // bitset<32> t= x;
        // cout << t << "\n";
        bool flag = 0;
        while (k--){
            x = bbrute(x);
            if (x > inf2){
                flag = 1;
                break;
            }
        }
        if (flag) cout << -1 << "\n";
        cout << x << "\n";
        // cout << (1<<(b(x))) + 1 << "\n";
    }

}