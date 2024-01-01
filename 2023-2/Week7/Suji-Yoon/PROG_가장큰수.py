def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: (x * 4)[:4], reverse=True)
    if numbers[0] == '0':
        return '0'
    return ''.join(numbers)
