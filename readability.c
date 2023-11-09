#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");

    int sentences = 0;
    int letters = 0;
    int words = 1;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            letters++;
        }
        else if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    printf("Letters: %i\n", letters);

    for (int i = 0; i < n; i++)
    {
        if (isspace(s[i]))
        {
            words++;
        }
    }
    printf("Words: %i\n", words);
    printf("Sentences: %i\n", sentences);

    float anl = ((float) letters / words) * 100;
    float ans = ((float) sentences / words) * 100;
    // Round the result
    int index = round(0.0588 * anl - 0.296 * ans - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

