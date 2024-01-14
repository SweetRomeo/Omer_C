#include <stdio.h>
#include <stdbool.h>

bool isValidCoordinate(int x, int y)
{
    return x >= 0 && x < 12 && y >= 0 && y < 12;
}

void setMines(char arena[12][12], int NumberOfMines) {
    for (int i = 0; i < NumberOfMines; ++i) {
        int x, y;
        printf("x?\n");
        scanf("%d", &x);
        printf("y?\n");
        scanf("%d", &y);
        if (isValidCoordinate(x, y)) {
            if (arena[x][y] == 'X') {
                printf("A mine is already placed here! Enter a new coordinate.\n");
                --i;
            } else {
                arena[x][y] = 'X';
            }
        } else {
            printf("Invalid Coordinates!\n");
            --i;
        }
    }
}

void count_bombs(int bombs[12][12], char arena[12][12])
{
    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            if(arena[i][j] == 'X')
            {
                printf("X ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (arena[i][j] == 'X') {
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < 12 && nj >= 0 && nj < 12 && !(di == 0 && dj == 0)) {
                            bombs[ni][nj]++;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            printf("%d ",bombs[i][j]);
        }
        printf("\n");
    }
}

void count_bombs_test(void)
{
    int bombs[12][12];
    char arena[12][12];
    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            arena[i][j] = '.';
        }
    }
    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            bombs[i][j] = 0;
        }
    }
    int NumberOfMines;
    printf("How many mines you would like to set?\n");
    (void)scanf("%d", &NumberOfMines);
    setMines(arena, NumberOfMines);
    count_bombs(bombs,arena);
}

int main()
{
    count_bombs_test();
    return 0;
}