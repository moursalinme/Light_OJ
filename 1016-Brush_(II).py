import sys
input = sys.stdin.readline

def ub (ar, n) :
    lo = 0
    hi = len(ar) - 1

    while lo < hi : 
        mid = (lo + hi)//2
        if ar[mid] == n :
            lo = mid + 1
        elif ar[mid] > n :
            hi = mid-1
        else :
            lo = mid+1
    
    if ar[lo] <= n :
        lo += 1
    return lo


def solve () :
    s = input()
    n, w = map(int, input ().split ())
    ar = []
    
    for k in range (n) :
        x, y = map (int, input().split())
        ar.append (y)
    
    ar.sort ()
    cnt = 0
    k = 0

    while k < n :
        hi = ub (ar, ar[k] + w)
        cnt += 1
        k = hi

    print (cnt)
    ar.clear()

for i in range (int (input ())) :
    print (f"Case {i+1}:", end = " ")
    solve ()
