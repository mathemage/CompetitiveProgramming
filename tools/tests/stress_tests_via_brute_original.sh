# from https://github.com/Errichto/youtube/blob/master/testing/s.sh
# - see also https://www.youtube.com/watch?v=JXTVOyQpSGM

for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./a < int) <(./brute < int) || break
done
