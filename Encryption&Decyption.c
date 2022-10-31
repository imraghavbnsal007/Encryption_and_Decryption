/*Program Description:- This C program works to encrypt and decrypt the code user will enter. When user enter 1 it will ask for 4 digit pin then menu will re-appear and when user enter 2 encrypted code will appear and also that encrypted code will match wth the default code in option 3 it will decrypt that code again option 4 will count how many code succesfully or unsucessfully entered

Author:- Raghav Bansal

Student Number:- D20123625

Compiler used:- Visual Studio Code

Date:- 06/03/2021*/

//PROGRAM WILL ENCRYPT CODE ONCE

/*When user runs the code it will ask for choice if user select 1 then it will ask for code, THIS CODE WILL TAKE THE DIGIT ONE-BY-ONE eg:-
1
2
3
4*/

#include <stdio.h>

//this is the header file of function
#include <stdlib.h>

//Declaring universal size for array
#define SIZE 4

//declaring array as fixed by using const in gloabal scope
const int access_code[SIZE] = {4, 5, 2, 3};

//this variable will act as a counter for menu 4 also declaring in global scope. This will count how many time code succesfully entered
int counting = 0;

//this variable will work as counter for menu 4 also declaring in global scope. This will count how many time code unsuccessfully entered
int counting_unsuccesfull = 0;

//declaring j and enc_k in global scope
int enc_k = 0;
int j = 0;

//using functions outside the main

//function for taking the code
void enter_any_code(int *);

//function for encrypt the code
int encrypt_verify(int *);

//function for decrypt the code
void decrypt_code(int *);

//function for counting the code succesfully or unscessfully entered
void counter(int *);

//function for existing the program gracefully
int exit_program(void);

//main function in which switch and menu will be written to call the function after ending main
int main()
{
    //taking variable i
    int i;

    //arr is and array variable and initializing that 0000
    int arr[SIZE] = {0, 0, 0, 0};

    //taking variable choice that will act as a choice in menu
    int choice;

    //using do- while loop for running this code in a loop
    do
    { //start do

        //this is menu of the program
        printf("\n1. Enter any code\n");
        printf("2. Encrypt code entered and verify if correct\n");
        printf("3. Decrypt code\n");
        printf("4. Display the number of times the encrypted code entered correct and incorrect\n");
        printf("5. Exit program\n");

        printf("\nPlease choose an option(1-5)\n");

        //scanf will take value from the menu
        scanf("%d", &choice);

        // Clear the buffer to ignore the "Enter" key used to select the menu option
        fflush(stdin);

        printf("\n");

        //using switch statement for having cases for each menu
        switch (choice)
        { //start switch

        case 1:
        { //start case 1

            //in case 1 calling function here code for entering the code is after the main...when user enter 1 this enter_any_code will be called and it will go outside the main
            enter_any_code(arr);
            break;
        } // end case 1

        case 2:
        { //start case 2

            //printing the code which is stored for more clarification so user will know what is stored
            printf("\nStored code is:");

            for(i=0; i<SIZE;i++)
            {
                printf("%d" , arr[i]);
            }

            //using flag here, flag will count 1 and 0. Taking variable name main2_fg because there are more flags variable in the code thats why..
            int main2_fg = 0;
            enc_k = 0;
            fflush(stdin);
            encrypt_verify(arr);
            
            break;
        } //end case 2

        case 3:
        { //start case 3

            //printing encrypted code so user will know what is the encrypted code that will be decrypted for more clarification
            printf("\nThe encrypted code that will be decrypted is:");
            
            for(i=0;i<SIZE;i++)
            {
                printf("%d" , arr[i]);
            }

            //calling function decrypt outside the main
            decrypt_code(arr);
            break;
        } //end case 3

        case 4:
        { //start case 4

            //calling counter outside the main
            counter(arr);
            break;
        } //end case 4

        case 5:
        { //start case 5

            //taking variable name act as a flag named as a mainflag that will be used in exit program
            int mainflag;
            mainflag = exit_program();
            // exit_program();

            //using if statement
            if (mainflag == 1)
            { //start if

                //printf("You are tring to end the program\n");
                exit(0);

            } //end if

            //using another if statement
            if (mainflag == 0)
            {
                //continue the function fif user enter no
                continue;
            }
        }

        //default case: if user enter invalid like "a,/,%,b,*" it will show invalid output
        default:
        {
            printf("\nInvalid output, Please enter number that match with menu \n");
            break;
        } //end of default

        } //end of switch

        printf("\n------------------------------------------------------------------------------------------------------------------\n");
        //choice = 0;
    }
    //while loop
    while (1);

    return 0;
}

// Function enter_any_code() will ask and store a 4-digit code entered by the user
void enter_any_code(int *arr)
{ //start enter any code

    int i; //variable i

    printf("Enter a 4-digit pin\n*Press Enter afer each digit*\n");

    // Loop to accept 4-digit code
    //if user enter something invalid in between enetring the code like "1  a  2  3" this will not run it will just take 4 digit integer
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nCode succesfully entered and stored");

} //end enter any code

// Function encrypt_verify() encrypts the code and verify it with the access_code.
// It only encrypts the code only if the code is decrypted.
int encrypt_verify(int *arr)
{ //start encrypt_ verify


    int temp; //taking variable temp acts a temporary for used in swapping
    int i;              //varibale i
    int case2_flag = 0; //another flag variable named as case2_flag for counting 

    // Swapping 1st and 3rd digits in array 1st term is 0 and 3rd term is 2
    temp = *(arr + 0);
    *(arr + 0) = *(arr + 2);
    *(arr + 2) = temp;

    // Swapping 2st and 4rd digits in array 2st term is 1 and 4rd term is 3
    temp = *(arr + 1);
    *(arr + 1) = *(arr + 3);
    *(arr + 3) = temp;

    printf("\n\nCalculating Encrypted Code....\n");

    //using for loop for increament everytime user run the code by 1
    for (i = 0; i < SIZE; i++)
    { //start for

        //increment
        arr[i]++;

        //taking case where if the digit is greater than 9 or after increament it is greater then 9 it will converted to zero(0)
        if (arr[i] > 9)
        {
            arr[i] = 0;
            
        }

        printf("The Encrypted Code is: %d\n", arr[i]);
    }

    //counter for counting the encrypt loop
    int counter = 0;

    //using if statement....program will run once if user enters 2 twice then it will encrypt but will show error message also encrypted code will be ecrypted of previous once
    if (j >= 1)
    { //start if
        case2_flag = 1;

        printf("\nIt will run again because user have pressed 2 twice\n\nOutput will be different\n");

        printf("\nUser already decoded the access pin\n");
        
        return case2_flag;
    } //end if

    //using for loop
    for (i = 0; i < SIZE; i++)
    { //start for

        //using if statement inside for loop
        if (arr[i] == access_code[i])
        { //start if

            //increament of counter
            counter++;

        } //end if

    } //end for

    //VERIFICATION 
    //if statement
    if (counter == 4) //when user enter 1234 and its encrypted will be 4325 if that match this will run
    {//start if

        printf("\nVerifying....\n");

        printf("\nPin is matching with Default code\n");

        //this is counting that we declared in global scope and act as counting for menu 4
        counting++;

        j++; //increament of j 

    } //end if

    //otherwise this will run
    if (counter != 4)
    {//start if

        printf("\nVerifying....\n");

        printf("\nPin is not matching with default code \nOr Pin is not stored yet");

        //this is counting_unsuccesfull that we declared in global scope and act as counting unsuccesfully code entered for menu 4
        counting_unsuccesfull++;
        j++;

    }//end if 

    

    return 0;

} //end encrypt_verify

// Function decrypt() decrypts the code. It only decrypts the code only if the code is encrypted.
void decrypt_code(int *arr)

{ //start decrypt function code

    int temp; //taking temp act as temporary for swapping

    int i; //variable i

    for (i = 0; i < SIZE; i++)
    {
        arr[i]--;

        if (arr[i] < 0)
        {
            arr[i] = 9;
        }
    }

    // Swapping 1st and 3rd digits in array 1st term is 0 and 3rd term is 2
    temp = *(arr + 0);
    *(arr + 0) = *(arr + 2);
    *(arr + 2) = temp;

    // Swapping 2st and 4rd digits in array 2st term is 1 and 4rd term is 3
    temp = *(arr + 1);
    *(arr + 1) = *(arr + 3);
    *(arr + 3) = temp;

    printf("\nShowing Decrypted Code....");

    //for loop for printing decrypt code
    for (i = 0; i < SIZE; i++)
    {
        printf("\nThe Decrypted Code is : %d", arr[i]);
    }
} //end decrypt function code

//function counter
void counter(int *arr)

{ //start counter function

    printf("Code succesfully entered:%d\n", counting);

    printf("Code Unsuccessfully entered:%d", counting_unsuccesfull);

} //end counter function

//function for exiting the program gracefully
int exit_program(void)

{ //start exit_program

    //using char for taking character as a response for yes or no
    char answer;
    int flag = 0;

    printf("Are you sure you want to exit? [Y/N]\n");
    scanf("%c", &answer);

    //using if statement
    if (answer == 'y' || answer == 'Y')
    {
        printf("Thanks for using the program.....\nEnding program!!!");
        flag = 1;
        return flag;
    }
    else if (answer == 'n' || answer == 'N')
    {
        printf("\nReturning to main menu\n");
        flag = 0;
        return flag;
    }
    else
    {
        printf("\nPlease enter only Y or N capitalized or lower case. Otherwise Menu will appear again \n");
    }

} //end exit_program