clear

for F in in*
do
  echo "############################## $F  ##############################"
  cat $F
  echo "############################## OUT ##############################"
#   (ulimit -s 65536 -t 4; time ./driver <$F)
#  (ulimit -s 65536 -t 4; ./driver <$F)
  (ulimit -s 65536 -t 4; python *.py <$F)
  echo "#################################################################"
  echo
done
