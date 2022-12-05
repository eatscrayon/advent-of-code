#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
char *line = NULL;
size_t len = 0;
ssize_t linelength;
int total = 0;
int crates[8][64] = {0}; // Init the array

void print_top_boxes(int crates[8][64])
{
    for (int y = 0; y <= 8; y++)
    {
        for (int x = 0; x <= 64; x++)
        {
            if (crates[y][x]==0){
                printf("%c",crates[y][x-1]);
                break;
            }
        }
    }
    printf("\n");
}

void move_boxes(int crates[8][64], int num_boxes, int origin_col, int destination_col)
{
    for (int i = 0; i < num_boxes; i++)
    {

        int start = 0;
        for (int j = 0; j <= 64; j++)
        {
            if (crates[origin_col][j] == 0)
            {
                start = j - 1;
                break;
            }
        }
        int end = 0;
        for (int k = 0; k <= 64; k++)
        {
            if (crates[destination_col][k] == 0)
            {
                end = k + num_boxes-1-i;//Part 2 change
                break;
            }
        }

        crates[destination_col][end] = crates[origin_col][start];
        crates[origin_col][start] = 0;
    }
};

int main(void)
{
    fp = fopen("./day-05.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    int count = 0;
    int row = 7;
    while ((linelength = getline(&line, &len, fp)) != -1)
    {
        // Pull values from file and fill arrary of arrays
        if (row >= 0)
        {
            int col = 0;
            for (int i = 1; i < 35; i += 4)
            {
                // printf("Col: %d Row: %d Value: %c\n", col, row, line[i]);
                if (line[i] != 32) // not equal " "
                {
                    crates[col][row] = line[i];
                }
                else
                {
                    crates[col][row] = 0;
                }
                col++;
            }
            row--;
        }

        // Process instructions
        if (count >= 10)
        {
            // move num_boxes from origin_col to destination_col
            strtok(line, " "); // move
            int num_boxes = atoi(strtok(NULL, " "));
            strtok(NULL, " "); // from
            int origin_col = atoi(strtok(NULL, " ")) - 1;
            strtok(NULL, " "); // to
            int destination_col = atoi(strtok(NULL, " ")) - 1;
            move_boxes(crates, num_boxes, origin_col, destination_col);
        }
        count++;
    }
    // close the file
    fclose(fp);
    if (line)
        free(line);

    
    for (int j = 0; j < 9; j++)
    {
        for (int k = 0; k < 32; k++)
        {
            if (crates[j][k]==0){
                break;
            }
            printf("[%c] ", crates[j][k]);
        }
        printf("\n");
    }
    print_top_boxes(crates);
    exit(EXIT_SUCCESS);
}