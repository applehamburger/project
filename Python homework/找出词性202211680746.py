
# coding: utf-8

# In[4]:


with open('D:\\360安全浏览器下载\\解放思想，实事求是，团结一致向前看（邓小平）.txt', 'r', encoding='utf-8') as f:
    content = f.read()
import jieba.posseg as pseg
words = pseg.cut(content)
freq = {}
for word, flag in words:
    if flag.startswith('v'):
        next_word = next(words, None)
        if next_word:
            next_flag = next_word.flag
            next_next_word = next(words, None)
            if next_next_word:
                next_next_flag = next_next_word.flag
                pos = '{} {} {}'.format(flag, next_flag, next_next_flag)
                freq[pos] = freq.get(pos, 0) + 1
# 按照频次从高到低输出词性组合的频次表
for pos, count in sorted(freq.items(), key=lambda x: x[1], reverse=True):
    print('{}: {}'.format(pos, count))

