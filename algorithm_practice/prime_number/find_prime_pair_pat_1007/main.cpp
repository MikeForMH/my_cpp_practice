//
//  main.cpp
//  find_prime_pair_pat_1007
//
//  Created by Michael Hui on 22/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <cstring>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void eratosthenes_sieve(const int &input_n){
    bool is_prime[100001];
    memset(is_prime, true, 100001);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i <= input_n; ++i){
        if(is_prime[i]){
            for(int j = i * 2; j <= input_n; j += i){
                is_prime[j] = false;
            }
        }
    }
    vector <int> prime;
    for(int i = 2; i <= input_n; ++i){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }
    int count = 0;
    for(size_t i = 1; i < prime.size(); ++i){
        if(prime[i] - prime[i - 1] == 2){
            ++count;
        }
    }
    cout << count << endl;
    return;
}

int main(){
    int n;
    cin >> n;
    eratosthenes_sieve(n);
    return 0;
}
