/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** str_to_word_array
*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

static int count_words(const char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (isspace(str[i])) {
            i++;
        }
        if (str[i] != '\0') {
            count++;
        }
        while (!isspace(str[i]) && str[i] != '\0') {
            i++;
        }
    }
    return count;
}

static char **allocate_words(int count)
{
    char **words = malloc((count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }
    words[count] = NULL;
    return words;
}

static char *allocate_word(const char *str, int start, int end)
{
    char *word = malloc(sizeof(char) * (end - start + 1));

    if (word == NULL) {
        return NULL;
    }
    memcpy(word, &str[start], end - start);
    word[end - start] = '\0';
    return word;
}

static void add_word(char **words, const char *str, int *words_index, int *i)
{
    int j = *i;

    if (str[*i] != '\0') {
        while (!isspace(str[*i]) && str[*i] != '\0') {
            *i += 1;
        }
        words[*words_index] = allocate_word(str, j, *i);
        if (words[*words_index] != NULL)
            *words_index += 1;
    }
}

char **str_to_word_array(const char *str)
{
    int word_count = count_words(str);
    char **words = allocate_words(word_count);
    int i = 0;
    int words_index = 0;

    if (words == NULL)
        return NULL;
    while (str[i] != '\0') {
        while (isspace(str[i])) {
            i++;
        }
        if (str[i] != '\0') {
            add_word(words, str, &words_index, &i);
        }
    }
    return words;
}
