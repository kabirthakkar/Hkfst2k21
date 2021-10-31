# Name: Aniruddha Sil
# Username: lawlesx
# https://codeforces.com/contest/1538/problem/A

# Stone Game
T = int(input())

# Constant Time or O(n)

while T != 0:
    n = int(input())
    v = [int(i) for i in input().split()]
    v_max = max(v)
    v_max_index = v.index(v_max)
    v_min = min(v)
    v_min_index = v.index(v_min)

    ans1 = max(v_max_index, v_min_index) + 1

    ans2 = n-min(v_max_index, v_min_index)

    ans3 = min(v_max_index+1, n-v_max_index)+min(v_min_index+1, n-v_min_index)

    print(min(ans1, ans2, ans3))

    T -= 1
