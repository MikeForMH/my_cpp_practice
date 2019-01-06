//
//  main.cpp
//  find_element_with_no_repetion
//
//  Created by Michael Hui on 12/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <algorithm>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::count;
using std::vector;
using std::remove;

int find_element_with_no_repetion(vector <int> &number_array, int &number_of_integers){
    int processing_element;
    while (number_of_integers > 1){
        processing_element = number_array[0];
        if (count(number_array.begin(), number_array.end(), processing_element) > 1){
            remove(number_array.begin(), number_array.end(), processing_element);
            number_of_integers -= 3;
        }
        else{
            return processing_element;
        }
    }
    return number_array[0];
}

int main(){
    int number_of_integer = 0, input_number = 0;
    vector <int> number_array;
    cin >> number_of_integer;
    for (int i = 0; i < number_of_integer; i++){
        cin >> input_number;
        number_array.push_back(input_number);
    }
    cout << find_element_with_no_repetion(number_array, number_of_integer) << endl;
    return 0;
}
