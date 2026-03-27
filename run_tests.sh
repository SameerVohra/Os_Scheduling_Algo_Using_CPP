#!/bin/bash

echo "🔧 Compiling..."
g++ -I. -o scheduling main.cpp algorithms/*.cpp core/*.cpp visualization/*.cpp

if [ $? -ne 0 ]; then
    echo "❌ Compilation failed"
    exit 1
fi

echo "✅ Compilation successful"
echo "======================================"

run_test() {
    echo -e "\n🧪 Running Test: $1"
    echo "--------------------------------------"
    ./scheduling <<EOF
$2
EOF
    echo "======================================"
}

# ---------------- TEST CASES ----------------

# 1. Basic Test
run_test "Basic Test" "1
3
0
5
1
3
2
1"

# 2. Idle Time Test
run_test "Idle Time Test" "1
2
10
3
15
2"

# 3. Same Arrival (Comparison)
run_test "Compare All (Same Arrival)" "4
4
0
8
0
4
0
2
0
1
2"

# 4. Large Gap Test
run_test "Large Gap Test" "1
2
0
2
1000
3"

# 5. SJF Advantage Case
run_test "SJF Advantage" "4
5
0
20
1
2
2
1
3
3
4
2
2"

# 6. RR Stress Test
run_test "RR Stress" "3
3
0
10
1
5
2
8
2"

# 7. Single Process
run_test "Single Process" "1
1
5
10"

# 8. Large Values
run_test "Extreme Values" "1
2
100000
1
200000
1000000000"

# 9. Random Mixed Case
run_test "Mixed Case" "4
6
0
7
2
4
4
1
5
4
6
6
7
3
2"

echo "🎉 All tests completed!"