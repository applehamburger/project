
# coding: utf-8

# In[2]:


import numpy as np

arr1 = np.arange(3)
arr2 = np.arange(3, 7)
arr3 = np.arange(7, 10)
array_of_arrays = np.array([arr1, arr2, arr3])

# 使用flatten函数将array_of_arrays转换为一维数组
result = array_of_arrays.flatten()

print(result)

