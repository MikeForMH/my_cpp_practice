# include <iostream>
# include <algorithm>
# include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;
using std::to_string;

void who_got_the_biggest_number (int *, int *, int, int);

int main (){
    int participants, rounds;
    cin >> participants >> rounds;
    int *participant_index = new int [participants];
    int *round_index = new int [rounds];
    for (int i = 0; i < participants; ++i){
        cin >> participant_index [i];
    }
    for (int i = 0; i < rounds; ++i){
        cin >> round_index [i];
    }
    who_got_the_biggest_number(participant_index, round_index, participants, rounds);
    return 0;
}

void who_got_the_biggest_number (int *participant_index, int *round_index, int participants, int rounds){
    sort (participant_index, participant_index + participants);
    for (int i = 0; i < rounds; ++i){
        if (participant_index [0] >= round_index [i]){
            cout << participant_index [0];
            if (i != rounds - 1){
                cout << " ";
            }
        }
        else {
            int lower_boundary = 0, upper_boundary = participants - 1, mid_pt = (lower_boundary + upper_boundary) / 2;
            for (;upper_boundary - lower_boundary > 1;){ //participant_index [lower_bounndary] is the required number.
                if (participant_index [mid_pt] > round_index [i]){
                    upper_boundary = mid_pt;
                    mid_pt = (lower_boundary + upper_boundary) / 2;
                }
                else {
                    lower_boundary = mid_pt;
                    mid_pt = (lower_boundary + upper_boundary) / 2;
                }
            }
            cout << participant_index [lower_boundary];
            if (i != rounds - 1){
                cout << " ";
            }
        }
    }
    return;
}
