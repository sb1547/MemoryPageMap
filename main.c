//
//  main.c
//  Memory Map Page
//
//  Created by Steven Bishop on 4/2/13.
//  Copyright (c) 2013 Steven Bishop. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//sb1547$ ps -ax | cut -c 1-6 | tee file.txt
//ps -ax 8831 for specific pid information
//ps -ax 8831 | cut -c 26-100 to get task for example mine sends back, login -pf sb1547
FILE *fr;
void main2();
void ProcRead()
{
    ///proc/cpuinfo
    FILE *f = fopen("foo12.txt", "r");
    size_t sz = 0;
    char * lin = 0;
    while (!feof (f)) {
        ssize_t lsz = getline (&lin, &sz, f);
        handle_line_of_size (lin, lsz);
    }
    fclose (f);
}
int main(int argc, const char * argv[])
{

    // insert code here...
  
    if(strcmp(argv[1], "13") == 0)
    {
          printf("Hello, Argument!\n");
    }
    char temp = *argv[1];
    if(system('ps -ax '+ temp )!= 0)
    {
        printf("Bad PID!\n");    }
    if(system("ps -ax | cut -c 1-6 | tee foo13.txt")!= 0)
    {
        printf("%s","Failed");
    }
    system("ls");
    ProcRead();
    //main2();
    

    return 0;
}
/**
 *http://stackoverflow.com/questions/8992430/any-idea-why-my-c-code-cant-read-from-proc
 */
int handle_line_of_size(char *lin,ssize_t *lsz)
{
    printf("value: %", lin);
    printf("value: %",  lsz);
}
void main2 ()
{
    int i;
    printf ("Checking if processor is available...");
    if (system(NULL))
        puts ("Ok");
    else
        exit(-1);
    printf ("Executing command DIR...\n");
    i=system ("dir");
    printf ("The value returned was: %d.\n",i);
    
}
//This is to manipulate the pid's to find a specfic one in the list
//    long elapsed_seconds;
//    char line[50];
//    fr = fopen ("foo13.txt", "rt");
//    /* open the file for reading */
//    /* elapsed.dta is the name of the file */
//    /* "rt" means open the file for reading text */
//    while(fgets(line, 50, fr) != NULL)
//    {
//        /* get a line, up to 80 chars from fr.  done if NULL */
//        sscanf (line, "%ld", &elapsed_seconds);
//        /* convert the string to a long int */
//        printf ("%ld\n", elapsed_seconds);
//    }
//    fclose(fr);
