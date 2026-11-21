#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int length, i;
    int upper = 0, lower = 0, digit = 0, special = 0;
    int score = 0;

    printf("=== Password Security Analyser ===\n");
    printf("Enter a password (no spaces): ");
    scanf("%99s", password);

    length = strlen(password);

    /* Check every character one by one */
    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
            upper = 1;
        else if (islower(password[i]))
            lower = 1;
        else if (isdigit(password[i]))
            digit = 1;
        else
            special = 1;
    }

    /* Check a few very common weak passwords */
    if (strcmp(password, "password") == 0 ||
        strcmp(password, "123456") == 0 ||
        strcmp(password, "qwerty") == 0 ||
        strcmp(password, "admin") == 0)
    {
        printf("\nThis is a very common password. Very Weak!\n");
        return 0;
    }

    /* Give points */
    if (length >= 8)
        score++;
    if (length >= 12)
        score++;
    if (upper)
        score++;
    if (lower)
        score++;
    if (digit)
        score++;
    if (special)
        score++;

    /* Show the report */
    printf("\n--- Report ---\n");
    printf("Length            : %d characters\n", length);
    printf("Uppercase letter  : %s\n", upper ? "Yes" : "No");
    printf("Lowercase letter  : %s\n", lower ? "Yes" : "No");
    printf("Number            : %s\n", digit ? "Yes" : "No");
    printf("Special character : %s\n", special ? "Yes" : "No");
    printf("Score             : %d / 6\n", score);

    if (score <= 2)
        printf("Strength          : Weak\n");
    else if (score <= 4)
        printf("Strength          : Medium\n");
    else
        printf("Strength          : Strong\n");

    /* Tips */
    printf("\n--- Tips ---\n");
    if (length < 8)
        printf("- Use at least 8 characters.\n");
    if (!upper)
        printf("- Add an uppercase letter (A-Z).\n");
    if (!lower)
        printf("- Add a lowercase letter (a-z).\n");
    if (!digit)
        printf("- Add a number (0-9).\n");
    if (!special)
        printf("- Add a special character like @ # $ !\n");

    return 0;
}
