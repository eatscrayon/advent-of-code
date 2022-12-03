#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t linelength;
    int linecount = 0;
    int total = 0;
    int arr[SIZE] = {0};

    // open the file
    fp = fopen("./day-03.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    // read it line by line
    while ((linelength = getline(&line, &len, fp)) != -1)
    {
        int i = 0;
        char pocketA[128] = {0};
        char pocketB[128] = {0};
        // split each line in half and save
        while (i < (linelength - 1) / 2)
        {
            pocketA[i] = line[i];
            pocketB[i] = line[i + ((linelength - 1) / 2)];
            i++;
        }
        char match = 0;
        // nested for loops to find a match
        for (int j = 0; j < strlen(pocketA); j++)
        {
            for (int k = 0; k < strlen(pocketB); k++)
            {
                if (pocketA[j] == pocketB[k])
                {
                    // adjust "score" of item
                    match = pocketA[j] - 96;

                    if (match < 0)
                    {
                        match = match + 58;
                    }
                    total += match;
                    goto done; // lol
                }
            }
        }
    done:
        linecount++;
    }
    // close the file
    fclose(fp);
    if (line)
        free(line);

    printf("Total: %d\n", total);
    exit(EXIT_SUCCESS);
}