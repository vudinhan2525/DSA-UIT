#include<iostream>
using namespace std;
struct node{
	long long data;
	node *left,*right;
	node(long long x){
		data = x;
		left = right = NULL;
	}	
};
void insert(node *&root,long long x){
	if(root == NULL){
		root = new node(x);
		return;
	}
	if(root->data == x){
		return;
	}
	else if(root->data < x){
		insert(root->right,x);
	}
	else{
		insert(root->left,x);
	}
}
bool check(node *root){
	if(root == NULL)	return true;
	int cnt1 = 0;
	int cnt2 = 0;
	if(root->left == NULL)	cnt1++;
	if(root->right == NULL)	cnt2++;
	int cnt = cnt1 + cnt2;
	if(cnt == 1)	return false;
	return check(root->left) && check(root->right);
}
int main(){
	node *root = NULL;
	int n;cin >> n;
	for(int i = 0;i < n; i++){
		long long x;cin >> x;
		insert(root,x);
	}
	if(check(root)){
		cout << "YES" ;
	}
	else{
		cout << "NO";
	}
}