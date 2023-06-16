class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        map<int,int> mp;
        int f=n;
        for(int i=0;i<n;i++){
            int idx=-1;
            for(int j=0;j<n;j++){
                if(arr[j]==f){
                    idx=j;
                }
            }
            f--;
            
            reverse(arr.begin(),arr.begin()+idx+1);
            ans.push_back(idx+1);
            ans.push_back(arr[0]);
            reverse(arr.begin(),arr.begin()+arr[0]);
            
        }
        return ans;
    }
};