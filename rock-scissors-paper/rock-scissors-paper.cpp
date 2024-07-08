#include <iostream>
#include <ctime>
#include <map>

using namespace std;

const map<int, pair<char, string>> CHOICES = {
    {1,{'s',"Scissors"s}},
    {2, {'r',"Rock"s} },
    {3,{'p',"Paper"s}}
};

char ComputerChoice() {
    srand(time(0));
    return ::CHOICES.at(rand() % 3 + 1).first;
}

char HumanChoice() {
    char res;
    cout << "##############"s << endl;
    cout << "[r] - Rock"s << endl;
    cout << "[s] - Scissors"s << endl;
    cout << "[p] - Paper"s << endl;
    cout << "[x] - EXIT!"s << endl;
    cout << "##############"s << endl;
    cout << "Your choice: "s;
    cin >> res;
    return res;
}

int CheckChoice(char choice) {
    if (choice == 'x') {
        return 2;
    }
    for (const auto &c : ::CHOICES) {
        if (c.second.first == choice) {
            return 1;
        }
    }
    return 0;
}

string GetChoiceName(char choice) {
    string res;
    for (const auto& c : ::CHOICES) {
        if (c.second.first == choice) {
            res = c.second.second;
        }
    }
    return res;
}

void DisplayChoice(string who, char choice) {
    cout << who << " choice is: "s << GetChoiceName(choice) << endl;
}

void ChooseWinner(char human, char computer) {
    bool win = false;
    if (human == computer) {
        cout << "It's a tie!" << endl;
    }
    else {
        win = (
                (human == 's' && computer == 'r') ||
                (human == 'p' && computer == 's') ||
                (human == 'r' && computer == 'p')
              ) ? false : true;
        cout << "You "s << (win ? "win"s : "loose"s) << '!' << endl;
    }
}

int main()
{
    char human;
    char computer;
    cout << "******************************" << endl;
    
    while (true){
        human = HumanChoice();
        int check_choice = CheckChoice(human);
        if (check_choice == 2) {
            break;
        }
        else if (check_choice == 0) {
            cout << "Input wrong!" << endl;
            continue;
        }
        DisplayChoice("Your's"s, human);
        computer = ComputerChoice();
        DisplayChoice("Computer's"s, computer);
        ChooseWinner(human, computer);
    }

    cout << "******************************" << endl;
    cout << "Good Bye!" << endl;
    cout << "******************************" << endl;
}
