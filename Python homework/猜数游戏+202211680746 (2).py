
# coding: utf-8

# In[2]:


#猜数游戏  3.14
import random
while 1:
    i = 0
    num = random.randint(1,100)
    while i < 5:
        i +=1
        guess = int (input ("请输入你猜的数字："))
        if guess == num:
            print("您猜对了！")
            break
        if i==5:
            print("game over")
        elif num > guess:
            print("猜小了！")
        elif num < guess:
            print("猜大了！")
    n=int(input("结束游戏请输入0,再来一局请输入1"))
    if n==0:
        break

