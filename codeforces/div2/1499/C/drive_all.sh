clear

for F in in*
do
  echo "############################## $F  ##############################"
  cat $F
  echo "############################## OUT ##############################"
  ./driver <$F
  echo "#################################################################"
  echo
done
