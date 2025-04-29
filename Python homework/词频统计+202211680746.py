
# coding: utf-8

# In[3]:


def word_count(s):
    # 利用空格分割字符串得到单词列表
    words = s.split()
    # 计算总单词数
    count = len(words)
    
    # 构建字典，记录每个单词出现的次数
    word_dict = {}
    for word in words:
        if word not in word_dict:
            word_dict[word] = 1
        else:
            word_dict[word] += 1
    
    # 将字典转化为元组的列表
    word_list = [(word, count) for word, count in word_dict.items()]
    
    return count, word_list


def word_count_without_count(s):
    # 利用空格分割字符串得到单词列表
    words = s.split()
    # 总单词数初始化为0
    count = 0
    
    # 构建字典，记录每个单词出现的次数
    word_dict = {}
    for word in words:
        # 如果单词不在字典中，则将其添加，并将计数值初始化为1
        if word not in word_dict:
            word_dict[word] = 1
        else:
        # 如果单词已经在字典中，则将其计数值加1
            word_dict[word] += 1
        # 每处理一个单词，总单词数加1
        count += 1
    
    # 将字典转化为元组的列表
    word_list = [(word, count) for word, count in word_dict.items()]
    
    return count, word_list


s=r'love never fails no matter you believe it or not but someone always asks why you have to go into love because love is forever is everlasting like the mountain shining far away after the long long  everlasting journey it is good it is always good for you and for me and for everyone someone and having no end no earth no answer least'

# 使用count函数
count, word_list = word_count(s)
print("单词数：", count)
print("每个单词出现次数：", word_list)

# 不使用count函数
count, word_list = word_count_without_count(s)
print("单词数：", count)
print("每个单词出现次数：", word_list)

