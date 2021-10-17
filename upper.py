def uplow(str1):
    uc=0
    lc=0
    for c in str1:
        if c.isupper():
            uc+=1
        if c.islower():
            lc+=1
    
    print('Original string %s\nNo.of lower case:%d\nNo. of upper case:%d'%(str1,lc,uc))

uplow(input('Enter the string'))
