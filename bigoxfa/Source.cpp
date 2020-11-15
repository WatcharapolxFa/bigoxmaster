#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>

#define NumCols 7
#define NumRow 7
#define ToTAl NumCols*NumRow
struct table
{
int row[ToTAl];
}go;

void shuffle();
void createCard();
void callNumber();
int main() {
    srand(time(NULL)); // seed number
    int players;
    printf("How many players ->");
    scanf_s("%d", &players);

    for (int i = 0; i < players; ++i) {
        createCard();
        printf("\n\n");
    }
    callNumber();
    return 0;
}
void shuffle(int* array, size_t n) {
    for (int i = 0; i <= n - 2; ++i) {
        int j = rand() % n;
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}

void createCard() {
    
    for (int i = 0; i < ToTAl; ++i) {
        go.row[i] = i + 1;
    }
    shuffle(go.row, 25);
    int* pim = &go.row[0];
    for (int i = 0; i < NumRow; ++i) {
        printf("|");
        for (int j = 0; j < NumCols; ++j) {
            if (i == NumCols/2 & j == NumRow/2) {
                printf("    |");
            }
            else {
                printf(" %2d |", *(pim++));
            }
        }
        printf("\n");
    }
}

void callNumber()
{
    for (int i = 0; i < ToTAl; ++i) {
        go.row[i] = i + 1;
    }
    shuffle(go.row, ToTAl);
    printf("Press enter key to call or 'Q' to Quit : \n");
    for (int j = 0; j < ToTAl; ++j)
    {
        if (toupper(getchar()) == 'Q')
        {
            break;
        }
        printf("%d\n", go.row[j]);
    }
    printf("Good Bye ........\n");

}