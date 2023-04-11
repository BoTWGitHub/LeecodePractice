from re import finditer

def findIndex(arr: list[int]) -> str:
    s = sum(arr)
    left = 0
    right = s-arr[0]
    if left == right:
            return 'YES'
    for i in range(1, len(arr)):
        left+=arr[i-1]
        right-=arr[i]
        if left == right:
            return 'YES'
    return 'NO'

nums = [5,6,8,11]
print(findIndex(nums))
        