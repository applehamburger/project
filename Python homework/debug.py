# 让同学们debug的实例-1

def add_underscores(word):
    new_word = "_"
    for i in range(len(word)):
        new_word = word[i] + "_"
    return new_word



def my_reverse(word):
    return word[::-1]



phrase = "hello"
my_reverse(phrase)
print(add_underscores(phrase))
# 希望输出：_o_l_l_e_h_



​

# 让同学们debug的实例-2
L = [[5, 5.5, "dsfd"], (6, 56.6, "adfsa"), 5, 5,5, "asdksa"]
total = 0
for item in L:
    if isinstance(item, int) or isinstance(item, float):
        total += item
    elif isinstance(item, list) or isinstance(item, tuple):
        for e in item:
            if isinstance(item, int) or isinstance(item, float):
                total += item

print(total)

#无需提交，自行调试