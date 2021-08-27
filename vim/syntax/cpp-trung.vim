" set equalprg=cindent

" g++ - make
"map m :wa:!make && scp crc-write.exe root@tpsrv212:~/kha/
"map! m :wa:!make && scp crc-write.exe root@tpsrv212:~/kha/
map m :wa:!make
map! m :wa:!make

" Qt - make
" map ,q :wa:!qmake -project:!qmake `basename % .cpp`".pro":make
" map! ,q :wa:!qmake -project:!qmake `basename % .cpp`".pro":make

" " skok na předchozí chybové hlášení
" map <F3> :cp<cr>
" 
" " skok na následující chybové hlášení
" map <F4> :cn<cr>

" uložení aktuálně editovaného souboru a spuštění překladu
map <F9> :wa<cr>:make<cr>

" výpis všech chybových hlášení překladače
map <F10> :cl<cr><cr>

colorscheme desert

" g++ for CodeChef beginning
" map <F5> <Esc>:wa<cr>:!g++ % -o `basename % .cpp`<cr>
" map! <F5> <Esc>:wa<cr>:!g++ % -o `basename % .cpp`<cr>
" map <F5> <Esc>:wa<cr>:!./drive_all.sh<cr>
" map! <F5> <Esc>:wa<cr>:!./drive_all.sh<cr>
map <F4> <Esc>:wa<cr>:let @+ = expand("%:p")<cr>:!./drive_all.sh<cr>
map! <F4> <Esc>:wa<cr>:let @+ = expand("%:p")<cr>:!./drive_all.sh<cr>
" map <F6> <Esc>:wa<cr>:!g++ % -pthread -o `basename % .cpp`<cr>
" map! <F6> <Esc>:wa<cr>:!g++ % -pthread -o `basename % .cpp`<cr>

" g++ for CodeForces, CodeChef
map <F7> <Esc>:wa<cr>:!g++ -g -std=c++11 % -o driver && (ulimit -c unlimited; ./driver < in) <cr>
map! <F7> <Esc>:wa<cr>:!g++ -g -std=c++11 % -o driver && (ulimit -c unlimited; ./driver < in) <cr>
map <F8> <Esc>:wa<cr>:!g++ -g -std=c++0x % -o driver && (ulimit -c unlimited; ./driver < in) <cr>
map! <F8> <Esc>:wa<cr>:!g++ -g -std=c++0x % -o driver && (ulimit -c unlimited; ./driver < in) <cr>
" map <F2> <Esc>:wa<cr>:!g++ -g -std=c++0x % -o driver && (ulimit -c unlimited; ./driver) <cr>
" map! <F2> <Esc>:wa<cr>:!g++ -g -std=c++0x % -o driver && (ulimit -c unlimited; ./driver) <cr>

" https://codeforces.com/blog/entry/75004 - g++ -static -DONLINE_JUDGE -Wl,--stack=268435456 -O2 -std=c++17 program.cpp
" https://codeforces.com/blog/entry/15547 - -Wextra -pedantic TODO
map <F2> <Esc>:w<cr>:wa<cr>:let @+ = expand("%:p")<cr>:!g++ -static -DONLINE_JUDGE -DMATHEMAGE_LOCAL -Wall -Wextra -pedantic -O2 -std=c++17 -fsanitize=undefined -fno-sanitize-recover % -o driver && (ulimit -s 65536 -t 4; time ./driver <in) <cr>
map! <F2> <Esc>:w<cr>:wa<cr>:let @+ = expand("%:p")<cr>:!g++ -static -DONLINE_JUDGE -DMATHEMAGE_LOCAL -Wall -Wextra -pedantic -O2 -std=c++17 -fsanitize=undefined -fno-sanitize-recover % -o driver && (ulimit -s 65536 -t 4; time ./driver <in) <cr>
map <F3> <Esc>:w<cr>:wa<cr>:let @+ = expand("%:p")<cr>:!g++ -static -DMATHEMAGE_DEBUG -DMATHEMAGE_LOCAL -g -Wall -Wextra -pedantic -O2 -std=c++17 -fsanitize=undefined -fno-sanitize-recover % -o driver && (ulimit -s 65536 -t 7; time ./driver <in) <cr>
map! <F3> <Esc>:w<cr>:wa<cr>:let @+ = expand("%:p")<cr>:!g++ -static -DMATHEMAGE_DEBUG -DMATHEMAGE_LOCAL -g -Wall -Wextra -pedantic -O2 -std=c++17 -fsanitize=undefined -fno-sanitize-recover % -o driver && (ulimit -s 65536 -t 7; time ./driver <in) <cr>

map <F5> <Esc>:wa<cr>:%y+<cr>
map! <F5> <Esc>:wa<cr>:%y+<cr>

" abbreviations
so ~/.vim/syntax/c++-abbreviations.vim

colorscheme slate
