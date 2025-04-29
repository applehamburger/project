
# coding: utf-8

# In[6]:


#质数的距离 3.28  

def sushu(m):
    i=1
    j=0
    while i<m/2:
        i+=1
        if m%i==0:
            j+=1
    if j==0:
        return m
    else:
        return 0
    

def lenth(l):
    s=[]
    i=0
    while i<len(l):
            j=0
            j=i+1
            if j<len(l) and l[j]-l[i]!=0:
                if l[j]-l[i]>0:
                    s.append(l[j]-l[i])
                else:
                    s.append(l[i]-l[j])
            i+=1
    return s       


def zuida(n,nums=[]):
    maxs=0
    for i in range(n):
        if nums[i]>maxs:
            maxs=nums[i]
    print('最大值=',maxs)


def zuixiao(n,nums=[]):
    mins=1000000
    for i in range(n):
        if nums[i]<mins:
            mins=nums[i]
    print('最小值=',mins)


def pingjun(n,nums=[]):
    s=0
    for i in range(n):
        s+=nums[i]
    average=s/n
    print('平均值=',average)
    return average


def fangcha(c,nums=[]):
    s=0
    t=0
    z=0
    for i in range(len(nums)):
        z=(nums[i]-c)*(nums[i]-c)
        t=z+t
    s=t/len(nums)
    print("方差=",s)
    
def then(d,nums=[]):
    j=0
    for i in range(len(nums)):
        if nums[i]>d:
            j+=1
    print("超过平均值的距离的个数=",j)
    

for k in range(3,1000):
    if sushu(k)!=0:
        print(sushu(k),end=' ')      
print('\n')


l=[]
x=0
for x in range(3,1000):
    if sushu(x)!=0:
        l.append(sushu(x))
print(lenth(l))

n=len(lenth(l))
zuida(n,lenth(l))
zuixiao(n,lenth(l))
y=pingjun(n,lenth(l))
fangcha(y,lenth(l))

then(y,lenth(l))

