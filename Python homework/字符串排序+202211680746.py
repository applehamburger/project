
# coding: utf-8

# In[2]:


def string_sort(s):
    n = len(s)
    for i in range(1, n):
        j = i
        while j > 0 and s[j] < s[j-1]:
            s = s[:j-1] + s[j] + s[j-1] + s[j+1:]
            j -= 1
    return s

s = "loveneverfailsnomatteryoubelieveitornot" 
sorted_s = string_sort(s)
print(sorted_s)

