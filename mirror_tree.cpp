/*
https://practice.geeksforgeeks.org/problems/mirror-tree/1/?track=md-tree&batchId=144
Source:
Date: 05-03-2020
*/

Node *mirrortree (Node* P){
    if(!P || (!P->left && !P->right)){
        return P;
    }else{
        Node *tmp=P->right;
        P->right=mirrortree(P->left);
        P->left=mirrortree(tmp);
        return P;
    }
}
/* Should convert tree to its mirror */
void mirror(Node* node) 
{
    node= mirrortree(node);
}