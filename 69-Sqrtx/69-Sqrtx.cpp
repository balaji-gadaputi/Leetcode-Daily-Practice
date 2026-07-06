// Last updated: 06/07/2026, 12:00:33
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int high=x/2, low=1, ans=-1;
        while(high>=low){
            int mid=low + (high-low)/2;
            long long product = 1LL*mid*mid;
            if(product == x){return mid;}
            else if(product > x){high = mid-1;}
            else if(product < x){ans=mid; low = mid+1;}
        }
        return ans;
    }
};