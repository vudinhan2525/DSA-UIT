stack<Node*> st;
    st.push(root);
    Node * prev = NULL;
    while(!st.empty()){
        Node *cur = st.top();
        if(prev == NULL || prev->left == cur || prev->right == cur){
            if(cur->left)   st.push(cur->left);
            else if(cur ->right)    st.push(cur->right);
            else{
                st.pop();
                cout << cur->data << " ";
            }
        }
        else if(cur-> left == prev){
            if(cur->right){
                st.push(cur->right);
            }
            else{
                st.pop();
                cout << cur->data << " ";
            }
        }
        else if(cur->right == prev){
            cout << cur->data << " ";
            st.pop();
        }
        prev = cur;
    }