//
//  main.cpp
//  pat_1037
//
//  Created by Michael Hui on 10/3/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;


struct amount{
    int Kunt = 0;
    int Sickle = 0;
    int Galleon = 0;
    int total_Kunt = 0;
};

string find_change(amount &price, amount &paid){
    string result;
    amount change;
    price.total_Kunt = (price.Galleon * 17 + price.Sickle) * 29 + price.Kunt;
    paid.total_Kunt = (paid.Galleon * 17 + paid.Sickle) * 29 + paid.Kunt;
    change.total_Kunt = paid.total_Kunt - price.total_Kunt;
    change.Kunt = change.total_Kunt % 29;
    change.Sickle = change.total_Kunt / 29;
    change.Galleon = change.Sickle / 17;
    change.Sickle = change.Sickle % 17;
    if(change.total_Kunt < 0){
        change.Sickle *= -1;
        change.Kunt *= -1;
    }
    result = to_string(change.Galleon) + '.' + to_string(change.Sickle) + '.' + to_string(change.Kunt);
    return result;
}

int main(){
    amount price, paid;
    string input_price, input_paid;
    cin >> input_price >> input_paid;
    price.Galleon = stoi(input_price);
    input_price = input_price.substr(input_price.find('.') + 1);
    price.Sickle = stoi(input_price);
    input_price = input_price.substr(input_price.find('.') + 1);
    price.Kunt = stoi(input_price);
    
    paid.Galleon = stoi(input_paid);
    input_paid = input_paid.substr(input_paid.find('.') + 1);
    paid.Sickle = stoi(input_paid);
    input_paid = input_paid.substr(input_paid.find('.') + 1);
    paid.Kunt = stoi(input_paid);
    
    //cout << price.Galleon << " " << price.Sickle << " " << price.Kunt << endl;
    //cout << paid.Galleon << " " << paid.Sickle << " " << paid.Kunt << endl;
    
    cout << find_change(price, paid) << endl;
    return 0;
}
