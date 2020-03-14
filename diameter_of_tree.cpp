/*
Source: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/?track=md-tree&batchId=144
Date: 05-03-2020
*/

int diameter(Node* node) {
	
    // Your code here
    if(node==NULL)
    return 0;
    else{
        int lheight=height(node->left);
        int rheight=height(node->right);
        int total_height=lheight+rheight+1;
        
        int ld=diameter(node->left);
        int rd=diameter(node->right);
        int maxd=max(ld,rd);
        int res=max(maxd,total_height);
        return res;
    }
}