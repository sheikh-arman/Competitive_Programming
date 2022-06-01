ar=[]
ar.append(0)
ar.append(1)
for i in range(2,5001):
    ar.append(ar[i-1]+ar[i-2])
while (0 or 1):
    try:
        num = int(input())
        print('The Fibonacci number for %d is' %num,ar[num])
    except EOFError:
        break