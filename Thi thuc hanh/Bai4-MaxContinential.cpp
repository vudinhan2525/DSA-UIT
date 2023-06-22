#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1001];
int a[1001];
int visited[1001];
vector<int> way[1001];
void dfs(int u,int res){
	visited[u] = true;
	way[res].push_back(u);
	for(auto x : v[u]){
		if(!visited[x]){
			dfs(x,res);
		}
	}
}
int findMin(vector<int> tmp){
	int res = tmp[0];
	for(auto x : tmp){
		if(x < res){
			res = x;
		}
	}
	return res;
}
int main(){
	int n,m;cin >> m >> n;
	for(int i = 0;i < m; i++){
		cin >> a[i];
	}
	for(int i = 0;i < n; i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int res = 0;
	for(int i = 0;i < m; i++){
		if(!visited[i]){
			dfs(i,res);
			res++;		
		}
	}
	long long ans = 0;
	int idx = 0;
	int minElement = -1;
	for(int i = 0;i < res ;i++){
		long long sum = 0;
		for(auto x : way[i]){
			sum += a[x];
		}
		if(sum > ans){
			ans = sum;
			idx = i;
			minElement = findMin(way[i]);
		}
		else if(sum == ans){
			int tmp2 = findMin(way[i]);
			if(tmp2 < minElement){
				ans = sum;
				idx = i;
				minElement = tmp2;
			}
		}
	}
	for(auto x : way[idx]){
		a[x] = -1;
	}
	for(int i = 0;i < m; i++){
		if(a[i] == -1)	cout << i << " ";
	}
}