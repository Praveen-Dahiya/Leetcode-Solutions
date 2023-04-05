class Solution {
public:
    bool canDo(vector<int> nums,int mi){
        
        long long carry=0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            
            
            if(nums[i]>mi){
                carry+=(nums[i]-mi);
                nums[i]=mi;
               
            }else{
                
                if((carry+nums[i])>mi){
                    
                    carry-=(mi-nums[i]);
                    nums[i]=mi;
                   
                }else{
                    nums[i]=nums[i]+carry;
                    carry=0;
                }
            }
        }
        
        // cout<<mi<<"-->";
        // cout<<carry<<"\n";
      if(carry>0) return false;
      
        return true;
        
    }
    int minimizeArrayValue(vector<int>& nums) {
        int si=0;
        int ei=*max_element(nums.begin(),nums.end());
        int ans=ei;
        
        while(si<=ei){
            
            
            
            int mi=si+((ei-si)/2);
            
            if(canDo(nums,mi)){
                ans=mi;
                ei=mi-1;
            }else{
                si=mi+1;
            }
            
        }
        return ans;
    }
};