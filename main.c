#include <stdio.h>
#include <string.h>

/* 

 _ __   __ _ _ __ __ _ _ __ ____ 
| '_ \ / _` | '__/ _` | '_ ` _  |      
| |_) | (_| | | | (_| | | | | | |
| .__/ \__,_|_|  \__,_|_| |_| |_|
| |                              
|_|                              
                                                        
                                                      
*/

main(argc, argv, envp)
    int argc;                /* Number of args */
    char *argv[];            /* Argument ptr array */
    char *envp[];            /* Environment ptr array */

{
    int a;                   /* re-used loop index variable */


    /* debug command; should normally be commented out */
    /*
    printf("\n\non entry argc is %i\n\n",argc);
    */


    /* dis-allow pathological invocation */
    if (argc < 2) 
    {
        printf("\nmust have at least one argument, ? for help\n\n");   
        return 0;
    }

    /* lend assistance to the user */
    //if (strcmp(argv[1],"?") || strcmp(argv[1], "-?"))
    if (!strcmp(argv[1],"?"))
    {
        printf("\nthis program prints out its own invocation\n");
        printf("give an 'omit' parameter to suppress environment variables\n"); 
        printf("give a 'full' parameter to see the environment variables\n"); 
        printf("give a '?' parameter to see this list again\n\n"); 
        return 0;
    }

    /* show the command */
    printf("\ncommand:\n\t%s\n", argv[0]);              

    /* show the argumeents to the command */
    printf("\narguments:\n");
    for (a=1; a<argc; a++)
        printf("\t%2d:\t%s\n", a, argv[a]);

    /* show the environment variables of the invoking shell */
    if (!strcmp(argv[1], "omit" ))
    {
        a = 0;
        printf("\nenvironment:\n");
        while (envp[a] != NULL)
            printf("\t%s\n", envp[a++]);
    };

    /* clean up */
    printf("\n");
    return 0;
}
