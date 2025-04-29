
# coding: utf-8

# In[1]:



import pandas as pd
import matplotlib.pyplot as plt

# 1. 读取csv文件并打印前5行数据
df = pd.read_csv("C:/Users/lenovo/Downloads/appl_1980_2014.csv")
print(df.head())

# 2. 打印所有列的数据类型
print(df.dtypes)

# 3. 将Date这一列的数据类型转换为datetime类型
df['Date'] = pd.to_datetime(df['Date'])

# 4. 将Date这一列设置为索引
df.set_index('Date', inplace=True)

# 5. 查看是否有重复的索引日期
print(df.index.duplicated())

# 6. 将数据按照日期先后顺序进行排列，并打印排序后的前5行数据
df.sort_index(inplace=True)
print(df.head())

# 7. 获取每个月最后一个工作日，并打印出前5个日期
res = df.resample('BM').last()
print(res.head())

# 8. 统计文件中有多少个月的数据
print('文件中有', res.shape[0], '个月的数据')

# 9. 将“Adj Close”列中的数据进行可视化，图片大小设置为13.5*9英寸
df['Adj Close'].plot(figsize=(13.5, 9))
plt.show()



