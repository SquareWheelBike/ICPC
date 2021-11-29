// Chef and Typing

/**
 * find total time for chef to type all words
 * only uses 'd f j k', df on left and jk on right
 * 0.2 seconds to type first character, then 0.2 for same hand or 0.4 for changing hand
 * if word already typed before, it can be typed in half the time
 * 
 * starts with integer number of test cases
 * each test case starts with an integer number of words for that case, then the set of words for that set
 */

// gcc typing.c -Wall && ./a.out < input.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in_set(char *);
int add_to_set(char *);
void clear_set();
char hand(char);

// 100 is small enough we can just keep that many spaces in memory
char set[100][21]; // up to 100 words, 20 in length (plus a null terminator)
int wordtime[100], setsize = 0;

int main()
{
    int t; // test cases
    scanf(" %d", &t);
    //printf("%d test cases\n", t);

    char str[21]; // temp string to hold words as they come in, for processing

    for (int c = 0; c < t; c++)
    {
        int setsize;
        scanf(" %d", &setsize);
        //printf("set size %d: %d", c + 1, setsize);
        int score = 0;
        for (int i = 0; i < setsize; i++)
        {
            scanf("%s", str);
            int temp = in_set(str);
            //printf(" read <%s>, ", str);
            if (!temp)
            {
                temp = add_to_set(str);
                //printf("not in set, adding to set with score %d\n", temp);
            }
            else
            {
                temp /= 2;
                //printf("found in set, adding %d to score\n", temp);
            }
            score += temp;
        }
        printf("%d\n", score);
        clear_set(); // reset setsize to 0
    }
}

// returns word time if in set, 0 if not in set
int in_set(char *word)
{
    for (int i = 0; i < setsize; i++)
    {
        if (!strcmp(set[i], word))
        {
            return wordtime[i];
        }
    }
    return 0;
}

// adds new word to set, and returns size of new word
int add_to_set(char *word)
{
    int len = strlen(word);       // get word length
    strcpy(set[setsize], word);   // copy word into where it goes in set
    int score = 2;                // always 0.2s on first keypress
    char last = hand(word[0]);    // set hand to value of first keypress
    for (int i = 1; i < len; i++) // process remaining characters
    {
        char cur = hand(word[i]);
        if (last != cur)
        {
            score += 2;
            last = cur;
        }
        else
        {
            score += 4;
        }
    }
    wordtime[setsize] = score;
    ++setsize;
    return score;
}

char hand(char key)
{
    switch (key)
    {
    case 'd':
    case 'f':
        return 'l';
    case 'j':
    case 'k':
        return 'r';
    default:
        perror("character not in keyset");
        exit(0);
    }
}

void clear_set()
{
    setsize = 0;
}