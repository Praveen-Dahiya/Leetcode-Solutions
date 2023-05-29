class ParkingSystem {
public:
    int type1,type2,type3;
    ParkingSystem(int big, int medium, int small) {
        type1=big;
        type2=medium;
        type3=small;
    }
    
    bool addCar(int carType) {
        
        if(carType==1 && type1>0){
            type1--;
            return true;
        }else if(carType==2 && type2>0){
            type2--;
             return true;
        }else if(carType==3 && type3>0){
            type3--;
             return true;
        }
         return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */