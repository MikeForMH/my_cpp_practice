//
//  main.cpp
//  template_practice_1
//
//  Created by Michael Hui on 13/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <class T>
class Array{
private:
    T *member_array;
    int simulated_iterator = 0;
    int number_of_elements = 0;
public:
    Array (int element_numbers);
    void insert(const T &input_element);
    void showAll();
};

template <class T> Array <T>::Array(int element_numbers){
    member_array = new T [element_numbers];
    number_of_elements = element_numbers;
}

template <class T> void Array <T>::insert(const T &input_element){
    if (simulated_iterator < number_of_elements){
        member_array[simulated_iterator] = input_element;
        simulated_iterator++;
        return;
    }
    else {
        cout << "array full" << endl;
        return;
    }
}

template <class T> void Array <T>::showAll(){
    for (int i = 0; i < number_of_elements; ++i){
        cout << member_array[i] << endl;
    }
    return;
}


int main() {
    string str1="yangzhou301";
    Array<char> arr1(str1.length());
    for(auto c:str1)
    {
        arr1.insert(c);
    }
    arr1.showAll();
    int num[]={1,9,2,6,0,8,1,7};
    Array<int>arr2(sizeof(num)/sizeof(int));
    for(auto c:num)
    {
        arr2.insert(c);
    }
    arr2.showAll();
    arr2.insert(301);
    return 0;
}

