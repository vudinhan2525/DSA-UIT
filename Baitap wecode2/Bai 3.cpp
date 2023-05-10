#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};
Node *Makenode(double x,int y){
	Node *newnode = new Node();
	newnode->data = new DONTHUC(x,y);
	newnode->next = NULL;
	return newnode;
}
void Nhap(DATHUC &a,double heso,int somu){
	Node *newnode = Makenode(heso,somu);
	if(a.head == NULL){
		a.head = a.tail = newnode;
	}
	else{
		a.tail->next = newnode;
		a.tail = newnode;
	}
}
void in(double a,int b,int ok1,int ok2,int ok3){
	if(ok1 == 1 && ok2 == 0 && ok3 == 0){
		if(a > 0)	cout << "+" << "x^" << b;
		else{
			cout << "-" << "x^" << b;
		}
	}
	else if(ok1 == 1 && ok2 == 1 && ok3 == 0){
		if(a > 0)	cout << "+" << a;
		else{
			cout << a;
		}
	}
	else if(ok1 == 1 && ok2 == 0 && ok3 == 1){
		if(a > 0)	cout << "+x";
		else{
			cout << "-x";
		}
	}
	else if(ok1 == 0 && ok2 == 1 && ok3 == 0){
		if(a > 0)	cout << "+" << a ;
		else{
			cout << a;
		}
	}
	else if(ok1 == 0 && ok2 == 0 && ok3 == 1){
		if(a > 0)	cout << "+" << a << "x";
		else{
			cout << a << "x";
		}
	}
	else{
		if(a > 0)	cout << "+" << a << "x^" << b;
		else{
			cout << a << "x^" << b;
		}
	}
}
void check1(double a,int b){
	if(a == 0)	return;
	int ok1 = 0,ok2 = 0,ok3 = 0;
	if(a == 1 || a == -1)	ok1 = 1;
	if(b == 0)	ok2 = 1;
	if(b == 1)	ok3 = 1;
	in(a,b,ok1,ok2,ok3);
}
void Xuat(DATHUC a){
	int i = 0;
	bool check = false;
	while(a.head != NULL){
		double x = a.head->data->heso;
		int y = a.head->data->somu;
		if(x != 0)	check = true;
		if(i == 0){
			if(x <= 0){
				check1(x,y);
			}
			else{
				if(x == 1){
					if(y == 0){
						cout << 1;
					}
					else if(y == 1){
						cout << "x";
					}
					else{
						cout << "x^" << y;
					}
				}
				else{
					if(y == 0){
						cout << x;
					}
					else if(y == 1){
						cout << x << "x";
					}
					else{
						cout << x << "x^" << y;
					}
				}
			}
		}
		else check1(x,y);
		if(x != 0)	i++;
		a.head = a.head->next;
	}
	if(check == false)	cout << 0;
}
double TinhDaThuc(DATHUC  B,double x){
	double s = 0;
	while(B.head != NULL){
		double a = B.head->data->heso;
		int b = B.head->data->somu;
		s += a * (pow(x,b));
		B.head = B.head->next;
	}
	return s;
}
int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}