#!/usr/bin/env python
# coding: utf-8

# In[ ]:


'''
根据idiomPY.txt，编写代码，实现成语接龙：

（1）可以进行人机对战

（2）有三个难度：Hard: 接上的成语的首字必须和题目的末字相同才行（课上已经实现，自己写一下）、Middle: 接上的成语的首字和题目末字拼音相同即可（声调也要相同）、Easy: 接上的成语的首字和题目末字拼音相同（无需声调相同）

（3）选做实现两机对战

'''

import random

def formIds(fn):
    ids,pds,cys,pcys,qcys,tcys,jcys=[],[],{},{},{},{},set()
    with open(fn) as f:
        for line in f:
            cy=line.split('[')[0]
            dy=line.split('[')[1].split(' ')[0]
            ey=line.split('[')[1].split(' ')[-1][:-2]
            ids.append(cy)
            pds.append(dy)
            jcys.add(dy)
            jcys.add(ey)
            if cy[0] not in cys:
                cys[cy[0]]=[cy]
            else:
                cys[cy[0]].append(cy)
            if cy[0] not in pcys:
                pcys[cy[0]]=[dy]
            elif cy[0] in pcys and dy not in pcys[cy[0]]:
                pcys[cy[0]].append(dy)
            if cy[-1] not in pcys:
                pcys[cy[-1]]=[ey]
            elif cy[-1] in pcys and ey not in pcys[cy[-1]]:
                pcys[cy[-1]].append(ey)
            if dy[:-1] not in qcys:
                qcys[dy[:-1]]=[cy]
            else:
                qcys[dy[:-1]].append(cy)
            if cy not in tcys:
                tcys[cy]=line.split('[')[1].split(' ')
    return cys,ids,pcys,qcys,tcys,jcys

cys,ids,pcys,qcys,tcys,jcys=formIds(r"C:\Users\IdiomPY.txt")
que=random.choice(ids)
while True:
    n=int(input('请选择您的难度：Easy(1)/Middle(2)/Hard(3)：'))
    que=random.choice(ids)
    if n==1:
        while(True):
            print(que)
            inp=input('请输入可以接的成语：')
            print(pcys[inp[0]][0][:-1],pcys[que[-1]][0][:-1],pcys[inp[-1]][0][:-1])
            if inp in ids: 
                flag=0
                for i in pcys[inp[0]]:
                        for j in pcys[que[-1]]:
                            if i[:-1]==j[:-1]:
                                flag=1
                                break
                if flag==1:
                    if pcys[inp[-1]][0][:-1] not in pcys:
                        print('awsl！')
                        break
                    else:
                        que=random.choice(qcys[pcys[inp[-1]][0][:-1]])
                else:
                    print('你输了！')
                    break
            else:
                print('你输了！')
                break

    if n==2:
        while(True):
            print(que)
            inp=input('请输入可以接的成语：')
            if inp in ids and inp[0]==que[-1]:
                if inp[-1] not in cys:
                    print('awsl！')
                    break
                else:
                    que=random.choice(cys[inp[-1]])
            else:
                print('你输了！')
                break
    if n==3:
        while(True):
            print(que)
            inp=input('请输入可以接的成语：')
            if inp in ids and inp[0]==que[-1] and tcys[inp][0]==tcys[que][-1][:-2]:                                                                          
                if tcys[inp][-1][:-2] not in jcys or inp[-1] not in cys:
                    print('awsl！')
                    break
                else:
                    que=random.choice(cys[inp[-1]])
            else:
                print('你输了！')
                break

def formIds(fn):
    ids,pds,cys,pcys,qcys,tcys,jcys=[],[],{},{},{},{},set()
    with open(fn) as f:
        for line in f:
            cy=line.split('[')[0]
            dy=line.split('[')[1].split(' ')[0]
            ey=line.split('[')[1].split(' ')[-1][:-2]
            ids.append(cy)
            pds.append(dy)
            jcys.add(dy)
            jcys.add(ey)
            if cy[0] not in cys:
                cys[cy[0]]=[cy]
            else:
                cys[cy[0]].append(cy)
            if cy[0] not in pcys:
                pcys[cy[0]]=[dy]
            elif cy[0] in pcys and dy not in pcys[cy[0]]:
                pcys[cy[0]].append(dy)
            if cy[-1] not in pcys:
                pcys[cy[-1]]=[ey]
            elif cy[-1] in pcys and ey not in pcys[cy[-1]]:
                pcys[cy[-1]].append(ey)
            if dy[:-1] not in qcys:
                qcys[dy[:-1]]=[cy]
            else:
                qcys[dy[:-1]].append(cy)
            if cy not in tcys:
                tcys[cy]=line.split('[')[1].split(' ')
    return cys,ids,pcys,qcys,tcys,jcys
cys,ids,pcys,qcys,tcys,jcys=formIds(r"C:\Users\21194\Documents\WeChat Files\wxid_rofydjd6fugi22\FileStorage\File\2023-05\IdiomPY.txt")
print(jcys)

