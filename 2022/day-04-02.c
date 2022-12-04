#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t linelength;

    fp = fopen("./day-04.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int total = 0;
    while ((linelength = getline(&line, &len, fp)) != -1)
    {
        int elfA1 = atoi(strtok(line, "-,"));
        int elfA2 = atoi(strtok(NULL, "-,"));
        int elfB1 = atoi(strtok(NULL, "-,"));
        int elfB2 = atoi(strtok(NULL, "-,"));

        if ((elfA1 <= elfB2 && elfA2 >= elfB1) ||
            (elfA1 >= elfB2 && elfA2 <= elfB1))
        {
            total++;
            printf("ELFA: %d %d ELFB: %d %d Total: %d\n", elfA1, elfA2, elfB1, elfB2, total);
        }
    }
    // close the file
    fclose(fp);
    if (line)
        free(line);
    printf("Total: %d\n", total);
    exit(EXIT_SUCCESS);
}