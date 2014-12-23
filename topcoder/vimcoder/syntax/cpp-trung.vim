" set equalprg=cindent

" g++ - make
"map m :wa:!make && scp crc-write.exe root@tpsrv212:~/kha/
"map! m :wa:!make && scp crc-write.exe root@tpsrv212:~/kha/
map m :wa:!make
map! m :wa:!make

" Qt - make
map ,q :wa:!qmake -project:!qmake `basename % .cpp`".pro":make
map! ,q :wa:!qmake -project:!qmake `basename % .cpp`".pro":make

" skok na předchozí chybové hlášení
map <F3> :cp<cr>

" skok na následující chybové hlášení
map <F4> :cn<cr>

" uložení aktuálně editovaného souboru a spuštění překladu
map <F9> :wa<cr>:make<cr>

" výpis všech chybových hlášení překladače
map <F10> :cl<cr><cr>

colorscheme desert

" g++ for CodeChef beginning
map <F5> <Esc>:wa<cr>:!g++ % -o `basename % .cpp`<cr>
map! <F5> <Esc>:wa<cr>:!g++ % -o `basename % .cpp`<cr>
map <F6> <Esc>:wa<cr>:!g++ % -pthread -o `basename % .cpp`<cr>
map! <F6> <Esc>:wa<cr>:!g++ % -pthread -o `basename % .cpp`<cr>

" g++ for CodeForces, CodeChef
map <F7> <Esc>:wa<cr>:!g++ -g -std=c++11 % -o driver && (ulimit -c unlimited; ./driver < in) <cr>
map! <F7> <Esc>:wa<cr>:!g++ -g -std=c++11 % -o driver && (ulimit -c unlimited; ./driver < in) <cr>

colorscheme slate
