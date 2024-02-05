#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Car {
public:
    string model;
    string licensePlate;
    bool isRented;

    Car(string m, string lp) : model(m), licensePlate(lp), isRented(false) {}
};

class CarRentalSystem {
private:
    vector<Car> cars;

public:
    void addCar(string model, string licensePlate) {
        cars.push_back(Car(model, licensePlate));
    }

    void displayAvailableCars() {
        cout << "Available Cars:" << endl;
        cout << setw(15) << "Model" << setw(15) << "License Plate" << endl;
        cout << "-----------------------------------" << endl;

        for (const auto& car : cars) {
            if (!car.isRented) {
                cout << setw(15) << car.model << setw(15) << car.licensePlate << endl;
            }
        }
    }

    void rentCar(string licensePlate) {
        for (auto& car : cars) {
            if (car.licensePlate == licensePlate && !car.isRented) {
                car.isRented = true;
                cout << "Car rented successfully!" << endl;
                return;
            }
        }
        cout << "Car not available for rent." << endl;
    }

    void returnCar(string licensePlate) {
        for (auto& car : cars) {
            if (car.licensePlate == licensePlate && car.isRented) {
                car.isRented = false;
                cout << "Car returned successfully!" << endl;
                return;
            }
        }
        cout << "Invalid license plate or car not rented." << endl;
    }
};

int main() {
    CarRentalSystem rentalSystem;

    rentalSystem.addCar("Toyota Camry", "ABC123");
    rentalSystem.addCar("Honda Accord", "XYZ789");

    rentalSystem.displayAvailableCars();

    rentalSystem.rentCar("ABC123");

    rentalSystem.displayAvailableCars();

    rentalSystem.returnCar("ABC123");

    rentalSystem.displayAvailableCars();

    return 0;
}
