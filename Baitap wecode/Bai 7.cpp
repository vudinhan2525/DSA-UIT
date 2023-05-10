#include <iostream>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int const maxn = 1e7 + 1;
int a[100000];
int main(){
	int n;cin >> n;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	int x;cin >> x;
	int ok = 0;
	for(int i = 0;i < n; i++){
		if(x == a[i]){
			ok = 1;
			cout << i + 1 << " ";
		}
	}
	if(ok == 0)	cout << "NO";
}