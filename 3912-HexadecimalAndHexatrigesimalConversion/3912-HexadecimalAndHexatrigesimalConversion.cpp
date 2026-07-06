// Last updated: 06/07/2026, 11:58:42
class Solution {
public:
    string concatHex36(int n) {
        if(n==0) return "0";
        long long num=1LL * n*n;
        string hexchar="0123456789ABCDEF";
        string hex;
        while(num>0LL){
            int rem=num%16LL;
            hex=hexchar[rem]+hex;
            num=num/16LL;
        }
        num=1LL*n*n*n;
        string hexchartri="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string hextri;
        while(num>0LL){
            int rem=num%36LL;
            hextri=hexchartri[rem]+hextri;
            num=num/36LL;
        }
        string res=hex+hextri;
        return res;
    }
};