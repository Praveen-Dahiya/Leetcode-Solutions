class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<salary.size();i++)
        {
            mx=max(mx,salary[i]);
            mn=min(mn,salary[i]);
            sum+=salary[i];
        }
        sum=sum-mx-mn;
        return sum/(salary.size()-2);
    }
};