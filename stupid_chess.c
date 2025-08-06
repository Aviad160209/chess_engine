#include <stdio.h>

int main()
{
    char chessBord[8][8];
    char move[10];
    int row=0;
    int col=0;
    int lenOfMove=3;
    int vale=0;
    int amountOfMoves=0;
    int rockRow=0;
    int j=0;
    for (row=0;row<8;row++)
    {
        for (col = 0; col < 8; col++)
        {
            if ((row==0&&col==0)||(row==0&&col==7))
            {
                chessBord[row][col]='r';
            }

            else if ((row==0&&col==1)||(row==0&&col==6))
            {
                chessBord[row][col]='n';
            }
            
            else if ((row==0&&col==2)||(row==0&&col==5))
            {
                chessBord[row][col]='b';
            }
            
            else if (row==0&&col==3)
            {
                chessBord[row][col]='k';
            }
            
            else if (row==0&&col==4)
            {
                chessBord[row][col]='q';
            }
            
            else if (row==1)
            {
                chessBord[row][col]='p';
            }
            
            else if (row==6)
            {
                chessBord[row][col]='P';
            }
            
            else if ((row==7&&col==0)||(row==7&&col==7))
            {
                chessBord[row][col]='R';
            }
            
            else if ((row==7&&col==1)||(row==7&&col==6))
            {
                chessBord[row][col]='N';
            }
            
            else if ((row==7&&col==2)||(row==7&&col==5))
            {
                chessBord[row][col]='B';
            }
            
            else if (row==7&&col==3)
            {
                chessBord[row][col]='K';
            }
            
            else if (row==7&&col==4)
            {
                chessBord[row][col]='Q';
            }
            
            else
            {
                chessBord[row][col]='.';
            }
        } 
    }
    while (amountOfMoves==0)
    {
        printf("white move: ");
        fgets(move, sizeof(move), stdin);
        if (move[0] == 'r') 
        {
            int targetRow = move[2] - '1';
            int targetCol;
            if (move[1] >= 'A' && move[1] <= 'H')
            {
                targetCol = move[1] - 'A';
            }
            else if (move[1] >= 'a' && move[1] <= 'h')
            {
                targetCol = move[1] - 'a';
            }
            else 
            {
                printf("Invalid column\n");
                continue;
            }

            int found = 0;

            for (row = 0; row < 8 && !found; row++) 
            {
                for (col = 0; col < 8; col++)
                {
                    if (chessBord[row][col] == 'r') 
                    {
                        // אם הצריח נמצא באותה עמודה
                        if (col == targetCol) 
                        {
                            int step = (targetRow > row) ? 1 : -1;
                            int clear = 1;
                            for (int i = row + step; i != targetRow; i += step) 
                            {
                                if (chessBord[i][col] != '.') 
                                {
                                    clear = 0;
                                    break;
                                }
                            }
                            if (clear) 
                            {
                                chessBord[targetRow][col] = 'r';
                                chessBord[row][col] = '.';
                                found = 1;
                                amountOfMoves++;
                                break;
                            }
                        }
                        // אם הצריח נמצא באותה שורה
                        else if (row == targetRow) 
                        {
                            int step = (targetCol > col) ? 1 : -1;
                            int clear = 1;
                            for (int i = col + step; i != targetCol; i += step) 
                        {
                            if (chessBord[row][i] != '.') 
                            {
                                clear = 0;
                                break;
                            }
                        }
                        if (clear) 
                        {
                            chessBord[row][targetCol] = 'r';
                            chessBord[row][col] = '.';
                            found = 1;
                            amountOfMoves++;
                            break;
                        }
                    }
                }
            }
        }
        if (!found) 
        {
            printf("Invalid rook move!\n");
        }
    }
    for (row = 0; row < 8; row++)
    {
        for ( col = 0; col < 8; col++)
        {
            printf("%c ",chessBord[row][col]);
        }
            printf("\n");
        }   
    }
    getchar();
}