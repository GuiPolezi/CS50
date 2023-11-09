#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototypes
int is_let(const char *str);
void encrypt(string s, string key);

int main(int argc, string argv[])
{
    // if argc not have 2 args
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // storing the argument after ./substitution
    char *argument = argv[1];
    // variable int receive length of argument
    int length = strlen(argument);
    // if not is letter (argv[1])
    if (!is_let(argv[1]))
    {
        printf("Error the key not accept numbers\n");
        return 1;
    }
    // if length of argument (argv[1]) is different than 26
    if (length != 26)
    {
        printf("The key must have contain 26 letters\n");
        return 1;
    }

    string phrase = get_string("Simple text: ");

    // Function encrypt
    encrypt(phrase, argument);
    printf("ciphertext: %s\n", phrase);
}

// function is letter
int is_let(const char *str)
{
    while (*str)
    {
        if (!isalpha(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function encrypt (two args = string (text from user), key = positions from letters)
void encrypt(string s, string key)
{

    int n = strlen(s);
    // loop for while i (0) is < n (length s), 0 = 0 + 1
    for (int i = 0; i < n; i++)
    {
        // if isalpha(s[i]) -> verify if s[i] is letter
        if (isalpha(s[i]))
        {
            // Character shift receive ternary operator, if s[i] is upper letter (if true -> shift = 'A', else 'a')
            char shift = isupper(s[i]) ? 'A' : 'a';
            // s[i] = each letter receive ternary operator, if s[i] is upper (then toupper each key letter[s[i] - shift] else tolower)
            s[i] = isupper(s[i]) ? toupper(key[s[i] - shift]) : tolower(key[s[i] - shift]);
        }
    }
}
