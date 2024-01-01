def solution(phone_book):
    book = {}
    for number in phone_book:
        book[number] = True

    for number in phone_book:
        for i in range(len(number)):
            prefix = number[:i]
            if (book.get(prefix)): return False
    return True
