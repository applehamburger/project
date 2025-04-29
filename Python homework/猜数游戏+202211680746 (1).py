
# coding: utf-8

# In[ ]:


#猜数游戏3.21
import random
def guess_number():
    guess_times = 0
    guess_range = (20, 30)
    target_number = random.randint(*guess_range)
    while True:
        guess = input("请输入{}到{}之间的整数：".format(*guess_range))
        if not guess.isdigit():
            print("输入错误，请输入整数！")
            continue
        guess = int(guess)
        if guess < guess_range[0] or guess > guess_range[1]:
            print("猜测越界，请输入{}到{}之间的整数！".format(*guess_range))
            continue
        guess_times += 1
        if guess < target_number:
            print("猜小了！")
        elif guess > target_number:
            print("猜大了！")
        else:
            print("恭喜你，猜对了！你猜了{}次。".format(guess_times))
            break
guess_number()

