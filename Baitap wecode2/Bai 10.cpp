#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int const maxn = 1e7 + 1;
ll a[1000000];
struct node{
	ll data;
    node * left;
    node * right;
    node(ll val = 0)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
void insert(node **root,ll x){
	if((*root) == NULL)	{
		*root = new node(x);
		return;
	}
	node *tmp = *root;
	while(tmp){
		if(tmp->data >= x){
			if(tmp->left == NULL){
				tmp->left = new node(x);
				return;
			}
			else{
				tmp = tmp->left;
			}
		}
		else{
			if(tmp->right == NULL){
				tmp->right = new node(x);
				return;
			}
			else{
				tmp = tmp->right;
			}
		}
	}	
	return;
}
void topView(node *root){
	map<int,ll> mp;
	vector<ll> v;
    queue<pair<node*,int>> qe;
    qe.push({root,0});
    while(!qe.empty()){
        pair<node*,int> tmp = qe.front();qe.pop();
        if(mp.count(tmp.second) != 1){
            mp[tmp.second] = tmp.first->data;
            v.push_back(tmp.first->data);
        }
		if(tmp.first->right != NULL){
            qe.push({tmp.first->right, tmp.second - 1});
        }
        if(tmp.first->left != NULL){
            qe.push({tmp.first->left,tmp.second + 1});
        }
    }
    sort(v.begin(),v.end());
	for(auto x : v){
		cout << x << " ";
	}
}
int main(){
	int n;cin >> n;
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	node *root = NULL;
	for(int i = 0;i < n; i++){
		insert(&root,a[i]);
	}
	topView(root);
	
}