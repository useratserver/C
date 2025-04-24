#include <stdio.h>
#include <string.h>
#define MAXLINES 5000 //max lines to be sorted
#define BUFSIZE 5000
char *lineptr[MAXLINES]; //pointers to text lines
int readlines(char *lineptr[], char *buf, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
/* sort input lines */
int main()
{
int nlines; //number of input lines read
char buf[BUFSIZE];  
if ((nlines = readlines(lineptr, buf, MAXLINES)) >= 0)
{
printf("%d\n", nlines);
qsort(lineptr, 0, nlines - 1);
writelines(lineptr, nlines);
return 0;
}
else
{
printf("error: input too big to sort\n");
return 1;
}
}
#define MAXLEN 1000 //max lenght of any input line
int my_getline(char *, int);
/* readlines: read input lines */
int readlines(char *lineptr[], char *buf, int maxlines)
{
int len, nlines;
char line[MAXLEN];
char *p = buf;     
char *bufstop = buf + BUFSIZE;
nlines = 0;
while ((len = my_getline(line, MAXLEN)) > 0)
{
if (nlines >= maxlines || p + len > bufstop)
return -1;
else
{
line[len - 1] = '\0'; //delete newline
strcpy(p, line);
lineptr[nlines++] = p;
p += len;
}
}
return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
int i;
for (i = 0; i < nlines; i++)
printf("%s\n", lineptr[i]);
}
int my_getline(char *l, int lim)
{
int c;
char *tmp = l;
for (; --lim > 0 && (c=getchar()) != EOF && c!='\n'; l++)
*l = c;
if(c=='\n')
*l++ = c;
*l = '\0';
return l - tmp;
}
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *lineptr[], int left, int right)
{
int i, last;
void swap(char *lineptr[], int i, int j);
if (left >= right) //do nothing if array contains
return; //fewer than two elementes
swap (lineptr, left, (left + right)/2);
last = left;
for (i = left + 1; i <= right; i++)
if (strcmp(lineptr[i], lineptr[left]) < 0)
swap(lineptr, ++last, i);
swap(lineptr, left, last);
qsort(lineptr, left, last - 1);
qsort(lineptr, last + 1, right);
}
void swap(char *lineptr[], int i, int j)
{
char *temp;
temp = lineptr[i];
lineptr[i] = lineptr[j];
lineptr[j] = temp;
}
