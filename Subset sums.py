class Solution:

    @staticmethod
    def subsetSums(array, n):
        array.sort()
        result = []
        total = 2 ** n

        for i in range(total):
            value = 0

            for j in range(n):
                if (i & (1 << j)) != 0:
                    value += array[j]
            result.append(value)
        result.sort()

        return result


# {
#  Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        N = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.subsetSums(arr, N)
        for x in ans:
            print(x, end=" ")
        print("")

# } Driver Code Ends
