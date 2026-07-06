// Last updated: 06/07/2026, 12:00:40
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> nums;
        for(int i=1; i<=n; i++){
            nums.push_back(to_string(i));
        }
        string res=""; k = k-1;
        int f = fact(n-1);
        while(true){
            res = res + nums[k/f];
            nums.erase(nums.begin()+ (k/f));
            if(nums.size() == 0) break;
            k = k%f; f = f/nums.size();
        }
        return res;
    }
    int fact(int n){
        int res=1;
        while(n!=0){
            res *= n; n--;
        }
        return res;
    }
};