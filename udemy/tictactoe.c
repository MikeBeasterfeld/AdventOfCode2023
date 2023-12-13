#include <stdio.h>

void drawBoard(int board[10]);
int hasWinner(int board[10]);
char playerMapper(int *player);

int main(void)
{
    int board[10] = {};
    int currentPlayer = 1;
    int chosenSpace = 0;
    int winner = 0;

    do
    {
        printf("winner %i\n", winner);
        drawBoard(board);

        printf("Player %i please choose a space\n", currentPlayer);
        scanf("%i", &chosenSpace);

        board[chosenSpace] = currentPlayer;
        if (currentPlayer == 1)
            currentPlayer = 2;
        else
            currentPlayer = 1;

    } while ((winner = hasWinner(board)) == 0);

    printf("Player %i is the winner\n", winner);

    return 0;
}

int hasWinner(int board[10])
{
    if (board[1] != 0 && board[1] == board[2] && board[2] == board[3])
    {
        return board[1];
    }
    if (board[4] != 0 && board[4] == board[5] && board[5] == board[6] != 0)
        return board[4];
    if (board[7] != 0 && board[7] == board[8] && board[8] == board[9] != 0)
        return board[7];

    if (board[1] != 0 && board[1] == board[4] && board[4] == board[7] != 0)
        return board[1];
    if (board[2] != 0 && board[2] == board[5] && board[5] == board[8] != 0)
        return board[2];
    if (board[3] != 0 && board[3] == board[6] && board[6] == board[9] != 0)
        return board[3];

    if (board[1] != 0 && board[1] == board[5] && board[5] == board[9] != 0)
        return board[1];
    if (board[3] != 0 && board[3] == board[5] && board[5] == board[7] != 0)
        return board[3];

    return 0;
};

void drawBoard(int board[10])
{
    printf("_____________\n");
    printf("|   |   |   |\n");
    printf("| %c | %c | %c |\n", playerMapper(&board[1]), playerMapper(&board[2]), playerMapper(&board[3]));
    printf("|___|___|___|\n");
    printf("|   |   |   |\n");
    printf("| %c | %c | %c |\n", playerMapper(&board[4]), playerMapper(&board[5]), playerMapper(&board[6]));
    printf("|___|___|___|\n");
    printf("|   |   |   |\n");
    printf("| %c | %c | %c |\n", playerMapper(&board[7]), playerMapper(&board[8]), playerMapper(&board[9]));
    printf("|___|___|___|\n");
}

char playerMapper(int *player)
{
    if (*player == 1)
        return 'X';
    if (*player == 2)
        return 'O';
    return ' ';
}