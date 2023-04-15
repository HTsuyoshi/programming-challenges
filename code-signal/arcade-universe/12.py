from copy import copy
def solution(a):
    b = []
    for i in range(len(a)):
        if a[i] == -1: continue
        b.append(a[i])
        a[i] = -2
    
    b = sorted(b, reverse=False)
    for i in range(len(a)):
        if a[i] == -2: a[i] = b.pop(0);
    return a
