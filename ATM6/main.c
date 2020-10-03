#include <stdio.h>

#define PINLENGTH 4

//Program by: Jakub Zareba, November 2018
//A simple ATM program to enter and change your PIN and check the number of login attempts
//Compiler used: CLion v2018.2.5 IDE with Cygwin compiler

int main()
{
    //Initializing variables
    int i, option, correctAttempts, incorrectAttempts, falsePin, notMatchingPin;
    char pinDefault[PINLENGTH] = {'1', '2', '3', '4'};
    char pinNew[PINLENGTH] = {'0'};
    char checkPin[PINLENGTH] = {'0'};
    char reenterPin[PINLENGTH] = {'0'};

    option = 0;
    i = 0;
    correctAttempts = 0;
    incorrectAttempts = 0;
    falsePin = 0;
    notMatchingPin = 0;


    // a do while loop to display menu in every iteration
    do
    {
        //resetting an option variable after each iteration
        option = 0;

        //Menu
        printf("1. Enter your PIN.\n");
        printf("2. Change PIN.\n");
        printf("3. Display number of times the PIN was entered.\n");
        printf("4. Exit.\n\n");


        //scanf along with loop which flushes the buffer to prevent excess input
        scanf("%d", &option);
        while (getchar() != '\n');

        //Switch for every menu option
        switch(option)
        {

            case 1:
            {
                printf("Enter your PIN:\n");

                //loop to read in user PIN
                for (i = 0; i < PINLENGTH; i++)
                {
                    checkPin[i] = getchar();
                }

                //flushing the buffer
                while (getchar() != '\n');

                //Comparison if entered pin matches the existing one
                for (i = 0; i < PINLENGTH; i++)
                {
                    if ( checkPin[i] == pinDefault[i] )
                    {
                        falsePin++;
                    }

                    else
                    {
                        falsePin = 10;
                    }
                }

                if (falsePin == 4)
                {
                    printf("PIN is correct.");
                    correctAttempts++;
                    falsePin = 0;
                }

                else
                {
                    printf("Incorrect PIN.");
                    incorrectAttempts++;
                    falsePin = 0;
                }


                printf("\n\n");
                break ;
            }//end case 1


            case 2:
            {
                printf("Enter your new PIN:\n");

                //a loop to read in new PIN
                for (i = 0; i < PINLENGTH; i++)
                {
                    pinNew[i] = getchar();
                }

                //flushing the buffer
                while (getchar() != '\n');

                printf("Re-enter your new PIN:\n");

                //a loop to read in array for verification
                for (i = 0; i < PINLENGTH; i++)
                {
                    reenterPin[i] = getchar();
                }

                //flushing the buffer
                while (getchar() != '\n');

                //a loop to compare and verify if the PINs are the same
                for (i = 0; i < PINLENGTH; i++)
                {
                    if ( pinNew[i] == reenterPin[i] )
                    {
                        notMatchingPin++;
                    }

                    else
                    {
                        notMatchingPin = 10;
                    }
                }

                if (notMatchingPin == 4)
                {
                    printf("Your PIN has been changed.\n\n");

                    //a loop to reset defaultPin variable and make it unreachable to the user
                    for (i = 0; i < PINLENGTH; i++)
                    {
                        pinDefault[i] = pinNew[i];
                    }
                }

                else
                {
                    printf("Your PIN does not match.\n\n");
                }


                notMatchingPin = 0;
                break;
            }//end case 2


            case 3:
            {
                // Display of both - correct and incorrect login attempts
                printf("Number of successful attempts: %d\n", correctAttempts);
                printf("Number of unsuccessful attempts: %d\n\n", incorrectAttempts);
                break;
            }//end case 3


            case 4:
            {
                //Exiting the loop
                printf("Program Closed.");
                break;
            }//end case 4


            default:
            {
                //Answer for every unspecified input
                printf("Invalid input.\n\n");
                break;
            }//end default


        }//end switch

    } //end do

    while (option != 4);

    return 0;

} // end main