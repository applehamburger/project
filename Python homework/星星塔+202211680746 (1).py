
# coding: utf-8

# In[ ]:


#星星塔4.4
s=input("请输入符号：")
b=int(input("你喜欢的高度："))
def zuoxiazhijiao(s):
    for i in range(1, h+1):
        print(s*i)


def zuoshangzhijiao(s):
    for i in range(1, h+1):
        print(s*(h-i+1)+' '*(i-1))
        

def youxiazhijiao(s):
    for i in range(1, h+1):
        print(' '*(h-i)+s*i)
        

def youshangzhijiao(s):
    for i in range(1, h+1):
        print(' '*(i-1)+s*(h+1-i))


def shangdingjiao(s):
    for i in range(1,h+1):
        print(' '*(h-i)+s*(2*i-1))
        
def xiadingjiao(s):
    for i in range(1,h+1):
        print(' '*(i-1)+s*(2*(h-i+1)-1)+' '*(i-1))
zuoxiazhijiao(s)

zuoshangzhijiao(s)

youxiazhijiao(s)

youshangzhijiao(s)

shangdingjiao(s)

xiadingjiao(s)

