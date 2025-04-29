
# coding: utf-8

# In[ ]:


file=r"D:\20thReport.txt"

f=open(file,encoding='utf-8')
txt=f.read()
f.close()

TT=list(txt)

tt=[]
for i in TT:
    if i not in tt:
        tt.append(i)
HH=[]
for i in tt:
    HH.append([i,TT.count(i)])
    
for i in range(len(HH)):
    for j in range(len(HH)-1-i):
        if HH[j][1]<=HH[j+1][1]:
            HH[j],HH[j+1]=HH[j+1],HH[j]

fr=r"D:\chs_sort_20Report.txt"

f=open(fr,'w')

f.write(str(HH))jif
            
f.close()

