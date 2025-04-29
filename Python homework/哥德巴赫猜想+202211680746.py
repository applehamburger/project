
# coding: utf-8

# In[5]:


#哥德巴赫猜想 3.27
n=10000
list1=[2]
list2=[]
lista=[]
listb=[]
listo=[]
for i in range(3,n+1):
    j=2
    for j in range(2,i):
        if i%j==0:
            break
        else:
            list1.append(i)
for q in range(1,n+1):
    if q%2==0:
        listo.append(q)
list2=listo[4990:5000]

for e in list2:
    flag=False
    a=2
    for a in list1:
        if flag==True:
            continue
        b=2
        
        for b in list1:
            if e==a+b:
                
                lista.append([e,a,b])
                flag=True
                continue
print(lista)

