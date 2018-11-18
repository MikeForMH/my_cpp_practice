//
//  main.cpp
//  find_nth_small_number
//
//  Created by Michael Hui on 19/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

int find_nth_small_number(const int &length, const int &nth_number){
    int *array = new int [length];
    int input_element;
    for (int i = 0; i < length; i++){
        cin >> input_element;
        array[i] = input_element;
    }
    sort(array, array + length);
    int return_value = array[nth_number - 1];
    delete [] array;
    return return_value;
}

int main(){
    int length, nth_number;
    cin >> length >> nth_number;
    cout << find_nth_small_number(length, nth_number) << endl;
    return 0;
}

