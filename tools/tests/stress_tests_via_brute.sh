# from https://github.com/Errichto/youtube/blob/master/testing/s.sh
# - see also https://www.youtube.com/watch?v=JXTVOyQpSGM

for((i = 1; ; ++i)); do
    echo Random case $i:
    ./gen_int $i > int
    # ./driver < int > out1
    # ./driver_brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./driver < int) <(./driver_brute < int) || break
done
