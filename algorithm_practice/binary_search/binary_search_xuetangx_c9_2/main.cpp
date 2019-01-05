//
//  main.cpp
//  binary_search_xuetangx_c9_2
//
//  Created by Michael Hui on 5/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
int binSearch(T arr[], int n, T key){
    int low_bound = 0;
    int high_bound = n - 1;
    while(low_bound <= high_bound){
        int mid = (low_bound + high_bound) / 2;
        cout << mid << endl;
        if(key == arr[mid]){
            return mid;
        }
        else if(key > arr[mid]){
            low_bound = mid + 1;
        }
        else{
            high_bound = mid - 1;
        }
    }
    return -1;
};

/*请实现折半查找，并按顺序输出被访问的元素下标*/

int main()
{
    int n, m;
    int key1;
    double key2;
    cin >> n >> m >> key1 >> key2;
    int* arr_int = new int[n];
    double* arr_double = new double[m];
    for (int i = 0; i < n; ++i)
        cin >> arr_int[i];
    for (int i = 0; i < m; ++i)
        cin >> arr_double[i];
    binSearch(arr_int, n, key1);
    binSearch(arr_double, m, key2);
    return 0;
}
