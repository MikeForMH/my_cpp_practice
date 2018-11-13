//
//  main.cpp
//  jumping_in_array
//
//  Created by Michael Hui on 13/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

string can_i_jump_to_last(vector <int> &array){
    int number_of_elements = array.size();
}

int main(){
    int number_of_elements, input_element;
    cin >> number_of_elements;
    vector <int> array;
    while (cin >> input_element){
        array.push_back(input_element);
    }
    cout << can_i_jump_to_last(array) << endl;
    return 0;
}
