// Last updated: 14/03/2026, 20:47:28
1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        vector<int> mx(nums.size()); vector<int> prefixgcd(nums.size());
5        mx[0] = nums[0];
6
7        // computing mx vector
8        for(int i=1; i<nums.size(); i++){
9            mx[i] = ( max(mx[i-1], nums[i]) );
10        }
11
12        // computing gcd vector
13        for(int i=0; i<nums.size(); i++){
14            prefixgcd[i] = gcd(nums[i],mx[i]);
15        } // sorting the gcd vector
16        sort(prefixgcd.begin(),prefixgcd.end());
17
18        vector<pair<int,int>> p; int l=0,r=nums.size()-1;
19        while(l<r){
20            p.push_back({ prefixgcd[l],prefixgcd[r] }); l++; r--;
21        } long long res=0;
22        for(auto i:p){
23            res += gcd(i.first,i.second);
24        }
25        return res;
26    }
27    int gcd(int a,int b){
28        while(b!=0){
29            int temp = b;
30            b = a%b; a = temp;
31        }
32        return a;
33    }
34};