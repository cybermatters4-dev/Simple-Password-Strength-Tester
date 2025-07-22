#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include <ctype.h>
int password_score(const char* password) 
{
    int score = 0;
    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_good_length = false;
    bool has_specialchar = false;
    for (int i = 0; i < strlen(password); i++) 
    {
        char passchar = password[i];
        if (islower(passchar)) 
        {
            has_lower = true;
            
        }
        if (isupper(passchar)) 
        {
            has_upper = true;
           
        }
        if (isdigit(passchar)) 
        {
            has_digit = true;
           
        }
        if (strlen(password) >= 12) 
        {
            has_good_length = true;
           
        }
        if (!isalpha(passchar) && !isdigit(passchar)) 
        {
            has_specialchar = true;
            
        }
    }
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
    return score;

}


int main() 
{
    char password[64];
    printf("Enter your password ");
    scanf("%s",password);
    printf("\n Your password score is %d/5",password_score(password));
    return 0;
}
