#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int tc;
    char piece;
    int rows, cols, max, min;
    rows = cols= max = min = tc = 0;
    scanf("%d", &tc);
    while(tc--){
        cin >> piece >> rows >> cols;
        if(rows>cols){
            max=rows;
            min=cols;
        }
        else{
            max=cols;
            min=rows;
        }
        switch (piece)
        {
        case 'r':
            printf("%d\n", min);
            break;
        case 'k':
            if(rows<=6 && cols<=6 ){
                printf("%d\n", max*2);
            }
            else{
                printf("%d\n", (int)ceil((max/2.0)*min));
            }
            break;
        case 'Q':
            printf("%d\n", min);
        break;
        case 'K':
            printf("%d\n", (int)(ceil(cols/2.0)* ceil(rows/2.0)));
        break;
        }
    }
    return 0;
}