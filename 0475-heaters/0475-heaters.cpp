class Solution {
public:
    bool canDo(vector<int>& houses, vector<int>& heaters,int mid){
        int idx=0;
        
        
        for(int i=0;i<houses.size();i++){
            
            if(abs(houses[i]-heaters[idx]) >mid){
                idx++;
                
                while(idx<heaters.size() && abs(houses[i]-heaters[idx]) >mid){
                    idx++;
                }
                if(idx>=heaters.size()){
                    return false;
                }
            }
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int si=0;
        int ei=1e9;
        int ans=-1;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        while(si<=ei){
            int mi=(si+ei)/2;
            if(canDo(houses,heaters,mi)){
                ans=mi;
                ei=mi-1;
            }else{
                si=mi+1;
            }
            
        }
        return ans;
    }
};