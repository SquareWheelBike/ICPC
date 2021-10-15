
from random import randrange, randint

t = 150

f = open("biginput.txt", "w")
f.write(str(t) + "\n")
# percent chance, 0-100%


def chance(percent):
    return randrange(100) < percent


for c in range(t):
    n = randint(10000, 100000)
    # generate array b
    b = [0] * n
    # for random number of times, up to n/3
    for i in range(randrange(int(n/3))):
        # add 1, 2, 3 to random spot between 0 and n-2
        j = randrange(n-2)
        for k in range(3):
            b[j+k] += k + 1
    # generate valid a
    # 10% chance of just blanking it out
    a = []
    if chance(10):
        a = [0] * n
    else:
        # copy b into a
        a = b.copy()
        # do the same shit to a as b, from b reference
        for i in range(randrange(int(n/3))):
            # add 1, 2, 3 to random spot between 0 and n-2
            j = randrange(n-2)
            for k in range(3):
                b[j+k] += k + 1
    # 10% chance of messing with adding randoms to A
    if chance(10):
        for i in range(randrange(int(n/100))):
            a[i] += randrange(3)
    # now that n, a, and b are generated, print them to file
    f.write(str(n) + '\n')
    for i in a:
        f.write(str(i) + " ")
    f.write("\n")
    for i in b:
        f.write(str(i) + " ")
    f.write("\n")
f.close()
