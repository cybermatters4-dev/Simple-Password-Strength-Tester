#include <stdio.h> // includes I/O function etc.
#include <stdbool.h> // to include the bool data type which does not exist by default
#include<string.h> // to include string function like strlen() to get the length of a string
#include <ctype.h> // for islower(), isupper(), isdigit() isalptha() etc.

int password_score(const char* password) 
{
    int score = 0; // the variable to calculate the score
    // variables to check after the loop is finished
    bool has_lower = false; 
    bool has_upper = false;
    bool has_digit = false;
    bool has_good_length = false;
    bool has_specialchar = false;
    int passwordlength = strlen(password); // used to get the length of the password
    // loops through the characters of the string
    for (int i = 0; i < passwordlength; i++) 
    {
        char passchar = password[i];
        if (islower(passchar)) // checks if it is in lowercase letters
        {
            has_lower = true;
            
        }
        if (isupper(passchar)) // checks if it is in uppercase letters
        {
            has_upper = true;
           
        }
        if (isdigit(passchar)) // checks if it is a digit
        {
            has_digit = true;
           
        }
        if (passwordlength >= 12) // checks if the length of the string is longer or equal to 21
        {
            has_good_length = true;
           
        }
        if (!isalpha(passchar) && !isdigit(passchar)) // if it's not a normal character or a digit then it's a special character
        {
            has_specialchar = true;
            
        }
    }
    // Does the checks and increases the score
    if (has_lower)
     score++;
    if (has_upper)
     score++;
    if (has_digit)
     score++;
    if (has_good_length)
     score++;
    if (has_specialchar)
     score++;
    return score; // returns it to use it into our main function

}


int main() 
{
    char password[64]; // makes a password array which can fit up to 64 characters
    printf("Enter your password "); // the text that informs the user to enter the password
    scanf("%s",password); // scanf to get the input and store it in password, since it's array we do not need to specify the memory address with &
    printf("\n Your password score is %d/5",password_score(password));  // prints the password score based on the returned value we get
    return 0;
}
