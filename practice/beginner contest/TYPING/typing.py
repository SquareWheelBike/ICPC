
t = int(input())

words = []
values = []

def side(key):
    if (key == 'f' or key == 'd'):
        return 'l'
    elif (key == 'j' or key == 'k'):
        return 'r'

for c in range(t):
    n = int(input())
    temp = input()
    score = 0
    lastside = 'c'  # neither side to start
    if temp in words:
        score += values[words.index(temp)] / 2
    else:
        words.append(temp)
        for chars in temp:
            if lastside == side(chars):
                score += 4
            else:
                score += 2
                score = side(chars)
    print(score)
