class ParkingSystem {
public:
    int bigslot = 0, smallslot =  0, medslot = 0;
    ParkingSystem(int big, int medium, int small) {
        bigslot = big, medslot = medium, smallslot = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1 && bigslot > 0) {
            bigslot--;
            return 1;
        } else if (carType == 2 && medslot > 0) {
            medslot-- ;
            return 1;
        } else if (carType == 3 && smallslot > 0) {
            smallslot--;
            return 1;
        }
        return 0;
    }
};