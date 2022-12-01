#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t linelength;
    int total = 0;
    int count = 0;
    int max = 0;
    int firstplace =0;
    int secondplace =0;
    int thirdplace =0;
    
    int arr[SIZE] = {0};

    fp = fopen("./day-1.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((linelength = getline(&line, &len, fp)) != -1)
    {
        if (linelength == 1)
        {
            //printf("Count: %d Total: %d\n", count, total);

            arr[count++] = total;
            total = 0;
        }
        else
        {
            total = total + atoi(line);
        }
    }
    // close the file
    fclose(fp);
    if (line)
        free(line);


    //sorting values
    qsort(arr, SIZE, sizeof(int), cmpfunc);

    printf("Max: %d\n", arr[0]);
    printf("Top 3: %d\n",(arr[0]+arr[1]+arr[2]));
    exit(EXIT_SUCCESS);
}