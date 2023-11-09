#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_numeric(const char *str);
void encrypt(string s, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // atoi = string to int
    int key = atoi(argv[1]);

    if (!is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string text = get_string("Plaintext: ");

    encrypt(text, key);
    printf("Ciphertext: %s\n", text);
}

// Function is_numeric in command line
int is_numeric(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}
// Function encrypt (two args = string (text from user), key = positions from letters)
void encrypt(string s, int key)
{
    int n = strlen(s);
    // For while to last letter on string
    for (int i = 0; i < n; i++)
    {
        // Condition to uppercase letters
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            // Caesar algorithm
            // s[i] -> first letter of the string, receive s[i] - 'A' ascii first uppercase letter + key, % rest of division 26 + 'A';
            s[i] = (s[i] - 'A' + key) % 26 + 'A';
        }
        // Condition to lowercase letters
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (s[i] - 'a' + key) % 26 + 'a';
        }
    }


}
