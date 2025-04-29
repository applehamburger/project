# 读取词典文件并获取词语集合和最大长度
def readDict(fn):
    words = set()
    max_len = 0
    with open(fn, encoding='utf-8') as fr:
        for line in fr:
            line = line.strip()
            words.add(line)
            if len(line) > max_len:
                max_len = len(line)
    return words, max_len

# 分词函数
def segment(inp, words, max_len):
    segged = ''
    rest = inp

    while rest:
        for i in range(max_len, 0, -1):
            candi = rest[:i]

            if candi in words:
                segged += candi + ' '
                rest = rest[i:]
                break
            elif i == 1:
                segged += candi + ' '
                rest = rest[i:]

    return segged

# 总控执行分词
def main(fn):
    words, max_len = readDict(r"C:\Users\67327\Desktop\python\dict.txt")
    output_file = r"C:\Users\67327\Desktop\seg.txt"
    with open(output_file, 'w', encoding='utf-8') as fo:
        with open(fn, encoding='utf-8') as fr:
            for line in fr:
                line = segment(line.strip(), words, max_len)
                fo.write(line + '\n')
    print("分词完成。分词结果保存在:", output_file)

input_file = r"C:\Users\67327\Desktop\python\news (1).txt" # 输入文件路径
main(input_file)