// Last updated: 06/07/2026, 12:01:11
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<char,string> m = {
            {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
            {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
        };
        function<void(int, string)> back = [&](int i, string curstr) {
            if (curstr.size() == digits.size()) {
                res.push_back(curstr);
                return;
            }
            for (char c : m[digits[i]]) {
                back(i + 1, curstr + c);
            }
        };
        if(digits.empty())return{};
        back(0,"");
        return res;
    }
};