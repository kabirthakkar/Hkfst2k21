#This Python program will check whether the Entered password and returns output that whether it was valid password or Invalid password
def CheckPassword(s,n):
    if n<4:
        return "Invalid Password"
    if s[0].isdigit():
        return "Invalid Password"
    cap=0
    nu=0
    for i in range(n):
        if s[i]==' ' or s[i]=='/':
            return "Invalid Password"
        if s[i]>='A' and s[i]<='Z':
            cap+=1
        elif s[i].isdigit():
            nu+=1
 
    if cap>0 and nu>0:
        return "Valid Password"
    else:
        return "Invalid Password"
 
s=input()
a=len(s)
print(CheckPassword(s,a))
