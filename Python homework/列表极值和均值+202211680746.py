
# coding: utf-8

# In[3]:


#列表最大最小值及均值3.21
def my_max(lst):
    max_num = lst[0]
    for num in lst:
        if num > max_num:
            max_num = num
    return max_num

def my_min(lst):
    min_num = lst[0]
    for num in lst:
        if num < min_num:
            min_num = num
    return min_num

def my_mean(lst):
    sum_num = 0
    for num in lst:
        sum_num += num
    mean_num = sum_num / len(lst)
    return mean_num

lst = []
n = int(input("请输入整数个数："))
for i in range(n):
    num = int(input("请输入第{}个整数：".format(i+1)))
    lst.append(num)
max_num = my_max(lst)
min_num = my_min(lst)
mean_num = my_mean(lst)
print("列表的最大值为：", max_num)
print("列表的最小值为：", min_num)
print("列表的平均值为：", mean_num)

