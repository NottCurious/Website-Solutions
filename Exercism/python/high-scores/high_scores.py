def latest(scores):
    return scores[-1]


def personal_best(scores):
    sort(scores)
    return scores[0]


def personal_top_three(scores):
    sort(scores)
    return scores[0:3]

def sort(a):
    for i in range(len(a)):
        for j in range(len(a) - i - 1):
            if a[j] < a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]


