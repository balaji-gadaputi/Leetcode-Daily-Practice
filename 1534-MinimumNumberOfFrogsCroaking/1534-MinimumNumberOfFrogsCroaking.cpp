// Last updated: 06/07/2026, 11:58:52
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string &frogs=croakOfFrogs;
        int c=0,r=0,o=0,a=0,k=0,maxfrogs=0,currfrog=0;
        for(auto i:frogs){
            switch (i){
                case 'c': c++; currfrog++; maxfrogs=max(maxfrogs,currfrog);break;
                case 'r': if(c==0) return -1; c--; r++;break;
                case 'o': if(r==0) return -1; r--; o++;break;
                case 'a': if(o==0) return -1; o--; a++;break;
                case 'k': if(a==0) return -1; a--; currfrog--;break;
            }
        }
        if(c||r||o||a) return -1;
        return maxfrogs;
    }
};