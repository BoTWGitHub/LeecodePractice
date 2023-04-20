def CompressStr(s: str) -> str:
    count = 1
    c = s[0]
    res = ''
    for i in range(1, len(s)):
        if s[i]!=c:
            res+=c
            res+=str(count)
            c = s[i]
            count = 1
        else:
            count+=1
    res+=c
    res+=str(count)
    if len(res)>=len(s):
        return s
    return res
    
def main():
    s = input('input string: ')
    print(CompressStr(s))

if __name__=='__main__':
    main()