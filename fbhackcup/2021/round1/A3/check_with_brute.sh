clear

for F in in*
do
  echo "############################## $F  ##############################"
  echo "############################## via brute1 ##############################"
#   (ulimit -s 65536 -t 4; diff -w <(./driver_A2 <$F) <(./driver_brute <$F) )
#   ( diff -w <(./driver <$F) <(./driver_brute1 <$F) )
  ( diff -w <(./driver_A3 <$F) <(./driver_brute1 <$F) )
  echo "#################################################################"
  echo
done

for F in in*
do
  echo "############################## $F  ##############################"
  echo "############################## via brute2 ##############################"
#   (ulimit -s 65536 -t 4; diff -w <(./driver_A2 <$F) <(./driver_brute <$F) )
  ( diff -w <(./driver_A3 <$F) <(./driver_brute2 <$F) )
  echo "#################################################################"
  echo
done

# for F in validation/*input*
# do
#   echo "############################## $F  ##############################"
#   echo "############################## OUT ##############################"
# #   (sudo ulimit -t 8; diff -w <(./driver_A2 <$F) <(./driver_brute <$F) )
#   ( diff -w <(./driver_A2 <$F) <(./driver_brute <$F) )
#   echo "#################################################################"
#   echo
# done
