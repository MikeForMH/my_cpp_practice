//
//  main.cpp
//  get_sum_of_array_xuetangx_c9_1
//
//  Created by Michael Hui on 2/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

#include <iostream>
using namespace std;

/*请在这里填充代码*/
template <typename T> T getSum(const T *input_array, const int &count){
    T result = 0;
    for(int i = 0; i < count; ++i){
        result += input_array[i];
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int* arr_int = new int[n];
    double* arr_double = new double[m];
    for (int i = 0; i < n; ++i)
        cin >> arr_int[i];
    for (int i = 0; i < m; ++i)
        cin >> arr_double[i];
    cout << getSum(arr_int, n) << endl;
    cout << getSum(arr_double, m) << endl;
    return 0;
}
