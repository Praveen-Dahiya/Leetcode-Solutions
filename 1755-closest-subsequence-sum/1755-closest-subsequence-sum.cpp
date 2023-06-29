class Solution {
public:
    void cmp(vector<int> &a1,vector<int> &a2,int &ans,int goal){
        for(int i=0;i<a1.size();i++){
            
            int si=0;
            int ei=a2.size()-1;
            int ans1=-1;
            while(si<=ei){
                int mi=(si+ei)/2;
                
                int f=goal-a1[i];
                
                if(a2[mi]<=f){
                    ans1=a2[mi];
                    si=mi+1;
                }else{
                    ei=mi-1;
                }
                
                
            }
            if(ans1 !=-1){
                ans=min(ans,abs(goal-a1[i]-ans1));
            }
            // cout<<a1[i]<<" "<<ans1<<"\n";

             int ans2=-1;
            si=0;
            ei=a2.size()-1;
            while(si<=ei){
                int mi=(si+ei)/2;
                
                int f=goal-a1[i];
                
                if(a2[mi]>=f){
                    ans2=a2[mi];
                    ei=mi-1;
                }else{
                    si=mi+1;
                }
                
                
            }
            if(ans2 !=-1){
                ans=min(ans,abs(goal-a1[i]-ans2));
            }
             // cout<<a1[i]<<" "<<ans2<<"\n";
        }
    }
    vector<int> a1,a2;
    void allPossible(vector<int>& nums,vector<int>& a,int idx,int e,int sum){
        
        if(idx>=e){
            a.push_back(sum);
            return;
        }
        
        allPossible(nums,a,idx+1,e,sum+nums[idx]);
        allPossible(nums,a,idx+1,e,sum);
        
        
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int ans=1e9;
        allPossible(nums,a1,0,(nums.size()+1)/2,0);
        allPossible(nums,a2,((nums.size()+1)/2),nums.size(),0);
         sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        // for(auto &x:a1){
        //         cout<<x<<" ";
        // }
        // cout<<"\n";
        // for(auto &x:a2){
        //         cout<<x<<" ";
        // }
        // cout<<"\n";
        cmp(a1,a2,ans,goal);
        // cout<<"\n";
        // cmp(a2,a1,ans,goal);
        
        
        
        return ans;
    }
};