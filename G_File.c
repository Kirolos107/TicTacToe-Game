#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "G_File.h"
#include "STD_TYPES.h"


/**
  * @brief   Display game interface
  * @param   Array name
 **/
void DisplayGame(uint8 Arr[][7])
{
    printf("\n*********************************\n");
    printf("** Welcome To TIC TAC TOE Game **\n");
    printf("*********************************\n");

    uint8 i;
    uint8 j;
    uint8 k;

    // For initialize numbers in its position in game pattern
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 7; j++)
        {
            // We add (48) to convert from digit to character (ASCII)
            // Position is from (1 To 9), and at playing we put X or O
            if((i == 1) && (j % 2 != 0))
            {
                Arr[i][j] = (i + (j * .5) + 5.5) + 48;
            }
            else if((i == 3) && (j % 2 != 0))
            {
                Arr[i][j] = (i + (j * .5) + .5) + 48;
            }
            else if((i == 5) && (j % 2 != 0))
            {
                Arr[i][j] = (i + (j * .5) - 4.5) + 48;
            }
        }
    }

    // Drawing the pattern
    for(i = 0; i < 7; i++)
    {
        // For space, To make game patter almost in middle
        for(k = 0; k < 7; k++)
        {
            printf(" ");
        }

        for(j = 0; j < 7; j++)
        {
            if(i % 2 == 0)
            {
                if(j != 6)
                {
                    printf("---");
                }
            }
            else if (j % 2 == 0)
            {
                if(j == 0)
                {
                    printf ("|");
                }
                else
                {
                    printf (" | ");
                }
            }
            else
            {
                printf(" %c ", Arr[i][j]); // Assign the number in its position
            }
        }
        printf("\n");
    }
}
/************************************************************/
/************************************************************/
/**
  * @brief   Display the pattern only
  * @param   Array name
 **/
void DisplayOnlyPattern(uint8 Arr[][7])
{
    uint8 i;
    uint8 j;
    uint8 k;

    // For initialize numbers in its position in game pattern
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 7; j++)
        {
            // We add (48) to convert from digit to character (ASCII)
            // Position is from (1 To 9), and at playing we put X or O
            if((i == 1) && (j % 2 != 0))
            {
                Arr[i][j] = (i + (j * .5) + 5.5) + 48;
            }
            else if((i == 3) && (j % 2 != 0))
            {
                Arr[i][j] = (i + (j * .5) + .5) + 48;
            }
            else if((i == 5) && (j % 2 != 0))
            {
                Arr[i][j] = (i + (j * .5) - 4.5) + 48;
            }
        }
    }

    // Drawing the pattern
    for(i = 0; i < 7; i++)
    {
        // For space, To make game patter almost in middle
        for(k = 0; k < 7; k++)
        {
            printf(" ");
        }

        for(j = 0; j < 7; j++)
        {
            if(i % 2 == 0)
            {
                if(j != 6)
                {
                    printf("---");
                }
            }
            else if (j % 2 == 0)
            {
                if(j == 0)
                {
                    printf ("|");
                }
                else
                {
                    printf (" | ");
                }
            }
            else
            {
                printf(" %c ", Arr[i][j]); // Assign the number in its position
            }
        }
        printf("\n");
    }
}
/************************************************************/
/************************************************************/
/**
  * @brief   Game modes
  * @param   Array name
 **/
void Game_Modes(uint8 Arr[][7])
{
    sint8 User_Choice;
    GameInst();
    printf("\n");
    printf("  - Press (1)  For Single Mode\n  - Press (2)  For Multi Mode\n  - Press (-1) For Exit The Game\n\nPlease, Choose The Game Mode : ");
    scanf("%d", &User_Choice);

    // Display game menu
    switch(User_Choice)
    {
        case  1 : SingleMode_Game(Arr);                                         break;
        case  2 : MultiMode_Game(Arr);                                          break;
        case -1 : printf("Good Bye :), Have A Nice Time\n");                    break;
        default : printf("Invalid Choice..!, Choose Again !"); Game_Modes(Arr); break;
    }
}
/************************************************************/
/************************************************************/
/**
  * @brief   Display the game instruction
 **/
void GameInst(void)
{
    printf("Our Game Include Two Modes : \n\n"
           "You Will Only Use NumPad To Play, Press The Number To Put (X) Or (O) In The Required Position :)\n\n"
           "The First  Is => Single Mode, User Will Play Against The PC\n"
           "The Second Is => Multi Mode, Two User Will Play Against US\n\n"
           "Remember, To Quit From The Game, Press (-1) At Any Time\n");
}
/************************************************************/
/************************************************************/
/**
  * @brief   Putting (X) as user input from NumPad
  * @param   Array name
 **/
uint8 FirstPlayer_Moving(uint8 Arr[][7])
{
    sint8 User_Enter;
    uint8 Base;
    uint8 X_Pos;
    uint8 Y_Pos;
    uint8 i;
    uint8 j;
    uint8 k;

    while(1)
    {
        printf("\nEnter The Position You Want To Put 'X' : ");
        if((scanf("%d", &User_Enter) != 1) || (User_Enter < 1) || (User_Enter > 9)) // Neglect any input except (1 To 9)
        {
            if(User_Enter == -1) // When user enter (-1) at any time ==> return (Quit)
            {
                return 0;
            }
            else
            {
                fflush(stdin); // Clear buffer
                printf("Invalid Position..!!, Enter Position From (1) To (9)\n");
                }
        }
        else
        {
            if((User_Enter >= 7) && (User_Enter <= 9))
            {
                Base  = 7;
                X_Pos = 1;
                Y_Pos = GetCol(Base, User_Enter);
            }
            else if((User_Enter >= 4) && (User_Enter <= 6))
            {
                Base  = 4;
                X_Pos = 3;
                Y_Pos = GetCol(Base, User_Enter);
            }
            else if((User_Enter >= 1) && (User_Enter <= 3))
            {
                Base  = 1;
                X_Pos = 5;
                Y_Pos = GetCol(Base, User_Enter);
            }

            if((Arr[X_Pos][Y_Pos] != 'X') && (Arr[X_Pos][Y_Pos] != 'O'))
            // If the position assign by X or O, break ant ask user for valid position
            {
                Arr[X_Pos][Y_Pos] = 'X';
                break;
            }
            else
            {
                printf("This Position Is Full..!, Choose Empty Position From The Board :)\n");
            }
        }
    }

    printf("\n");
    // Drawing the pattern after assign (X) by user enter
    for(i = 0; i < 7; i++)
    {
        for(k = 0; k < 7; k++)
        {
            printf(" ");
        }

        for(j = 0; j < 7; j++)
        {
            if(i % 2 == 0)
            {
                if(j != 6)
                {
                    printf("---");
                }
            }
            else if (j % 2 == 0)
            {
                if(j == 0)
                {
                    printf ("|");
                }
                else
                {
                    printf (" | ");
                }
            }
            else
            {
                printf(" %c ", Arr[i][j]);
            }
        }
        printf("\n");
    }
    return 1;
}
/************************************************************/
/************************************************************/
/**
  * @brief   Putting (O) as user input from NumPad
  * @param   Array name
 **/
uint8 SecondPlayer_Moving(uint8 Arr[][7])
{
    sint8 User_Enter;
    uint8 Base;
    uint8 X_Pos;
    uint8 Y_Pos;
    uint8 i;
    uint8 j;
    uint8 k;

    while(1)
    {
        printf("\nEnter The Position You Want To Put 'O' : ");
        if((scanf("%d", &User_Enter) != 1) || (User_Enter < 1) || (User_Enter > 9)) // Neglect any input except (1 To 9)
        {
            if(User_Enter == -1) // When user enter (-1) at any time ==> return (Quit)
            {
                return 0;
            }
            else
            {
                fflush(stdin); // Clear buffer
                printf("Invalid Position..!!, Enter Position From (1) To (9)\n");
            }
        }
        else
        {
            if((User_Enter >= 7) && (User_Enter <= 9))
            {
                Base  = 7;
                X_Pos = 1;
                Y_Pos = GetCol(Base, User_Enter);
            }
            else if((User_Enter >= 4) && (User_Enter <= 6))
            {
                Base  = 4;
                X_Pos = 3;
                Y_Pos = GetCol(Base, User_Enter);
            }
            else if((User_Enter >= 1) && (User_Enter <= 3))
            {
                Base  = 1;
                X_Pos = 5;
                Y_Pos = GetCol(Base, User_Enter);
            }

            if((Arr[X_Pos][Y_Pos] != 'X') && (Arr[X_Pos][Y_Pos] != 'O'))
            // If the position assign by X or O, break ant ask user for valid position
            {
                Arr[X_Pos][Y_Pos] = 'O';
                break;
            }
            else
            {
                printf("This Position Is Full..!, Choose Empty Position From The Board :)\n");
            }
        }
    }

    printf("\n");
    // Drawing the pattern after assign (O) by user enter
    for(i = 0; i < 7; i++)
    {
        for(k = 0; k < 7; k++)
        {
            printf(" ");
        }

        for(j = 0; j < 7; j++)
        {
            if(i % 2 == 0)
            {
                if(j != 6)
                {
                    printf("---");
                }
            }
            else if (j % 2 == 0)
            {
                if(j == 0)
                {
                    printf ("|");
                }
                else
                {
                    printf (" | ");
                }
            }
            else
            {
                printf(" %c ", Arr[i][j]);
            }
        }
        printf("\n");
    }
    return 1;
}
/************************************************************/
/************************************************************/
///**
//  * @brief   Algorithm fr PC player
//  * @param   Array name
// **/
//uint8 PC_Player_Moving(uint8 Arr[][7])
//{
//    uint8 Base;
//    uint8 X_Pos;
//    uint8 Y_Pos;
//    uint8 i;
//    uint8 j;
//    uint8 k;
//
//    while(1)
//    {
//        uint8 Found = 0;
//        printf("\nNow, PC Will Play 'O'");
//
//        if((Arr[1][1] == Arr[3][3]) && (Arr[5][5] != 'X') && (Arr[5][5] != 'O'))
//        {
//            X_Pos = 5;
//            Y_Pos = 5;
//        }
//        else if((Arr[1][1] == Arr[5][5]) && (Arr[3][3] != 'X') && (Arr[3][3] != 'O'))
//        {
//            X_Pos = 3;
//            Y_Pos = 3;
//        }
//        else if((Arr[3][3] == Arr[5][5]) && (Arr[1][1] != 'X') && (Arr[1][1] != 'O'))
//        {
//            X_Pos = 1;
//            Y_Pos = 1;
//        }
//        else if((Arr[1][5] == Arr[3][3]) && (Arr[5][1] != 'X') && (Arr[5][1] != 'O'))
//        {
//            X_Pos = 5;
//            Y_Pos = 1;
//        }
//        else if((Arr[5][1] == Arr[3][3]) && (Arr[1][5] != 'X') && (Arr[1][5] != 'O'))
//        {
//            X_Pos = 1;
//            Y_Pos = 5;
//        }
//        else if((Arr[1][5] == Arr[5][1]) && (Arr[3][3] != 'X') && (Arr[3][3] != 'O'))
//        {
//            X_Pos = 3;
//            Y_Pos = 3;
//        }
//        else if (Arr[1][3] != 'X' && Arr[1][3] != 'O') // Additional condition
//        {
//            X_Pos = 1;
//            Y_Pos = 3;
//        }
//        else
//        {
//            for(i = 1; i < 7 && !Found; i+=2)
//            {
//                for(j = 1; j < 7 && !Found; j+=2)
//                {
//                    if((Arr[i][1] == Arr[i][3]) && (Arr[i][5] != 'X') && (Arr[i][5] != 'O'))
//                    {
//                        X_Pos = i;
//                        Y_Pos = 5;
//                        Found = 1;
//                    }
//                    else if((Arr[i][1] == Arr[i][5]) && (Arr[i][3] != 'X') && (Arr[i][3] != 'O'))
//                    {
//                        X_Pos = i;
//                        Y_Pos = 3;
//                        Found = 1;
//                    }
//                    else if((Arr[i][3] == Arr[i][5]) && (Arr[i][1] != 'X') && (Arr[i][1] != 'O'))
//                    {
//                        X_Pos = i;
//                        Y_Pos = 1;
//                        Found = 1;
//                    }
//                    else if((Arr[1][i] == Arr[3][i]) && (Arr[5][i] != 'X') && (Arr[5][i] != 'O'))
//                    {
//                        X_Pos = 5;
//                        Y_Pos = i;
//                        Found = 1;
//
//                    }
//                    else if((Arr[3][i] == Arr[5][i]) && (Arr[1][i] != 'X') && (Arr[1][i] != 'O'))
//                    {
//                        X_Pos = 1;
//                        Y_Pos = i;
//                        Found = 1;
//                    }
//                    else if((Arr[1][i] == Arr[5][i]) && (Arr[3][i] != 'X') && (Arr[3][i] != 'O'))
//                    {
//                        X_Pos = 3;
//                        Y_Pos = i;
//                        Found = 1;
//                    }
//                    else
//                    {
//                        if(Arr[i][j] != 'X')
//                        {
//                            X_Pos = i;
//                            Y_Pos = j;
//                            Found = 1;
//                        }
//                    }
//                }
//            }
//        }
//        printf("Arr[%d][%d]\n", X_Pos, Y_Pos);
//        Arr[X_Pos][Y_Pos] = 'O';
//        break;
//    }
//
//    printf("\n");
//    // Drawing the pattern after assign (O) by user enter
//    for(i = 0; i < 7; i++)
//    {
//        for(k = 0; k < 7; k++)
//        {
//            printf(" ");
//        }
//
//        for(j = 0; j < 7; j++)
//        {
//            if(i % 2 == 0)
//            {
//                if(j != 6)
//                {
//                    printf("---");
//                }
//            }
//            else if (j % 2 == 0)
//            {
//                if(j == 0)
//                {
//                    printf ("|");
//                }
//                else
//                {
//                    printf (" | ");
//                }
//            }
//            else
//            {
//                printf(" %c ", Arr[i][j]);
//            }
//        }
//        printf("\n");
//    }
//    return 1;
//}
/************************************************************/
/************************************************************/
/**
  * @brief   Algorithm for computer player in single mode
  * @param   Array name
 **/
/**
  * @brief   Algorithm for computer player in single mode
  * @param   Array name
 **/
uint8 PC_Player_Moving(uint8 Arr[][7])
{
    uint8 i;
    uint8 j;
    uint8 k;

    printf("\nNow, PC Will Play 'O'");
    // Iterate through the game board to find an empty position
    for(i = 1; i < 7; i += 2)
    {
        for (j = 1; j < 7; j += 2)
        {
            if(Arr[i][j] != 'X' && Arr[i][j] != 'O')
            {
                Arr[i][j] = 'O';  // Place 'O' in the first available empty position
                printf("\n");

                // Drawing the pattern after assigning 'O' by PC
                for(i = 0; i < 7; i++)
                {
                    for(k = 0; k < 7; k++)
                    {
                        printf(" ");
                    }
                    for(j = 0; j < 7; j++)
                    {
                        if (i % 2 == 0)
                        {
                            if(j != 6)
                            {
                                printf("---");
                            }
                        }
                        else if(j % 2 == 0)
                        {
                                if (j == 0)
                                {
                                    printf("|");
                                }
                                else
                                {
                                    printf(" | ");
                                }
                        }
                        else
                        {
                            printf(" %c ", Arr[i][j]);
                        }
                    }
                    printf("\n");
                }
                return 1;
            }
        }
    }
    return 0;  // If there are no empty positions, return 0 to indicate that the PC couldn't make a move
}
/************************************************************/
/************************************************************/
/**
  * @brief   Get the column after user enter the position
  * @param   Base (From 7->9 = 7, From 4->6 = 4, From 1->3 = 1)
  * @param   User input (Position at NumPad)
 **/
uint8 GetCol(uint8 Base, uint8 Input)
{
    uint8 Y_Pos;

    if((Input - Base) == 0)
    {

        Y_Pos = Input - Base + 1;
    }
    else if((Input - Base) == 1)
    {
        Y_Pos = Input - Base + 2;
    }
    else if((Input - Base) == 2)
    {
        Y_Pos = Input - Base + 3;
    }

    return Y_Pos;
}
/************************************************************/
/************************************************************/
//uint8 WinCondition(uint8 Arr[][7])
//{
//    Arr[1][1] == Arr[3][3] == Arr[5][5] ==> i == j
//
//    Arr[1][1] == Arr[1][3] == Arr[1][5]
//    Arr[3][1] == Arr[3][3] == Arr[3][5] ==> i == i, j += 2
//    Arr[5][1] == Arr[5][3] == Arr[5][5]
//
//    Arr[1][1] == Arr[3][1] == Arr[5][1]
//    Arr[1][3] == Arr[3][3] == Arr[5][3] ==> j == j, i += 2
//    Arr[1][5] == Arr[3][5] == Arr[5][5]
//
//    Arr[1][5] == Arr[3][3] == Arr[5][1] ==> i += 2, j -= 2
//}
/************************************************************/
/************************************************************/
/**
  * @brief   Determine the winner player
  * @param   Array name
 **/
uint8 WinCondition(uint8 Arr[][7])
{
    uint8 i;
    uint8 j;
    uint8 Status = 0;

    for(i = 1; i < 7; i+=2)
    {
        for(j = 1; j < 7; j+=2)
        {
            if((Arr[1][1] == Arr[3][3]) && (Arr[5][5] == Arr[1][1])) // Diagonal
            {
                Status = 1;
            }
            else if((Arr[1][5] == Arr[3][3]) && (Arr[5][1] == Arr[1][5])) // Diagonal
            {
                Status = 1;
            }
            else if((Arr[i][1] == Arr[i][3]) && (Arr[i][5] == Arr[i][1])) // Row
            {
                Status = 1;
            }
            else if((Arr[1][i] == Arr[3][i]) && (Arr[5][i] == Arr[1][i])) // Column
            {
                Status = 1;
            }
        }
    }
    return Status;
}
/************************************************************/
/************************************************************/
/**
  * @brief   Determine when the game is draw
  * @param   Array name
 **/
 uint8 DrawCondition(uint8 Arr[][7])
{
    uint8 Count_X  = 0;
    uint8 Count_O  = 0;
    uint8 Complete = 0;
    uint8 i;
    uint8 j;

    for(i = 1; i < 7; i += 2)
    {
        for(j = 1; j < 7; j += 2)
        {
            if(Arr[i][j] == 'X')
            {
                Count_X++;
            }
            if(Arr[i][j] == 'O')
            {
                Count_O++;
            }
        }
    }
    if((Count_X == 5) || (Count_O == 5)) // When user put X for five times and no winner ==> its draw
    {
        Complete = 1;
    }
    return Complete;
}
/************************************************************/
/************************************************************/
/**
  * @brief   Multi mode game
  * @param   Array name
 **/
void MultiMode_Game(uint8 Arr[][7])
{
    printf("\n              ==> Welcome To Multi Mode :) <==\n");
    printf("\n** Remember, To Quit From The Game, Press (-1) At Any Time **\n\n");

    uint8 First_Name[20];
    uint8 Second_Name[20];

    printf("Enter The Name Of First User  : ");
    scanf("%s", First_Name);

    printf("Enter The Name Of Second User : ");
    scanf("%s", Second_Name);

    printf("\n%s, Your Sign Is (X)\n", First_Name);
    printf("%s, Your Sign Is (O)\n", Second_Name);
    printf("\nGood Luck, To You Both\nLet's Go :)\n\n");
    DisplayOnlyPattern(Arr);
    printf("\n");

    while(1)
    {
        if(FirstPlayer_Moving(Arr))
        {
            if(WinCondition(Arr))
            {
                printf("Congratulations To Player %s (X) !!, You Are Win (:\nHard Luck To Player (O) ):\n", First_Name);
                break;
            }
            else if(DrawCondition(Arr))
            {
                printf("No Winner, The Match Is Draw :( \n");
                break;
            }
        }
        else
        {
            printf("Good Bye :), Have A Nice Time\n");
            return;
        }

        if(SecondPlayer_Moving(Arr))
        {
            if(WinCondition(Arr))
            {
                printf("Congratulations To Player %s (O) !!, You Are Win (:\nHard Luck To Player (O) ):\n", Second_Name);
                break;
            }
            else if(DrawCondition(Arr))
            {
                printf("No Winner, The Match Is Draw :( \n");
                break;
            }
        }
        else
        {
            printf("Good Bye :), Have A Nice Time\n");
            return;
        }
    }

    RepeatGame(Arr); // Ask user if he want to play again
}
/************************************************************/
/************************************************************/
/**
  * @brief   Single mode game
  * @param   Array name
 **/
void SingleMode_Game(uint8 Arr[][7])
{
    printf("\n              ==> Welcome To Single Mode :) <==\n");
    printf("\n** Remember, To Quit From The Game, Press (-1) At Any Time **\n\n");

    uint8 First_Name[20];
    printf("Enter The Name Of First User  : ");
    scanf("%s", First_Name);

    printf("\n%s, Your Sign Is (X)\n", First_Name);
    printf("PC, Your Sign Is (O)\n");
    printf("\nGood Luck, To You Both\nLet's Go :)\n\n");
    DisplayOnlyPattern(Arr);
    printf("\n");

    while(1)
    {
        if(FirstPlayer_Moving(Arr))
        {
            if(WinCondition(Arr))
            {
                printf("Congratulations To Player %s (X) !!, You Are Win (:\nHard Luck To Player (O) ):\n", First_Name);
                break;
            }
            else if(DrawCondition(Arr))
            {
                printf("No Winner, The Match Is Draw :( \n");
            }
        }
        else
        {
            printf("Good Bye :), Have A Nice Time\n");
            return;
        }

        if(PC_Player_Moving(Arr))
        {
            if(WinCondition(Arr))
            {
                printf("Congratulations To Player PC (O) !!, You Are Win (:\nHard Luck To Player (O) ):\n");
                break;
            }
            else if(DrawCondition(Arr))
            {
                printf("No Winner, The Match Is Draw :( \n");
                break;
            }
        }
        else
        {
            printf("Good Bye :), Have A Nice Time\n");
            return;
        }
    }

    RepeatGame(Arr); // Ask user if he want to play again
}
/************************************************************/
/************************************************************/
/**
  * @brief   Repeat the game
  * @param   Array name
 **/
 void RepeatGame(uint8 Arr[][7])
{
    while(1)
    {
        uint8 Rep_NoRep;
        printf("\nDo You Want To Play Again (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &Rep_NoRep);

        if((Rep_NoRep == 'Y') || (Rep_NoRep == 'y'))
        {
            system("cls");
            DisplayGame(Arr);
            Game_Modes(Arr);
        }
        else if((Rep_NoRep == 'N') || (Rep_NoRep == 'n'))
        {
            printf("Good Bye :), Have A Nice Time\n");
            break;
        }
        else
        {
            printf("Please Enter Valid Choice..!!\n");
        }
    }
}
/************************************************************/
/************************************************************/
