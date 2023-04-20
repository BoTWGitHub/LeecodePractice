import time

def canBePalindrom(s: str) -> bool:
    count = dict()
    for c in s:
        if c not in count:
            count[c]=1
        else:
            count[c]+=1
    
    odd_count = 0
    for c in count:
        if count[c]%2!=0:
            odd_count+=1
            if odd_count > 1:
                return False
    return True

def isPalindrom(s: str) -> bool:
    left, right = 0, len(s)-1
    while left<right:
        if s[left]!=s[right]:
            return False
        left+=1
        right-=1

    return True

def permutationsPalindrome(string: list[str], res: set, step: int = 0):
    if step == len(string):
        temp = ''.join(string)
        if isPalindrom(temp):
            res.add(temp)

    for i in range(step, len(string)):
        string_copy = [character for character in string]
        string_copy[step], string_copy[i] = string_copy[i], string_copy[step]

        permutationsPalindrome(string_copy, res, step + 1)

def permutations(string: list[str], res: set, step: int = 0):
    if step == len(string):
        res.add(''.join(string))

    for i in range(step, len(string)):
        string_copy = [character for character in string]
        string_copy[step], string_copy[i] = string_copy[i], string_copy[step]

        permutations(string_copy, res, step + 1)

def main():
    temp = 'aaaaabbbbccddeeffffgg'
    if canBePalindrom(temp):
        '''permute_set = set()
        start = time.time()
        permutationsPalindrome(temp, permute_set)
        print(f'Brutal Force {time.time()-start}s')
        print(list(permute_set))'''

        count = dict()
        for c in temp:
            if c in count:
                count[c]+=1
            else:
                count[c]=1
        permute_str = ''
        odd_str = ''
        for c in count:
            if count[c]%2==1:
                odd_str+=c
            permute_str+=c*(count[c]//2)

        permute_set = set()
        start = time.time()
        permutations(permute_str, permute_set)
        res = list(permute_set)
        for i in range(len(res)):
            res[i] = res[i]+odd_str+res[i][::-1]
        print(f'Optimize {time.time()-start}s')
        print(res)
    else:
        print('can\' be palindrome')

if __name__=='__main__':
    main()
