" abbreviations
so ~/.vim/syntax/c++-abbreviations.vim

" make commands
" map <F3> <ESC>:wa!<cr>:vs Makefile<cr>/CXXFLAGS<cr>A -std=c++11<ESC>ZZ
" map! <F3> <ESC>:wa!<cr>:vs Makefile<cr>/CXXFLAGS<cr>A -std=c++11<ESC>ZZ
" map <F4> <ESC>:wa!<cr>:vs Makefile<cr>/CXXFLAGS<cr>A -std=c++0x<ESC>ZZ
" map! <F4> <ESC>:wa!<cr>:vs Makefile<cr>/CXXFLAGS<cr>A -std=c++0x<ESC>ZZ

map <F2> <ESC>:wa!<cr>:make clean<cr>:!(ulimit -s 65536 -t 8 && make CXXFLAGS:="-DONLINE_JUDGE" run)<cr>
map! <F2> <ESC>:wa!<cr>:make clean<cr>:!(ulimit -s 65536 -t 8 && make CXXFLAGS:="-DONLINE_JUDGE" run)<cr>
map <F3> <ESC>:wa!<cr>:make clean<cr>:!(ulimit -s 65536 -t 14 && make CXXFLAGS:="-DMATHEMAGE_DEBUG -Wall -pedantic" test)<cr>
map! <F3> <ESC>:wa!<cr>:make clean<cr>:!(ulimit -s 65536 -t 14 && make CXXFLAGS:="-DMATHEMAGE_DEBUG -Wall -pedantic" test)<cr>
map <F4> <ESC>:wa!<cr>:make clean<cr>:!(ulimit -s 65536 -t 14 && make CXXFLAGS:="-DMATHEMAGE_DEBUG -Wall -Wextra -pedantic" test)<cr>
map! <F4> <ESC>:wa!<cr>:make clean<cr>:!(ulimit -s 65536 -t 14 && make CXXFLAGS:="-DMATHEMAGE_DEBUG -Wall -Wextra -pedantic" test)<cr>

map <F5> <ESC>:wa!<cr>:make run<cr>
map! <F5> <ESC>:wa!<cr>:make run<cr>
map <F6> <ESC>:wa!<cr>:make test<cr>
map! <F6> <ESC>:wa!<cr>:make test<cr>
map <F7> <ESC>:wa!<cr>:make<cr>
map! <F7> <ESC>:wa!<cr>:make<cr>
