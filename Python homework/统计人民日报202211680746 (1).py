
# coding: utf-8

# In[ ]:


wl=open(r'199801.txt',encoding='utf-8').read().split(' ')
wf={}
for i in wl:
    if i in wf:
        wf[i]+=1
    else:
        wf[i]=1
        
wfs=sorted(wf.items(),key=lambda d:d[1],reverse=True)
print(wfs[:20])


s=[]
if i=='n':
    s.append(i)
wf={}
for i in s:
    if i in wf:
        wf[i]+=1
    else:
        wf[i]=1
        
wfs=sorted(wf.items(),key=lambda d:d[1],reverse=True)
print(wfs[:20])


a=[]
if i=='i':
    a.append(i)
wf={}
for i in a:
    if i in wf:
        wf[i]+=1
    else:
        wf[i]=1
        
wfs=sorted(wf.items(),key=lambda d:d[1],reverse=True)
print(wfs[:20])

