
# coding: utf-8

# In[2]:


import os
import codecs

# 读取文件内容
with open("E:/Python作业/199801.txt", 'r', encoding='utf-8') as file:
    content = file.read()

# 转换为utf8编码并写入文件
with codecs.open('199801_utf8.txt', 'w', encoding='utf-8') as file:
    file.write(content)

# 转换为utf16be编码并写入文件
with codecs.open('199801_utf16be.txt', 'w', encoding='utf-16be') as file:
    file.write(content)

# 转换为gbk编码并写入文件
with codecs.open('199801_gbk.txt', 'w', encoding='gbk') as file:
    file.write(content)

# 比较文件大小
utf8_size = os.path.getsize('199801_utf8.txt')
utf16be_size = os.path.getsize('199801_utf16be.txt')
gbk_size = os.path.getsize('199801_gbk.txt')

print("utf8编码文件大小:", utf8_size, "字节")
print("utf16be编码文件大小:", utf16be_size, "字节")
print("gbk编码文件大小:", gbk_size, "字节")

