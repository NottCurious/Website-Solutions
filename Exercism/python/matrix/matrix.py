class Matrix:
    def __init__(self, matrix_string):
        mymatrix = matrix_string

    def row(self, index):
        rrow = ''
        i = index
        matrix = self.mymatrix

        while i < len(matrix):
            rrow += matrix[i]
            i += 3

        return rrow

    def column(self, index):
        pass
