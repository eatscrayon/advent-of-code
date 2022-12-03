#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t linelength;
    int total = 0;
    int reset = 0;
    // open the file
    fp = fopen("./day-03.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int count = 0;
    char groupA[128] = {0};
    char groupB[128] = {0};
    char groupC[128] = {0};
    while ((linelength = getline(&line, &len, fp)) != -1)
    {
        count++;

        if (count == 1)
        {

            int i = 0;
            while (i < (linelength - 1))
            {
                groupA[i] = line[i];
                i++;
            }
        }
        else if (count == 2)
        {

            int i = 0;
            while (i < (linelength - 1))
            {
                groupB[i] = line[i];
                i++;
            }
        }
        else if (count == 3)
        {

            count = 0;
            int i = 0;
            while (i < (linelength - 1))
            {
                groupC[i] = line[i];
                i++;
            }

            int match = 0;

            for (int j = 0; j < strlen(groupA); j++)
            {

                for (int k = 0; k < strlen(groupB); k++)
                {

                    for (int l = 0; l < strlen(groupC); l++)
                    {

                        if (groupC[l] == groupA[j] && groupC[l] == groupB[k])
                        {

                            // adjust "score" of item
                            match = groupC[l] - 96;

                            if (match < 0)
                            {
                                match = match + 58;
                            }
                            total += match;

                            reset = 1;
                            goto done;
                        }
                    }
                }
            }
        }
    done:
        if (reset == 1)
        {
            reset = 0;
            for (int c = 0; c < 128; c++)
            {
                groupA[c] = 0;
                groupB[c] = 0;
                groupC[c] = 0;
            }
        }
    }
    // close the file
    fclose(fp);
    if (line)
        free(line);

    printf("Total: %d\n", total);
    exit(EXIT_SUCCESS);
}