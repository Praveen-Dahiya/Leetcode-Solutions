class Solution {
public:
    
    
     int dp[100001][2];
    int stock(vector<int>& prices,int idx,bool purchased,int fee) {
        
        if(idx==prices.size()){
            return 0;
        }
        int x=0;
        int y=0;
        int z=0;
        int a=0;
        
       
        
        if(dp[idx][purchased] !=-1){
            return dp[idx][purchased];
        }
        
        if(purchased==true){
            
            
              
                
                  x= -fee+prices[idx]+stock(prices,idx+1,false,fee);//selling
            
          
            y=stock(prices,idx+1,purchased,fee);//no selling
            
        }else{
            z= -prices[idx]+stock(prices,idx+1,true,fee);//purchase
            a= stock(prices,idx+1,false,fee);// no purchase
           
        }
        // cout<<idx<<" "<<x<<" "<<y<<" "<<z<<" "<<a<<"\n";
        
        
        return dp[idx][purchased]=max(dp[idx][purchased],max(max(x,y),max(z,a)));
        
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        
        return stock(prices,0,false,fee);
    }
};