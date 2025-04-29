
# coding: utf-8

# In[2]:


#现代化4.18
file= r"D:\20thReport.txt"
f= open(file,encoding="utf-8") 
T=f.read()
f.close()

l=[]
l=T.split('。')
words=('\n'.join(l))
t=[]
t=words.split('\n')

s=[]
for j in t:
    for k in range(len(j)):
        if k<len(j) and j[k]=="中":
            if k+1<len(j)and j[k+1]=="国":
                if  k+2<len(j)and j[k+2]=="式":
                    if k+3<len(j)and j[k+3]=="现":
                        if k+4<len(j)and j[k+4]=="代":
                            if k+5<len(j)and j[k+5]=="化":
                                s.append(j)
 
file2 = r"D:\ChineseMordernization.txt"
f2 = open(file2, "w")
for i in s:
    print(i,file=f2)
    print('\n',file=f2)
f2.close()

