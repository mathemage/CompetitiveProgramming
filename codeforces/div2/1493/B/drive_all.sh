clear

for F in in*
do
  echo "> INPUT:"
  cat $F
  echo "> OUTPUT:"
  ./driver <$F
  echo
done
