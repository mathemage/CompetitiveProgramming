clear

for F in in*
do
  cat $F
  ./driver <$F
  echo
done
