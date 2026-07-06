// Last updated: 06/07/2026, 11:58:09
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> mx(nums.size()); vector<int> prefixgcd(nums.size());
        mx[0] = nums[0];

        // computing mx vector
        for(int i=1; i<nums.size(); i++){
            mx[i] = ( max(mx[i-1], nums[i]) );
        }

        // computing gcd vector
        for(int i=0; i<nums.size(); i++){
            prefixgcd[i] = gcd(nums[i],mx[i]);
        } // sorting the gcd vector
        sort(prefixgcd.begin(),prefixgcd.end());

        vector<pair<int,int>> p; int l=0,r=nums.size()-1;
        while(l<r){
            p.push_back({ prefixgcd[l],prefixgcd[r] }); l++; r--;
        } long long res=0;
        for(auto i:p){
            res += gcd(i.first,i.second);
        }
        return res;
    }
    int gcd(int a,int b){
        while(b!=0){
            int temp = b;
            b = a%b; a = temp;
        }
        return a;
    }
};