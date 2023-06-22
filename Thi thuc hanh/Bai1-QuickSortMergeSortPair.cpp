#include<iostream>
#include <cmath>
using namespace std;
struct toado{
	int x,y;
};
struct node{
	toado data;
	node *pNext;	
};
node *Makenode(int r,int t){
	node *newnode = new node();
	newnode->data.x = r;
	newnode->data.y = t;
	newnode->pNext = NULL;
	return newnode;
}
struct nodelist{
	node *pHead,*pTail;
};
void pushBack(nodelist &a,int x,int y){
	node *newNode = Makenode(x,y);
	if(a.pHead == NULL){
		a.pHead = a.pTail = newNode;
	}
	else{
		a.pTail->pNext = newNode;
		a.pTail = newNode;
	}
}
void duyet(nodelist a){
	while(a.pHead != NULL){
		cout << a.pHead->data.x << " " << a.pHead->data.y << endl;
		a.pHead = a.pHead->pNext;
	}
	cout << endl;
}
node* midPoint(node *head){
	node *tmp = head;
	node *tmp2 = head;
	int n = 0;
	while(tmp != NULL){
		n++;
		tmp = tmp->pNext;
	}
	for(int i = 1;i < (n / 2);i++){
		tmp2 = tmp2->pNext;
	}
	return tmp2;
}
double calc(toado a){
	return (double)sqrt(a.x * a.x+ a.y * a.y);
}
node* merge(node *a,node *b){
	if(a == NULL)	return b;
	if(b == NULL)	return a;
	node *tmp = a;
	if(calc(a->data) > calc(b->data)){
		tmp = b;
		b = b->pNext;
	}
	else{
		a = a->pNext;
	}
	node *cur = tmp;
	while(a != NULL && b != NULL){
		if(calc(a->data) < calc(b->data)){
			cur->pNext = a;
			a = a->pNext;
			cur = cur->pNext;
		}
		else if(calc(a->data) > calc(b->data)){
			cur->pNext = b;
			b = b->pNext;
			cur = cur->pNext;
		}
		else{
			if(a->data.x < b->data.x){
				cur->pNext = a;
				a = a->pNext;
				cur = cur->pNext;
			}
			else{
				cur->pNext = b;
				b = b->pNext;
				cur = cur->pNext;
			}
		}
	}
	while(a != NULL){
		cur->pNext = a;
		a = a->pNext;
		cur = cur->pNext;
	}
	while(b != NULL){
		cur->pNext = b;
		b = b->pNext;
		cur = cur->pNext;
	}
	return tmp;
}
node* mergeSort(node *a){
	if(a == NULL || a->pNext == NULL)	return a;
	node* mid = midPoint(a);
	node *b = mid->pNext;
	node *c = a;
	mid->pNext = NULL;
	c = mergeSort(c);
	b = mergeSort(b);
	return merge(c,b);
}
double calc2(pair<int,int> a){
	return (double)sqrt(a.first * a.first + a.second * a.second);
}
bool check(pair<int,int> a,pair<int,int> b){
	double u = calc2(a);
	double v = calc2(b);
	if(u < v){
		return true;
	}
	else if(u > v){
		return false;
	}
	else{
		return a.first < b.first;
	}
}
int partition(pair<int,int> a[],int l,int p){
	pair<int,int> pivot = a[l];
	int i = l - 1;
	int j = p + 1;
	while(1){
		do{
			i++;
		}while(check(a[i],pivot) == true);
		do{
			j--;
		}while(check(pivot,a[j]) == true);
		if(i < j){
			swap(a[i],a[j]);		
		}
		else	return j;
	}
}
void quicksort(pair<int,int> a[],int l,int r){
	if(l >= r)	return;
	int p = partition(a,l,r);
	quicksort(a,l,p);
	quicksort(a,p + 1,r);
}
int main(){
//	nodelist a;
//	a.pHead = NULL;
//	a.pTail = NULL;
//	int n;cin >> n;
//	for(int i = 0;i < n; i++){
//		int x,y;
//		cin >> x >> y;
//		pushBack(a,x,y);
//	}
//	a.pHead = mergeSort(a.pHead);
//	duyet(a);
	int n;cin >> n;
	pair<int,int> a[1001];
	for(int i = 0;i < n; i++){
		int x,y;
		cin >> x >> y;
		a[i] = {x,y};
	}
	quicksort(a,0,n - 1);
	nodelist b;
	b.pHead = NULL;
	b.pTail = NULL;
	for(int i = 0;i < n;i++){
		pushBack(b,a[i].first,a[i].second);
	}
	duyet(b);
}