#include <iostream>
using namespace std;

// Set fuel economy
// set full tank
// ask for distance and give remaining fuel
// give a warning if fuel goes below approx. 10%

const float fuel_econ = 12.0; // 17 km/L  
float tank_cap = 40.0;        // 60 Liters               
const float fuel_price = 280;

void fuel_gauge(float tank_cap){
    for(int i = 1;i <= (tank_cap/5); i++ ){
        cout << "|";
    }
    cout << endl;
    cout << "Fuel Remaining: " << tank_cap << "L" << endl;   
}

void refuel(){
    float cost;
    cout << "*** Fuel Price ***" << endl;
    cout << fuel_price << "Rs/L" << endl;
    cout << "How much fuel would you like: "; cin >> cost;
    tank_cap += (cost/fuel_price);
    if (tank_cap > 40){
        tank_cap = 40;
    }
    fuel_gauge(tank_cap);
    cout << "Refill Successful" << endl;
}

void warning(){
    char choice;
    cout << "LOW FUEL! Kindly Refuel" << endl;
    cout << "Do you want to refuel: "; cin >> choice;
    if (choice == 'y' || choice == 'Y'){
        refuel();
    }
}

void journey(){
    bool cont = true;
    char ch;
    float distance, req_fuel;
    fuel_gauge(tank_cap);
    while (cont == true){
        cout << "Enter distance you want to travel: ";
        cin >> distance;
        req_fuel = distance/fuel_econ;
        tank_cap -= req_fuel;
        fuel_gauge(tank_cap);
        if (tank_cap <= 4){
            warning();
        }
        cout << "Continue Journey OR Refuel OR Stop(c,r,s): \n c (Continue), r (Refuel), s (Stop): "; 
        cin >> ch;
        switch (ch){
            case 'y':
                cont = true;
                break;
            case 'r':
                refuel();
                break;
            case 's':
                cont = false;
                break;
        }   
    }   
}
int main(){
    journey();
    return 0;
}
