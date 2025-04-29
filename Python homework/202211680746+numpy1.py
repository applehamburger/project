
# coding: utf-8

# In[1]:


import numpy as np

arr = np.array([1, 2, 3, np.nan, 5, 6, 7, np.nan])

# 使用isnan函数检查是否为NaN值
mask = np.isnan(arr)

# 使用布尔索引获取非NaN值
result = arr[~mask]

print(result)

