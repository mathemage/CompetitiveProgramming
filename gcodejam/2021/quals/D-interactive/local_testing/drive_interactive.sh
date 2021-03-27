clear

for case in $(seq 16)
# for case in $(seq 5)
# for case in $(seq 1)
do
  echo "############################## $case ##############################"
  echo "case == $case"

  echo "############################## INTERACTION ##############################"
#   2. python interactive_runner.py python3 testing_tool.py 0 -- ./my_solution
  python interactive_runner.py python3 local_testing_tool.py 0 -- ../driver 
#   python interactive_runner.py python3 local_testing_tool.py 0 -- ./driver 
  echo "#################################################################"

  echo
done
