//
//  main.cpp
//  find_nth_prime_pat_1013
//
//  Created by Michael Hui on 25/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
# include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sqrt;

void output_prime_from_ath_to_bth(const int &a, const int &b){
    vector <int> prime;
    prime.push_back(2);
    int i = 3;
    while(prime.size() < b){
        bool prime_flag = true;
        float sqrt_of_i = sqrt(i);
        for(int var: prime){
            if(i % var == 0){
                prime_flag = false;
                break;
            }
            else if(var > sqrt_of_i){
                break;
            }
        }
        if(prime_flag){
            prime.push_back(i);
        }
        ++i;
    }
    i = a;
    while(i <= b){
        for(int j = 0; j < 10; ++j){
            if(i > b){
                break;
            }
            if(j != 0){
                cout << " ";
            }
            cout << prime[i - 1];
            ++i;
        }
        cout << endl;
    }
    return;
}

int main(){
    int m, n;
    cin >> m >> n;
    output_prime_from_ath_to_bth(m, n);
    return 0;
}
