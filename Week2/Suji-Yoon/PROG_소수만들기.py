import math

# 에라스토스테네스의 체
def makePrimeArr():
    array = [True for _ in range(3001)]
    for i in range(2, int(math.sqrt(3000)) + 1):
        if array[i] == True:
            j = 2
            while i * j < 3000:
                array[i*j] = False
                j += 1
    return array

# 소수 판별
def checkPrime(num):
    for i in range(2, num):
        if (num % i == 0):
            return False
    return True

def solution(nums):
    answer = 0
    isPrime = makePrimeArr()
    
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            for k in range(j+1, len(nums)):
                num = nums[i] + nums[j] + nums[k]
                # if (isPrime[nums[i] + nums[j] + nums[k]]):
                #     answer += 1
                if (checkPrime(num)):
                    answer += 1

    return answer
