
# coding: utf-8

# In[2]:


#维特比算法

# 定义拼音到汉字的转换规则
pinyin_dict = {
    'bei': '北',
    'jing': '京',
    'yu': '语',
    'yan': '言',
    'da': '大',
    'xue': '学'
}

def viterbi(pinyin):
    # 初始化动态规划表
    dp = [(-1, '')] * (len(pinyin) + 1)
    dp[0] = (0, '')

    # 运用维特比算法计算最优路径
    for i in range(1, len(pinyin) + 1):
        for j in range(0, i):
            if pinyin[j:i] in pinyin_dict:
                score = dp[j][0] + 1
                if score > dp[i][0]:
                    dp[i] = (score, dp[j][1] + pinyin_dict[pinyin[j:i]])

    # 返回最优路径
    return dp[len(pinyin)][1]

# 测试示例
pinyin = 'beijingyuyandaxue'
result = viterbi(pinyin)
print(result)

