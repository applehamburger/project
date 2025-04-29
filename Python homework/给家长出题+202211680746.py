
# coding: utf-8

# In[1]:


#给家长随机出题 3.12
import random
n=int(input("请指定题目数量："))
i=0
j=0
while i<n:
    a=random.randint(0,100)
    b=random.randint(0,100)
    c=random.choice('+-*/')
    if c=='+'and (a+b)>0 and (a+b)<100: 
        print(a,'+',b,'=',a+b)
        i+=1
    if c=='-' and (a-b)>0 and (a-b)<100: 
        print(a,'-',b,'=',a-b)
        i+=1
    if c=='*' and (a*b)>0 and (a*b)<100: 
        print(a,'*',b,'=',a*b)
        i+=1
    if c=='/'and a!=0 and (a%b)==0: 
        print(a,'/',b,'=',a/b)
        i+=1

