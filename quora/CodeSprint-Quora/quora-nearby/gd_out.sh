clear

./driver_brute_force <"in"  &> out_brute_force && git diff out_brute_force
./driver_brute_force <"./in03_09" &>out03_09_brute_force && vimdiff out03_09_brute_force out03_09

# cat out*dp
