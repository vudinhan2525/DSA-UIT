#include<iostream>
#include<vector>
using namespace std;
int a[10000000];
int main(){
	int m,n;
	cin >> m >> n;
	for(int i = 0;i < m; i++){
		a[i] = 0;
	}
	for(int j = 0;j < n;j++){
		int i = 0;
		int x;cin >> x;
		int h = x % m;
		int ok = 0;
		while(a[h] != 0){
			h = ((x % m) + (i * i)) % m;
			i++;
			if(i == m){
				ok = 1;
				cout << x << " NULL" << endl;
				break;
			}
		}
		if(ok == 0) a[h] = x;	
	}
	for(int i = 0;i < m; i++){
		cout << a[i] << " ";
	}
	/*
	10 5
	89
	18
	49
	58
	69
	
	*/
}