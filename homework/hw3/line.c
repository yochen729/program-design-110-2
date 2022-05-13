#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#define MAX_LINE_LEN 60
//#define MAX_WORD_LEN 20
 
int line_len = 0;
int num_words = 0;
 
struct node
{
  char word[MAX_LINE_LEN];
  struct node *next;
};
struct node *line = NULL;

void clear_line(void)
{
  struct node *ptr = line,*pre;
  while(ptr)
  {
    pre = ptr;
    ptr = ptr->next;
    free(pre);
  }
  line = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  struct node *ptr = (struct node*)malloc(sizeof(struct node));;
  ptr->next = NULL;

  if (num_words > 0) {
    line_len++;
  }
  strcpy(ptr->word,word);
  if (num_words == 0) {
    line = ptr;
  }
  else
  {
    struct node *temp = line;
    while(temp->next)
    {
      temp = temp->next;
    }
    temp->next = ptr;
  }

  line_len += strlen(word);
  //printf("line:%d\n",line_len);
  num_words++;
}
 
int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, i, j ,k;
 // printf("write:::");
  extra_spaces = MAX_LINE_LEN - line_len;
  struct node *temp = line;
    while (temp != NULL)
    {
      printf("%s",temp->word);
      if((num_words-1)==0 ) 
      {
        temp = temp->next;
        continue;
      }
      spaces_to_insert = extra_spaces / (num_words - 1);
      //printf("s:%ds",spaces_to_insert);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
      temp = temp->next;
    }
  putchar('\n');
}
 
void flush_line(void)
{
  if (line_len > 0)
  {
    struct node *temp = line;
    while(temp)
    {
      printf("%s ",temp->word);
      temp = temp->next;
    }
  }
}
