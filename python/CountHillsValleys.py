nums = [5,5,4,4,3,1,3]
temp = []
for num1, num2 in zip(nums[0:-1], nums[1:]):
    temp.append(num2-num1)

while 0 in temp:
    temp.remove(0)

res = 0
neg = False
if temp[0] < 0:
    neg = True

for i in temp[1:]:
    if neg:
        if i > 0:
            res+=1

print(temp)