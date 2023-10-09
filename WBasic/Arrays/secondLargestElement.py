# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
# print("Hello world")

a=[2,3,5,6,8,4]
maxi=0
for i in a:
    if maxi<i:
        maxi=i;
        
diff=0
j=0
secMax=-1
for i in a:
    minus=abs(maxi-i)
    if (j==0):
        diff=minus;
        secMax=i;
        j+=1;
    if diff>minus and i != maxi:
        diff=minus;
        secMax=i;
        

print("Max is ",maxi)
print("Second Max is ",secMax)
        
        