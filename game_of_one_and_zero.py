def game_of_one_and_zero(decimal, binary_number):
    binary_number_list = list(binary_number)
    print(binary_number_list)
    list_0 = []  # position of 0 in the binary number is inserted in that list
    list_1 = []  # position of 1 in the binary number is inserted in that list

    for i in range(len(binary_number)):
        if binary_number[i] == '0':
            list_0.append(i)
        else:
            list_1.append(i)

    non_consecutive_1 = []  # all non consecutive 1 in the binary number is inserted in that list
    consecutive_0 = []  # all consecutive 0 in the binary number is inserted in that list
    j = 0
    while (j < len(list_1)):
        if j != len(list_1) - 1:
            if int(list_1[j + 1]) - int(list_1[j]) != 1:
                non_consecutive_1.append(list_1[j + 1])
        j += 1

    k = 0
    while (k < len(list_0)):
        if k != len(list_0) - 1:
            if int(list_0[k + 1]) - int(list_0[k]) == 1:
                consecutive_0.append(list_0[k])
                consecutive_0.append(list_0[k + 1])
        k += 1
    non_consecutive_1 = list(dict.fromkeys(non_consecutive_1))  # remove duplicate position if any
    consecutive_0 = list(dict.fromkeys(consecutive_0))  # remove duplicate position if any

    if len(consecutive_0) != 0 or len(non_consecutive_1) != 0:
        if len(non_consecutive_1) != 0:
            for i in non_consecutive_1:
                binary_number_list[i] = '0'
        if len(consecutive_0) != 0:
            for j in consecutive_0:
                binary_number_list[j] = '1'
        game_of_one_and_zero(decimal_number, ''.join(binary_number_list))
    else:
        if int(''.join(binary_number_list), 2) > decimal_number:
            print('WON')
        else:
            print('LOST')


if __name__ == "__main__":
    decimal_number = int(input('Input number: '))
    binary_number = "{0:b}".format(decimal_number)
    game_of_one_and_zero(decimal_number, binary_number)
