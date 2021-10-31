# Name: Aniruddha Sil
# Username: lawlesx

# Problem From codeforces https://codeforces.com/contest/1440/problem/A

# Buy the string
T = int(input())
while T != 0:
    n, c0, c1, h = [int(i) for i in input().split()]
    v = list(input())
    ones, zeros = 0, 0
    # Time Complexity: O(n)
    for i in v:
        if i == '0':
            zeros += 1
        elif i == '1':
            ones += 1
    total = 0
    if c0+h <= c1:
        total = c0*n+ones*h
    elif c1+h <= c0:
        total = c1*n + zeros*h
    else:
        total = c1*ones+c0*zeros

    print(total)
    T -= 1
