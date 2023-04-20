import chardet

def main():
    f = open('C:\\Users\\flywh\\Downloads\\test.txt', 'r')
    temp = f.read()
    f.close()

    temp2 = ''
    i=1
    count = 1
    c = temp[0]
    while i < len(temp):
        if temp[i]==c:
            count+=1
        else:
            if count>1:
                temp2+=(str(count)+c)
            else:
                temp2+=c
            c=temp[i]
            count=1
        i+=1
    
    f = open('C:\\Users\\flywh\\Downloads\\testCompress.txt', 'w')
    f.write(temp2)
    f.close()

if __name__=='__main__':
    main()
