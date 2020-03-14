/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    vector < vector < int >> levelOrder(TreeNode * root) {
      vector < vector < int >> v;

      if (root == NULL) {

        return v;
      }

      queue < TreeNode * > q;
      q.push(root);
      while (q.empty() == false) {
        vector < int > level;
        int qsize = q.size();
        while (qsize > 0) {
          TreeNode * x = q.front();
          q.pop();
          level.push_back(x - > val);
          if (x - > left != NULL)
            q.push(x - > left);
          if (x - > right != NULL)
            q.push(x - > right);
          qsize--;
        }
        v.push_back(level);

      }
      return v;
    }
};