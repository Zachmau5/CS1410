#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    string valueStr;
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
            valueStr = to_string(card.value);
    }

    string suitStr;
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

    cout << "|" << valueStr << " " << suitStr << " | ";
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

    cout << "=== Blackjack Round ===" << endl;

    // Dealer deals two cards, revealing only the first one
    Card dealerFirstCard = getRandomCard();
    cout << "Dealer: ";
    showCard(dealerFirstCard);
    cout << "| ? |" << endl;
    if (dealerFirstCard.value == 14) {
        dealerAceCount++;
        dealerTotal += 11;
    } else if (dealerFirstCard.value > 10) {
        dealerTotal += 10;
    } else {
        dealerTotal += dealerFirstCard.value;
    }

    // Deal Player
    cout << "Player: ";
    dealCardAndTotal(playerAceCount, playerTotal);
    dealCardAndTotal(playerAceCount, playerTotal);
    cout << endl;
    cout << "Player Total: " << playerTotal << endl;

    if (playerTotal == 21) {
        cout << "\nPlayer has Blackjack! You win!\n" << endl;
        return;
    }

    // Player's turn
    string choice;
    cout << "(H)it or (S)tand: ";
    cin >> choice;

    while (choice == "h") {
        dealCardAndTotal(playerAceCount, playerTotal);
        cout << endl;
        cout << "Player Total: " << playerTotal << endl;

        if (playerTotal > 21) {
            cout << "Player Busts. You lose!" << endl;
            return;
        }

        cout << "(H)it or (S)tand: ";
        cin >> choice;
    }

    // Dealer's turn
    cout << "Dealer: ";
    showCard(dealerFirstCard);
    while (dealerTotal < 17) {
        dealCardAndTotal(dealerAceCount, dealerTotal);
    }
    cout << endl;

    // Compare player's and dealer's totals
    cout << "Player Total: " << playerTotal << endl;
    cout << "Dealer Total: " << dealerTotal << endl;

    if (dealerTotal > 21) {
        cout << "\nDealer Busts. You win!\n" << endl;
    } else if (playerTotal > dealerTotal) {
        cout << "\nWinner Winner Chicken Dinner!\n" << endl;
    } else if (playerTotal < dealerTotal) {
        cout << "\nYou lose!\n" << endl;
    } else {
        cout << "\nPush!\n" << endl;
    }
}

int main() {
    srand(time(0));

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        playBlackjackRound();
        cout << "Play again? (Y/N): ";
        cin >> playAgain;
        cout << endl;
    }

    return 0;
}
