#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

vector<char> spades;
vector<char> hearts;
vector<char> diamonds;
vector<char> clubs;

// 0-S, 1-H, 2-D, 3-C.
bool stopped[4];
int notrump;
int points;
int sizes[4];
int maxSize;
int maxSizePos;

char suit;
char crank;

string in;

void getPoints(char ctrank, int pos){
    switch(ctrank){
        case 'A':
            points += 4;
            stopped[pos] = true;
            notrump = points;
            break;
        case 'K':
            points += 3;
            if(sizes[pos]-1 < 1){
                points -= 1;
            }else{
                stopped[pos] = true;
            }
            notrump = points;
            break;
        case 'Q':
            points += 2;
            if(sizes[pos]-1 < 2){
                points -= 1;
            }else{
                stopped[pos] = true;
            }
            notrump = points;
            break;
        case 'J':
            points += 1;
            if(sizes[pos]-1 < 3){
                points -= 1;
            }
            notrump = points;
            break;
    }
}

int main(){
    
    while(getline(cin, in)){

        stopped[0] = stopped[1] = stopped[2] = stopped[3] = false;
        notrump = 0;
        points = 0;

        for(int i=0; i<13; i++){
            crank = in.at(3*i);
            suit = in.at((3*i)+1);

            if(suit == 'S'){
                spades.push_back(crank);
            }else if(suit == 'H'){
                hearts.push_back(crank);
            }else if(suit == 'D'){
                diamonds.push_back(crank);
            }else if(suit == 'C'){
                clubs.push_back(crank);
            }
        }
        
        sizes[0] = spades.size();
        sizes[1] = hearts.size();
        sizes[2] = diamonds.size();
        sizes[3] = clubs.size();

        for(int i = 0; i < sizes[0]; i++){
            getPoints(spades[i], 0);
        }

        for(int i = 0; i < sizes[1]; i++){
            getPoints(hearts[i], 1);
        }

        for(int i = 0; i < sizes[2]; i++){
            getPoints(diamonds[i], 2);
        }

        for(int i = 0; i < sizes[3]; i++){
            getPoints(clubs[i], 3);
        }

        if(stopped[0] && stopped[1] && stopped[2] && stopped[3] && notrump >= 16){
            printf("BID NO-TRUMP");
        }else{
            maxSize = 0;
            maxSizePos = -1;
            for(int i=0; i<4; i++){

                if(sizes[i] > maxSize){
                    maxSize = sizes[i];
                    maxSizePos = i;
                }

                if(sizes[i] == 2){
                    points += 1;
                }
                if(sizes[i] == 1){
                    points += 2;
                }
                if(sizes[i] == 0){
                    points += 2;
                }
            }

            if(points >= 14){
                switch(maxSizePos){
                    case 0:
                        printf("BID S");
                        break;
                    case 1:
                        printf("BID H");
                        break;
                    case 2:
                        printf("BID D");
                        break;
                    case 3:
                        printf("BID C");
                        break;
                }
            }else{
                printf("PASS");
            }

        }
        printf("\n");

        spades.clear();
        hearts.clear();
        diamonds.clear();
        clubs.clear();
    }

    return 0;
}