class Solution {
public:
    int convertTime(string current, string correct) {
        
        int x1=(current[0]-'0')*10+(current[1]-'0');
        int x2=(correct[0]-'0')*10+(correct[1]-'0');
        
        int y1=(current[3]-'0')*10+(current[4]-'0');
         int y2=(correct[3]-'0')*10+(correct[4]-'0');
        
        int ans=((x2-x1)*60)+(y2-y1);
        
        int fans=0;
        vector<int> a={60,15,5,1};
        int idx=0;
        while(ans>0){
            
            fans+=(ans/a[idx]);
            
            ans=ans%a[idx];
            idx++;
        }
        return fans;
    }
};