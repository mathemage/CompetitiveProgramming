clear

./driver_brute_force <"in"  &> out_brute_force && git diff out_brute_force
./driver_brute_force <"./in03_09" &>out03_09_brute_force && vimdiff out03_09_brute_force out03_09
./driver_brute_force <"./in06_09" &>out06_09_brute_force && vimdiff out06_09_brute_force out06_09

# cat out*dp
