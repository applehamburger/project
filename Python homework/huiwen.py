def B2Q(char):
    inside_code = ord(char)
    if inside_code <0x0020 or inside_code > 0x7e :
        return char
    # 空格
    elif inside_code == 0x0020 :
        inside_code = 0x3000
    else:
        inside_code += 0xfee0
    return chr(inside_code)


sentence=str(input('please give me a sentence:'))
sentence = "".join([ B2Q(c) for c in sentence ])
length = len(sentence)
for i in range(length*2):
    print(" "*(length*2-i-1),end="")
    if  i>0:
        print(str(sentence[0:int(i/2)+1]),end="")
        print("".join(reversed(sentence[0:int( (i-1)/2)+1])))
    else:
        print(str(sentence[0:int(i/2)+1]))


