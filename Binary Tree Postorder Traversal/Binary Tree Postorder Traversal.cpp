/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct node
{
    TreeNode *p;
    bool flag;      //flag��ʾ��û�з��ʹ�������
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *p = root;
        stack<node> s;
        while(1){
            while(p){                       //��������ջ
                s.push((node){p,0});
                p = p->left;
            }
            if(s.empty())   break;
            node u = s.top();s.pop();
            if(u.flag || (u.p)->right == NULL){         //���ʽڵ㱾��
                res.push_back((u.p)->val);
            }
            else{                           //��������ջ
                u.flag = 1;
                s.push(u);
                p = (u.p)->right;
            }
        }
        return res;
    }
};
