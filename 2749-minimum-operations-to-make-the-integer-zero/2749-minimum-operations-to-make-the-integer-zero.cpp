class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1==0){
            return 0;
        }
        if(num1<num2) return -1;
        int ans=-1;
        for(int ops = 1;ops<=1e5;ops++){
            
            long long n=num1-((long long)ops*(long long)num2);
            long long times= __builtin_popcountll(n);
            if(ops>=times &&  ops<=n ){
                ans=ops;
                break;
            }
        
            
        }
        // cout<<"\n";
        return ans;
    }
};