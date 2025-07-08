# 54. Spiral matrix

class Solution(object):

    def print_row(self, matrix, row, start_col, end_col):
        return [matrix[row][i] for i in range(start_col, end_col + 1)]

    def print_col(self, matrix, col, start_row, end_row):
        return [matrix[i][col] for i in range(start_row, end_row + 1)]

    def print_row_reverse(self, matrix, row, start_col, end_col):
        return [matrix[row][i] for i in range(end_col, start_col - 1, -1)]

    def print_col_reverse(self, matrix, col, start_row, end_row):
        return [matrix[i][col] for i in range(end_row, start_row - 1, -1)]


    def spiralOrder(self, matrix): 
        if not matrix or not matrix[0]:
            return []

        r, c = len(matrix), len(matrix[0])
        top, bottom, left, right = 0, r - 1, 0, c - 1
        res = []

        while top <= bottom and left <= right:
            # Top row
            res += self.print_row(matrix, top, left, right)
            top += 1

            # Right column
            res += self.print_col(matrix, right, top, bottom)
            right -= 1

            if top <= bottom:
                # Bottom row (reverse)
                res += self.print_row_reverse(matrix, bottom, left, right)
                bottom -= 1

            if left <= right:
                # Left column (reverse)
                res += self.print_col_reverse(matrix, left, top, bottom)
                left += 1

        return res