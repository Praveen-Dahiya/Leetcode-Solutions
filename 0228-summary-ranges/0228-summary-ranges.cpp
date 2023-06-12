class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        int si=0;
        int ei=0;
        vector<string> ans;
        for(int i=1;i<nums.size();i++){
            
            if((nums[i-1]+1)==nums[i]){
                ei=i;
            }else{
                if(si==ei){
                    string s="";
                    s+=to_string(nums[si]);
                    ans.push_back(s);
                }else{
                    string s="";
                    s+=to_string(nums[si]);
                    s+="->";
                     s+=to_string(nums[ei]);
                    ans.push_back(s);
                   
                }
                 si=i;
                    ei=i;
            }
            // cout<<si<<" "<<ei<<"\n";
        }
        if(si==ei){
                    string s="";
                    s+=to_string(nums[si]);
                    ans.push_back(s);
                }else{
                    string s="";
                    s+=to_string(nums[si]);
                    s+="->";
                     s+=to_string(nums[ei]);
                    ans.push_back(s);
                  
                }
        return ans;
    }
};