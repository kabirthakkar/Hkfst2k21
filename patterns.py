'''
Pattern1:
* 
* * 
* * * 
* * * * 
* * * * *
'''

def pattern1(num):
    for i in range(0, num):     #loop to handle number of rows
        for j in range(0, i+1): #loop to handle number of columns
            print("* ",end="")
        print("\n")

#function call
pattern1(5)

'''
Pattern2:
        * 
      * * 
    * * * 
  * * * * 
* * * * * 
'''

def pattern2(num):
    k = 2*num - 2               # number of spaces
    for i in range(0, num):     #loop to handle number of rows
        for j in range(0, k):   #loop to handle number spaces
            print(end=" ")
        k = k - 2
        for j in range(0, i+1): #loop to handle number of columns
            print("* ",end="")
        print("\n")

#function call
pattern2(5)
'''
Pattern3:
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
'''
def pattern3(num):
    k = num - 1                 # number of spaces
    for i in range(0, num):     #loop to handle number of rows
        for j in range(0, k):   #loop to handle number spaces
            print(end=" ")
        k = k - 1
        for j in range(0, i+1): #loop to handle number of columns
            print("* ",end="")
        print("\n")

#function call
pattern3(5)
