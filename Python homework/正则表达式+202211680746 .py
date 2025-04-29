
# coding: utf-8

# In[ ]:


'''将1998年1月人民日报中形容词a+“的”+地名ns的情况统计出来，并进行排序，输出前20种组合，形成res.txt。
格式如：
美丽 的 北京   120031
宽阔 的 长江   100211
……'''

import re 

p1=r'\w+\/a  的/u  \w+\/ns'
p2=r'\w+\/a  的/u  \[[^\]]+\]]ns'
res={}
with open(r'C:\Users\lenovo\Documents\WeChat Files\wxid_xbbl8ok0ynhv22\FileStorage\File\2023-09\199801.txt') as f:
    for line in f:
        w1=re.findall(p1,line)
        for i in w1:
            if i not in res:
                res[i]=1
            else:
                res[i]+=1

        w2=re.findall(p2,line)
        for j in w2:
            if j not in res:
                res[j]=1
            else:
                res[j]+=1

fo=open(r'C:\Users\lenovo\Documents\WeChat Files\wxid_xbbl8ok0ynhv22\FileStorage\File\2023-09\199801.txt','w')
nslist=sorted(res.items(),key=lambda d:d[1],reverse=True)
reslist=nslist[:20]
for m,n in reslist:
    fo.write(m+'\t'+str(n)+'\n')

fo.close()

