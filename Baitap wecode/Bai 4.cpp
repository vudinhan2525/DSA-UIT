#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int const maxn = 1e7 + 1;
ll a[100000];
void merge(ll a[],int l,int m,int r){
	vector<ll> x(a + l,a + m + 1);
	vector<ll> y(a + m + 1, a + r + 1);
	int i = 0;int j = 0;
	while(i < x.size() && j < y.size()){
		if(x[i] <= y[j]){
			a[l] = x[i];i++;l++;
		}
		else if(x[i] > y[j]){
			a[l] = y[j];j++;l++;
		}
	}
	while(i < x.size()){
		a[l] = x[i];i++;l++;
	}
	while(j < y.size()){
		a[l] = y[j];j++;l++;
	}
}
void mergeSort(ll a[],int l,int r){
	if(l >= r)	return ;
	int m = (l + r) / 2;
	mergeSort(a,l,m);
	mergeSort(a,m + 1, r);
	merge(a,l,m,r);
}
int main(){
	int n;cin >> n;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	mergeSort(a,0,n - 1);
	int ok = 0;
	for(int i = 0;i < n; i++){
		if(a[i] != i){
			cout << i;
			ok = 1;
			return 0;
		}
	}
	if(ok == 0)	cout << a[n - 1] + 1;
	if(n == 0)	cout << 0;
}