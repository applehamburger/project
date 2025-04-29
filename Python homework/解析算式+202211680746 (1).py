
# coding: utf-8

# In[5]:


def calculate(s):
    
    tokens = s.replace('+', ' ').replace('-', ' ').replace('x', ' ').replace('/', ' ').split()
    
    # 将分割得到的三个数字转化为整数型
    x, y, z = map(int, tokens)
    
    # 遍历原始字符串，根据加减乘除符号计算出结果
    result = None
    for i in range(len(s)):
        if s[i] == '+':
            result = x + y + z
            break
        elif s[i] == '-':
            result = x - y - z
            break
        elif s[i] == 'x':
            result = x * y * z
            break
        elif s[i] == '/':
            result = int(x / y / z)
            break
    
    return result
    

# 测试
s = '1+52+4'
result = calculate(s)
print(s, '=', result)

