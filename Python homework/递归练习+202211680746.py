
# coding: utf-8

# In[ ]:


def my_rec_sum(a,b):
    if a==b:
        return b
    else:
        return a+my_rec_sum(a+1,b)

print(my_rec_sum(0,100))


def Digitsum(n):
    i=0
    while n%(10**i)!=n:
        i=i+1
    t=n//10**(i-1)
    if i==1:
        return n
    else:
        return t+Digitsum(n-t*(10**(i-1)))
        
print(Digitsum(1729))


def Liustep(n):
    if n<=2:
        return n
    else:
        return Liustep(n-1)+Liustep(n-2)


print(Liustep(10))

