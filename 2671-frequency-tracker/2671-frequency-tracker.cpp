class FrequencyTracker {
public:
    map<int,int> mp;
    map<int,int> freq;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int x= mp[number];
        mp[number]++;
        
        freq[x]--;
        freq[x+1]++;
        
    }
    
    void deleteOne(int number) {
        
        if(mp.find(number) !=mp.end()){
            freq[mp[number]]--;
            mp[number]--;
            freq[mp[number]]++;
            if(mp[number]==0){
                mp.erase(number);
            }
        }
      
    }
    
    bool hasFrequency(int frequency) {
        
        if(freq[frequency]>0){
            return true;
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */