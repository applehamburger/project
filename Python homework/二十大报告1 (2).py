
# coding: utf-8

# In[2]:


file= "C:\Users\lenovo\Downloads\20ReportEng.txt"
f= open(file,encoding="utf-8")
T= f.read()
f.close()

def to(T):
    l1=[]
    l1=T.split(' ')
    l2=('\n'.join(l1))
    t=[]
    t=l2.split('\n')
    word=[]
    for i in t:
        if i not in word:
            word.append(i)
    j=0
    words = {c for c in word}
    for c in words:
        j+=1
    return j

print(to(T))

