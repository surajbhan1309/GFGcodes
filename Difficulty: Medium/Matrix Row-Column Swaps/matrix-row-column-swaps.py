class Solution:
    def solveQueries(self, m, n, queries):
        rows = list(range(m))
        cols = list(range(n))

        ans = []

        for t, a, b in queries:
            if t == 1:
                rows[a], rows[b] = rows[b], rows[a]

            elif t == 2:
                cols[a], cols[b] = cols[b], cols[a]

            else:
                ans.append(rows[a] * n + cols[b] + 1)

        return ans