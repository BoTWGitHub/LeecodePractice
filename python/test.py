from collections import defaultdict

nums = [1,1,2,2,3,3,3,4,4,5]
l = 1
index = 1
q = {nums[0]}
while nums:
    print(f'L = {l}')
    l+=1
    for _ in range(len(q)):
        temp = q.pop()
        print(temp, end=',')
        q.add(nums[index])
        index+=1
        if index==len(nums):
            break