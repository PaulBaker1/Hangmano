#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void showHangman(int);

int main(void)
{
    char hangmanWord[100], tempWord[100];
    char hangmanOutput[100];
    int wrongTry = 6;
    int matchFound = 0;

    int counter = 0;
    int position = 0;
    int winner;
    int length;
    int i;
    char alphabetFromUser;

    system("cls");
    printf("\n\nPlease enter any word in small letters and press: Enter");
    printf("\n\n\t Your Word Here ==> ");
    scanf("%s",hangmanWord);
    printf("\n\n Now give the Computer to your Colleague and see they can win! ");
    printf("\n\n\t Press: Enter! ");
    getchar();
    length = strlen(hangmanWord);

    system("cls");

    printf("\n\n !!!Welcome To The HangMan Game!!!\n\n\n ");
    printf("\n\n You have 5 chances to guess the correct word ");
    printf("\n\n To save this man from his cruel demise! ");
    printf("\n\n So here you go! ");

    getchar();

    printf("\n\n\t Press Enter!");

    getchar();

    system("cls");

    printf("\n\t||===== ");
    printf("\n\t||    | ");
    printf("\n\t||      ");
    printf("\n\t||      ");
    printf("\n\t||      ");
    printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n",length);
    for(i=0; i<length; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] ='\0';
    }
    for(i = 0; i < length; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);
    }
    while(wrongTry !=0)
    {
        matchFound = 0;
        printf("\n\n Enetr any alphabet letter from a to z only in small cases! ");
        printf("\n\n\t Press Enter ==> ");

        fflush(stdin);

        scanf("%c",&alphabetFromUser);
        if(alphabetFromUser < 'a' || alphabetFromUser >'z')
        {
            system("cls");
            printf("\n\n\t Wrong input please try again! ");
            matchFound = 2;
        }
        fflush(stdin);
        if (matchFound !=2 )
        {
            for(counter=0; counter<length; counter++)
            {

                if(alphabetFromUser==hangmanWord[counter])
                {
                    matchFound = 1;
                }

            }
            if(matchFound == 0)
            {
                printf("\n\t :(You have &d tries left ",--wrongTry);
                getchar();
                showHangman(wrongTry);
                getchar();
            }
            else
            {
                for(counter = 0; counter < length; counter++)
                {
                    matchFound = 0;
                    if(alphabetFromUser == hangmanWord[counter])
                    {
                        position = counter;
                        matchFound = 1;
                    }
                    if(matchFound == 1)
                    {
                        for(i=0; i < length; i++)
                        {
                            if (i == position)
                            {
                                hangmanOutput[i] = alphabetFromUser;
                            }
                            else if(hangmanOutput[i]>='a'&&hangmanOutput[i]<='z')
                            {
                                continue;
                            }
                            else
                            {
                                hangmanOutput[i]='_';
                            }
                        }
                        tempWord[position] = alphabetFromUser;
                        tempWord[length] = '\0';
                        winner = strcmp(tempWord,hangmanWord);

                        if(winner == 0)
                        {
                            printf("\n\n\t \t  You are the winner! ");
                            printf("\n\n\t The Word was %s ",hangmanWord);
                            getchar();
                            return 0;
                        }
                    }
                }
            }
        }

        printf("\n\n\t");
        for(i = 0 ; i < length ; i++)
        {
            printf(" ");
            printf("%c",hangmanOutput[i]);                /**Show the original Word With blanks and right Input alphabet**/
        }

        getchar();
    }

    if(wrongTry <= 0)                                 /**if the player can not guess the whole word in 5 chaces**/
    {
        printf("\n\n\t The Word was %s ",hangmanWord);
        printf("\n\n\t The man is dead!");
        printf("\n\n\t Better luck next!");

    }
    getchar();
    return 0;
}



void showHangman(int choice)                            /**This function show the hangman after each wrong try**/
{

    switch(choice)
    {

    case 0:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/",'\\');
        printf("\n\t||    | ");
        printf("\n\t||   / %c",'\\');
        printf("\n\t||      ");
        break;
    case 1:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/",'\\');
        printf("\n\t||    | ");
        printf("\n\t||     %c",'\\');
        printf("\n\t||      ");
        break;
    case 2:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/",'\\');
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 3:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/",'\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 4:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO ",'\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 5:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||    O ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    }//end of switch-case
    return;
}
