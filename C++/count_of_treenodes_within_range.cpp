/*
Created on 21-03-2020
Source: https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1/?track=md-tree&batchId=144
*/

int getCountOfNode(Node *root, int l, int h)
{
    int count=0;
    if(root==NULL)
    return count;
    int d = root->data;
    if(d>= l && d<=h)
        count++;
    return count+getCountOfNode(root->left,l,h)+getCountOfNode(root->right,l,h);
    return 0;
}