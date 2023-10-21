#include <stdio.h>
#include <stdlib.h>

#include "G_File.h"
#include "STD_TYPES.h"

int main()
{
    uint8 Arr[7][7] = {0};

    DisplayGame(Arr);

    Game_Modes(Arr);

    return 0;
}
