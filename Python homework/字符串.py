
# coding: utf-8

# In[12]:


#字符串5.9
file=r"C:\Users\lenovo\Downloads\20Report.txt"

f=open(file,encoding='')
txt=f.read()
f.close()

TT=list(txt)

tt=[]
for i in TT:
    if i not in tt:
        tt.append(i)
SK=[]
for i in tt:
    SK.append([i,TT.count(i)])
    
for i in range(len(SK)):
    
            

fr=r"C:\Users\lenovo\Downloads\20Report.txt"

f=open(fr,'w')

f.write(str(SK))
            
f.close()


