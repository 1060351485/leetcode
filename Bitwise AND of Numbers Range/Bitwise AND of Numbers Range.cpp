/*
    ��ϸ��������ֻҪ��m��n����߲�ͬλbit�Ϳ�����
    ��Ϊn��m֮��һ�������һ��0~bit-1λ����0����
    ��ô�𰸾���bitλ���µĶ���0��bitλ���ϵĺ�m,nһ��
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bit = 0;
        while(m != n){
            m = m >> 1;
            n = n >> 1;
            bit++;
        }
        return m << bit;
    }
};
