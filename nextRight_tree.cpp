/*
Created On: 21-03-2020
Source: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/?track=md-tree&batchId=144
*/

void connect(Node *p)
{
   // Your Code Here
   queue <Node*> q;
   q.push(p);
   while(!q.empty()){
       Node *prev=NULL;
       int size=q.size();
       while(size--){
         Node *temp = q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        if(prev!=NULL)
            prev->nextRight = temp;
        prev=temp;
       }
       prev->nextRight=NULL;
   }
}