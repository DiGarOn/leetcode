from sys import *
from json import *
a=loads(stdin.read())
a=[w.strip() for w in a]
p=a[0]
a=a[1:]
# if len(set(a))>1:
# 	exit(1)

print(a, file=stderr)

a[0] = list(a[0].split())
a[1] = list(a[1].split())


for i in range(len(a[1])):
    # print(a[1][i], end = ",  ")
    # print(a[0][i])
    if(a[1][i] != a[0][i]):
        count_1 = 0
        for j in range(int(a[1][i])-1, i + 1):
            if(p[j] == '0'):
                count_1 -= 1
            else:
                count_1 += 1
        count_2 = 0
        for j in range(int(a[0][i])-1, i + 1):
            if(p[j] == '0'):
                count_2 -= 1
            else:
                count_2 += 1
        # print(count_1)
        # print(count_2)
        if(count_1 > 0 and count_2 > 0 or count_1 < 0 and count_2 < 0) :
            exit(0)
        else:
            exit(1)