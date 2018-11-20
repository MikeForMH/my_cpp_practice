//
//  main.cpp
//  sequent_list_practice_3
//
//  Created by Michael Hui on 20/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::pow;

int main(){
    int number_of_terms = 0, x_variable = 0, coefficient = 0, index = 0, length = 0;
    int *coefficient_list, *index_list;
    cin >> number_of_terms;
    coefficient_list = new int [number_of_terms];
    index_list = new int [number_of_terms];
    for (int i = 0; i < number_of_terms; ++i){
        cin >> coefficient >> index;
        if (coefficient == 0){
            continue;
        }
        coefficient_list[length] = coefficient;
        index_list[length] = index;
        ++length;
    }
    cin >> x_variable;
    int result = 0;
    for (int i = 0; i < length; ++i){
        result += coefficient_list[i] * static_cast <int> (pow(x_variable, index_list[i]));
    }
    cout << result << endl;
    delete [] coefficient_list;
    delete [] index_list;
    return 0;
}
