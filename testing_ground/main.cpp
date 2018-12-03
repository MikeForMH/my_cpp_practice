//
//  main.cpp
//  testing_ground
//
//  Created by Michael Hui on 16/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int result = static_cast <int> (floor(log(N)/log(2)));
    cout << result << endl;
    return 0;
}
