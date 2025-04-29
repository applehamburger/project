
# coding: utf-8

# In[4]:


s=input()
def reverse(s):
    if len(s)<=1:
        return s
    else:
        return s[::-1]
print(reverse(s))

