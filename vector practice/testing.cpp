//
//  testing.cpp
//  vector practice
//
//  Created by Michael Hui on 9/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

//#include <stdio.h>
# include <iostream>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
    int number_of_integers, input_integer, integer_to_be_eraded, remaining_integers;
    vector <int> array;
    cin >> number_of_integers;
    remaining_integers = number_of_integers;
    for (int i = 0; i < number_of_integers; ++i){
        cin >> input_integer;
        array.push_back(input_integer);
    }
    cin >> integer_to_be_eraded;
    for (int i = 0; i < number_of_integers; ++i){
        if (array[i] == integer_to_be_eraded){
            --remaining_integers;
        }
    }
    cout << remaining_integers << endl;
    return 0;
}
