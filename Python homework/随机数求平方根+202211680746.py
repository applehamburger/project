
# coding: utf-8

# In[2]:


#随机求平方根3.20
import random
def mean_sqrt(n, m, k):
    n = int(input("请输入随机整数个数："))
    m = int(input("请输入随机整数范围下限："))
    k = int(input("请输入随机整数范围上限："))
    lst = [random.randint(m, k) for i in range(n)]  # 生成n个随机整数的list
    mean = sum(lst) / n  # 计算均值
    sqrt_mean = mean ** 0.5  # 计算均值的平方根
    return sqrt_mean

