#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a player's turn
void snake(char user[20], int *p)
{
    int point = *p; // Get the current point of the player
    srand(time(NULL)); // Seed the random number generator
    int dice = rand() % 6 + 1; // Roll the dice (random number between 1 and 6)
    
    printf("%s, it's your turn...\nPress the Enter key to roll the dice.\n", user);
    getchar(); // Wait for Enter key press
    
    printf("%s, you rolled a %d.\n", user, dice);
    point += dice; // Update the player's point

    // Check for ladders and snakes
    switch (point)
    {
    case 4:
        point = 25; // Ladder from 4 to 25
        break;
    case 21:
        point = 39; // Ladder from 21 to 39
        break;
    case 29:
        point = 74; // Ladder from 29 to 74
        break;
    case 43:
        point = 76; // Ladder from 43 to 76
        break;
    case 63:
        point = 80; // Ladder from 63 to 80
        break;
    case 71:
        point = 89; // Ladder from 71 to 89
        break;
    case 30:
        point = 7; // Snake from 30 to 7
        break;
    case 47:
        point = 15; // Snake from 47 to 15
        break;
    case 56:
        point = 19; // Snake from 56 to 19
        break;
    case 73:
        point = 51; // Snake from 73 to 51
        break;
    case 82:
        point = 42; // Snake from 82 to 42
        break;
    case 92:
        point = 75; // Snake from 92 to 75
        break;
    case 98:
        point = 55; // Snake from 98 to 55
        break;
    }

    // Ensure the point doesn't exceed 100
    if (point > 100)
    {
        point -= dice; // Revert the move if it exceeds 100
    }
    
    printf("%s, your current point is %d.\n\n", user, point);

    // Update the player's point
    *p = point;

    // Display the board
    unsigned int j = 1;
    for (int i = 1; i <= 10; i++)
    {
        for (j; j <= 10 * i; j++)
        {
            if (point == j)
            {
                printf(" %s ", user); // Mark the player's position on the board
            }
            else
            {
                printf(" %d ", j); // Print the board numbers
            }
        }
        printf("\n");
    }
}

int main()
{
    int point1 = 0, point2 = 0; // Initialize points for both players
    char user1[20], user2[20];

    // Input player names
    printf("Enter your name, Player 1: ");
    scanf("%s", user1);
    getchar(); // Clear the input buffer

    printf("Enter your name, Player 2: ");
    scanf("%s", user2);
    getchar(); // Clear the input buffer

    // Game loop
    while (1)
    {
        snake(user1, &point1); // Player 1's turn
        snake(user2, &point2); // Player 2's turn

        // Check for a winner
        if (point1 >= 100)
        {
            printf("Congratulations %s, you win!\n", user1);
            break;
        }
        if (point2 >= 100)
        {
            printf("Congratulations %s, you win!\n", user2);
            break;
        }
        if (point1 >= 100 && point2 >= 100)
        {
            printf("%s and %s, your match is a tie!\n", user1, user2);
            break;
        }
    }

    return 0;
}
