class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int ans1=0;
        int ans2=0;
        
        for(int i=0;i<player1.size();i++){
            bool f1=false;
            if((i-1)>=0 && player1[i-1]==10 ){
                f1=true;
            }
            
             if((i-2)>=0 && player1[i-2]==10 ){
                f1=true;
            }
            
            if(f1){
                ans1+=2*player1[i];
            }else{
                ans1+=player1[i];
            }
        }
        
         for(int i=0;i<player2.size();i++){
            bool f1=false;
            if((i-1)>=0 && player2[i-1]==10 ){
                f1=true;
            }
            
             if((i-2)>=0 && player2[i-2]==10 ){
                f1=true;
            }
            
            if(f1){
                ans2+=2*player2[i];
            }else{
                ans2+=player2[i];
            }
        }
        
        if(ans1>ans2){
            return 1;
        }else if(ans1<ans2){
            return 2;
        }
        return 0;
        
        
    }
};