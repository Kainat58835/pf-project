#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

struct Player {
    string name;  // Player's name
    double amount;   // Player's wallet balance
    double bidAmount; //sharth
    int guess; //user guess 1-10
    int dice; //rand function value
    string choice; // For replaying the casino game
};
//players array of Player type
Player players[10]; // Array to store up to 10 player profiles
int playerCount = 0; // Tracks the number of created players
// Function declarations

void welcome();
void showRules();
void createProfile(); //create account/object
void viewProfiles(); //view account/object details
void updateProfile(); //edit existing account/object details
void deleteProfile(); //delete object
void casinoGame(Player& player);
void mainMenu();

int main() {
    srand(time(0)); //jitni dfa main run ho utni dfa  new number gen ho
    mainMenu();
}

void welcome() {
    cout << "*******************************************\n";
    cout << "*       Welcome to the Casino Game!       *\n";
    cout << "*******************************************\n";
}

void showRules() {
    cout << "Casino Game Rules:\n";
    cout << "1. Choose a number between 1 and 10.\n";
    cout << "2. If you guess the correct number, you win double your bid amount.\n";
    cout << "3. If you guess wrong, you lose your bid amount.\n";
}

void createProfile() {
    if (playerCount >= 10) {
        cout << "Cannot create more profiles. Maximum limit reached.\n";
        return;
    }

    string newName;
    cout << "Enter player name: ";
    cin >> newName;

    // Check for duplicate names
    for (int i = 0; i < playerCount; ++i) {
        if (players[i].name == newName) {
            cout << "Error: A profile with the name \"" << newName << "\" already exists.\n";
            return;
        }
    }

    Player newPlayer;
    newPlayer.name = newName;
    cout << "Enter starting balance: ";
    cin >> newPlayer.amount;

    players[playerCount++] = newPlayer;
    cout << "Player profile created successfully!\n";
}


void viewProfiles() {
    if (playerCount == 0) {
        cout << "No player profiles available.\n";
        return;
    }

    cout << "Player Profiles:\n";
    for (int i = 0; i < playerCount; ++i) {
        cout << i + 1 << ". Name: " << players[i].name
             << ", Balance: " << players[i].amount << "\n";
    }
}

void updateProfile() {
    if (playerCount == 0) {
        cout << "No player profiles available to update.\n";
        return;
    }

    string name;
    cout << "Enter the player's name to update: ";
    cin >> name;

    for (int i = 0; i < playerCount; ++i) {
        if (players[i].name == name) {
            cout << "Enter new balance: ";
            cin >> players[i].amount;
            cout << "Profile updated successfully!\n";
            return;
        }
    }
    cout << "Player not found.\n";
}

void deleteProfile() {
    if (playerCount == 0) {
        cout << "No player profiles available to delete.\n";
        return;
    }

    string name;
    cout << "Enter the player's name to delete: ";
    cin >> name;

    for (int i = 0; i < playerCount; ++i) {
        if (players[i].name == name) {
            players[i] = players[--playerCount]; // Replace with the last profile and decrease count
            cout << "Profile deleted successfully!\n";
            return;
        }
    }

    cout << "Player not found.\n";
}


void casinoGame(Player& player) {
    showRules();

    while (true) {
        cout << "Your current balance: " << player.amount << "\n";
        cout << "Enter bid amount: ";
        cin >> player.bidAmount;

        while (player.bidAmount > player.amount) {
            cout << "Bid amount exceeds your balance. Re-enter: ";
            cin >> player.bidAmount;
        }

        cout << "Guess a number between 1 and 10: ";
        cin >> player.guess;

        while (player.guess < 1 || player.guess > 10) {
            cout << "Number must be between 1 and 10. Re-enter: ";
            cin >> player.guess;
        }

        player.dice = (rand() % 10) + 1; 

        if (player.guess == player.dice) {
            player.amount += player.bidAmount * 2;
            cout << "You guessed correctly! You win " << player.bidAmount * 2 << "!\n";
        } else {
            player.amount -= player.bidAmount;
            cout << "Wrong guess! The correct number was " << player.dice
                 << ". You lose " << player.bidAmount << ".\n";
        }

        cout << "Current balance: " << player.amount << "\n";
        if (player.amount <= 0) {
            cout << "You have no balance left. Game over!\n";
            break;
        }

        cout << "Do you want to play again? (yes/no): ";
        cin >> player.choice;
        if (player.choice != "yes") break;
    }
}

void mainMenu() {
	int choice;
    do {
        system("cls"); // Clears the screen 
        welcome();
        cout << "1. Create Player Profile\n";
        cout << "2. View Player Profiles\n";
        cout << "3. Update Player Profile\n";
        cout << "4. Delete Player Profile\n";
        cout << "5. Play Casino Game\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createProfile();
                break;
            case 2:
                viewProfiles();
                break;
            case 3:
                updateProfile();
                break;
            case 4:
                deleteProfile();
                break;
            case 5: {
                string name;
                cout << "Enter your name to play: ";
                cin >> name;

                bool found = false;
                for (int i = 0; i < playerCount; ++i) {
                    if (players[i].name == name) {
                        casinoGame(players[i]);
                        found = true;
                        break;
                    }
                }

                if (found!=true) {
                    cout << "Player not found. Create a profile first.\n";
                }
                break;
            }
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        } 
        system("pause"); //user controls with pressing a key to continue
    } while (choice != 6);
}
