# Name: Aniruddha Sil
# Username: lawlesx

# Problem From codeforces https://codeforces.com/contest/1447/problem/A

# Add Candies

T = int(input())
while T != 0:
    n = int(input())
    print(n)
    # Complexity: O(n)
    for i in range(1, n+1):
        print(i, end=' ')
    T -= 1
