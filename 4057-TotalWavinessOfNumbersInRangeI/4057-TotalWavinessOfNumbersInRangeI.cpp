// Last updated: 06/07/2026, 11:58:33
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0, waviness = 0;
        for(int i=num1; i<=num2; i++){
            waviness = PeakValley(i);
            res += waviness;
        }
        return res;
    }
    int PeakValley(int num){
        vector<int> aux; int waviness=0;
        while(num != 0){
            int dig = num%10; num /= 10;
            aux.push_back(dig);
        }
        if(aux.size()<3) return 0;
        for(int i=aux.size()-2; i>0; i--){
            if(aux[i]>aux[i+1] && aux[i]>aux[i-1]){
                waviness++;
            }
            else if(aux[i]<aux[i+1] && aux[i]<aux[i-1]){
                waviness++;
            }
        }
        return waviness;
    }
};