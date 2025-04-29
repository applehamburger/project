
# coding: utf-8

# In[ ]:


import requests
from bs4 import BeautifulSoup
r=requests.get("http://news.blcu.edu.cn/lysp.htm")
soup = BeautifulSoup(r.content, 'html.parser')

contents = soup.find_all('div', attrs='wz')
url_title_dict={}
for line in contents: 
    url_titles=line.find_all('a')
    for url_title in url_titles:
        url=url_title.get('href')
        title=url_title.string
    #print(url,title)
        if url and url.endswith(r'.htm'):
            url_title_dict[url]=title


blcu_news={}
for u,t in url_title_dict.items():
    u='http://news.blcu.edu.cn/'+u
    r=requests.get(u)
    soup=BeautifulSoup(r.content.decode('utf-8'),'html.parser')
    title=soup.find('div',attrs="content-title")
    mt=title.find('h3')
    html=soup.find('div',attrs='content-con')
    text=''
    if html:
         passages=html.find_all('p')
         for passage in passages:
            if passage.string:
                 text+=passage.string
    blcu_news[u]=mt.string+'\n'+text
for k,v in blcu_news.items():
    print(k,v)
import requests
from bs4 import BeautifulSoup
r=requests.get("http://news.blcu.edu.cn/lysp.htm")
soup = BeautifulSoup(r.content, 'html.parser')

contents = soup.find_all('div', attrs='wz')
url_title_dict={}
for line in contents: 
    url_titles=line.find_all('a')
    for url_title in url_titles:
        url=url_title.get('href')
        title=url_title.string
        #print(url,title)
        if url and url.endswith(r'.htm'):
            url_title_dict[url]=title


blcu_news={}
for u,t in url_title_dict.items():
    u='http://news.blcu.edu.cn/'+u
    r=requests.get(u)
    soup=BeautifulSoup(r.content.decode('utf-8'),'html.parser')
    title=soup.find('div',attrs="content-title")
    mt=title.find('h3')
    html=soup.find('div',attrs='content-con')
    text=''
    if html:
        passages=html.find_all('p')
        for passage in passages:
            if passage.string:
                text+=passage.string
    blcu_news[u]=mt.string+'\n'+text
for k,v in blcu_news.items():
    print(k,v)

