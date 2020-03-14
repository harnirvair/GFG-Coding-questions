/*

Date: 14-03-2020
Print spiral level traversal of binary tree

*/

void printSpiral(Node *root)
{   if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    int qsize;bool flag=true;
    while(q.empty()==false){
        qsize=q.size();
        vector<int> v;
        while(qsize>0){
            Node *x = q.front();
            v.push_back(x->data);
            q.pop();
            if(x->left!=NULL)
                q.push(x->left);
            if(x->right!=NULL)
                q.push(x->right);
            qsize--;
        }
        if(flag){
            reverse(v.begin(),v.end());
            flag=false;
        }else{
            flag=true;
        }
         for(auto itr=v.begin();itr!=v.end();itr++){
            cout<<*itr<<" ";
         }
    }
}
