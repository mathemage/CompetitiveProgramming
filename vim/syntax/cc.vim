" abbreviations
so ./c++-abbreviations.vim

" make commands
map <F3> <ESC>:wa!<cr>:vs Makefile<cr>/CXXFLAGS<cr>A -std=c++11<ESC>ZZ
map! <F3> <ESC>:wa!<cr>:vs Makefile<cr>/CXXFLAGS<cr>A -std=c++11<ESC>ZZ
map <F4> <ESC>:wa!<cr>:vs Makefile<cr>/CXXFLAGS<cr>A -std=c++0x<ESC>ZZ
map! <F4> <ESC>:wa!<cr>:vs Makefile<cr>/CXXFLAGS<cr>A -std=c++0x<ESC>ZZ
map <F5> <ESC>:wa!<cr>:make run<cr>
map! <F5> <ESC>:wa!<cr>:make run<cr>
map <F6> <ESC>:wa!<cr>:make test<cr>
map! <F6> <ESC>:wa!<cr>:make test<cr>
map <F7> <ESC>:wa!<cr>:make<cr>
map! <F7> <ESC>:wa!<cr>:make<cr>
