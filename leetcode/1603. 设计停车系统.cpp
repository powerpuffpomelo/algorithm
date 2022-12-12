// ###################################################### 版本1 ###################################################### //
// 我的初版
class ParkingSystem {
public:
    vector<int> park;
    ParkingSystem(int big, int medium, int small) {
        park = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(park[carType - 1] > 0){
            park[carType - 1]--;
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