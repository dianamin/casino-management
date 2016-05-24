
#include "Game.h"
#include <string>
#include<time.h>
#include<cstdlib>
using namespace std;

Expenditure blackjack::play(int nr) {
    sum = nr;

    srand(time(0));

    while(1) {
        cout << string( 100, '\n' );
        cout << "Budget: " << sum << "\n1 x - Bet x , 2 - Exit : ";
        int a, b;
        cin >> a;

        if(a == 1) {

            cin >> b;

            if(b > sum)
                continue;

            newBet(b);

        }
        else
            break;
    }

    return Expenditure("BlackJack", nr - sum, "666");
}

int blackjack::getCard() {
    int r = rand() % 13 + 1;

    if(r > 10)
        r = 10;

    return r;
}

void blackjack::newBet(int b) {
    sum -= b;

    int su = getCard() + getCard();
    int dl = getCard();

    cout << "Dealer : " << dl << "\n";
    while(1) {
        cout << "You : " << su << "  (1 - hit, 2 - stand)\n";

        if(su == 21) {
            cout << "Blackjack! won : " << 3 * b / 2 + b << "\n";

            sum += 3 * b / 2 + b;
        }

        int a;
        cin >> a;

        if(a == 1) {
            su += getCard();
            if(su > 21) {
                cout << su << " You lost.";
            }
        }
        else {

            while(dl < 17)
                dl += getCard();

            if(su == dl) {
                cout << "Draw.";
                sum += b;
            }

            if(dl > 21 || dl < su) {

                cout << "win : " << 2 * b << "\n";

                sum += 2 * b;
            }
        }
    }
}

Expenditure pacanea::play(int nr) {
    sum = nr;

    srand(time(0));

    while(1) {
        cout << string( 100, '\n' );
        cout << "Budget: " << sum << "\n1 x - Bet x , 2 - Exit : ";
        int a, b;
        cin >> a;

        if(a == 1) {

            cin >> b;

            if(b > sum)
                continue;

            newBet(b);

        }
        else
            break;
    }

    return Expenditure("Pacanea", nr - sum, "777");
}

void pacanea::newBet(int b) {
    int x[5], i;

    sum -= b;

    for(i = 0; i < 5; ++i) {
        x[i] = rand() % 8 + 1;

        cout << x[i] << " ";
    }

    if(x[0] == x[1] && x[1] == x[2]) {

        int win = (x[0] + 1) / 2 * b;

        if(x[0] == x[3]) {

            win *= 3;

            if(x[0] == x[4])
                win *= 3;

        }

        cout << "\n Win : " << win << "\n";

        sum += win;
    }
}
