
# coding: utf-8

# In[1]:


import re
import time

# 读取文件内容
with open("E:/Python作业/199801.txt", 'r', encoding='utf-8') as file:
    content = file.read()

# 字符串形式的正则表达式匹配
start_time = time.time()
for _ in range(1000):
    re.findall(r'人民', content)
end_time = time.time()
string_matching_time = end_time - start_time

# 字节形式的正则表达式匹配
content_bytes = content.encode('utf-8')  # 转换为字节形式
start_time = time.time()
for _ in range(1000):
    re.findall(rb'\xe4\xba\xba\xe6\xb0\x91', content_bytes)
end_time = time.time()
bytes_matching_time = end_time - start_time

print("字符串形式匹配时间：", string_matching_time, "秒")
print("字节形式匹配时间：", bytes_matching_time, "秒")

