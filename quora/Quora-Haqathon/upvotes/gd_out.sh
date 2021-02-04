clear

# ./driver <"in" |& tee out_naive_counting && git diff out_naive_counting
# ./driver <"in2" |& tee out2_naive_counting && git diff out2_naive_counting
# ./driver <"in3" |& tee out3_naive_counting && git diff out3_naive_counting
# ./driver <"in4" |& tee out4_naive_counting && git diff out4_naive_counting

# ./driver <"in"  &>out_naive_counting && git diff out_naive_counting
# ./driver <"in2" &>out2_naive_counting && git diff out2_naive_counting
# ./driver <"in3" &>out3_naive_counting && git diff out3_naive_counting
# ./driver <"in4" &>out4_naive_counting && git diff out4_naive_counting

# ./driver_brute_force <"in"  &> out_brute_force && git diff out_brute_force
# ./driver_brute_force <"in2" &>out2_brute_force && git diff out2_brute_force
# ./driver_brute_force <"in3" &>out3_brute_force && git diff out3_brute_force
# ./driver_brute_force <"in4" &>out4_brute_force && git diff out4_brute_force

./driver <"in"  &> out_dp && git diff out_dp
./driver <"in2" &>out2_dp && git diff out2_dp
./driver <"in3" &>out3_dp && git diff out3_dp
./driver <"in4" &>out4_dp && git diff out4_dp
cat out*dp
