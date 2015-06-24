/*
    dfs
    һ����n�㣬���������������ö��ÿ���Ԫ��
    �ڵ�i�㣬������s����¼ǰ��i-1��ʹ�ù���Ԫ��
    ��󵽵�n��ʱ���Ǿ��ܵõ�һ����
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        int n = num.size();
        if(!n)  return res;
        sort(num.begin(),num.end());
        vector<int> tmp;
        dfs(res,num,tmp,0,0,n);
        return res;
    }
    void dfs(vector<vector<int> > &res,vector<int> &num,vector<int> tmp,int cur,int s,int n)
    {
        if(cur == n){       //��n��  �õ�һ����
            res.push_back(tmp);return ;
        }
        for(int i = 0;i < n;i++){
            if(s & (1<<i))    continue;         //�Ѿ���ʹ�ù���Ԫ�ز����ٱ�ʹ��
            else{
                if(tmp.size() != cur + 1)     tmp.push_back(num[i]);
                else    tmp[cur] = num[i];
                dfs(res,num,tmp,cur + 1,(1 << i) | s,n);
            }
        }
    }
};
