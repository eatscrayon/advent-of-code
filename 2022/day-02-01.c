#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t linelength;
    int count = 0;
    int scoreA = 0;
    int scoreB = 0;
    fp = fopen("./day-01.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    // A for Rock, B for Paper, and C for Scissors.
    // X for Rock, Y for Paper, and Z for Scissors
    // score 1 for Rock, 2 for Paper, and 3 for Scissors
    // score 0 if you lost, 3 if the round was a draw, and 6 if you won
    while ((linelength = getline(&line, &len, fp)) != -1)
    {
        char playerA = strtok(line, " ")[0] - 65;
        char playerB = strtok(NULL, " ")[0] - 88;

        // draw each player gets value of shape
        scoreA += playerA + 1;
        scoreB += playerB + 1;

        // draw each player gets 3 points
        if (playerA == playerB)
        {

            scoreA += 3;
            scoreB += 3;
        }

        // playerA wins
        if (((playerA | 1 << (2)) - (playerB | 0 << (2))) % 3)
        {
            scoreA += 6;
        }
        else
        {
            scoreB += 6;
        }
        count++;

        // printf("Round: %d PlayerA: %d PlayerB: %d\n", count, playerA, playerB);
    }
    printf("PlayerA Score: %d PlayerB Score: %d\n", scoreA, scoreB);
    // close the file
    fclose(fp);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}