#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int const maxn = 1e7 + 1;
string a[50000];
void ms(string a[],int l,int m,int r){
	vector<string> x(a + l,a + m + 1);
	vector<string> y(a + m + 1, a + r + 1);
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
void MERSORT(string a[],int l,int r){
	if(l >= r)	return ;
	int m = (l + r) / 2;
	MERSORT(a,l,m);
	MERSORT(a,m + 1, r);
	ms(a,l,m,r);
}
int main(){
	int n;cin >> n;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	MERSORT(a,0,n - 1);
	int cnt = 0;
	for(int i = 0;i < n; i++){
		while(a[i + 1] == a[i]){
			i++;
		}
		cnt++;
	}
	cout << cnt;
}