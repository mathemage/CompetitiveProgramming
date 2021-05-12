" abbreviations
iab fo for (auto & it:.) {<CR><ESC>-f.s
iab fis for (int i = 0; i < SZ(.); i += 1) {<CR><ESC>-f.c

iab if if (.) {<CR><ESC>-f.c
iab ifel if (.) {<CR>} else {<ESC>-f.c
iab whi while (.) {<CR><ESC>-f.c
iab while while (.) {<CR><ESC>-f.c
" iab dow do {<CR><ESC>awhile (.);<ESC>-f.s TODO
iab switch switch (.) {<CR>case '': <ESC>-f.c

iab ato atoi(.c_str())<ESC>F.i

" iab ll long long

iab vs vector<string>
iab vi vector<int>
iab vll vector<long long>
iab vb vector<bool>
iab vd vector<double>

iab ii pair<int, int>
iab dd pair<double, double>
" iab pi pair<int, int>
" iab pd pair<double, double>

iab vii vector<pair<int, int>>
iab vdd vector<pair<double, double>>

iab vvi vector<vector<int>>
iab vvd vector<vector<double>>
iab vvll vector<vector<long long>>
iab vvb vector<vector<bool>>

iab seti set<int>
iab setd set<double>
iab setc set<char>
iab setl set<long long>
iab useti unordered_set<int>
iab usetd unordered_set<double>
iab usetc unordered_set<char>
iab usetl unordered_set<long long>

iab minu MINUPDATE(., .);<ESC>2F.c
iab maxu MAXUPDATE(., .);<ESC>2F.c
iab min( min(., .)<ESC>2F.c
iab max( max(., .)<ESC>2F.c

iab acc accumulate(ALL(.), 0LL)<ESC>F.c
iab accd accumulate(ALL(.), 0.0)<ESC>2F.c
iab accu accumulate(..begin(), .end(), 0)<ESC>3F.c
iab accum accumulate(ALL(.), 0, [](auto & a, auto & b) { return a+b; } )<ESC>F.c
iab sor sort(ALL(.));<ESC>F.c
iab sort sort(ALL(?), [](auto & a, auto & b) { return a.S < b.S; } );<ESC>F?c
iab rsor sort(REVALL(.));<ESC>F.c

iab coun count(ALL(.), .)<ESC>2F.c
" iab cif count_if(ALL(.), ., [](int i) {.})<ESC>3F.c  " TODO
