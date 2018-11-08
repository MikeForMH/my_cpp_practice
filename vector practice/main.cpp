//
//  main.cpp
//  vector practice
//
//  Created by Michael Hui on 7/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <algorithm>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::greater;

bool compare (const int &var1, const int &var2){
    return var1 > var2;
};

int main() {
    vector <int> number_array;
    int input, original_array_size, new_array_size = 0;
    while (cin >> input){
        number_array.push_back(input);
    }
    original_array_size = static_cast <int> (number_array.size());
    sort(number_array.begin(), number_array.end(), greater<int>());
    for (int i = 0, temp = number_array [0] + 1; i < original_array_size; ++i){
        if (number_array [i] < temp){
            cout << number_array [i] << endl;
            temp = number_array [i];
            new_array_size++;
        }
    }
    cout << new_array_size << endl;
    return 0;
}
