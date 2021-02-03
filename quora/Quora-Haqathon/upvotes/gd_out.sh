# ./driver <"in" |& tee out_naive_counting && git diff out_naive_counting
# ./driver <"in2" |& tee out2_naive_counting && git diff out2_naive_counting
# ./driver <"in3" |& tee out3_naive_counting && git diff out3_naive_counting
# ./driver <"in4" |& tee out4_naive_counting && git diff out4_naive_counting

./driver <"in"  &>out_naive_counting && git diff out_naive_counting
./driver <"in2" &>out2_naive_counting && git diff out2_naive_counting
./driver <"in3" &>out3_naive_counting && git diff out3_naive_counting
./driver <"in4" &>out4_naive_counting && git diff out4_naive_counting
