def longest_palindrome(s,i,j):
    if i==j:
        return 1
    elif i>j:
        return 0
    else:
        if s[i]==s[j]:
            return 2+ longest_palindrome(s,i+1,j-1)
        else:
            return max(longest_palindrome(s,i+1,j),longest_palindrome(s,i,j-1))


if __name__ == '__main__':
    s=input()
    print(longest_palindrome(s,0,len(s)-1))
