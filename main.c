/*set ts=4 sw=4 sts=4 et nonu */    // to make vim happy
#include <stdio.h>                  // for printf()
#include <string.h>                 // for strlen() & etc.
#include <unistd.h>                 // for getopt()
#include <limits.h>                 // for CHAR_BIT

// the following to make printouts harder to lose
/* 

                                                       _       
 _ __ ___   __ _  __ _  ___  ___       _ __ ___   __ _(_)_ __  
| '_ ` _ \ / _` |/ _` |/ _ \/ _ \_____| '_ ` _ \ / _` | | '_ \.
| | | | | | (_| | (_| |  __/  __/_____| | | | | | (_| | | | | |
|_| |_| |_|\__,_|\__, |\___|\___|     |_| |_| |_|\__,_|_|_| |_|
                 |___/                                         



programmer notes:
Mon Feb 25 15:39:07 PST 2013
    created github acct. d-harvey2 passwd <jimmy's boat>2005
    pull from https://github.com/d-harvey2/magee.git
*/

// the following to make lawyers happy
/*

TITLE: GNU Free Documentation License

Copyright (C)  2014  Donald Cory Harvey [d.harvey2@ctec.clark.edu] for Clark College
       Permission is granted to copy, distribute and/or modify this document
       under the terms of the GNU Free Documentation License, Version 1.3
       or any later version published by the Free Software Foundation;
       with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
       Texts.  A copy of the license is included in the section entitled ''GNU
       Free Documentation License''.
*/

main(argc, argv, envp)       /* this is the emulation engine, no display here */
    int argc;                /* Number of args */
    char *argv[];            /* Argument ptr array */
    char *envp[];            /* Environment ptr array */

{
    int *p;                  /* used to snake out the size of a pointer */
    int a;                   /* re-used loop index variable */
    int opt = 1;             /* return from getopt() */
    static const char *optString = "f:ucepsth?";  // see getopt() documentation
                             /* 
                               c - show command
                               p - show parameters
                               u - get input from user
                               f - get command line from a file
                               e - show environment variables
                               s - show computer specific information
                               t - exercise a meaningless binary tree -- for now
                               h - show full help table
                               ? - show quick help list
                             */   
     
/* 
   getopt() processing--see also getopt_long() for support of -- prefix switches
   note, though, that getopt() is posix compliant, but getopt_long() isn't

   I find it easiest to arrange getopt() switch statement processing so that
   all the help is grouped tightly together at the top.
*/
if (argc==1) {                 // no arguments given
    printf("\n-? switch for help\n");
    return;  }
while((opt=getopt(argc, argv, optString)) != -1 ) {
    switch( opt ) {            
        case '?':              // invalid switch, or short help requested
            printf("\nswitches:\n");
            printf("    -c    to display the invoking command\n");
            printf("    -p    to display the command line parameters\n");
            printf("    -f    to get commands from a file, specify a file name\n");
            printf("    -u    to get commands from the user interactively\n");
            printf("    -e    to display the inherited environmental variables\n");
            printf("    -s    to display computer specific structure information\n");
            printf("    -t    to execute simulation \n");
            printf("    -h    to display more complete help\n");
            break;
        case 'h':              // long help requested
            printf("\nno long help yet  00  this is fake\n");
            printf("this program prints out its own invocation\n");
            printf("give an 'omit' parameter to suppress environment variables\n"); 
            printf("give a 'full' parameter to see the environment variables\n"); 
            printf("give a '?' parameter to see this list again\n"); 
            break;        


        case 'u':
            // printf("\ncommand:\t%s: \n", argv[0]);              
            printf("\nstubbed out -- prompt user for input\n");              
            break;
            
        case 'f':
            // printf("\ncommand:\t%s: \n", argv[0]);              
            printf("\nstubbed out prompt for get input from file:  %s\n", optarg);              
            break;
            
        case 't':
            // printf("\ncommand:\t%s: \n", argv[0]);              
            treewalk();
            break;
            
        case 'c':
            printf("\ncommand:\t%s: \n", argv[0]);              
            break;
            
        case 'p':
            printf("\narguments:\n");
            for (a=1; a<argc; a++) printf("\t%2d:\t%s\n", a, argv[a]);
            break;
            
        case 'e':
            /* show the environment variables of the invoking shell */
                a = 0;
                printf("\nenvironment:\n");
                while (envp[a] != NULL) printf("%i\t%s\n", a, envp[a++]);
            break;
           
        case 's':
            /* show machine-dependent internal values */
            printf("\nmachine-dependent internal structure:");
            printf("\n    size of char in bits = %d",CHAR_BIT);
            printf("\n\n    size of char = %d byte ", sizeof(char));
            printf("\n    size of short int = %d bytes ", sizeof(short int));
            printf("\n    size of int = %d bytes ", sizeof(int));
            printf("\n    size of long int = %d bytes ", sizeof(long int));
            printf("\n    size of long long int = %d bytes ", sizeof(long long int));
            printf("\n    size of float = %d bytes ", sizeof(float));
            printf("\n    size of double = %d bytes ", sizeof(double));
            printf("\n    size of integer pointer = %d bytes \n", sizeof(&p));
            break;

        default:
            printf("using getopt(), You shouldn't ever get here.\n");
            printf("getopt() intercepts invalid input\n");
            printf("and errors out directly, then returns ?\n");
            break;
    }
}


// show the raw command line absent the switch options
if (optind < argc)
    printf("\n command line entries less the switch options:\n");
while (optind < argc)
    printf("    %s\n", argv[optind++]);


/* clean up */
printf("\n");
return 0;
}
