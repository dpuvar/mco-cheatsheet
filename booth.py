def incrementBinaryByOne(num):
    num.reverse()
    if num[0] == '0':
        num[0] = '1'
    else:
        num[0] = '0'
        x = 1
        for x in range(1, len(num)):
            if num[x] == '0':
                num[x] = '1'
                break
            else:
                num[x] = '0'
    num.reverse()
    return num

def positiveBinaryConversion(num):

    stack = [num]
    binary = []

    while num > 1:
        num = num//2
        stack.append(num)
    stack.reverse()

    for binNum in stack:
        binary.append(str(binNum%2))
    '''
    We want the number of bits to be 8 and
    if they are not we need to make them 8
    we do this cause the we are dealing with
    8 bit binary numbers in the binary representation
    in the booth's algorithm
    '''
    while not len(binary) == 8:
        binary.insert(0, "0")
    return "".join(binary)

def twoscompliment(num):
    binary = []
    for element in positiveBinaryConversion(num * -1):
        if element == '1':
            binary.append('0')
        elif element == '0':
            binary.append('1')
    binary = incrementBinaryByOne(binary)
    return "".join(binary)

def twoscomplimentForSub(num):

    binary = []
    num.split()

    for element in num:
        if element == '1':
            binary.append('0')
        elif element == '0':
            binary.append('1')

    binary = incrementBinaryByOne(binary)
    return "".join(binary)

def convertToBinary(num):
    if num >= 0:
        return positiveBinaryConversion(num)
    else:
        return twoscompliment(num)

def addBinary(num1, num2):

    num1.split()
    num2.split()

    added = []
    carry = 0

    for x in range(len(num1)-1, -1, -1):
        if num1[x] == '0' and num2[x] == '0':
            if carry == 1:
                added.append('1')
                carry = 0
            else:
                added.append('0')
        elif (num1[x] == '0' and num2[x] == '1') or (num1[x] == '1' and num2[x] == '0'):
            if carry == 1:
                added.append('0')
            else:
                added.append('1')
        elif num1[x] == '1' and num2[x] == '1':
            if carry == 1:
                added.append('1')
            else:
                added.append('0')
                carry = 1
    added.reverse()
    return "".join(added)

def rightShift(a,q):

    num = a + q
    num.split()

    shifted = [num[0]]
    for x in range(0, len(num) - 1):
        shifted.append(num[x])

    return "".join(shifted)[:8], "".join(shifted)[8:]

def multByBooth(m, q):
    a = "00000000"
    qN1 = "0"
    qN = q[len(q)-1]
    print("-----------------------------------------------------------------------")
    print("| qN qN+1 |   Process                 |     AC     |     QR     | SC  |")
    print("-----------------------------------------------------------------------")
    count = len(m)
    print("|  ~~~~~", " | Initial                   | ", a,' | ', q,' | ', count,' | ')
    for loop in range(count, 0, -1):

        if qN1 == "0" and qN == "0" or qN1 == "1" and qN == "1":
            qN1 = qN
            a, q = rightShift(a, q)
            qN = q[len(q)-1]
            print("| ", qN," ", qN1,  " | ashr(AC,QR)               | ", a,' | ', q,' | ', loop-1,' | ')

        elif qN == "1" and qN1 == "0":
            a = addBinary(a, twoscomplimentForSub(m))
            qN1 = qN
            a, q = rightShift(a, q)
            qN = q[len(q)-1]
            print("| ", qN," ", qN1, " | Subtract BR, ashr(AC,QR)  | ", a,' | ', q,' | ', loop-1,' | ')

        elif qN == "0" and qN1 == "1":
            a = addBinary(a, m)
            qN1 = qN
            a, q = rightShift(a, q)
            qN = q[len(q)-1]
            print("| ", qN," ", qN1, " | Add BR, ashr(AC,QR)       | ", a,' | ', q,' | ', loop-1,' | ')
    print("-----------------------------------------------------------------------")
    print()
    print("After multiplication the answer in binary is : ", a+q)

b1=int(input("Enter BR: "))
b2=int(input("Enter QR: "))
binaryNum1 = convertToBinary(b1)
binaryNum2 = convertToBinary(b2)
print("\nBR (2's compliment): ", binaryNum1)
print("QR (2's compliment): ", binaryNum2,'\n')
print('                      |-------BOOTH TABLE-------|\n')
multByBooth(binaryNum1, binaryNum2)
print('\nAfter multiplication the answer in decimal is : ',int(b1)*int(b2))
print("\nNAME AND ID :: DHRUV DIGVIJAYSINH PUVAR AND 20CE117\n")
