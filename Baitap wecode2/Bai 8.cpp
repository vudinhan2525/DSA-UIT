queue<Node*> qe;
    qe.push(root);
    while(!qe.empty()){
        Node*tmp = qe.front();qe.pop();
        cout << tmp->data << " ";
        if(tmp->left != NULL){
            qe.push(tmp->left);
        }
        if(tmp->right != NULL){
            qe.push(tmp->right);
        }
    }