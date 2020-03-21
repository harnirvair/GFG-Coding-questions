/*
Created on: 21-03-2020
Source: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1/?track=md-tree&batchId=144
*/
void bToDLL(Node *root, Node **head_ref)
{
    if(root == NULL)
    return; 
    // your code here
    static Node *prev = NULL;
    bToDLL(root->left, head_ref);
    if(*head_ref == NULL){
        *head_ref = root;
        prev = NULL;
    }else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    bToDLL(root->right, head_ref);
    
}

