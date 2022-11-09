#include "StructDoc.h"

struct document get_document(char *text)
{
    int len = strlen(text);
    text = realloc(text, (len + 1) * sizeof(char));
    strcat(text, "\n");

    struct document *Doc;
    char *paragraph, *sentence, *word;
    char *end_paragraph, *end_sentence, *end_word;
    int i = 0, j = 0, k = 0;

    Doc = malloc(sizeof(struct document));
    Doc->paragraph_count = 0;
    paragraph = strtok_r(text, "\n", &end_paragraph);
    while (paragraph != NULL)
    {
        Doc->paragraph_count++;
        if (i == 0)
            Doc->data = malloc(sizeof(struct paragraph));
        else
            Doc->data = realloc(Doc->data, Doc->paragraph_count * sizeof(struct paragraph));

        Doc->data[i].sentence_count = 0;
        sentence = strtok_r(paragraph, ".", &end_sentence);
        while (sentence != NULL)
        {
            Doc->data[i].sentence_count++;
            if (j == 0)
                Doc->data[i].data = malloc(sizeof(struct sentence));
            else
                Doc->data[i].data = realloc(Doc->data[i].data, Doc->data[i].sentence_count * sizeof(struct sentence));

            Doc->data[i].data[j].word_count = 0;
            word = strtok_r(sentence, " ", &end_word);
            while (word != NULL)
            {
                Doc->data[i].data[j].word_count++;
                if (k == 0)
                    Doc->data[i].data[j].data = malloc(sizeof(struct word));
                else
                    Doc->data[i].data[j].data = realloc(Doc->data[i].data[j].data, Doc->data[i].data[j].word_count * sizeof(struct word));

                Doc->data[i].data[j].data[k].data = (char *)malloc(strlen(word) * sizeof(char));
                strcpy(Doc->data[i].data[j].data[k].data, word);

                word = strtok_r(NULL, " ", &end_word);
                k++;
            }

            k = 0;
            sentence = strtok_r(NULL, ".", &end_sentence);
            j++;
        }

        j = 0;
        paragraph = strtok_r(NULL, "\n", &end_paragraph);
        i++;
    }
    return *Doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n)
{
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m)
{
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k)
{
    return Doc.data[k - 1];
}

void print_word(struct word w)
{
    printf("%s", w.data);
}

void print_sentence(struct sentence sen)
{
    for (int i = 0; i < sen.word_count; i++)
    {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1)
        {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para)
{
    for (int i = 0; i < para.sentence_count; i++)
    {
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc)
{
    for (int i = 0; i < doc.paragraph_count; i++)
    {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char *get_input_text()
{
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++)
    {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char *returnDoc = (char *)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}
