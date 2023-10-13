# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
print("Hello world")
dict1={};
arr=[2,3,5,3,3,2,6,2];
# print(dict1[1])

for i in arr:
    if i in dict1 :
        dict1[i]=dict1[i]+1;
    else:
        dict1[i]=1;
        
maxi=0;
occurance=0;
for j in dict1:
    if dict1[j] > maxi:
        maxi=j
        occurance=dict1[j]
        
# for j in dict1.values()
print("maxi",maxi);
print('occurance',occurance)