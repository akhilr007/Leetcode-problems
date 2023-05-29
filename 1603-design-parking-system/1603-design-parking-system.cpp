class ParkingSystem {
public:
    int bigParkingSpace;
    int mediumParkingSpace;
    int smallParkingSpace;
    
    ParkingSystem(int big, int medium, int small) {
        bigParkingSpace = big;
        mediumParkingSpace = medium;
        smallParkingSpace = small;
    }
    
    bool addCar(int carType) {
        
        if(carType == 1){
            // big
            if(bigParkingSpace)
            {
                bigParkingSpace -= 1;
                return true;
            }
            return false;
        }
        else if(carType == 2){
            // medium
            if(mediumParkingSpace)
            {
                mediumParkingSpace -= 1;
                return true;
            }
            return false;
        }
        else{
            // small
            if(smallParkingSpace)
            {
                smallParkingSpace -= 1;
                return true;
            }
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */