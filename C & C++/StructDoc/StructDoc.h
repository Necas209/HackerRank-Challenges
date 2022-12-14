#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word
{
    char *data;
};

struct sentence
{
    struct word *data;
    int word_count; // denotes number of words in a sentence
};

struct paragraph
{
    struct sentence *data;
    int sentence_count; // denotes number of sentences in a paragraph
};

struct document
{
    struct paragraph *data;
    int paragraph_count; // denotes number of paragraphs in a document
};

struct document get_document(char *);
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document, int, int, int);
struct sentence kth_sentence_in_mth_paragraph(struct document, int, int);
struct paragraph kth_paragraph(struct document, int);
void print_word(struct word);
void print_sentence(struct sentence);
void print_paragraph(struct paragraph);
void print_document(struct document);
char *get_input_text();