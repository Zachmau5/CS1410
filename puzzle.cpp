#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>

class Vial {
private:
    char contents[4];
    int filled;
    int label;

public:
    // Default constructor
    Vial() : filled(0), label(0) {}

    // Parameterized constructor with add member function
    Vial(char c1, char c2, char c3, char c4, int filled) : filled(filled), label(0) {
        contents[0] = c1;
        contents[1] = c2;
        contents[2] = c3;
        contents[3] = c4;
    }

    // Parameterized constructor with char array
    Vial(const char contents[], int size, int filled) : filled(filled), label(0) {
        for (int i = 0; i < size; ++i) {
            this->contents[i] = contents[i];
        }
    }

    // Add character to the vial
    bool add(char character) {
        if (filled < 4) {
            contents[filled] = character;
            filled++;
            return true;
        }
        return false;
    }

    // Display the contents of the vial
    void display() const {
        std::cout << "Vial " << label << ": ";
        for (int i = 0; i < filled; ++i) {
            std::cout << contents[i] << " ";
        }
        std::cout << std::endl;
    }

    // Check if the vial is complete (all characters are the same)
    bool isComplete() const {
        if (filled == 0)
            return false;
        char firstCharacter = contents[0];
        for (int i = 1; i < filled; ++i) {
            if (contents[i] != firstCharacter)
                return false;
        }
        return true;
    }

    // Set the label of the vial
    void setLabel(int label) {
        this->label = label;
    }
/*
    //Uncomment this, and comment the other and it will dump remainder of vial into
    //the other vials on the transfer. Substaintially harder!!
    // Transfer contents from source vial to destination vial
    bool transfer(Vial& destination) {
        if (this == &destination || filled == 0 || destination.getFilled() == 4)
            return false;

        int numTransferred = 0;
        while (filled > 0 && destination.getFilled() < 4) {
            char character = contents[filled - 1];
            if (destination.add(character)) {
                filled--;
                numTransferred++;
            } else {
                break;
            }
        }

        return numTransferred > 0;
    }
*/
    // Transfer one character from source vial to destination vial
    bool transfer(Vial& destination) {
        if (this == &destination || filled == 0 || destination.getFilled() == 4)
            return false;

        char character = contents[filled - 1];
        if (destination.add(character)) {
            filled--;
            return true;
        }

        return false;
    }

    // Get the label of the vial
    int getLabel() const {
        return label;
    }

    // Get the contents of the vial
    const char* getContents() const {
        return contents;
    }

    // Get the number of characters filled in the vial
    int getFilled() const {
        return filled;
    }

};

    // Function to check if all vials are full
    bool allVialsFull(const std::vector<Vial>& vials) {
        for (const auto& vial : vials) {
            if (!vial.isComplete())
                return false;
            }
        return true;
    }

    // Function to generate a random number between min and max (inclusive)
    int generateRandomNumber(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(gen);
    }
    // Function to check if all non-empty vials have four characters
    bool allVialsHaveFourCharacters(const std::vector<Vial>& vials) {
        for (const auto& vial : vials) {
            if (vial.getFilled() > 0 && vial.getFilled() != 4)
                return false;
            }
        return true;
    }



int main() {
    // Create vials and initialize the game state
    std::vector<Vial> vials;
    vials.emplace_back();
    vials.emplace_back();
    vials.emplace_back();
    vials.emplace_back();
    vials.emplace_back();
    vials.emplace_back();

    // Initialize the characters
    std::vector<char> characters = { 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c', 'd', 'd', 'd', 'd' };

    // Shuffle the characters once
    std::shuffle(characters.begin(), characters.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    // Fill the vials with characters using the shuffled order
    int characterIndex = 0;
    for (int i = 0; i < vials.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            if (characterIndex < characters.size()) {
                vials[i].add(characters[characterIndex]);
                characterIndex++;
            }
        }
    }

    // Set labels for vials
    for (int i = 0; i < vials.size(); ++i) {
        vials[i].setLabel(i + 1);
    }

    std::cout << "Welcome Simple Sort Puzzle that looks very much like the water sorting game..." << std::endl;

     // Game loop
    while (true) {
        // Display the current state of vials
        for (const auto& vial : vials) {
            vial.display();
        }
        std::cout << std::endl;

        // Prompt the player for input
        std::cout << "Enter source vial number (1-6), or 'q' to quit: ";
        std::string input;
        std::cin >> input;

        // Check if the player wants to quit
        if (input == "q") {
            std::cout << "You quit the game. Better luck next time!" << std::endl;
            break;
        }

        int sourceIndex;
        try {
            sourceIndex = std::stoi(input) - 1;
        } catch (const std::exception& e) {
            std::cout << "Invalid input! Please try again." << std::endl;
            continue;
        }

        if (sourceIndex < 0 || sourceIndex >= vials.size()) {
            std::cout << "Invalid input! Please try again." << std::endl;
            continue;
        }

        // Check if the player selected the empty vial for source
        if (vials[sourceIndex].getFilled() == 0) {
            std::cout << "You selected an empty vial as the source. Please choose a different source." << std::endl;
            continue;
        }

        // Prompt the player for the destination vial
        std::cout << "Enter destination vial number (1-6), or 'q' to quit: ";
        std::cin >> input;

        // Check if the player wants to quit
        if (input == "q") {
            std::cout << "You quit the game. Better luck next time!" << std::endl;
            break;
        }

        int destinationIndex;
        try {
            destinationIndex = std::stoi(input) - 1;
        } catch (const std::exception& e) {
            std::cout << "Invalid input! Please try again." << std::endl;
            continue;
        }

        if (destinationIndex < 0 || destinationIndex >= vials.size()) {
            std::cout << "Invalid input! Please try again." << std::endl;
            continue;
        }

        // Perform the transfer
        if (vials[sourceIndex].transfer(vials[destinationIndex])) {
            std::cout << "Transfer successful!" << std::endl;

            // Check for win condition
            if (allVialsHaveFourCharacters(vials)) {
                std::cout << "Congratulations! You have successfully sorted all vials." << std::endl;
                break; // Break the loop when all non-empty vials have four characters
            }
        } else {
            std::cout << "Invalid move! Please try again." << std::endl;
        }
    }

    std::cout << "Game Over." << std::endl;

    return 0;
}
