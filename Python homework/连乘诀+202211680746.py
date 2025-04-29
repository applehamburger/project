
# coding: utf-8

# In[4]:


#连乘诀 3.13
n=int(input("请输入起始数n："))
m=int(input("请输入终止数m："))
def lc(n,m):
    j=1
    while n<m:
        j=j*n
        n=n+1
    return(j)
if n==1 and m==50:
    sum=0
    while n<m:
        sum=sum+lc(n,m)
        n=n+1
    print("lc(1,50)+lc(2,50)+lc(3,50)...lc(49,50)最终结果：",sum)

