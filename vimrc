"basic vim startup preferences (donald.cory.harvey@gmail.com 14-MAY-12)
" this file would normally be in the user's home directory as a .vimrc
" file to be active.
"
" personal display prejudices
wildmenu                      " fancies up tab completions
set path+=**                  " makes :find recurse down the local path
set modeline                  " accept settings from file being edited
set modelines=5               " standard no. of lines to look into a file
set encoding=utf-8            " defaults to latin1
colorscheme elflord           " darkblue is also good
let loaded_matchparen = 1     " stop colorizing matched brackets
set nohlsearch                " stop colorizing search finds
"set colorcolumn=72           " put an end of line bar for convenience
"set columns=84               " limits the screen width used by vi
set number                    " display line # on far left
set visualbell                " flash, don't ring
set ruler                     " show info on bottom line+1
set laststatus=2              " always display the status line 
syntax off                    " show syntax elements by distinct color
"
"
filetype plugin on            " enable plugin scripts & such
set nowrap                    " long lines go off right edge of screen
"
"
" caution: wrapscan must be set for tags to be reliable
" for multiple tag files--example: set tags=tags\ /usr/local/lib/tags
set nowrapscan                " don't endlessly wrap a global search
"
"
" what tab-haters do          " abbreviations for use in autocmd:
set cindent                   " [use c code formatting features]
set tabstop=4                 " ts
set softtabstop=4             " sts
set shiftwidth=4              " sw
set shiftround                " autoindent will use shiftwidth setting
set expandtab                 " turn tabs into spaces
"                             " has to be done in this order ???
"                             " 4 is optimal for reading code
"
" useful to know:
"
" best help for learning to write functions:
" :help autocmd
" :help scripts
" :help variables
" :help functions
" :help usr_40.txt
"
" programmer productivity help:
" :help folding
" :help indenting
" :help insertion
" :help filter
" :help syntax
" :help quickfix
" :help ins-completion
"
" if $USER == 'davidr'
" echo "on home pc"
" set .. etc
" else
" echo "on work pc"
" set .. etc
" endif
"
" need to understand this better
" set wrapmargin=72             " auto carriage-return line-feed
"
"
" example mappings:
" ab cskel #include <stdio.h>void main(void){}O	printf("hello, world");
" nmap <f9> qxvi(!sh<CR>q
" abbrev (TM) <SUP><SMALL>(TM)</SMALL></SUP>
" "
" nmap <leader>l :set list!<CR>
" unset some things for
" nnoremap <F8> :setl noai nocin nosi inde=<CR>  
" imap html5 <html><CR>    <head><CR>    </head><CR>    <body><CR>    </body><CR></html>
"
"
" sets up for making vim into a poor man's IDE
" use :copen to open the quickfix list. 
" note that this is a setup for a 3 window tab,
" with with code to the left, output to the right,
" and compiler results in the quickfix list below
map <Leader>c :w param.c | silent! make | normal 
map ,, :w | silent! make | normal 
map <Leader>r l1GdG:.!param 10 11
map ,  | 1GdG:.!param 10 11
" the breakdown:
"     <Leader> defaults to '\'
"     ctrl-V followed by "|" is the old, foolproof style of cmd separator
"     "make" is vim builtin that triggers your default makefile
"            and puts the results into the quickfix list
"     "silent" is so your screen doesn't garbage up while compiling
"     "normal L" is to clean up any resulting screen awkwardness
"     "param" is a placeholder for the executable's name--use ./a.out
"             if you haven't set up your executable's directory on the PATH
"
" note that to save a complete setup use :mksession [<filename>]
" default restart is   > vim -S Session.vim  --  mass quit with :qall!
" also :set modifiable is useful to remember when window navigation
" doesn't seem to be working.
" 
" :cn to go to next error w/out leaving code window
" :cnf to go to first error in the next filed
" :copen to open quickfix window
"
" hit ctrl-f after : in command mode and vim goodness ensues
"
"
"
"
"
"
"
"  cool things to know about vi
"
"    :.,$w >>temp        {to append}
"    :1,30s/his/the/gc   {global-confirm}
"    :g/th/              {:v does opposite}
"    :.,/while/d
"    :g/SYNTAX/,/DESCRIPTION/-1 mo /PARAMETERS/-1
"
"
"    vi(!sh            {built-in dev. cycle}
"
"    vimcasts.org
"    http://www.derekwyatt.org/vim/vim-tutorial-videos
"
"
"
"
"
