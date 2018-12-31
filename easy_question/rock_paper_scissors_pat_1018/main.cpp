//
//  main.cpp
//  rock_paper_scissors_pat_1018
//
//  Created by Michael Hui on 31/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;

// B > C > J

class Player{
private:
    int win_by_rock, win_by_scissors, win_by_paper, draw, loss;
    char most_win_by(){
        char temp = 'B';
        if(win_by_rock > win_by_paper || win_by_scissors > win_by_paper){
            temp = 'C';
            if(win_by_scissors > win_by_rock){
                temp = 'J';
            }
        }
        return temp;
    }
public:
    Player(){
        win_by_rock = 0;
        win_by_scissors = 0;
        win_by_paper = 0;
        draw = 0;
        loss = 0;
    }
    static void game(Player &p1, Player &p2, char &p1_input, char &p2_input){
        if(p1_input == p2_input){
            ++p1.draw;
            ++p2.draw;
            return;
        }
        else if (p1_input == 'J'){
            if(p2_input == 'C'){
                ++p1.loss;
                ++p2.win_by_rock;
                return;
            }
            else{
                ++p1.win_by_scissors;
                ++p2.loss;
                return;
            }
        }
        else if(p1_input == 'C'){
            if(p2_input == 'B'){
                ++p1.loss;
                ++p2.win_by_paper;
                return;
            }
            else{
                ++p1.win_by_rock;
                ++p2.loss;
                return;
            }
        }
        else if(p2_input == 'J'){ // p1_input == 'B'
            ++p1.loss;
            ++p2.win_by_scissors;
            return;
        }
        else{
            ++p1.win_by_paper;
            ++p2.loss;
            return;
        }
    }
    static void output(Player &p1, Player &p2){
        cout << p1.win_by_paper + p1.win_by_scissors + p1.win_by_rock << " " << p1.draw << " " << p1.loss << endl;
        cout << p2.win_by_paper + p2.win_by_scissors + p2.win_by_rock << " " << p2.draw << " " << p2.loss << endl;
        cout << p1.most_win_by() << " " << p2.most_win_by() << endl;
        return;
    }
};

int main(){
    int n;
    char temp_1, temp_2;
    Player p1, p2;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> temp_1 >> temp_2;
        Player::game(p1, p2, temp_1, temp_2);
    }
    Player::output(p1, p2);
    return 0;
}
