#include <stdio.h>
#include <stdlib.h>

#define SIZE 4
int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t linelength;
    int total = 0;
    int count = 0;

    fp = fopen("./day-06.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int answer = 0;
    while ((linelength = getline(&line, &len, fp)) != -1)
    {
        
        for (int i = 0; i < linelength - 4; i++)
        {
            char buff[SIZE] = {0};
            for (int j = 0; j < SIZE; j++)
            {
                buff[j] = line[i+j];
            }
            int matches = 0;
            
            for (int n = 0; n < SIZE; n++)
            {
                for (int k = n + 1; k < SIZE; k++)
                {

                    if (buff[n] == buff[k])
                    {

                        matches = 1;
                        break;
                    }
                }
            }
            if (!matches)
            {
                answer = i +SIZE;
                printf("Answer: %d\n", answer);
                break;
            }
        }
    }
    // close the file
    fclose(fp);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}