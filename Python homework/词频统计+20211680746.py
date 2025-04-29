
# coding: utf-8

# In[1]:


import jieba

file=r"D:\20thReport.txt"
with open(file,encoding='utf-8') as fr:
    txt=fr.read()

dd=jieba.lcut(txt)         
hh=[]
for i in dd:
    if i not in hh:     #去除重复项
        hh.append(i)

HH=[]
for i in hh:            
    HH.append([i,dd.count(i)])


k=0
for i in HH:
    if i[1]>=k:          #找出最高的频次
        k=i[1]

for i in range(1,k+1):
    count=0              
    for j in HH:
        if j[1]==i:
            count=count+1
    if count!=0:
        print("共有",count,"个数出现了",i,"次")
        

