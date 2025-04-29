
# coding: utf-8

# In[6]:


def is_harshad_number(n):
    # 将数字n拆分成各位数值
    digits = [int(d) for d in str(n)]
    # 计算n的数字和
    digit_sum = sum(digits)
    # 判断
    return n % digit_sum == 0


def find_harshad_numbers(limit):
    # 存储所有哈沙德数
    harshad_numbers = []
    for i in range(1, limit+1):
        if is_harshad_number(i):
            harshad_numbers.append(i)
    
    return harshad_numbers


# 查找1000以内所有的哈沙德数并输出
harshad_numbers = find_harshad_numbers(1000)
print("1000以内的哈沙德数有：", harshad_numbers)

