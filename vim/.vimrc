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
set nocp      " for omnicppcomplete

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark

" .cc setting
autocmd BufRead,BufNewFile *.cc source ~/.vim/syntax/cc.vim

" .cpp setting
autocmd bufnewfile *.cpp,*.h so ~/.vim/syntax/cpp.template
autocmd bufnewfile *.cpp,*.h exe "1," . 10 . "g/File Name :.*/s//File Name : " .expand("%")
autocmd bufnewfile *.cpp,*.h exe "1," . 10 . "g/Creation Date :.*/s//Creation Date : " .strftime("%d-%m-%Y")
autocmd bufnewfile *.cpp,*.h execute "normal G"
autocmd Bufwritepre,filewritepre *.cpp,*.h execute "normal ma"
autocmd Bufwritepre,filewritepre *.cpp,*.h exe "1," . 10 . "g/Last Modified :.*/s/Last Modified :.*/Last Modified : " .strftime("%c")
autocmd bufwritepost,filewritepost *.cpp,*.h execute "normal `a"
autocmd BufRead,BufNewFile *.[ch]pp,*.h source ~/.vim/syntax/cpp-trung.vim

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

" .tex setting
autocmd BufRead,BufNewFile *.tex map <F8> <Esc>:wa<cr>:make clean<cr>:make<cr>
autocmd BufRead,BufNewFile *.tex map! <F8> <Esc>:wa<cr>:make clean<cr>:make<cr>

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
let g:EclimCompletionMethod = 'omnifunc'
au BufNewFile,BufRead,BufEnter *.cpp,*.cxx,*.hxx,*.hpp,*.cu,*.cl set omnifunc=omni#cpp#complete#Main

" CUDA syntax
au BufNewFile,BufRead *.cu set ft=cu
au BufNewFile,BufRead *.cuh set ft=cu

" gVim
set guioptions-=m  "remove menu bar
set guioptions-=T  "remove toolbar
set guioptions-=r  "remove right-hand scroll bar
set guioptions-=L  "remove left-hand scroll bar

"set so=666
noremap <Esc>s :update<CR>
