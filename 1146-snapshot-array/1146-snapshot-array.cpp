class SnapshotArray {
public:
    
    int snap_id;
    
    vector<vector<pair<int, int>>> a;
    
    SnapshotArray(int length) {
        snap_id = 0;
        
        a.resize(length);
        
        for(int i = 0; i < length; i++) {
            
            a[i].push_back({0, 0});
            
        }
    }
    
    void set(int index, int val) {
        
        a[index].push_back({snap_id, val});
        
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        
        int si = 0, ei = a[index].size()-1;

        int ans = 0;
        while(si <= ei) {
            
            int mid = (ei+si)/2;
            
            if(a[index][mid].first <= snap_id) {
                ans = a[index][mid].second;
                si = mid+1;
            } else {
                ei = mid-1;
            }
            
        }
        
        return ans;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */