class Solution {
public:
    int splitNum(int num) {
        
        string s=to_string(num);
        int num2=0;
        int num1=0;
sort(s.begin(),s.end());
        
        for(int i=0;i<s.length();i+=2){
            num1+=(s[i]-'0');
            num1*=10;
        }
        for(int i=1;i<s.length();i+=2){
            num2+=(s[i]-'0');
            num2*=10;
        }
        // cout<<num1<<" "<<num2<<"\n";
        return (num1+num2)/10;
        
    }
};