stack<Node*> st;
    st.push(root);
    while(!st.empty()){
    	Node *tmp = st.top();
    	cout << tmp->data << " ";
    	st.pop();
    	if(tmp->right){
    		st.push(tmp->right);
		}
		if(tmp->left){
			st.push(tmp->left);
		}
	}