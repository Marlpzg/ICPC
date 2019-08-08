#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct element{
    char cRank = 'c';
    char cSuit = 'S';
};

int TC;
int X, Y;
char card[3];
vector<element> pile;
vector<element> hand;
element elem;
char val;

int getValue(char cardRank){
    int num = 10;
    switch(cardRank){
        case 'A': case 'T': case 'J': case 'Q': case 'K':
            num = 10;
            break;
        default:
            num = cardRank-'0';
            break;       
    }
    return num;
}

int main(){

    scanf("%d", &TC);

    for(int n=1; n <= TC; n++){

        X = Y = 0;
        pile.clear();
        hand.clear();

        for(int i=0; i<52; i++){

            scanf("%s", &card);
            elem.cRank = card[0];
            elem.cSuit = card[1];
            if(i < 27){
                pile.push_back(elem);
            }else{
                hand.push_back(elem);
            }
        }

        for(int i=0; i<3; i++){
            val = pile.at(pile.size()-1).cRank;
            pile.pop_back();
            X = getValue(val);
            Y += X;
            for(int j = 0; j < 10-X; j++){
                pile.pop_back();
            }
        }      

        pile.insert(pile.end(), hand.begin(), hand.end());

        printf("Case %d: %c%c\n", n, pile.at(Y-1).cRank, pile.at(Y-1).cSuit);
    }

    return 0;
}