def maximum_pairwise_product(numbers):
    n = len(numbers)
    first = 0
    second = 0
    for x in range(n):
        if numbers[x] >= first:
            second = first
            first = numbers[x]
        elif numbers[x] > second:
            second = numbers[x]

    return first * second

if __name__ == '__main__':
    arrayNumber = input()
    content = input()
    array = list(map(int, content.split(" ")))
    print(maximum_pairwise_product(array))