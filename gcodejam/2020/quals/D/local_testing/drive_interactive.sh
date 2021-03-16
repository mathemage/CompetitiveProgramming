clear

# for case in $(seq 16)
for case in $(seq 5)
do
  echo "############################## $case ##############################"
  echo "case == $case"
  echo "############################## INTERACTION ##############################"
  python interactive_runner.py python3 local_testing_tool.py 0 -- ../driver 
  echo "#################################################################"
  echo
done
