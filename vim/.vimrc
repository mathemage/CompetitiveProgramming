set backupdir=~/vimtmp,.
set directory=~/vimtmp,.

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

" When doing tab completion, give the following files lower priority. You may
" wish to set 'wildignore' to completely ignore files, and 'wildmenu' to enable
" enhanced tab completion. These can be done in the user vimrc file.
set suffixes+=.info,.aux,.log,.dvi,.bbl,.out,.o,.lo
set wildmenu

" {{{ Syntax highlighting settings
" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  "set hlsearch
endif
" }}}

" Uncomment the next line (or copy to your ~/.vimrc) for plugin-provided
" indent settings. Some people don't like these, so we won't turn them on by
" default.
filetype indent on
filetype plugin on
se nocp

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark

" .cc setting
autocmd BufRead,BufNewFile *.cc source ~/.vim/syntax/cc.vim

" .cpp setting
autocmd bufnewfile *.cpp so ~/.vim/syntax/cpp.template
autocmd bufnewfile *.cpp exe "1," . 10 . "g/File Name :.*/s//File Name : " .expand("%")
autocmd bufnewfile *.cpp exe "1," . 10 . "g/Creation Date :.*/s//Creation Date : " .strftime("%d-%m-%Y")
autocmd bufnewfile *.cpp execute "normal G"
autocmd Bufwritepre,filewritepre *.cpp execute "normal ma"
autocmd Bufwritepre,filewritepre *.cpp exe "1," . 10 . "g/Last Modified :.*/s/Last Modified :.*/Last Modified : " .strftime("%c")
autocmd bufwritepost,filewritepost *.cpp execute "normal `a"
autocmd BufRead,BufNewFile *.[ch]pp source ~/.vim/syntax/cpp-trung.vim

" .cxx setting
autocmd bufnewfile *.cxx so ~/.vim/syntax/cxx.template
autocmd bufnewfile *.cxx exe "1," . 10 . "g/File Name :.*/s//File Name : " .expand("%")
autocmd bufnewfile *.cxx exe "1," . 10 . "g/TASK:.*/s//TASK: " .expand("%")
autocmd bufnewfile *.cxx exe "1," . 10 . "g/TASK: [^ ]*\.cxx/s/\.cxx//"
autocmd bufnewfile *.cxx exe "1," . 10 . "g/Creation Date :.*/s//Creation Date : " .strftime("%d-%m-%Y")
autocmd bufnewfile *.cxx execute "normal G"
autocmd Bufwritepre,filewritepre *.cxx execute "normal ma"
autocmd Bufwritepre,filewritepre *.cxx exe "1," . 10 . "g/Last Modified :.*/s/Last Modified :.*/Last Modified : " .strftime("%c")
autocmd bufwritepost,filewritepost *.cxx execute "normal `a"
autocmd BufRead,BufNewFile *.[ch]xx source ~/.vim/syntax/cpp-trung.vim

set completeopt=menuone

set showcmd		" Show (partial) command in status line.
set showmatch		" Show matching brackets.
set ignorecase		" Do case insensitive matching
set smartcase		" Do smart case matching
set incsearch		" Incremental search
"set hlsearch		" Hilite searched terms
"set autowrite		" Automatically save before commands like :next and
			":make

set nojoinspaces
set number
set tabstop=2
set sw=2        " Shiftwidth, pri indentovani
set expandtab
retab

" EXPERIMENTAL
colorscheme slate

let g:SuperTabDefaultCompletionType = 'context'
autocmd FileType *
      \ if &omnifunc != '' |
      \   call SuperTabChain(&omnifunc, "<c-p>") |
      \ endif

" configure tags - add additional tags here or comment out not-used ones
set tags+=~/.vim/tags/cpp
set tags+=~/.vim/tags/gl
set tags+=~/.vim/tags/sdl
set tags+=~/.vim/tags/qt4
" build tags of your own project with Ctrl-F12
map <C-F12> :!ctags -R --sort=yes --c++-kinds=+pl --fields=+iaS --extra=+q .<CR>

" OmniCppComplete
let OmniCpp_NamespaceSearch = 1
let OmniCpp_GlobalScopeSearch = 1
let OmniCpp_ShowAccess = 1
let OmniCpp_ShowPrototypeInAbbr = 1 " show function parameters
let OmniCpp_MayCompleteDot = 1 " autocomplete after .
let OmniCpp_MayCompleteArrow = 1 " autocomplete after ->
let OmniCpp_MayCompleteScope = 1 " autocomplete after ::
let OmniCpp_DefaultNamespaces = ["std", "_GLIBCXX_STD"]

" automatically open and close the popup menu / preview window
au CursorMovedI,InsertLeave * if pumvisible() == 0|silent! pclose|endif
set completeopt=menuone,menu,longest,preview

"let g:matlab_server_launcher = 'tmux'  "launch the server in a Neovim terminal buffer
let g:matlab_server_split = 'vertical'
let g:atp_Compiler='bash'

" " spell check
" set spell spelllang=en
" set iskeyword-=_

autocmd BufEnter *Dockerfile set nospell
autocmd BufLeave *Dockerfile set spell

" Commenting blocks of code - from https://stackoverflow.com/a/1676672/1460660
augroup commenting_blocks_of_code
  autocmd!
  autocmd FileType c,cc,cxx,cpp,java,scala let b:comment_leader = '// '
  autocmd FileType sh,ruby,python   let b:comment_leader = '# '
  autocmd FileType conf,fstab       let b:comment_leader = '# '
  autocmd FileType tex              let b:comment_leader = '% '
  autocmd FileType mail             let b:comment_leader = '> '
  autocmd FileType vim              let b:comment_leader = '" '
augroup END
noremap <silent>  :<C-B>silent <C-E>s/^/<C-R>=escape(b:comment_leader,'\/')<CR>/<CR>:nohlsearch<CR>
noremap <silent> ? :<C-B>silent <C-E>s/^\V<C-R>=escape(b:comment_leader,'\/')<CR>//e<CR>:nohlsearch<CR>
noremap <silent>  :<C-B>silent <C-E>s/^\V<C-R>=escape(b:comment_leader,'\/')<CR>//e<CR>:nohlsearch<CR>
noremap <silent> ,cc :<C-B>silent <C-E>s/^/<C-R>=escape(b:comment_leader,'\/')<CR>/<CR>:nohlsearch<CR>
noremap <silent> ,cu :<C-B>silent <C-E>s/^\V<C-R>=escape(b:comment_leader,'\/')<CR>//e<CR>:nohlsearch<CR>

if has('gui_running')
  set guioptions-=T  " no toolbar
  set guifont=Monospace\ 13
  set lines=65 columns=108 linespace=0
endif

map ,t :!tig<CR>
