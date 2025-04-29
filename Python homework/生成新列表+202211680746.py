
# coding: utf-8

# In[5]:


#间隔生成列表3.21
def merge_lists(a, b):
    """
    将两个相同长度的list，间隔插入，生成并返回一个新的list。
    :param a: 第一个list
    :param b: 第二个list
    :return: 生成的新list
    """
    result = []
    for i in range(len(a)):
        result.append(a[i])
        result.append(b[i])
    return result

