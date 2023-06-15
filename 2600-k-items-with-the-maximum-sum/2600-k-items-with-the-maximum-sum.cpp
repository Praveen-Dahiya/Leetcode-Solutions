class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        
        int ans=0;
        if(numOnes<=k){
            ans+=numOnes;
            k-=numOnes;
        }else{
            ans+=k;
            k=0;
        }
        // if(k==0) return ans;
        if(numZeros<=k){
            // ans+=numZeros;
            k-=numZeros;
        }else{
            // ans+=k;
            k=0;
        }
        // if(k==0) return ans;
        if(numNegOnes<=k){
            ans-=numNegOnes;
            k-=numNegOnes;
        }else{
            ans-=k;
            k=0;
        }
        return ans;
    }
};