/*
#include <iostream>
#include <cstdlib>
#include <ctime>

enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

struct Card {
    int value;
    Suit suit;
};

Card getRandomCard() {
    Card newCard;
    newCard.value = rand() % 13 + 2;
    int randomSuit = rand() % 4;
    switch (randomSuit) {
        case 0:
            newCard.suit = HEARTS;
            break;
        case 1:
            newCard.suit = DIAMONDS;
            break;
        case 2:
            newCard.suit = CLUBS;
            break;
        case 3:
            newCard.suit = SPADES;
            break;
    }
    return newCard;
}

void showCard(const Card& card) {
    std::string valueStr;
    switch (card.value) {
        case 11:
            valueStr = "J";
            break;
        case 12:
            valueStr = "Q";
            break;
        case 13:
            valueStr = "K";
            break;
        case 14:
            valueStr = "A";
            break;
        default:
            valueStr = std::to_string(card.value);
    }

    std::string suitStr;
    switch (card.suit) {
        case HEARTS:
            suitStr = "\u2665";  // Heart symbol
            break;
        case DIAMONDS:
            suitStr = "\u2666";  // Diamond symbol
            break;
        case CLUBS:
            suitStr = "\u2663";  // Club symbol
            break;
        case SPADES:
            suitStr = "\u2660";  // Spade symbol
            break;
    }

    std::cout << "|" << valueStr << " " << suitStr << " | ";
}

void dealCardAndTotal(int& aceCount, int& total) {
    Card newCard = getRandomCard();
    showCard(newCard);

    if (newCard.value == 14) {  // Ace
        aceCount++;
        total += 11;
    } else if (newCard.value > 10) {  // Face card (J, Q, K)
        total += 10;
    } else {
        total += newCard.value;
    }

    while (aceCount > 0 && total > 21) {
        aceCount--;
        total -= 10;
    }
}

void playBlackjackRound() {
    int playerAceCount = 0;
    int playerTotal = 0;
    int dealerAceCount = 0;
    int dealerTotal = 0;

    std::cout << "=== Blackjack Round ===" << std::endl;

    // Dealer deals two cards, revealing only the first one
    Card dealerFirstCard = getRandomCard();
    std::cout << "Dealer: ";
    showCard(dealerFirstCard);
    std::cout << "| ? |" << std::endl;
    if (dealerFirstCard.value == 14) {
        dealerAceCount++;
        dealerTotal += 11;
    } else if (dealerFirstCard.value > 10) {
        dealerTotal += 10;
    } else {
        dealerTotal += dealerFirstCard.value;
    }

    // Player is dealt two cards
    std::cout << "Player: ";
    dealCardAndTotal(playerAceCount, playerTotal);
    dealCardAndTotal(playerAceCount, playerTotal);
    std::cout << std::endl;
    std::cout << "Player Total: " << playerTotal << std::endl;

    // Player's turn
    std::string choice;
    std::cout << "(H)it or (S)tand: ";
    std::cin >> choice;

    while (choice == "h") {
        dealCardAndTotal(playerAceCount, playerTotal);
        std::cout << std::endl;
        std::cout << "Player Total: " << playerTotal << std::endl;

        if (playerTotal > 21) {
            std::cout << "Player Busts. You lose!" << std::endl;
            return;
        }

        std::cout << "(H)it or (S)tand: ";
        std::cin >> choice;
    }

    // Dealer's turn
    std::cout << "Dealer: ";
    showCard(dealerFirstCard);
    while (dealerTotal < 17) {
        dealCardAndTotal(dealerAceCount, dealerTotal);
    }
    std::cout << std::endl;

    // Compare player's and dealer's totals
    std::cout << "Player Total: " << playerTotal << std::endl;
    std::cout << "Dealer Total: " << dealerTotal << std::endl;

    if (dealerTotal > 21) {
        std::cout << "Dealer Busts. You win!" << std::endl;
    } else if (playerTotal > dealerTotal) {
        std::cout << "You win!" << std::endl;
    } else if (playerTotal < dealerTotal) {
        std::cout << "You lose!" << std::endl;
    } else {
        std::cout << "It's a push. No-win, no-loss." << std::endl;
    }
}

int main() {
    srand(time(0));  // Initialize random seed

    playBlackjackRound();

    return 0;
}
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

struct Card {
    int value;
    Suit suit;
};

Card getRandomCard() {
    Card newCard;
    newCard.value = rand() % 13 + 2;
    int randomSuit = rand() % 4;
    switch (randomSuit) {
        case 0:
            newCard.suit = HEARTS;
            break;
        case 1:
            newCard.suit = DIAMONDS;
            break;
        case 2:
            newCard.suit = CLUBS;
            break;
        case 3:
            newCard.suit = SPADES;
            break;
    }
    return newCard;
}

void showCard(const Card& card) {
    std::string valueStr;
    switch (card.value) {
        case 11:
            valueStr = "J";
            break;
        case 12:
            valueStr = "Q";
            break;
        case 13:
            valueStr = "K";
            break;
        case 14:
            valueStr = "A";
            break;
        default:
            valueStr = std::to_string(card.value);
    }

    std::string suitStr;
    switch (card.suit) {
        case HEARTS:
            suitStr = "\u2665";  // Heart symbol
            break;
        case DIAMONDS:
            suitStr = "\u2666";  // Diamond symbol
            break;
        case CLUBS:
            suitStr = "\u2663";  // Club symbol
            break;
        case SPADES:
            suitStr = "\u2660";  // Spade symbol
            break;
    }

    std::cout << "|" << valueStr << " " << suitStr << " | ";
}

void dealCardAndTotal(int& aceCount, int& total) {
    Card newCard = getRandomCard();
    showCard(newCard);

    if (newCard.value == 14) {  // Ace
        aceCount++;
        total += 11;
    } else if (newCard.value > 10) {  // Face card (J, Q, K)
        total += 10;
    } else {
        total += newCard.value;
    }

    while (aceCount > 0 && total > 21) {
        aceCount--;
        total -= 10;
    }
}

void playBlackjackRound() {
    int playerAceCount = 0;
    int playerTotal = 0;
    int dealerAceCount = 0;
    int dealerTotal = 0;

    std::cout << "=== Blackjack Round ===" << std::endl;

    // Dealer deals two cards, revealing only the first one
    Card dealerFirstCard = getRandomCard();
    std::cout << "Dealer: ";
    showCard(dealerFirstCard);
    std::cout << "| ? |" << std::endl;
    if (dealerFirstCard.value == 14) {
        dealerAceCount++;
        dealerTotal += 11;
    } else if (dealerFirstCard.value > 10) {
        dealerTotal += 10;
    } else {
        dealerTotal += dealerFirstCard.value;
    }

    // Deal Player
    std::cout << "Player: ";
    dealCardAndTotal(playerAceCount, playerTotal);
    dealCardAndTotal(playerAceCount, playerTotal);
    std::cout << std::endl;
    std::cout << "Player Total: " << playerTotal << std::endl;

    if (playerTotal == 21) {
        std::cout << "\nPlayer has Blackjack! You win!\n" << std::endl;
        return;
    }

    // Player's turn
    std::string choice;
    std::cout << "(H)it or (S)tand: ";
    std::cin >> choice;

    while (choice == "h") {
        dealCardAndTotal(playerAceCount, playerTotal);
        std::cout << std::endl;
        std::cout << "Player Total: " << playerTotal << std::endl;

        if (playerTotal > 21) {
            std::cout << "Player Busts. You lose!" << std::endl;
            return;
        }

        std::cout << "(H)it or (S)tand: ";
        std::cin >> choice;
    }

    // Dealer's turn
    std::cout << "Dealer: ";
    showCard(dealerFirstCard);
    while (dealerTotal < 17) {
        dealCardAndTotal(dealerAceCount, dealerTotal);
    }
    std::cout << std::endl;

    // Compare player's and dealer's totals
    std::cout << "Player Total: " << playerTotal << std::endl;
    std::cout << "Dealer Total: " << dealerTotal << std::endl;

    if (dealerTotal > 21) {
        std::cout << "\nDealer Busts. You win!\n" << std::endl;
    } else if (playerTotal > dealerTotal) {
        std::cout << "\nWinner Winner Chicken Dinner!\n" << std::endl;
    } else if (playerTotal < dealerTotal) {
        std::cout << "\nYou lose!\n" << std::endl;
    } else {
        std::cout << "\nPush!\n" << std::endl;
    }
}

int main() {
    srand(time(0));

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        playBlackjackRound();
        std::cout << "Play again? (Y/N): ";
        std::cin >> playAgain;
        std::cout << std::endl;
    }

    return 0;
}
