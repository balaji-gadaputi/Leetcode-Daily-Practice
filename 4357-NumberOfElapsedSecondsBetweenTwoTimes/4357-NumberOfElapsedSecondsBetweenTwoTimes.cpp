// Last updated: 15/07/2026, 10:38:06
class Solution {
    /*
    hh : mm : ss
    01 2 34 5 67
*/
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        long long start=0, end=0;
        int sh = stoi( startTime.substr(0,2) );
        int sm = stoi( startTime.substr(3,2) );
        int ss = stoi( startTime.substr(6,2) );
        start = 1LL * ( (sh * 60 * 60) + (sm*60) + ss);
        
        int eh = stoi( endTime.substr(0,2) );
        int em = stoi( endTime.substr(3,2) );
        int es = stoi( endTime.substr(6,2) );

        end = 1LL * ( (eh * 60 * 60) + (em*60) + es);
        return (int)end - start;
    }
};