" abbreviations
iab fis for (int i = 0; i < .size(); ++i) {<CR>}<ESC>-f.i
iab ato atoi(.c_str())<ESC>F.i
iab vs vector<string>
iab vi vector<int>
iab vll vector<long long>
iab ll long long
iab vb vector<bool>
iab AC accumulate(.begin(), .end(), 0);<ESC>2F.i
iab ii pair<int, int>

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
