//
//  main.cpp
//  first_missing_positive_number
//
//  Created by Michael Hui on 20/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//
//  interestingly, the input_number of this question is not larger than 100 :3 // jisuanke

# include <iostream>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
    bool input_array[101] = {0};
    int n, input_number;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input_number;
        if(input_number > 0){
            input_array[input_number] = true;
        }
    }
    for(int i = 1;; ++i){
        if(!input_array[i]){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
