// Last updated: 06/07/2026, 11:58:39
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long res,psum=0,csum=0;
        vector<int> prime,composite;
        for(int i=0;i<nums.size();i++){
            int flag = isprime(i);
            if(flag) prime.push_back(nums[i]);
            else composite.push_back(nums[i]);
        }
        for(int i=0;i<prime.size();i++){
            psum += (long) prime[i];
        }
        for(int i=0;i<composite.size();i++){
            csum += (long) composite[i];
        }
        res=abs(csum-psum);
        return res;
    }
    int isprime(int x){
        if(x==2) return 1;
        if(x<=1 || x%2 == 0) return 0;
        for(int i=3; i <= sqrt(x);i += 2){
            if (x%i == 0) return 0;
        }
        return 1;
    }
};