
# coding: utf-8

# In[4]:


#随堂测试题：

#从键盘读入任意长度大于13的字符串，且必须包含"ab"，且"ab"不在索引0位置。写程序：
s=input("请输入小于13的字符串")
if "ab"in s:
    print("ab在字符串中")
else:
    print("ab不在字符串中")
#0）判断"ab"是否在该自字符串中（10分）
print(s[0])
print(s[-1])
for i in range(len(s)):
    print(s[i])
print(s[::-1])
print(s[3:13:3])
print(s.count("ab"))
print(s.find("ab"))


