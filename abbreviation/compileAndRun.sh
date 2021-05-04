mkdir build
mkdir ./testcases/result
mkdir ./testcases/debugLog

CPPFILENAME=abbreviation

gcc ./$CPPFILENAME.cpp -lstdc++ -o ./build/$CPPFILENAME

TESTCASE=01
cat ./testcases/input/input$TESTCASE.txt | ./build/$CPPFILENAME ./testcases/result/results$TESTCASE.txt >  ./testcases/debugLog/debugLog$TESTCASE.txt && cat ./testcases/debugLog/debugLog$TESTCASE.txt && diff -c ./testcases/result/results$TESTCASE.txt ./testcases/output/output$TESTCASE.txt