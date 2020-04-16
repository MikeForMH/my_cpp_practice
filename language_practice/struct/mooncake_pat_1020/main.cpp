//
//  main.cpp
//  mooncake_pat_1020
//
//  Created by Michael Hui on 2/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <iomanip>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::setprecision;
using std::fixed;
using std::vector;
# define MAX 1000

struct Mooncake{
    double _total_stock;
    double _total_value;
    double _unit_price;
};

void price_sorting(vector <Mooncake> &input_list, vector <Mooncake> &temp, const int &left, const int &right){
    if(left == right){
        return;
    }
    int mid = (left + right) / 2;
    price_sorting(input_list, temp, left, mid);
    price_sorting(input_list, temp, mid + 1, right);
    int x = left, y = mid + 1, loc = left;
    while(x <= mid || y <= right){
        if(x <= mid && (y > right || input_list[x]._unit_price >= input_list[y]._unit_price)){
            swap(temp[loc], input_list[x]);
            ++x;
        }
        else{
            swap(temp[loc], input_list[y]);
            ++y;
        }
        ++loc;
    }
    for(int i = left; i <= right; ++i){
        swap(temp[i], input_list[i]);
    }
    return;
}

int main(){
    int n;
    double demand, input;
    cin >> n >> demand;
    vector <Mooncake> product_list(MAX), temp(MAX);
    for(int i = 0; i < n; ++i){
        cin >> input;
        product_list[i]._total_stock = input;
    }
    for(int i = 0; i < n; ++i){
        cin >> input;
        product_list[i]._total_value = input;
        product_list[i]._unit_price = product_list[i]._total_value / product_list[i]._total_stock;
    }
    price_sorting(product_list, temp, 0, n - 1);
    double result = 0;
    for(int i = 0; demand > 0 && i < n; ++i){
        if(product_list[i]._total_stock == 0){
            continue;
        }
        if(product_list[i]._total_stock < demand){
            result += product_list[i]._total_value;
            demand -= product_list[i]._total_stock;
            continue;
        }
        else{
            result += product_list[i]._unit_price * demand;
            demand = 0;
            continue;
        }
    }
    cout << fixed << setprecision(2) << result << endl;
    return 0;
}
