//
//  main.cpp
//  find_set_intersection
//
//  Created by Michael Hui on 22/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
# include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::find;
using std::end;

void print_array(const vector <int> &array){
    cout << array.size() << endl;
    if (array.size() == 0){
        return;
    }
    for (int i = 0; i < array.size(); ++i){
        if (i != 0){
            cout << " ";
        }
        cout << array[i];
    }
    cout << endl;
    return;
}

int find_element(const vector <int> &array, const int &element, const int dynamic_iterator){
    for (int i = dynamic_iterator; i < array.size(); ++i){
        if (array[i] == element){
            return i;
        }
    }
    return -1;
}

int main(){
    int size_1, size_2, temp;
    vector <int> array_1, array_2, result;
    cin >> size_1;
    for (int i = 0; i < size_1; ++i){
        cin >> temp;
        array_1.push_back(temp);
    }
    cin >> size_2;
    for (int i = 0; i < size_2; ++i){
        cin >> temp;
        array_2.push_back(temp);
    }
    if (size_2 > size_1){
        swap(array_1, array_2);
        swap(size_1, size_2);
    }
    int dynamic_iterator = 0;
    for (int i = 0; i < size_2; ++i){
        temp = find_element(array_1, array_2[i], dynamic_iterator);
        if (temp != -1){
            dynamic_iterator = temp;
            result.push_back(array_2[i]);
        }
    }
    print_array(result);
    return 0;
}
