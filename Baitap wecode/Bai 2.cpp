#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int const maxn = 1e7 + 1;
ll a[100000];
int n;
ll binarysearch(ll x,ll y){
	if(x == 1){
		for(int i = 0;i < n; i++){
			if(a[i] == y){
				return i + 1;
			}
		}
	}
	if(x == 2){
		for(int i = n - 1;i >= 0; i--){
			if(a[i] == y){
				return i + 1;
			}
		}
	}
	return -1;
}
int main(){
	int q;
	cin >> n >> q;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	while(q--){
		string s;cin >> s;
		ll x,y;cin >> x >> y;
		cout << binarysearch(x,y) << endl;
	}
}