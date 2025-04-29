
# coding: utf-8

# In[ ]:


#最值4.3
def zuizhi (*n):
    maxs=-1000000
    for i in n:
        if i>maxs:
            maxs=i
    mins=1000000
    for j in n:
        if j<mins:
            mins=j
    return maxs,mins

a,b=zuizhi(1,2,3,4,5)
print(a,,b)

