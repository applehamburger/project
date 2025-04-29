
# coding: utf-8

# In[3]:


#关于整数的一切
N = int((input ("请输入一个数字：")))
def sm():
    print ("A功能：给出N的数据类型")
    print ("B功能：给出N是否为质数")
    print ("C功能：求1至N的累加")
    print ("D功能：求1至N的阶乘")
    print ("E功能：给出N的奇偶")
sm()
F = (input("请输入功能ABCDE中的一个："))
if F == "A":
    lx(N)
if F == "B":
    zs(N)
if F == "C":
    he(N)
if F == "D":
    jc(N)
if F == "E":
    jo(N)
def lx(n):
    print(n,"为",type(n))
def zs(n):
    i = 2
    if n ==1:
        print (n,"不是质数")
    else :
        while i <= n - 1:
            if n % i == 0:
                break
            i += 1
        if i >= n:
            print (n,"是质数")
        else:
            print (n,"不是质数")
def he(n):
    i = 0
    num = 0
    while i < n:
        i += 1
        num += i
    print ("1至N的累加结果为：",num)
def jc(n):
    i = 0
    num = 1
    while i < n:
        i += 1
        num *= i
    print ("1至N的阶乘结果为：",num)
def jo(n):
    if n % 2 != 0:
        print (n,"是奇数")
    else:
        print (n,"是偶数")



