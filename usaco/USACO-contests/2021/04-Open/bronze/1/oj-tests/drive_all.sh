clear

for F in *.in
do
  echo "############################## $F  ##############################"
  cat $F
  echo "############################## OUT ##############################"
  (ulimit -s 65536 -t 4; ../driver <$F)

  outfile=${F%.*}.out
  echo "############################## $outfile ##############################"
  cat $outfile
  echo "#################################################################"
  echo
done
