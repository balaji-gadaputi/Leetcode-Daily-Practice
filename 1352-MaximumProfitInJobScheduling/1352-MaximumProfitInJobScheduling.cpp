// Last updated: 06/07/2026, 11:58:53
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        vector<int> result;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1];});
        
        result.push_back(weighted_interval_scheduling(jobs));

        return result[0];
    }
    int weighted_interval_scheduling(vector<vector<int>> &jobs){
        int n=jobs.size();
        vector<int> dp(n,0);
        dp[0]=jobs[0][2];
        for(int i=1; i<n; i++){
            int includeprofit=jobs[i][2];
            int low=0, high=n-1, index=-1;
            while(low<=high){
                int mid= (low+high)/2;
                if(jobs[mid][1]<=jobs[i][0]){
                    index=mid; low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            if(index != -1){
                includeprofit += dp[index];
            }
            dp[i]=max(dp[i-1],includeprofit);
        }
        return dp[n-1];
    }
};