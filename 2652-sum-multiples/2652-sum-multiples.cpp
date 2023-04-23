class Solution {
public:
    int sumOfMultiples(int n) {
        
        
        int ans=0;
        
        for(int i=1;i<=n;i++){
            
            bool f=false;
            
            if(i%3==0) f=true;
            if(i%5==0) f=true;
            if(i%7==0) f=true;
            
                if(f)
                ans+=i;
        }
        return ans;
    }
};