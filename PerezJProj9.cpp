#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

class HiScores { //class for managing high scores
private:
    struct ScoreEntry { //structure to represent score entry
        string name; //player name
        int score; //player score
        string date; // date of score
    };

    vector<ScoreEntry> scores; //vector to store score entries

public:
    void addHiScore(const string& name, int score, const string& date) {
        if (isValidScore(score)) { //check if score is valid
            ScoreEntry newEntry = { name, score, date }; //create a new score
            scores.push_back(newEntry); //add new entry to vector
            cout << "Hi-Score added successfully!\n"; //print success message
        }
        else { //if score is not valid. 
            cout << "Invalid score! Please enter a positive number between 100 and 10,000.\n";
        }
    }

    void listHiScores() const { //method to list high scores
        if (scores.empty()) { //if no scores in vector
            cout << "No Hi-Scores available.\n"; //print message indicating no scores
            return;
        }

        vector<ScoreEntry> sortedScores = scores; //create copy of scores vector
        sort(sortedScores.begin(), sortedScores.end(), [](const ScoreEntry& a, const ScoreEntry& b) { //sort scores in descending order
            return a.score > b.score; //compare scores
            });

        cout << "Hi-Scores (descending order):\n"; //print header for high scores
        for (const auto& entry : sortedScores) { //iterate over sorted scores
            cout << "Name: " << entry.name << "\tScore: " << entry.score << "\tDate: " << entry.date << "\n";
        }
    }

private:
    bool isValidScore(int score) const { //method to check if score is valid.
        return (score >= 100 && score <= 10000); //return true if score is between 100 and 10,000
    }
};

int main() {
    HiScores hiScores; //create HiScores object
    int choice; //variable to store user choice

    do {
        cout << "\nMain Menu:\n"; //print main menu options
        cout << "1) Add Hi-Score\n";
        cout << "2) List Hi-Scores by score (descending order)\n";
        cout << "3) Quit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice) || (choice < 1 || choice > 3)) { //validate user input
            cout << "Invalid choice! Please enter a number between 1 and 3.\n"; //print error message for invalid choice
            cin.clear(); //clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore invalid input
        }

        cin.ignore(); //clear newline character

        switch (choice) { //switch based on user choice
        case 1: //if user choosed to add a hi-score
        {
            string name, date; //variables to store name and date
            int score; //variable to store score
            cout << "Enter Name: ";
            getline(cin, name); //read name from input
            cout << "Enter Score: "; //prompt for score
            while (!(cin >> score)) { //validate score input
                cout << "Invalid score! Please enter a number.\n"; //print error message for invalid score
                cin.clear(); //clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore invalid input.
            }
            cin.ignore(); //clear newline character from the buffer
            cout << "Enter Date (MM/DD/YYYY): "; //prompt for date
            getline(cin, date); //read date from input
            hiScores.addHiScore(name, score, date);  // add hi-score with name, score, and date
        }
        
        break;

        case 2: //if user choose to list hi-scores
            hiScores.listHiScores(); //list hi-scores
            break;

        case 3: //if user chooses to quit
            cout << "Exiting the program. Goodbye!\n";
            break;

        default: //for invalid choices
            cout << "Invalid choice! Please enter a number between 1 and 3.\n";
        }

    } while (choice != 3); //repeat until user chooses to quit

    return 0;
}
