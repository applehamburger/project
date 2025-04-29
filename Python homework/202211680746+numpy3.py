
# coding: utf-8

# In[3]:


import numpy as np

a = np.array([1, 2, 3, 4, 5])
b = np.array([4, 5, 6, 7, 8])

# 使用linalg.norm函数计算欧氏距离
distance = np.linalg.norm(a - b)

print(distance)

