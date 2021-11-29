# generate an input file for testing limits of Qualprel.c

# constraints:
# 1 <= T <= 1000
# 1 <= K <= N <= 100 000
# 1 <= S[i] <= 1 000 000 000
# the sum N for all test cases does not exceed 1 000 000

import random

random.seed()

T = random.randint(500, 1000)

f = open("biginput.txt", "w")
f.write(str(T) + "\n")

for c in range(T):
    N = random.randint(5000, 10000)
    K = random.randint(1, N)
    f.write(str(N) + " " + str(K) + "\n")
    s = ""
    for i in range(N):
        s += str(random.randint(1, 1000000000)) + " "
    f.write(s + "\n")
