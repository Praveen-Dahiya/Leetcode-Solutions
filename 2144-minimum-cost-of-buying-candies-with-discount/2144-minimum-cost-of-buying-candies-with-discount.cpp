class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        
        // if(cost.size()<3){
        //     int sum=0;
        //     for(auto &x:cost) sum+=x;
        //     return sum;
        // }
        int ans=0;
        // for(auto &x:cost){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        for(int i=1;i<(cost.size()/3)*3;i+=3){
            ans+=cost[i]+cost[i-1];
        }
        cout<<ans<<" ";
        int idx=(cost.size()/3)*3;
        // cout<<idx<<" ";
        while(idx<cost.size()){
            ans+=cost[idx];
            idx++;
        }
        return ans;
    }
};