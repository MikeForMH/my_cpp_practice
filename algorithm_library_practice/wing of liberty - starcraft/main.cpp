//
//  main.cpp
//  wing of liberty - starcraft
//
//  Created by Michael Hui on 6/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int SCV = 0;
const int MARINE = 1;
const int MEDIC = 2;

class WingOfLiberty{
public:
    WingOfLiberty (string new_name, int given_minerals, int *given_sequence, int sequence_size):name_(new_name), minerals_(given_minerals), sequence_size_(sequence_size){
        sequence = given_sequence;
    };
    void start_battle_simulation();
private:
    int * sequence;
    int sequence_size_;
    int minerals_ = 0;
    int time_ = 0;
    int number_of_scv_ = 1;
    int number_of_marine_ = 1;
    int number_of_medic_ = 1;
    int troops_code_ = 0;
    string name_;
    void TrainSCV();
    void TrainMarine();
    void TrainMedic();
    const static int kHpOfScv;
    const static int kHpOfMarine;
    const static int kHpOfMedic;
};

const int WingOfLiberty::kHpOfScv = 10;
const int WingOfLiberty::kHpOfMarine = 5;
const int WingOfLiberty::kHpOfMedic = 4;

void WingOfLiberty::start_battle_simulation(){
    for (int i = 0; minerals_ >= 4; ++i){
        switch (sequence [i % sequence_size_]){
            case 0:
                TrainSCV();
                break;
            case 1:
                TrainMarine();
                break;
            case 2:
                TrainMedic();
                break;
        }
    }
    cout << "Time: " << time_ - 1 << "  " << name_ << " base stop training troopers." << endl;
    return;
};

void WingOfLiberty::TrainSCV(){
    if (minerals_ >= 10){
        cout << "Time: " << time_ << "  " << name_ << " SCV " << troops_code_ << " born with HP " << kHpOfScv << " ";
        cout << number_of_scv_ << " SCV in base " << name_ << endl;
        ++time_; ++troops_code_; ++number_of_scv_;
        minerals_ -= 10;
    }
    return;
}
void WingOfLiberty::TrainMarine(){
    if (minerals_ >= 5){
        cout << "Time: " << time_ << "  " << name_ << " Marine " << troops_code_ << " born with HP " << kHpOfMarine << " ";
        cout << number_of_marine_ << " Marine in base " << name_ << endl;
        ++time_; ++troops_code_; ++number_of_marine_;
        minerals_ -= 5;
    }
    return;
}
void WingOfLiberty::TrainMedic(){
    if (minerals_ >= 4){
        cout << "Time: " << time_ << "  " << name_ << " Medic " << troops_code_ << " born with HP " << kHpOfMedic << " ";
        cout << number_of_medic_ << " Medic in base " << name_ << endl;
        ++time_; ++troops_code_; ++number_of_medic_;
        minerals_ -= 4;
    }
    return;
}


int main(){
    int raynor_training_sequence [3] = {SCV, MARINE, MEDIC};
    int mengsk_training_sequence [3] = {MARINE, MEDIC, SCV};
    int input_minerals;
    cin >> input_minerals;
    WingOfLiberty Raynor("Raynor", input_minerals, raynor_training_sequence, sizeof(raynor_training_sequence) / sizeof(int));
    WingOfLiberty Mengsk("Mengsk", input_minerals, mengsk_training_sequence, sizeof(mengsk_training_sequence) / sizeof(int));
    Raynor.start_battle_simulation();
    Mengsk.start_battle_simulation();
    return 0;
}
