#include <stdio.h>
#include <string.h>


/*


       _                                 
      | |                                
 _ __ | |__   __ _ _ __  _ __   ___ _ __ 
| '_ \| '_ \ / _` | '_ \| '_ \ / _ \ '__|
| | | | |_) | (_| | | | | | | |  __/ |   
|_| |_|_.__/ \__,_|_| |_|_| |_|\___|_|   
                                         



*/

/*
  more fullblown alternative to this code:
  figlet online: //www.network-science.de/ascii/
  good choices: stop *standard* smsslant small
                slant script big banner banner3
                doh doom

*/

enum {
    A = 1<<0,
    B = 1<<1,
    C = 1<<2,
    D = 1<<3,
    E = 1<<4,
    F = 1<<5,
    G = 1<<6,
    H = 1<<7,
};

char vec[] = " 0123456789"
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    ".,:!/\\|+-*=";

unsigned char map[sizeof(vec)][8] = {
    /* */ {A, B, C, D, E, F, G, H}, /* :) */
    /*0*/ {B|C|D|E|F, A|F|G, A|E|G, A|D|G, A|C|G, A|B|G, B|C|D|E|F, 0},
    /*1*/ {G, F|G, G, G, G, G, G, 0},
    /*2*/ {B|C|D|E|F, A|G, G, C|D|E|F, B, A, A|B|C|D|E|F|G, 0},
    /*3*/ {B|C|D|E|F, A|G, G, C|D|E|F, G, A|G, B|C|D|E|F, 0},
    /*4*/ {A|F, A|F, A|F, B|C|D|E|F|G, F, F, F, 0},
    /*5*/ {A|B|C|D|E|F|G, A, A, B|C|D|E|F, G, A|G, B|C|D|E|F, 0},
    /*6*/ {B|C|D|E|F, A, A, A|B|C|D|E|F, A|G, A|G, B|C|D|E|F, 0},
    /*7*/ {B|C|D|E|F|G, G, F, E, D, C, B, 0},
    /*8*/ {B|C|D|E|F, A|G, A|G, B|C|D|E|F, A|G, A|G, B|C|D|E|F, 0},
    /*9*/ {B|C|D|E|F, A|G, A|G, B|C|D|E|F|G, G, G, B|C|D|E|F, 0},
    /*a*/ {0, 0, B|C|D|E, F, B|C|D|E|F, A|F, B|C|D|E|G, 0},
    /*b*/ {B, B, B, B|C|D|E|F, B|G, B|G, A|C|D|E|F, 0},
    /*c*/ {0, 0, C|D|E, B|F, A, A, B|F, C|D|E},
    /*d*/ {F, F, F, B|C|D|E|F, A|F, A|F, B|C|D|E|G, 0},
    /*e*/ {0, 0, B|C|D|E, A|F, A|B|C|D|E|F, A, B|C|D|E, 0},
    /*f*/ {C|D|E, B, B, A|B|C|D, B, B, B, 0},
    /*g*/ {0, 0, B|C|D|E|G, A|F, A|F, B|C|D|E, F, B|C|D|E},
    /*h*/ {B, B, B, B|C|D|E, B|F, B|F, A|B|F, 0},
    /*i*/ {0, C, 0, B|C, C, C, A|B|C|D|E, 0},
    /*j*/ {0, D, 0, D, D, D, A|D, B|C},
    /*k*/ {B, B|E, B|D, B|C, B|D, B|E, A|B|E|F, 0},
    /*l*/ {A|B, B, B, B, B, B, A|B|C, 0},
    /*m*/ {0, 0, 0, A|C|E|F, A|B|D|G, A|D|G, A|D|G, 0},
    /*n*/ {0, 0, 0, B|D|E, B|C|F, B|F, B|F, 0},
    /*o*/ {0, 0, B|C|D|E, A|F, A|F, A|F, B|C|D|E, 0},
    /*p*/ {0, 0, A|B|C|D|E, B|F, B|F, B|C|D|E, B, A|B},
    /*q*/ {0, 0, B|C|D|E|G, A|F, A|F, B|C|D|E, F, F|G},
    /*r*/ {0, 0, A|B|D|E, B|C|F, B, B, A|B, 0},
    /*s*/ {0, 0, B|C|D|E, A, B|C|D|E, F, A|B|C|D|E, 0},
    /*t*/ {0, C, C, A|B|C|D|E, C, C, D|E, 0},
    /*u*/ {0, 0, A|F, A|F, A|F, A|F, B|C|D|E|G, 0},
    /*v*/ {0, 0, A|G, B|F, B|F, C|E, D, 0},
    /*w*/ {0, 0, A|G, A|G, A|D|G, A|D|G, B|C|E|F, 0},
    /*x*/ {0, 0, A|F, B|E, C|D, B|E, A|F, 0},
    /*y*/ {0, 0, B|F, B|F, B|F, C|F, A|D|E, B|C|D},
    /*z*/ {0, 0, A|B|C|D|E|F, E, D, C, B|C|D|E|F|G, 0},
    /*A*/ {D, C|E, B|F, A|G, A|B|C|D|E|F|G, A|G, A|G, 0},
    /*B*/ {A|B|C|D|E, A|F, A|F, A|B|C|D|E, A|F, A|F, A|B|C|D|E, 0},
    /*C*/ {C|D|E, B|F, A, A, A, B|F, C|D|E, 0},
    /*D*/ {A|B|C|D, A|E, A|F, A|F, A|F, A|E, A|B|C|D, 0},
    /*E*/ {A|B|C|D|E|F, A, A, A|B|C|D|E, A, A, A|B|C|D|E|F, 0},
    /*F*/ {A|B|C|D|E|F, A, A, A|B|C|D|E, A, A, A, 0},
    /*G*/ {C|D|E, B|F, A, A, A|E|F|G, B|F|G, C|D|E|G, 0},
    /*H*/ {A|G, A|G, A|G, A|B|C|D|E|F|G, A|G, A|G, A|G, 0},
    /*I*/ {A|B|C|D|E, C, C, C, C, C, A|B|C|D|E, 0},
    /*J*/ {A|B|C|D|E, C, C, C, C, C, A|C, B},
    /*K*/ {A|F, A|E, A|D, A|B|C, A|D, A|E, A|F, 0},
    /*L*/ {A, A, A, A, A, A, A|B|C|D|E|F, 0},
    /*M*/ {A|B|F|G, A|C|E|G, A|D|G, A|G, A|G, A|G, A|G, 0},
    /*N*/ {A|G, A|B|G, A|C|G, A|D|G, A|E|G, A|F|G, A|G, 0},
    /*O*/ {C|D|E, B|F, A|G, A|G, A|G, B|F, C|D|E, 0},
    /*P*/ {A|B|C|D, A|E, A|E, A|B|C|D, A, A, A, 0},
    /*Q*/ {C|D|E, B|F, A|G, A|G, A|C|G, B|D|F, C|D|E, F|G},
    /*R*/ {A|B|C|D, A|E, A|E, A|B|C|D, A|E, A|F, A|F, 0},
    /*S*/ {C|D|E, B|F, C, D, E, B|F, C|D|E, 0},
    /*T*/ {A|B|C|D|E|F|G, D, D, D, D, D, D, 0},
    /*U*/ {A|G, A|G, A|G, A|G, A|G, B|F, C|D|E, 0},
    /*V*/ {A|G, A|G, B|F, B|F, C|E, C|E, D, 0},
    /*W*/ {A|G, A|G, A|G, A|G, A|D|G, A|C|E|G, B|F, 0},
    /*X*/ {A|G, A|G, B|F, C|D|E, B|F, A|G, A|G, 0},
    /*Y*/ {A|G, A|G, B|F, C|E, D, D, D, 0},
    /*Z*/ {A|B|C|D|E|F|G, F, E, D, C, B, A|B|C|D|E|F|G, 0},
    /*.*/ {0, 0, 0, 0, 0, 0, D, 0},
    /*,*/ {0, 0, 0, 0, 0, E, E, D},
    /*:*/ {0, 0, 0, 0, D, 0, D, 0},
    /*!*/ {D, D, D, D, D, 0, D, 0},
    /*/ */ {G, F, E, D, C, B, A, 0},
    /*\\*/ {A, B, C, D, E, F, G, 0},
    /*|*/ {D, D, D, D, D, D, D, D},
    /*+*/ {0, D, D, B|C|D|E|F, D, D, 0, 0},
    /*-*/ {0, 0, 0, B|C|D|E|F, 0, 0, 0, 0},
    /***/ {0, B|D|F, C|D|E, D, C|D|E, B|D|F, 0, 0},
    /*=*/ {0, 0, B|C|D|E|F, 0, B|C|D|E|F, 0, 0, 0}
};

int enc(int c) { return strchr(vec,c)-vec; }

void show(char *s) {
    int row,col;
    char *sp;
    for (row=0; row<8; row++, putchar('\n'))
        for (sp = s; *sp; sp++)
            if (strchr(vec,*sp)!=NULL)
                for (col=0; col<8; col++)
                    putchar(map[enc(*sp)][row] & 1<<col ? *sp:' ');
}

int main(int c,char **v) {
    char banner[100];

    if (c > 1)
        for (--c,++v;*v;v++,c--) show(*v);
    else {
        fgets(banner, 100, stdin);
        show(banner);
    }
    return 0;
}


/*
   01234567  01234567  01234567  01234567  01234567  01234567
0   #####               #           ###               #
1  #     #              #          #                  #
2  #     #    ####      #          #        #### #    #
3   #####         #     #####    #####     #    #     ####
4  #     #    #####     #    #     #       #    #     #   #
5  #     #   #    #     #    #     #        ####      #   #
6   #####     #### #   # ####      #            #    ##   #
7                                           ####
*/

/*
   01234567  01234567  01234567  01234567  01234567  01234567
0                       #
1    #          #       #  #
2                       # #      #         #####      #### #
3   ##          #       ##       ### ##     #   #    #    #
4    #          #       # #      #  #  #    #   #    #    #
5    #          #       #  #     #  #  #    ####      ####
6  #####     #  #      ##  ##    ## #  #    #             #
7             ##                           ##             ##
*/

/*
   01234567  01234567  01234567  01234567  01234567  01234567
0
1
2  ## ##      ####     #    #     #   #    ######    #     #
3   ##  #    #          #  #      #   #        #     #     #
4   #         ####       ##       #   #       #      #  #  #
5   #             #     #  #       #  #      #       #  #  #
6  ##        #####     #    #    #  ##      ######    ## ##
7                                 ###
*/

/*
   01234567  01234567  01234567  01234567  01234567  01234567
0     #      #####       ###     ####      #####     #     #
1    # #     #    #     #   #    #   #       #       #     #
2   #   #    #    #    #         #    #      #       #     #
3   #   #    #####     #         #    #      #       #     #
4   #####    #    #    #         #    #      #       #  #  #
5  #     #   #    #     #   #    #   #       #       # # # #
6  #     #   #####       ###     ####      # #        #   #
7                                           #
*/
