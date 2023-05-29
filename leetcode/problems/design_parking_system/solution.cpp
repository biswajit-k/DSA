class ParkingSystem {
public:

    int space[3];

    ParkingSystem(int big, int medium, int small) {
        space[0] = big;
        space[1] = medium;
        space[2] = small;
    }
    
    bool addCar(int type) {
        if(space[type - 1])
        {
            space[type - 1]--;
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