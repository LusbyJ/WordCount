/*****************************************************************************/
/* Justin Lusby                                                              */
/* January 25th, 2018                                                        */
/* CS 241 Section 6                                                          */
/*****************************************************************************/
#include<stdio.h>
#define IN 1         /* If you are in a word */
#define OUT 0        /* If you are not in a word */

int fewestWords;     /* Keeps track of the line with the fewest words */
int fewestChars;     /* Keeps track of the line with the fewest chars */
int wordMin;         /* Keeps track of the lowest line word count */
int charMin;         /* Keeps track of the lowestt line char count */
int lineWord;        /* Number of words in current line */
int lineChar;        /* Number of chars in current line */
int firstChar;       /* Flag for lines without characters */
int state;           /* Keeps track if you are inside a word or not */
int wordCount, charCount, lineCount, c;

/*****************************************************************************
 * Main function of the program
 * Loops over each character from standard input
 * Counts each character occurance and word occurance for each line
 * Echos out original input line by line. With the line number preceeding each
 * line of input and the character count and word count for that line printed
 * in brackets at the end of the line.
 * At the end of the file, total character and word counts are printed out
 * as well as info on the lines with the fewest word and character occurences. 
 *****************************************************************************/
int main(void)
{
  /* initialize all values */
  wordMin = charMin = firstChar =0;
  wordCount = charCount = lineChar = lineWord = fewestWords = fewestChars = 0;
  lineCount = 0;
  state = OUT;
  
  /* Set line 0 to the highest limit so it's not included in any line counts */
  if(lineCount == 0);
  {
    wordMin = 15;
    charMin = 80;
  }
  
  /* Loop through input file */
  while((c = getchar()) != EOF)
  {
    while(firstChar < 1)
    {
      if(lineCount < 9)
      {
	printf(" %d. ", lineCount + 1);
	++firstChar;
      }
      else
      {
	printf("%d. ", lineCount + 1);
	++firstChar;
      }
    }
    if(c != '\n')
    {
      ++charCount;
      ++lineChar;
      printf("%c", c);
    }
    
    /* Check if inside a word or not */
    if(c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
    }
    else if(state == OUT)
    {
      state = IN;
      ++wordCount;
      ++lineWord;
    }
    
    if(c == '\n')
    {
      if(lineWord <= wordMin)
      {
	wordMin = lineWord;
	fewestWords = lineCount;
      }
      if(lineChar <= charMin)
      {
	charMin = lineChar;
	fewestChars = lineCount;
      }
      lineCount++;
      printf(" [%d,%d]\n", lineWord, lineChar);

      /* reset word count, char count, and firstChar for the next line */
      lineWord = lineChar = firstChar = 0;
    }
  }
  /* Print out total occurances and fewest occurance lines */
  printf("%d lines, %d words, %d characters\n",lineCount,wordCount, charCount);
  printf("Line %d has the fewest words with %d\n",fewestWords+1, wordMin);
  printf("Line %d has the fewest characters with %d\n",fewestChars+1, charMin);
  return 0;
}
