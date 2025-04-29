#!/usr/bin/env python
# coding: utf-8

# In[6]:


a={1,3,5,7,9,10}
b={1,3,5,6,8,9}
#交集
intersection=a&b
intersection_method=a.intersection(b)
print(intersection)
print(intersection_method)

#并集
union=a|b
union_method=a.union(b)
print(union)
print(union_method)

#差集
difference=a-b
print(difference)

#对称差集
symmetric_difference=a^b
symmetric_difference_method=a.symmetric_difference(b)
print(symmetric_difference)
print(symmetric_difference_method)


#调换位置
#交集
intersection=a&b
intersection_method=b.intersection(a)
print(intersection)
print(intersection_method)

#并集
union=a|b
union_method=b.union(a)
print(union)
print(union_method)

#差集
difference=b-a
print(difference)

#对称差集
symmetric_difference=a^b
symmetric_difference_method=b.symmetric_difference(a)
print(symmetric_difference)
print(symmetric_difference_method)


# In[ ]:




