/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root)    q.push(root);
        while(q.size()){
            TreeNode *p = q.front();    //ÿ��ȡ�����ұߵĵ����res
            res.push_back(p->val);
            int cnt = q.size();
            while(cnt--){       //�����һ��ĵ㣬������һ��ĵ���ҵ���������
                p = q.front();
                q.pop();
                if(p->right)    q.push(p->right);
                if(p->left)     q.push(p->left);
            }
        }
        return res;
    }
};
