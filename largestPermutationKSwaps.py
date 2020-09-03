t = int(input())
for i in range(0,t):
    n,k = [int(x) for x in input().strip().split(" ")] 
    lst = [int(x) for x in input().strip().split(" ")]
    pos = dict()
    for i in range(0, len(lst)):
        pos[lst[i]]=i

    for i in range(0, len(lst)):
        if k == 0:
            break
        if lst[i] == n-i:
            continue
        ind = pos[n-i]
        pos[lst[i]] = pos [n-i]
        pos [n-i] = i
        temp = lst[i]
        lst[i]=lst[ind]
        lst[ind]=temp
        k-=1
    for i in lst:
        print(i, end=" ")
    print()
