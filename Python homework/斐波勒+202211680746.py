
# coding: utf-8

# In[ ]:


#斐波勒4.3
def change(line):
    s=line
    i=s.find('l')
    s=s[0:i+1].replace('l','I')+s[i+1::]
    return s

line='I saw two FBls going down lower into the rooms.'
print(change(line))

