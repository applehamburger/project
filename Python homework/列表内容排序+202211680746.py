
# coding: utf-8

# In[1]:


#列表 3.27
import random
def generate_a_list():
    a_list = []
    for i in range(120):
        num = random.randint(1, 100)
        a_list.append(num)
    return a_list
def sort_a_list(a_list):
    b_list = []
    for i in range(len(a_list)):
        for j in range(i, len(a_list)):
            if a_list[i] > a_list[j]:
                a_list[i], a_list[j] = a_list[j], a_list[i]
    b_list = a_list
    return b_list
def print_index_above_mean(a_list):
    sum = 0
    for num in a_list:
        sum += num
    mean = sum / len(a_list)
    for i in range(len(a_list)):
        if a_list[i] > mean:
            print(i)
a_list = generate_a_list()
print(a_list)
b_list = sort_a_list(a_list)
print(b_list)
print_index_above_mean(a_list)

