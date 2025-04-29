
# coding: utf-8

# In[ ]:


import requests
from bs4 import BeautifulSoup
import re
import pandas as pd



#日期生成器
def dateGenerator(start_date,end_date):
    res=pd.date_range(start_date,end_date,freq='D')
    return list(res.strftime('%Y-%m/%d'))

#调试代码
dateList=dateGenerator('2023-09-01','2023-09-05')
print(dateList)


#版面链接生成器
baseLink=r'https://epaper.gmw.cn/gmrb/html/'
def pageLinkGenerator(baseLink,dateStr,pageNum):#生成各版面链接
    #'https://epaper.gmw.cn/gmrb/html/2023-10/09/nbs.D110000gmrb_01.htm'
    res=baseLink+dateStr+r'/nbs.D110000gmrb_0'+str(pageNum)+'.htm'
    return res

def pageLinkListGenerator(dateList):#生成各版面链接的列表
    res=[]
    for d in dateList:
        for i in range(1,5): 
            res.append(pageLinkGenerator(baseLink,d,i))
    return res
#调试代码
pageLinkList=pageLinkListGenerator(dateList)
print(pageLinkList)



def parsePageLink(link):#解析版面，获得文章链接
    newsLink={}
    dateLink=link.split('nbs')[0]#获得带有日期的url部分，可以直接和新闻篇章的局部地址拼接
    r=requests.get(link)
    page=r.content.decode('utf-8')
    #新闻链接在<a href=nw.  
    #<a href=nw.D110000gmrb_20231009_2-01.htm>国家主席习近平任免驻外大使  </a>
    ms=re.finditer(r'\<a href\=(nw\.D110000gmrb\_[^\>\s]+)\>([^\<]+)\<\/a>',page)
    for m in ms:
        print(m)
        url=m.group(1)
        title=m.group(2)
        newsLink[dateLink+url]=title
    return newsLink
#调试代码
newsLink=parsePageLink(r'https://epaper.gmw.cn/gmrb/html/2023-10/09/nbs.D110000gmrb_01.htm')
print(newsLink)


def parseNewsLink(link):
    r=requests.get(link)
    page=r.content.decode('utf-8')
    #标题在<h1>, 来源在<div class="lai">，内容在<!--enpcontent-->
    soup=BeautifulSoup(page,'html.parser')
    title=soup.find('div',attrs="text_c")
    t1=title.find('h1')
    t=t1.text
    '''
    还没解决副标题有时为空的问题
    t2=title.find('h2')
    t3=title.find('h3')
    if t1 and t2 and t3:
       t=t1.text+t2.text+t3.text
    elif t1 and t2:
       t=t1.text+t2.text
    else:
       t=t1.text 
    '''
    html=soup.find('div',id="articleContent")
    text=''
    if html:
        passages=html.find_all('p')
        for passage in passages:
            if passage.text:
                text+='\n'+passage.text
    print('processing...',t)
    return t+'\n\n'+text+'\n\n'+link
#调试代码
text=parseNewsLink(r'https://epaper.gmw.cn/gmrb/html/2023-10/09/nw.D110000gmrb_20231009_1-01.htm')
print(text)


'''
1生成日期列表
2按照日期生成版面链接列表
3按照版面链接列表获得各文章版面链接
4解析各文章版面获得文章，并写入硬盘
'''
baseLink=r'https://epaper.gmw.cn/gmrb/html/'
start_date=input('请按照2023-09-01这样的格式输入起始日期')
end_date=input('请按照2023-10-01这样的格式输入终止日期')
fn==r'C:\Users\大红红\Desktop\Python\05-06Corpus\gmrb\news'

num=0
dateList=dateGenerator(start_date,end_date)
pageLinkList=pageLinkListGenerator(dateList)
for pageLink in pageLinkList:
    newsLinkList=parsePageLink(pageLink)
    for newsLink in newsLinkList:
        num+=1
        fileName=fn+str(num)+r'.txt'
        fo=open(fileName,'w',encoding='utf-8')
        news=parseNewsLink(newsLink)
        fo.write(news)
        fo.close

