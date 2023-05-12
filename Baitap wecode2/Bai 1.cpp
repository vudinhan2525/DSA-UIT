#include <bits/stdc++.h>
using namespace std;
int isBalanced(string s) {
   stack<char> st;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
            if(!st.empty()){    
                if(s[i] - 1 == st.top() || s[i] - 2 == st.top()){
                    st.pop();
                }
                else{
                    return 0;
                }
            }
            else    return 0;
        }
        else{
        	continue;
		}
    }
    if(!st.empty()) return 0;
    return 1;
}
int main(){
	string s;cin >> s;
	cout << isBalanced(s);
}