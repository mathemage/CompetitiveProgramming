" abbreviations
iab fis for (int i = 0; i < .size(); ++i) {<CR>}<ESC>-f.i
iab ato atoi(.c_str())<ESC>F.i
iab vs vector<string>
iab AC accumulate(.begin(), .end(), 0);<ESC>2F.i

" make commands
map! <F5> <ESC>:wa!<cr>:make run<cr>
map! <F6> <ESC>:wa!<cr>:make test<cr>
map! <F6> <ESC>:wa!<cr>:make<cr>
