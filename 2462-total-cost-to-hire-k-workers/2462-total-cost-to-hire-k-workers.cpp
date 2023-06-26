class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        int n=costs.size();
        int si=0;
        int ei=n-1;
        priority_queue<int> pq1,pq2;
        for(int i=0;i<k;i++){
            while(pq1.size()<candidates && si<=ei){
                pq1.push(-costs[si]);
                si++;
            }
            while(pq2.size()<candidates && si<=ei){
                pq2.push(-costs[ei]);
                ei--;
            }
            long long p1=LLONG_MAX;
            long long p2=LLONG_MAX;
            if(pq1.size()>0){
                p1= -pq1.top();
            }
            if(pq2.size()>0){
                p2= -pq2.top();
            }
        
            if( (p1) <= (p2)){
                ans+=p1;
                pq1.pop();
            }else{
                 ans+=p2;
                pq2.pop();
            }
        }
        return ans;
    }
};