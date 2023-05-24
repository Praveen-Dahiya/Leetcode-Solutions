class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int,int> > a;
        
        for(int i=0;i<nums1.size();i++){
            a.push_back({nums2[i],nums1[i]});
        }
        
        sort(a.begin(),a.end());
 
        priority_queue<int> pq;
        long long ans=0;
        long long curans=0;
        for(int i=a.size()-1;i>=0;i--){
            int x=a[i].second;
            if((pq.size()==(k-1))){
                 pq.push(-x);
                  curans+=x;
                 ans=max(ans,curans*a[i].first);
            }else if(pq.size()<k){
                pq.push(-x);
                curans+=x;
            }else {
                 pq.push(-x);
                 curans+=x;
                 curans+=pq.top();
                
                    pq.pop();
                    ans=max(ans,curans*a[i].first);
            }
           
        }
        return ans;
    }
};