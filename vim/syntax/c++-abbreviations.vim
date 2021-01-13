" abbreviations
iab fo for (auto & i :.) {<CR><ESC>-f.s
iab fis for (int i = 0; i <.size(); i += 1) {<CR><ESC>-f.i

iab if if (.) {<CR><ESC>-f.c
iab whi while (.) {<CR><ESC>-f.c
iab while while (.) {<CR><ESC>-f.c
" iab dow do {<CR><ESC>awhile (.);<ESC>-f.s TODO

iab ato atoi(.c_str())<ESC>F.i

iab ll long long

iab vs vector<string>
iab vi vector<int>
iab vll vector<long long>
iab vb vector<bool>

iab ii pair<int, int>
iab dd pair<double, double>
iab pi pair<int, int>
iab pd pair<double, double>

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

iab minu MINUPDATE(., );<ESC>F.c
iab maxu MAXUPDATE(., );<ESC>F.c

iab acc accumulate(ALL(.), 0);<ESC>F.c
iab accu accumulate(..begin(), .end(), 0);<ESC>3F.c
iab sor sort(ALL(.));<ESC>F.c
iab rsor sort(REVALL(.));<ESC>F.c
