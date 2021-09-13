clear

for F in in*
do
  echo "############################## $F  ##############################"
#   cat $F
  echo "############################## OUT ##############################"
#   (ulimit -s 65536 -t 4; diff -w <(./driver_A2 <$F) <(./driver_brute <$F) )
  ( diff -w <(./driver_C <$F) <(./driver_brute <$F) )
  echo "#################################################################"
  echo
done

for F in validation/*input*
do
  echo "############################## $F  ##############################"
  echo "############################## OUT ##############################"
#   (sudo ulimit -t 8; diff -w <(./driver_A2 <$F) <(./driver_brute <$F) )
  ( diff -w <(./driver_C <$F) <(./driver_brute <$F) )
  echo "#################################################################"
  echo
done
