<h2><a href="https://www.geeksforgeeks.org/problems/matrix-row-column-swaps/1">Matrix Row-Column Swaps</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">You are given two integers <strong>m</strong> and <strong>n</strong>, representing the number of rows and columns of a grid. Initially, the grid is filled with integers from <strong>1</strong> to <strong>m × n</strong>, arranged sequentially from left to right, top to bottom.<br></span><span style="font-size: 18px;">In other words, the first row contains the first n numbers, the second row contains the next n, and so on.<br>You are also given a 2D vector <strong>queries[][] </strong>of size <strong>q</strong>, where each element is a list of three integers [type, a, b], representing an operation:&nbsp;</span></p>
<ul>
<li><span style="font-size: 18px;">type = 1 → Exchange the entire a-th row with the b-th row.</span></li>
<li><span style="font-size: 18px;">type = 2 → Exchange the entire a-th column with the b-th column.</span></li>
<li><span style="font-size: 18px;">type = 3 → Report the value currently present at position (a, b) in the grid.</span></li>
</ul>
<p><span style="font-size: 18px;">Your task is to process all the operations in the given order and return the results for every query of type 3.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">n = 3, m = 3, q = 6, </span><span style="font-size: 18px;">queries[][] = [[1, 0, 1],
                                      [3, 0, 0],
                                      [3, 1, 0],
                                      [2, 0, 1],
                                      [3, 0, 0],
                                      [3, 1, 0]]  
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">[4, 1, 5, 2]<br><strong>Explanation:</strong> Initially, the grid is filled in row-major order as a 3 × 3 matrix: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]. <br>The first query swaps row 0 and row 1, resulting in [[4, 5, 6], [1, 2, 3], [7, 8, 9]]. <br>The next two queries ask for values at positions (0,0) and (1,0), which are 4 and 1 respectively. <br>Then, a column swap between column 0 and column 1 transforms the grid into [[5, 4, 6], [2, 1, 3], [8, 7, 9]]. <br>Finally, the last two queries request values at positions (0,0) and (1,0), which are 5 and 2. <br>Therefore, the resulting output is [4, 1, 5, 2].<br></span></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>n = 2, m = 3, q = 4, queries[][] = [[2, 0, 2],
                                    [3, 0, 0],
                                    [1, 0, 1],
                                    [3, 0, 0]]  
<strong>Output: </strong>[3, 6]</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1 ≤ m*n ≤ 10<sup>9</sup><br>1 ≤ q ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;