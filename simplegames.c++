#include <iostream>
#include <cstdlib> // For generating random numbers
#include <ctime>   // For seeding the random number generator
#include <algorithm> // For std::transform
#include <cctype>  // For std::tolower
#include <vector>
#include <random>
#include <set>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <unistd.h>

void playGuessingGame() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomNumber = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guessing Game!\n";
    std::cout << "I have chosen a number between 1 and 100.\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        attempts++;

        if (guess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You found the number in " << attempts << " attempts.\n";
        }
    } while (guess != randomNumber);
}

void playRPSLSGame() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomNumber = std::rand() % 5 + 1;
    std::string computerChoice;
    std::string userChoice;

    switch (randomNumber) {
        case 1:
            computerChoice = "Rock";
            break;
        case 2:
            computerChoice = "Paper";
            break;
        case 3:
            computerChoice = "Scissors";
            break;
        case 4:
            computerChoice = "Lizard";
            break;
        case 5:
            computerChoice = "Spock";
            break;
    }

    std::cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock!\n";

    bool playAgain = true;
    while (playAgain) {
        std::cout << "Please enter your choice (Rock, Paper, Scissors, Lizard, Spock): ";
        std::cin >> userChoice;

        // Convert userChoice to lowercase for case-insensitive comparison
        std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(), [](unsigned char c) { return std::tolower(c); });

        std::cout << "Computer chooses: " << computerChoice << std::endl;
        std::cout << "You choose: " << userChoice << std::endl;

        // Game logic to determine the winner
        if (userChoice == computerChoice) {
            std::cout << "It's a tie!\n";
        } else if (
            (userChoice == "rock" && (computerChoice == "Scissors" || computerChoice == "Lizard")) ||
            (userChoice == "paper" && (computerChoice == "Rock" || computerChoice == "Spock")) ||
            (userChoice == "scissors" && (computerChoice == "Paper" || computerChoice == "Lizard")) ||
            (userChoice == "lizard" && (computerChoice == "Paper" || computerChoice == "Spock")) ||
            (userChoice == "spock" && (computerChoice == "Rock" || computerChoice == "Scissors"))
        ) {
            std::cout << "You win!\n";
        } else {
            std::cout << "Computer wins!\n";
        }

        // Prompt the player to play again
        char playChoice;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playChoice;

        // Convert playChoice to lowercase for case-insensitive comparison
        playChoice = std::tolower(playChoice);

        if (playChoice != 'y') {
            playAgain = false;
        }
    }
}

int scoreOnes(const int dice[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (dice[i] == 1) {
            score += 1;
        }
    }
    return score;
}

int scoreTwos(const int dice[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (dice[i] == 2) {
            score += 2;
        }
    }
    return score;
}

int scoreThrees(const int dice[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (dice[i] == 3) {
            score += 3;
        }
    }
    return score;
}

int scoreFours(const int dice[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (dice[i] == 4) {
            score += 4;
        }
    }
    return score;
}

int scoreFives(const int dice[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (dice[i] == 5) {
            score += 5;
        }
    }
    return score;
}

int scoreSixes(const int dice[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (dice[i] == 6) {
            score += 6;
        }
    }
    return score;
}


int countOccurrences(const int dice[], int numDice, int value) {
    int count = 0;
    for (int i = 0; i < numDice; i++) {
        if (dice[i] == value) {
            count++;
        }
    }
    return count;
}
// Function to calculate the score for a small straight
int calculateSmallStraightScore(const int dice[], int size) {
    int countUnique = std::set<int>(dice, dice + size).size();

    if (countUnique >= 4) {
        int sortedDice[size];
        std::copy(dice, dice + size, sortedDice);
        std::sort(sortedDice, sortedDice + size);

        bool validSmallStraight = false;
        for (int i = 0; i < size - 1; i++) {
            if (sortedDice[i] + 1 == sortedDice[i + 1]) {
                validSmallStraight = true;
            } else if (sortedDice[i] + 1 < sortedDice[i + 1]) {
                validSmallStraight = false;
                break;
            }
        }

        if (validSmallStraight) {
            return 30;
        }
    }

    return 0;
}

// Function to calculate the score for a large straight
int calculateLargeStraightScore(const int dice[], int size) {
    int countUnique = std::set<int>(dice, dice + size).size();

    if (countUnique == size && size == 5) {
        int sortedDice[size];
        std::copy(dice, dice + size, sortedDice);
        std::sort(sortedDice, sortedDice + size);

        bool validLargeStraight = true;
        for (int i = 0; i < size - 1; i++) {
            if (sortedDice[i] + 1 != sortedDice[i + 1]) {
                validLargeStraight = false;
                break;
            }
        }

        if (validLargeStraight) {
            return 40;
        }
    }

    return 0;
}

// Function to calculate the score for a full house
int calculateFullHouseScore(const int dice[], int size) {
    int countUnique = std::set<int>(dice, dice + size).size();

    if (countUnique == 2) {
        int sortedDice[size];
        std::copy(dice, dice + size, sortedDice);
        std::sort(sortedDice, sortedDice + size);

        if ((sortedDice[0] == sortedDice[1] && sortedDice[1] == sortedDice[2] && sortedDice[3] == sortedDice[4]) ||
            (sortedDice[0] == sortedDice[1] && sortedDice[2] == sortedDice[3] && sortedDice[3] == sortedDice[4])) {
            return 25;
        }
    }

    return 0;
}

int calculateThreeOfAKindScore(const int dice[], int size) {
    for (int i = 1; i <= 6; i++) {
        int count = countOccurrences(dice, size, i);
        if (count >= 3) {
            int sum = i * 3;
            return sum;
        }
    }

    return 0;
}

// Function to calculate the score for four of a kind
int calculateFourOfAKindScore(const int dice[], int size) {
    for (int i = 1; i <= 6; i++) {
        int count = countOccurrences(dice, size, i);
        if (count >= 4) {
            return i * 4;
        }
    }

    return 0;
}

// Function to calculate the score for a Yahtzee
int calculateYahtzeeScore(const int dice[], int size) {
    int firstDie = dice[0];

    for (int i = 1; i < size; i++) {
        if (dice[i] != firstDie) {
            return 0;
        }
    }

    return 50;
}


// Function to calculate the score for an upper section category
int scoreUpperSectionCategory(int category, const int dice[], int size) {
    int count = countOccurrences(dice, size, category);
    return category * count;
}
int calculateUpperSectionScore(int category, const int dice[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        if (dice[i] == category) {
            score += dice[i];
        }
    }
    return score;
}

// Function to calculate the score for a lower section category
int scoreLowerSectionCategory(int category, const int dice[], int size) {
    int score = 0;

    switch (category) {
        case 7: // Small Straight
            score = calculateSmallStraightScore(dice, size);
            break;
        case 8: // Large Straight
            score = calculateLargeStraightScore(dice, size);
            break;
        case 9: // Full House
            score = calculateFullHouseScore(dice, size);
            break;
        case 10: // Three of a Kind
            score = calculateThreeOfAKindScore(dice, size);
            break;
        case 11: // Four of a Kind
            score = calculateFourOfAKindScore(dice, size);
            break;
        case 12: // Yahtzee
            score = calculateYahtzeeScore(dice, size);
            break;
        default:
            std::cout << "Invalid category.\n";
            break;
    }

    return score;
}


int calculateTotalLowerScore(int category, const int dice[], int size) {
    // Implement the scoring logic for lower section categories according to your game rules
    // Update the lower section score and mark the category as complete
    // Print the score for the chosen category
    return 0; // Replace with your scoring logic
}

int calculateTotalScore(const int upperSectionScores[], int size) {
    int totalScore = 0;
    for (int i = 0; i < size; i++) {
        totalScore += upperSectionScores[i];
    }
    return totalScore;
}

void printDice(const int dice[], int size, int rollNumber, bool lastRoll = false) {
    if (lastRoll) {
        std::cout << "Final Roll: ";
    } else {
        std::cout << "Roll " << rollNumber << ": ";
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "|" << dice[i] << "|";
    }
    std::cout << std::endl;
}

void rollDice(int dice[], int size, std::mt19937& gen) {
    std::uniform_int_distribution<> dis(1, 6);

    for (int i = 0; i < size; i++) {
        dice[i] = dis(gen);
    }
}

int calculateScoreForUpperCategory(int dice[], int numDice, int category) {
    int score = 0;
    for (int i = 0; i < numDice; i++) {
        if (dice[i] == category) {
            score += category;
        }
    }
    return score;
}

void playYahtzee() {
    int dice[5] {};
    int category;
    const int UPPER_SECTION_CATEGORIES = 6;
    int upperSectionScores[UPPER_SECTION_CATEGORIES] = {0};
    bool upperSectionComplete[UPPER_SECTION_CATEGORIES] = {false};
    int lowerSectionScores[6] = {0};

    std::random_device rd;
    std::mt19937 gen(rd());

    // Loop until all upper section categories are filled
    while (!std::all_of(upperSectionComplete, upperSectionComplete + UPPER_SECTION_CATEGORIES, [](bool val) { return val; })) {
        for (int currentRoll = 1; currentRoll <= 3; currentRoll++) {
            if (currentRoll == 1) {
                rollDice(dice, 5, gen);
            }
            printDice(dice, 5, currentRoll);

            // Prompt the user to decide which dice to keep
            int keptDice[5] = {0};
            int numKeptDice = 0;
            for (int i = 0; i < 5; i++) {
                char choice;
                std::cout << "Do you want to keep die " << i + 1 << "? (y/n): ";
                std::cin >> choice;
                if (choice == 'y') {
                    keptDice[numKeptDice++] = dice[i];
                }
            }

            // Re-roll the remaining dice
            rollDice(dice, 5, gen);

            // Copy the kept dice back to the original dice array
            for (int i = 0; i < numKeptDice; i++) {
                dice[i] = keptDice[i];
            }

            if (currentRoll == 3) {
                printDice(dice, 5, currentRoll, true);
            }
        }

        // Print the available categories for the upper section
        std::cout << "Upper Section Categories:\n";
        for (int i = 1; i <= UPPER_SECTION_CATEGORIES; i++) {
            if (upperSectionComplete[i - 1]) {
                std::cout << i << ". [Scored]\n";
            } else {
                std::cout << i << ". [Available]\n";
            }
        }

        // Print the available categories for the lower section
        std::cout << "Lower Section Categories:\n";
        std::cout << "7. Three of a Kind";
        if (lowerSectionScores[0] == 0) {
            std::cout << " [Available]";
        }
        std::cout << "\n";
        std::cout << "8. Four of a Kind";
        if (lowerSectionScores[1] == 0) {
            std::cout << " [Available]";
        }
        std::cout << "\n";
        std::cout << "9. Full House";
        if (lowerSectionScores[2] == 0) {
            std::cout << " [Available]";
        }
        std::cout << "\n";
        std::cout << "10. Small Straight";
        if (lowerSectionScores[3] == 0) {
            std::cout << " [Available]";
        }
        std::cout << "\n";
        std::cout << "11. Large Straight";
        if (lowerSectionScores[4] == 0) {
            std::cout << " [Available]";
        }
        std::cout << "\n";
        std::cout << "12. Yahtzee";
        if (lowerSectionScores[5] == 0) {
            std::cout << " [Available]";
        }
        std::cout << "\n";

        bool validCategory = false;
        while (!validCategory) {
            char sectionChoice;
            std::cout << "Choose upper or lower scorecard (u/l): ";
            std::cin >> sectionChoice;

            if (sectionChoice == 'u') {
                std::cout << "Choose a category to score (1-6) for upper scorecard: ";
                std::cin >> category;

                if (category < 1 || category > 6) {
                    std::cout << "Invalid category. Choose a valid category.\n";
                } else {
                    if (upperSectionComplete[category - 1]) {
                        std::cout << "Category already scored. Choose another category.\n";
                        continue;
                    }

                    validCategory = true;
                    // Calculate the score for the chosen category
                    int score = calculateScoreForUpperCategory(dice, 5, category);
                    upperSectionScores[category - 1] = score;
                    upperSectionComplete[category - 1] = true;
                    std::cout << "Score for category " << category << ": " << score << std::endl;

                    // Print the upper section score
                    int upperSectionScore = calculateTotalScore(upperSectionScores, UPPER_SECTION_CATEGORIES);
                    std::cout << "Upper section score: " << upperSectionScore << std::endl;

                    // Print the lower section score
                    int lowerSectionScore = calculateTotalScore(lowerSectionScores, 6);
                    std::cout << "Lower Section score: " << lowerSectionScore << std::endl;
                }
            } else if (sectionChoice == 'l') {
                std::cout << "Choose a category to score (7-12) for lower scorecard: ";
                std::cin >> category;

                if (category < 7 || category > 12) {
                    std::cout << "Invalid category. Choose a valid category.\n";
                } else {
                    if (lowerSectionScores[category - 7] != 0) {
                        std::cout << "Category already scored. Choose another category.\n";
                        continue;
                    }

                    validCategory = true;
                    // Calculate the score for the chosen category
                    int score = 0;
                    switch (category) {
                        case 7:
                            score = calculateThreeOfAKindScore(dice, 5);
                            break;
                        case 8:
                            score = calculateFourOfAKindScore(dice, 5);
                            break;
                        case 9:
                            score = calculateFullHouseScore(dice, 5);
                            break;
                        case 10:
                            score = calculateSmallStraightScore(dice, 5);
                            break;
                        case 11:
                            score = calculateLargeStraightScore(dice, 5);
                            break;
                        case 12:
                            score = calculateYahtzeeScore(dice, 5);
                            break;
                    }
                    lowerSectionScores[category - 7] = score;
                    std::cout << "Score for category " << category << ": " << score << std::endl;

                    // Print the upper section score
                    int upperSectionScore = calculateTotalScore(upperSectionScores, UPPER_SECTION_CATEGORIES);
                    std::cout << "Upper section score: " << upperSectionScore << std::endl;

                    // Print the lower section score
                    int lowerSectionScore = calculateTotalScore(lowerSectionScores, 6);
                    std::cout << "Lower Section score: " << lowerSectionScore << std::endl;
                    std::cout << std::endl;
                }
            } else {
                std::cout << "Invalid choice. Choose a valid option.\n";
            }
        }
    }

    // Calculate the total score
    int upperSectionScore = calculateTotalScore(upperSectionScores, UPPER_SECTION_CATEGORIES);
    int lowerSectionScore = calculateTotalScore(lowerSectionScores, 6);
    int totalScore = upperSectionScore + lowerSectionScore;

    std::cout << "Game over!\n";
    std::cout << "Upper Section score: " << upperSectionScore << std::endl;
    std::cout << "Lower Section score: " << lowerSectionScore << std::endl;
    std::cout << "Total Score: " << totalScore << std::endl;
}
int main() {

    int choice;
    bool validChoice = false;

    do {
        std::cout << "Please choose a game to play:\n";
        std::cout << "1. Guessing Game\n";
        std::cout << "2. Rock, Paper, Scissors, Lizard, Spock\n";
        std::cout << "3. Yahtzee\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                playGuessingGame();
                validChoice = true;
                break;
            case 2:
                playRPSLSGame();
                validChoice = true;
                break;
            case 3:
                playYahtzee();
                validChoice = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (!validChoice);

    return 0;
}
