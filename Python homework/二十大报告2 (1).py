
# coding: utf-8

# In[ ]:


file1= "C:\Users\lenovo\Downloads\20ReportEng.txt"
f1= open(file1,encoding="utf-8")
T1= f1.read()
f1.close()

file2="C:\Users\lenovo\Downloads\19ReportEng.txt"
f2= open(file2,encoding="utf-8")
T2= f2.read()
f2.close()

def list(T):
    l1=[]
    l1=T.split(' ')
    l2=('\n'.join(l1))
    t=[]
    t=l2.split('\n')
    word=[]
    for i in t:
        if i not in word:
            word.append(i)
    return word

w1={i for i in list(T1)}
w2={j for j in list(T2)}

wj= w1 & w2
print(len(wj)/len(T1))
print(len(wj)/len(T2))

wd=w1^ w2

wb=w1|w2
print(len(wd)/len(wb))


f1=[]
f2=[]
for i in wd:
    if i in T1:
        f1.append(i)
    if i in T2:
        f2.append(i)
#产生词频表
def freq(l,T):
    words=[]
    for c in l:
        for k in words:
            if c==k[0]:
                k[1]+=1
                break
        else:
            words.append([c,1])
    for i in list(T1):
        for j in words:
            if i==j[0]:
                j[1]+=1
                break
    return words

c1=freq(f1,T1)
c2=freq(f2,T2)
#排序
def bubble_sort(lst):
    n = len(lst)
    for i in range(n-1):    
        flag = False
        for j in range(n - 1 - i):
            if lst[j][1] > lst[j + 1][1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
                flag = True
        if not flag: 
            break
    return lst[:5,-1]

print(bubble_sort(c1))
print(bubble_sort(c2))

