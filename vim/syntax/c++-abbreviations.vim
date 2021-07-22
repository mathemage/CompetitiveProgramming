" abbreviations
iab fo for (auto & it:.) {<CR><ESC>-f.s
iab fis for (ll i = 0; i < SZ(.); i += 1) {<CR><ESC>-f.c

iab if if (.) {<CR><ESC>-f.c
iab ifel if (.) {<CR>} else {<ESC>-f.c
iab whi while (.) {<CR><ESC>-f.c
" iab while while (.) {<CR><ESC>-f.c
iab dow do {<CR>}<ESC>a while (?);<ESC>jdd-f?c
" iab switch switch (.) {<CR>case '': <ESC>-f.c     " TODO delete
iab swi switch (.) {<CR>case '':<CR>break;<ESC>2-f.c

iab ato atoi(.c_str())<ESC>F.i

" iab ll long long

iab vs vector<string>
iab vi vector<int>
" iab vll vector<long long>
iab vll vector<ll>
iab vb vector<bool>
iab vd vector<double>

iab ii pair<int, int>
iab dd pair<double, double>
iab llll pair<ll, ll>

iab vii vector<pair<int, int>>
iab vdd vector<pair<double, double>>
iab vllll vector<pair<ll, ll>>

iab vvi vector<vector<int>>
iab vvd vector<vector<double>>
iab vvll vector<vector<ll>>
iab vvb vector<vector<bool>>

iab seti set<int>
iab setd set<double>
iab setc set<char>
iab setl set<long long>
" iab setll set<long long>
iab useti unordered_set<int>
iab usetd unordered_set<double>
iab usetc unordered_set<char>
iab usetl unordered_set<long long>
" iab usetll unordered_set<long long>

" TODO add <>F.c
iab umap unordered_map

iab acc accumulate(ALL(.), 0LL)<ESC>F.c
iab accd accumulate(ALL(.), 0.0)<ESC>2F.c
iab accu accumulate(..begin(), .end(), 0LL)<ESC>3F.c
iab accum accumulate(ALL(.), 0LL, [](auto & a, auto & b) { return a+b; } )<ESC>F.c
iab sor sort(ALL(.));<ESC>F.c
iab sort sort(ALL(?), [](auto & a, auto & b) { return a.S < b.S; } );<ESC>F?c
iab rsor sort(REVALL(.));<ESC>F.c
iab rev reverse(ALL(.));<ESC>F.c
iab iot iota(ALL(.), 0);<ESC>F.c
iab iot1 iota(ALL(.), 1);<ESC>F.c

iab coun count(ALL(.), .)<ESC>2F.c
" iab cif count_if(ALL(.), ., [](int i) {.})<ESC>3F.c  " TODO

iab 3d ?[][][]{}<ESC>F?c
iab 4d ?[][][][]{}<ESC>F?c
iab 5d ?[][][][][]{}<ESC>F?c
