def convert(number):
    s = ''
    isFactor = False

    if number % 3 == 0:
        s += 'Pling'
        isFactor = True
    if number % 5 == 0:
        s += 'Plang'
        isFactor = True
    if number % 7 == 0:
        s += 'Plong'
        isFactor = True

    if isFactor:
        return s
    return str(number)