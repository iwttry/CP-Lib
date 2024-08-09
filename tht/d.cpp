#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int b;
    int p;
};

bool compare(Process a, Process b) {
    return a.p > b.p;
}

int main() {
    vector<Process> pr = {
        {0, 0, 0},
    };
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pr.push_back({a, b, c});
    }

    sort(pr.begin(), pr.end(), compare);
    int srv = pr[0].b;
    int ans = 0;
    for (int i = 1; i < pr.size(); i++) {
        srv += pr[i - 1].b;
        int w = srv - pr[i].b;
        int t = w + pr[i].b;
        if (i != 1) ans += srv;
      
    }
    cout << ans;
    
}
