#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <iterator>

int cash = 100;

void randomizeCards(char cards[])
{
    srand(time(NULL));

    int x, y, temp;

    for (int i = 0; i < 10; i++)
    {
        x = rand() % 3;
        y = rand() % 3;

        temp = cards[x];
        cards[x] = cards[y];
        cards[y] = temp;
    }
}

bool handleGuess(int bet, char gamemode)
{
    char cards[] = {'K', 'Q', 'J'};
    randomizeCards(cards);

    switch (gamemode)
    {
    case 'S':
    {
        srand(time(NULL));

        int guess;
        char correct = cards[rand() % 3];

        std::cout << "Guess the position of " << correct << " (1-3): ";
        std::cin >> guess;

        return cards[guess - 1] == correct;
    }
    break;

    case 'A':
    {
        char guess[3];

        std::cout << "Guess the arrangement of the deck, e.g. K Q J (space separated): ";
        std::cin >> guess[0] >> guess[1] >> guess[2];

        return (std::equal(std::begin(guess), std::end(guess), std::begin(cards)));
    }
    break;

    default:
        return false;
    }
}

int main()
{
    int bet;
    char mode;

    std::cout << "Enter gamemode (S for guessing single card, A for guessing full deck arrangement): ";
    std::cin >> mode;

    while (true)
    {
        std::cout << "Cash balance: " << cash << std::endl;
        std::cout << "Enter your bet (0 to quit the game): ";
        std::cin >> bet;
        if (bet <= 0)
        {
            std::cout << "Thanks for playing! Final cash balance: " << cash << std::endl;
            break;
        }

        bool win = handleGuess(bet, mode);
        std::cout << (win ? "You Win! Your bet amount was tripled and added to cash." : "You Lose :( Your bet amount was deducted from cash.") << std::endl;

        cash += (win ? (bet * 3) : (-bet));
    }

    return 0;
}