#include <iostream>
#include <ctime>

void PrintIntroduction()
{
    // Print welcome messages to the terminal
    printf
    (
        "   ____                        _____     _       _     __  __\n"
        "  / ___| __ _ _ __ ___   ___  |_   _| __(_)_ __ | | ___\\ \\/ /\n"
        " | |  _ / _` | '_ ` _ \\ / _ \\   | || '__| | '_ \\| |/ _ \\\\  / \n"
        " | |_| | (_| | | | | | |  __/   | || |  | | |_) | |  __//  \\ \n"
        "  \\____|\\__,_|_| |_| |_|\\___|   |_||_|  |_| .__/|_|\\___/_/\\_\\\n"
        "                                          |_|                \n"
        "You are a secret agent\n"
        "    ------ \n"
        "   /      \\\n"
        "--  .    .  --\n"
        " \\  # -- #  /\n\n"

        "breaking into a secure server room...\n"
        "_________________________\n"
        "|  ___  |  ___  |  ___  |\n"
        "| |__ \\ | |__ \\ | |__ \\ |\n"
        "|   / / |   / / |   / / |\n"
        "|  |_|  |  |_|  |  |_|  |\n"
        "|  (_)  |  (_)  |  (_)  |\n"
        "|_______|_______|_______|\n\n"

        "Enter the correct code to continue...\n"
    );
}

void PrintLevelIntroduction(int LevelDiffculty)
{
    printf
    (
        "\n- Level %d\n\n"
        ,
        LevelDiffculty
    );
}

bool PlayGame(int LevelDifficulty)
{
    PrintLevelIntroduction(LevelDifficulty);

    // Declare 3 number codes
    const int CodeA = rand() % (LevelDifficulty + 1) + 1;
    const int CodeB = rand() % (LevelDifficulty + 1) + 1;
    const int CodeC = rand() % (LevelDifficulty + 1) + 1;

    const int CodeSum  = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    printf
    (
        "\n"
        "- Three are 3 nubmers in the code\n"
        "- The codes add-up to: %d\n"
        "- The codes multiply to: %d\n"
        "\n"
        ,
        CodeSum,
        CodeProduct
    );

    // Store player guess
    int GuessA, GuessB, GuessC;
    printf("> Please enter your guesses:\n");
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Chekc if the player's guess is right
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        printf
        (
            "\n$$ Code Correct! Level Passed! $$\n\n"
            "==================================================================\n"
            "==================================================================\n"
            "==================================================================\n\n"
        );
        return true;
    }
    else
    {
        printf
        (
            "\n~~ Wrong Code ~~\n\n"
            "==================================================================\n"
            "==================================================================\n"
            "==================================================================\n\n"
        );
        return false;
    }
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        prinf("%s\n", argv[i]);
    }
    srand(time(NULL));
    const int MaxDifficulty = 8;

    int LevelDifficulty = 1;
    PrintIntroduction();

    while (LevelDifficulty <= MaxDifficulty) // Loop games until all the levels are finished
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    printf
    (
        "***************************************************\n"
        "Congratulations! You have passed all the levels!!\n"
        "***************************************************\n\n"
    );

    return 0;
}
