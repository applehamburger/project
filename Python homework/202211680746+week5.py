#!/usr/bin/env python
# coding: utf-8

# In[10]:


import re
from collections import Counter
import pandas as pd 

def char_proc(fn):  #输入为文件路径，输出是字频表
    chars,count,af={},0,0  #af是累计频次
    with open(fn,encoding='utf-8') as fr:
        for line in fr:
            for c in line:
                count+=1
                if c not in chars:
                    chars[c]=1
                else:
                    chars[c]+=1
        
        charList=sorted(chars.items(),key=lambda d:d[1],reverse=True)
        fo=open('charList.txt','w',encoding='utf-8')
        for c,f in charList:
            af+=f
            fo.write(c+'\t'+str(f)+'\t'+str(f/count)+'\t'+str(af/count)+'\n')
        fo.close()
        
def word_proc(fn):
    words=Counter()
    with open(fn,encoding='utf-8')as fr:
        words.update(word.split('/')[0] for line in fr for word in line.split())
    wordList=words.most_commen()
    fo=open('wordList.txt','w',encoding='utf-8')
    total_words=sum(words.values())
    af=0
    for c,f in wordList:
        af+=f
        fo.write(f'{c}\t{f}\t{f/total_words}\t{af/total_words}\n')
        
    fo.close()
    


def pos_proc(fn):  #输入是路径，输出是词性分布表
    pos,count,af={},0,0  #af是累计频次
    with open(fn,encoding='utf-8') as fr:
        for line in fr:
            for c in line.split(' '):
                count+=1
                tmp=c.split('/')
                if len(tmp)>1:
                    p=tmp[1]
                    if p not in pos:
                        pos[p]=1
                    else:
                        pos[p]+=1
        
        posList=sorted(pos.items(),key=lambda d:d[1],reverse=True)
        fo=open('posList.txt','w',encoding='utf-8')
        for c,f in posList:
            af+=f
            fo.write(c+'\t'+str(f)+'\t'+str(f/count)+'\t'+str(af/count)+'\n')
        fo.close()

        
def sent_proc(fn):  #输入为文件路径，输出是句型分布和句长分析报告
    sents_total,dec,que,exc,count,af,sl=[],0,0,0,0,0,[]  #af是累计频次，sl是句长序列列表
    with open(fn,encoding='utf-8') as fr:
        for line in fr:
            dec+=line.count('。')
            que+=line.count('？')
            exc+=line.count('！')
            sents=re.split(r'[。！？]',line)
            sents_total+=sents
            count+=len(sents)
            for sent in sents:#统计每个句子长度
                sl.append(len(sent))
    
    fo=open('sentList.txt','w',encoding='utf-8')
    #用pandas分析句长分布
    psl=pd.Series(sl)
    fo.write(str(psl.describe()))
    #输出具体句长列表
    for c,f in {'dec':dec,'que':que,'exc':exc}.items():
        af+=f
        fo.write(c+'\t'+str(f)+'\t'+str(f/count)+'\t'+str(af/count)+'\n')
    fo.close()
                    

def main(fn):
    char_proc(fn+r'.raw.txt')#计算字频表
    word_proc(fn+r'.seg_pos.txt')#计算词频表
    pos_proc(fn+r'.seg_pos.txt')#计算词性分布
    sent_proc(fn+r'.raw.txt')#计算三种句子占比
    
        
fn=r'news'
main(fn)


        


# In[ ]:




