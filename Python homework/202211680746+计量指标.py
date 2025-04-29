
# coding: utf-8

# In[2]:




import nltk
nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')

def calculate_metrics(corpus):
    # 对语料库进行分词和词性标注
    tokens = nltk.word_tokenize(corpus)
    tagged_tokens = nltk.pos_tag(tokens, tagset='universal')

    # 计算总词数和词表长度
    total_words = len(tagged_tokens)
    unique_words = len(set([word.lower() for word, _ in tagged_tokens]))

    # 计算TTR
    ttr = unique_words / total_words

    # 计算动词总次数和总词数，并计算VR
    verb_count = len([word for word, pos in tagged_tokens if pos == 'VERB'])
    vr = verb_count / total_words

    return ttr, vr

# 读取2023.9.1-10.1语料库并计算指标
with open('E:\Python作业.txt', encoding='utf-8') as f:
    corpus1 = f.read()
ttr1, vr1 = calculate_metrics(corpus1)

# 读取2023.1.1-2.1语料库并计算指标
with open('E:\Python作业.txt', encoding='utf-8') as f:
    corpus2 = f.read()
ttr2, vr2 = calculate_metrics(corpus2)

# 输出指标结果
print('2023.9.1-10.1 TTR:', ttr1)
print('2023.9.1-10.1 VR:', vr1)
print('2023.1.1-2.1 TTR:', ttr2)
print('2023.1.1-2.1 VR:', vr2)

