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
map <F8> <Esc>:wa<cr>:!g++ -g -std=c++0x % -o driver && (ulimit -c unlimited; ./driver < `basename % .in`) <cr>
map! <F8> <Esc>:wa<cr>:!g++ -g -std=c++0x % -o driver && (ulimit -c unlimited; ./driver < `basename % .in`) <cr>

" abbreviations
iab fis for (int i = 0; i < .size(); ++i) {<CR><ESC>-f.i
iab ato atoi(.c_str())<ESC>F.i
iab vs vector<string>
iab vi vector<int>
iab vll vector<long long>
iab ll long long
iab vb vector<bool>
iab acc accumulate(.begin(), .end(), 0);<ESC>2F.i
iab ii pair<int, int>

colorscheme slate
