#include<iostream>
#include<queue>
using namespace std;
#define fi first
#define se second
char a[201][201];
int grass[201][201], dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
void bfs(int n, int m, int u, int v){
	queue<pair<int, int>> q;
	q.push({u, v});
	while (!q.empty()){
		pair<int, int> cur1 = q.front();
		if (a[cur1.fi][cur1.se] == 'C') return;
		q.pop();
		a[cur1.fi][cur1.se] = '*';
		for (int i = 0; i<4; i++){
			pair<int, int> cur2 = {cur1.fi + dx[i], cur1.se + dy[i]};
			if (cur2.fi >= 1 && cur2.fi <= n && cur2.se >= 1 && cur2.se <= m && a[cur2.fi][cur2.se] != '*')
			{
				q.push(cur2);
				grass[cur2.fi][cur2.se] = grass[cur1.fi][cur1.se] + 1;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	pair<int, int> start = {1, 1}, end = {1, 1};
	cin>>n>>m;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin>>a[i][j];
			if (a[i][j] == 'B') start = {i, j};
			if (a[i][j] == 'C') end = {i, j};
		}
	}
	bfs(n, m, start.fi, start.se);
	cout<<grass[end.fi][end.se];
}