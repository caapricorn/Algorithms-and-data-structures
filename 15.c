/*Составьте программу frame.c, выполняющую рисование рамки вокруг текстовой строки*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    int rowCount = atoi(argv[1]);
    int columnCount = atoi(argv[2]);
    char* s = argv[3];
    int text = strlen(s);

    if (text > columnCount - 2 || rowCount < 3) {
        printf("Error");
        exit(EXIT_FAILURE);
    }

    int rowSr = (rowCount+1)/ 2;
    int columnSr = ((columnCount) - text) / 2;

    for (int i = 1; i <= rowCount; i++) {
        if (i == 1 || i == rowCount)
            for (int i = 0; i < columnCount; i++)
                printf("%c", '*');
        else if (i == rowSr) {
            for (int j = 0; j < columnCount; j++)
                if (j == 0 || j == columnCount - text)
                    printf("%c", '*');
                else if (j == columnSr)
                    printf("%s", s);
                else
                    printf("%c", ' ');
        } else {
            for (int j = 1; j <= columnCount; j++) {
                if (j == 1 || j == columnCount)
                    printf("%c", '*');
                else
                    printf("%c", ' ');
            }
        }
        printf("\n");
    }
    return 0;
}





