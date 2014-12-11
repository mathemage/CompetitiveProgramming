scriptencoding utf-8
" ^^ Please leave the above line at the start of the file.

" Default configuration file for Vim
" $Header: /var/cvsroot/gentoo-x86/app-editors/vim-core/files/vimrc-r3,v 1.1 2006/03/25 20:26:27 genstef Exp $

" Written by Aron Griffis <agriffis@gentoo.org>
" Modified by Ryan Phillips <rphillips@gentoo.org>
" Modified some more by Ciaran McCreesh <ciaranm@gentoo.org>
" Added Redhat's vimrc info by Seemant Kulleen <seemant@gentoo.org>

" You can override any of these settings on a global basis via the
" "/etc/vim/vimrc.local" file, and on a per-user basis via "~/.vimrc". You may
" need to create these.

" {{{ General settings
" The following are some sensible defaults for Vim for most users.
" We attempt to change as little as possible from Vim's defaults,
" deviating only where it makes sense
set nocompatible        " Use Vim defaults (much better!)
set bs=2                " Allow backspacing over everything in insert mode
set ai                  " Always set auto-indenting on
set history=50          " keep 50 lines of command history
set ruler               " Show the cursor position all the time

set viminfo='20,\"500   " Keep a .viminfo file.

" Don't use Ex mode, use Q for formatting
map Q gq

" When doing tab completion, give the following files lower priority. You may
" wish to set 'wildignore' to completely ignore files, and 'wildmenu' to enable
" enhanced tab completion. These can be done in the user vimrc file.
set suffixes+=.info,.aux,.log,.dvi,.bbl,.out,.o,.lo
set wildmenu

" When displaying line numbers, don't use an annoyingly wide number column. This
" doesn't enable line numbers -- :set number will do that. The value given is a
" minimum width to use for the number column, not a fixed size.
if v:version >= 700
  set numberwidth=3
endif
" }}}

" {{{ Modeline settings
" We don't allow modelines by default. See bug #14088 and bug #73715.
" If you're not concerned about these, you can enable them on a per-user
" basis by adding "set modeline" to your ~/.vimrc file.
set nomodeline
" }}}

" {{{ Locale settings
" Try to come up with some nice sane GUI fonts. Also try to set a sensible
" value for fileencodings based upon locale. These can all be overridden in
" the user vimrc file.
if v:lang =~? "^ko"
  set fileencodings=euc-kr
  set guifontset=-*-*-medium-r-normal--16-*-*-*-*-*-*-*
elseif v:lang =~? "^ja_JP"
  set fileencodings=euc-jp
  set guifontset=-misc-fixed-medium-r-normal--14-*-*-*-*-*-*-*
elseif v:lang =~? "^zh_TW"
  set fileencodings=big5
  set guifontset=-sony-fixed-medium-r-normal--16-150-75-75-c-80-iso8859-1,-taipei-fixed-medium-r-normal--16-150-75-75-c-160-big5-0
elseif v:lang =~? "^zh_CN"
  set fileencodings=gb2312
  set guifontset=*-r-*
endif

" If we have a BOM, always honour that rather than trying to guess.
if &fileencodings !~? "ucs-bom"
  set fileencodings^=ucs-bom
endif

" Always check for UTF-8 when trying to determine encodings.
if &fileencodings !~? "utf-8"
  set fileencodings+=utf-8
endif

" Make sure we have a sane fallback for encoding detection
set fileencodings+=default
" }}}

" {{{ Syntax highlighting settings
" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  "set hlsearch
endif
" }}}

" {{{ Terminal fixes
if &term ==? "xterm"
  set t_Sb=^[4%dm
  set t_Sf=^[3%dm
  set ttymouse=xterm2
endif

if &term ==? "gnome" && has("eval")
  " Set useful keys that vim doesn't discover via termcap but are in the
  " builtin xterm termcap. See bug #122562. We use exec to avoid having to
  " include raw escapes in the file.
  exec "set <C-Left>=\eO5D"
  exec "set <C-Right>=\eO5C"
endif
" }}}

" {{{ Filetype plugin settings
" Enable plugin-provided filetype settings, but only if the ftplugin
" directory exists (which it won't on livecds, for example).
if isdirectory(expand("$VIMRUNTIME/ftplugin"))
  filetype plugin on

  " Uncomment the next line (or copy to your ~/.vimrc) for plugin-provided
  " indent settings. Some people don't like these, so we won't turn them on by
  " default.
  filetype indent on
endif
" }}}

" {{{ Fix &shell, see bug #101665.
if "" == &shell
  if executable("/bin/bash")
    set shell=/bin/bash
  elseif executable("/bin/sh")
    set shell=/bin/sh
  endif
endif
"}}}

" {{{ Our default /bin/sh is bash, not ksh, so syntax highlighting for .sh
" files should default to bash. See :help sh-syntax and bug #101819.
if has("eval")
  let is_bash=1
endif
" }}}

" {{{ Autocommands
if has("autocmd")

augroup gentoo
  au!

  " Gentoo-specific settings for ebuilds.  These are the federally-mandated
  " required tab settings.  See the following for more information:
  " http://www.gentoo.org/proj/en/devrel/handbook/handbook.xml
  " Note that the rules below are very minimal and don't cover everything.
  " Better to emerge app-vim/gentoo-syntax, which provides full syntax,
  " filetype and indent settings for all things Gentoo.
  au BufRead,BufNewFile *.e{build,class} let is_bash=1|setfiletype sh
  au BufRead,BufNewFile *.e{build,class} set ts=4 sw=4 noexpandtab

  " In text files, limit the width of text to 78 characters, but be careful
  " that we don't override the user's setting.
  autocmd BufNewFile,BufRead *.txt
        \ if &tw == 0 && ! exists("g:leave_my_textwidth_alone") |
        \     setlocal textwidth=78 |
        \ endif

  " When editing a file, always jump to the last cursor position
  autocmd BufReadPost *
        \ if ! exists("g:leave_my_cursor_position_alone") |
        \     if line("'\"") > 0 && line ("'\"") <= line("$") |
        \         exe "normal g'\"" |
        \     endif |
        \ endif

  " When editing a crontab file, set backupcopy to yes rather than auto. See
  " :help crontab and bug #53437.
  autocmd FileType crontab set backupcopy=yes
augroup END
endif " has("autocmd")
" }}}

" {{{ vimrc.local
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif
" }}}

" vim: set fenc=utf-8 tw=80 sw=2 sts=2 et foldmethod=marker :

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" All system-wide defaults are set in $VIMRUNTIME/debian.vim (usually just
" /usr/share/vim/vimcurrent/debian.vim) and sourced by the call to :runtime
" you can find below.  If you wish to change any of those settings, you should
" do it in this file (/etc/vim/vimrc), since debian.vim will be overwritten
" everytime an upgrade of the vim packages is performed.  It is recommended to
" make changes after sourcing debian.vim since it alters the value of the
" 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
"runtime! debian.vim

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
set nocompatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
syntax on

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
if has("autocmd")
  au BufReadPost * if line("'\"") > 0 && line("'\"") <= line("$")
    \| exe "normal g'\"" | endif
endif

" Uncomment the following to have Vim load indentation rules according to the
" detected filetype. Per default Debian Vim only load filetype specific
" plugins.
if has("autocmd")
  filetype indent on
endif

autocmd BufRead,BufNewFile *.php source ~/.vim/syntax/php.vim
autocmd BufRead,BufNewFile *.php5 source ~/.vim/syntax/php.vim
autocmd BufRead,BufNewFile *.tex source ~/.vim/syntax/tex.vim
autocmd BufRead,BufNewFile *.[ch] source ~/.vim/syntax/c-trung.vim
autocmd BufRead,BufNewFile *.cpp source ~/.vim/syntax/cpp-trung.vim
autocmd BufRead,BufNewFile *.pl source ~/.vim/syntax/pl-trung.vim
autocmd BufRead,BufNewFile *.py,*.sage,*.spyx source ~/.vim/syntax/py-trung.vim
autocmd BufRead,BufNewFile *.hs,*.lhs source ~/.vim/syntax/haskell-trung.vim
autocmd BufRead,BufNewFile empty_023984 * source ~/.vim/syntax/empty.vim
autocmd BufRead,BufNewFile *.cc source ~/.vim/syntax/cc.vim
set completeopt=menuone

" not change the directory if one is editing in /tmp
autocmd BufEnter * if expand("%:p:h") !~ '^/tmp' | lcd %:p:h | endif

" --------------------
" ShowMarks
" --------------------
let showmarks_include = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
let g:showmarks_enable = 1
" For marks a-z
highlight ShowMarksHLl gui=bold guibg=LightBlue guifg=Blue
" For marks A-Z
highlight ShowMarksHLu gui=bold guibg=LightRed guifg=DarkRed
" For all other marks
highlight ShowMarksHLo gui=bold guibg=LightYellow guifg=DarkYellow
" For multiple marks on the same line.
highlight ShowMarksHLm gui=bold guibg=LightGreen guifg=DarkGreen


" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
set showcmd		" Show (partial) command in status line.
set showmatch		" Show matching brackets.
set ignorecase		" Do case insensitive matching
set smartcase		" Do smart case matching
set incsearch		" Incremental search
"set hlsearch		" Hilite searched terms
set autowrite		" Automatically save before commands like :next and :make
set hidden             " Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes) in terminals

" Source a global configuration file if available
" XXX Deprecated, please move your changes here in /etc/vim/vimrc
"if filereadable("/etc/vim/vimrc.local")
  "source /etc/vim/vimrc.local
"endif

set ruler
set smartcase
set nojoinspaces
set smartindent
set backspace=2
set number
set cursorline
set cursorcolumn
set cindent

set tabstop=2
set sw=2        " Shiftwidth, pri indentovani
set expandtab
retab

set foldopen=all
set foldclose=all

" global substitution
"set gdefault

au BufWinLeave * mkview
au BufWinEnter * silent loadview

tab ball

colorscheme slate
syn on

let &termencoding = &encoding
"set encoding=utf-8
set encoding=iso-8859-2

syn match Tab "\t"
syn match Tab2 "\t\t"
hi def Tab  ctermbg=lightgreen guibg=lightgreen
hi def Tab2 ctermbg=lightred guibg=darkblue

" vim -b : edit binary using xxd-format!
augroup Binary_Java_Class
    au!
    au BufReadPre   *.class let &bin=1
    au BufReadPost  *.class if &bin | %!xxd -g1
    au BufReadPost  *.class set ft=xxd | endif
    au BufWritePre  *.class if &bin | %!xxd -g1 -r
    au BufWritePre  *.class endif
    au BufWritePost *.class if &bin | %!xxd -g1
    au BufWritePost *.class set nomod | endif
augroup END

"" TeX
"map! ;x :w:cd %:p:h:!tex % \\bye:!xdvi `basename % .tex`".dvi" -expertmode 0 -s 4 &> /dev/null & 
"map ;x :w:cd %:p:h:!tex % \\bye:!xdvi `basename % .tex`".dvi" -expertmode 0 -s 4 &> /dev/null & 
"
""map!  :w:cd %:p:h:!csplain %:!xdvi `basename % .tex`".dvi" -expertmode 0 -s 4 &> /dev/null & 
""map  :w:cd %:p:h:!csplain %:!xdvi `basename % .tex`".dvi" -expertmode 0 -s 4 &> /dev/null & 
"
"map! f :w:cd %:p:h:!pdfcsplain %:!xpdf `basename % .tex`".pdf" >& /dev/null 
"map f :w:cd %:p:h:!pdfcsplain %:!xpdf `basename % .tex`".pdf" >& /dev/null 
""map! æ :w:cd %:p:h:!csplain -output-format=pdf %:!xpdf `basename % .tex`".pdf" &
""map æ :w:cd %:p:h:!csplain -output-format=pdf %:!xpdf `basename % .tex`".pdf" &
"
"" Pdfcslatex
"map l :w:cd %:p:h:!latex %:!xdvi `basename % .tex`".dvi" -expertmode 0 -s 4 &> /dev/null &
"map! l :w:cd %:p:h:!latex %:!xdvi `basename % .tex`".dvi" -expertmode 0 -s 4 &> /dev/null &
"
""map  :w:cd %:p:h:!c:/MiKTeX/miktex/bin/pdfcslatex.exe --src -interaction=nonstopmode %:!C:/Program Files/Adobe/Reader 9.0/Reader/AcroRd32.exe %:p:h\%<.pdf
""map  :w:cd %:p:h:!c:/MiKTeX/miktex/bin/pdfcslatex.exe --src -interaction=nonstopmode %:!"C:/Program Files/Adobe/Reader 9.0/Reader/AcroRd32.exe" %<.pdf
""map!  :w:cd %:p:h:!c:/MiKTeX/miktex/bin/pdfcslatex.exe --src -interaction=nonstopmode %:!"C:/Program Files/Adobe/Reader 9.0/Reader/AcroRd32.exe" %<.pdf
"
"" prezentace v LaTeX Beamer + zobraz v Acrobat Readeru
""map  :w:cd %:p:h:!pdflatex %:!xpdf `basename % .tex`".pdf" -fullscreen >& /dev/null  
"map  :w:cd %:p:h:!pdflatex %:!acroread `basename % .tex`".pdf" >& /dev/null  
"map!  :w:cd %:p:h:!pdflatex %:!acroread `basename % .tex`".pdf" >& /dev/null  

" change directory to the file being edited
map ,cd :cd %:p:h<CR>

"" C - make
"map m :wa:make
"map! m :wa:make
"
"" IntelliSense via OmniComplete - '.'
"map! . :wa``a.
"imap . .
"
"" IntelliSense via OmniComplete - '->'
"map! > wa``a->
"imap -> ->

" -----------root navod - IDE for C------------------
" uložení aktuálně editovaného souboru
map <F2> :wa<cr>
map W :wa<cr>

"" skok na předchozí chybové hlášení
"map <F3> :cp<cr>
"
"" skok na následující chybové hlášení
"map <F4> :cn<cr>
"
"" uložení aktuálně editovaného souboru a spuštění překladu
"map <F9> :wa<cr>:make<cr>
"
"" výpis všech chybových hlášení překladače
"map <F10> :cl<cr><cr>

" TaskList switch-on
map <F8> :TaskList<CR>

" taglist toggle
let Tlist_Ctags_Cmd='/usr/local/bin/ctags'
map <F9> :TlistToggle<CR>

" default file browser
map <F11> :Explore<CR>

" NERDTree
map <F12> :NERDTree<CR>

" save & quit all
map XX :xa<CR>

" quit all
map XQ :qa<CR>

" switch between windows
"map k <C-w><Up>
"map j <C-w><Down>
"map l <C-w><Right>
"map h <C-w><Left>
map <c-k> <C-w><Up>
map <c-j> <C-w><Down>
map <c-l> <C-w><Right>
map <c-h> <C-w><Left>

"" Maximaze vim
"if has("gui_running")
"  " GUI is running or is about to start.
"  " Maximize gvim window.
"  set lines=999 columns=999
"else
"  " This is console Vim.
"  if exists("+lines")
"    set lines=50
"  endif
"  if exists("+columns")
"    set columns=100
"  endif
"endif

filetype plugin on
set ofu=syntaxcomplete#Complete
let g:pydiction_location = '/home/trung/.vim//pydiction-1.2/complete-dict'

""""""
" Sage settings (from Franco Saliola)
autocmd BufRead,BufNewFile *.sage,*.pyx,*.spyx set filetype=python
autocmd Filetype python set tabstop=4|set shiftwidth=4|set expandtab
autocmd FileType python set makeprg=sage\ -b\ &&\ sage\ -t\ %
autocmd FileType python set omnifunc=pythoncomplete#Complete

" Make vim recognize Prolog files
autocmd BufNewFile,BufRead *.pl set ft=prolog
" Turn off paren matching for Prolog files
autocmd BufNewFile,BufRead *.pl NoMatchParen

let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapWindowNavArrows = 1
let g:miniBufExplMapCTabSwitchBufs = 1
let g:miniBufExplModSelTarget = 1

" aspell
map  :w!<CR>:!aspell check %<CR>:e! %<CR>
