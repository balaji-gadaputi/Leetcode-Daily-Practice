// Last updated: 06/07/2026, 11:58:54
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,product=1;
        while(n!=0){
            sum=n%10+sum;
            product=n%10*product;
            n=n/10;
        }
        return (product-sum);
    }
};