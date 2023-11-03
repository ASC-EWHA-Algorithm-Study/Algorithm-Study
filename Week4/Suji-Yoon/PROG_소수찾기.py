import itertools

def is_prime(num):
    if (num > 1):
        for i in range(2, num // 2 + 1):
            if (num % i == 0):
                return False
        return True
    return False

def solution(numbers):
    answer = 0
    primes = {}
    for length in range(len(numbers) + 1):
        nums = list(itertools.permutations(numbers, length))
        for n in nums:
            n = ''.join(list(n))
            if (n and is_prime(int(n)) and int(n) not in primes):
                answer += 1
                primes[int(n)] = 1
    
    return answer
