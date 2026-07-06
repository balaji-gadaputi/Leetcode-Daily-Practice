// Last updated: 06/07/2026, 12:01:15
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> m={
            {"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000},{"IV",4},{"XL",40},{"IX",9},{"XC",90},{"CD",400},{"CM",900}
        };
        int index=0,num=0;
        while(index<s.size()){
            string temp=s.substr(index,2);
            if(m.find(temp) != m.end()){
                num += m[temp]; index += 2;
            }
            else{
                string t(1,s[index]);
                num += m[t]; index++;
            }  
        }
        return num;
    }
};