//
//  main.cpp
//  fibonacci_3
//
//  Created by Michael Hui on 13/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>

using std::cin;
using std::cout;
using std::endl;

int find_fibonacci(const int &N){
    if (N == 1){
        return 1;
    }
    else if (N == 2){
        return 2;
    }
    int *array = new int [N];
    array[0] = 1;
    array[1] = 2;
    for (int i = 2; i < N; ++i){
        array[i] = array[i - 1] + array[i - 2];
    }
    return array[N - 1];
}

int main(){
    int N;
    cin >> N;
    cout << find_fibonacci(N) << endl;
    return 0;
}
