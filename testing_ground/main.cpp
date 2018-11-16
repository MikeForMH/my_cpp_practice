//
//  main.cpp
//  testing_ground
//
//  Created by Michael Hui on 16/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int n;
    vector <int> array;
    for (int i = 0; i < 3; ++i){
        cin >> n;
        array.push_back(n);
    }
    for (int i = 0; i < 3; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
