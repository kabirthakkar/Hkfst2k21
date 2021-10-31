# Name: Aniruddha Sil
# Username: lawlesx

# Problem From codeforces https://codeforces.com/contest/1443/problem/A

# Kids Seating

T = int(input())


def f(a):
    if a % 2 == 0:
        return True
    else:
        return False


while T != 0:
    n = int(input())
    v = list(range(1, 4*n+1))
    # Complexity: O(n)
    for i in list(filter(f, v))[-n:]:
        print(i, end=' ')

    T -= 1
