//��ϣ������

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mapint;
        for(int i = 0;i < nums.size();i++){
            int id = mapint[nums[i]];
            if(id == 0){
                mapint[nums[i]] = i + 1;    //��������ֵ���±��1 ��Ϊ0��ʾû�����Ԫ��
            }
            else if(i - id < k)    return true;
            else{
                mapint[nums[i]] = i + 1;    //�����ͬԪ���±�Ĳ����k��Ҫ�ú�����±����ǰ���
            }
        }
        return false;
    }
};

//�������� �ӽ����������Ҫ��һЩ �����Ӷ���ʵ��һ����
struct state
{
    int val,id;
    bool operator<(const state &rhs)const{
        if(val != rhs.val)  return val < rhs.val;
        return id < rhs.val;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        state *a = new state[n];
        for(int i = 0;i < n;i++){
            a[i].val = nums[i];
            a[i].id = i;
        }
        sort(a,a+n);
        for(int i = 1;i < n;i++){
            if(a[i].val == a[i-1].val && a[i].id - a[i-1].id <= k){
                delete [] a;
                return true;
            }
        }
        delete [] a;
        return false;
    }
};
