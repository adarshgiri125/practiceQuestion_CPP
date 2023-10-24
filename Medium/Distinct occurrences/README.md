<h2><a href="https://practice.geeksforgeeks.org/problems/distinct-occurrences/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Distinct occurrences</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two strings <strong>S </strong>and<strong> T</strong> of length <strong>n</strong> and <strong>m</strong> respectively. Find count of distinct occurrences of T in S as a sub-sequence.&nbsp;</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
S = "banana" , T = "ban"
<strong>Output:</strong> 3
<strong>Explanation</strong>: There are 3&nbsp;sub-sequences:
[ban], [ba n], [b an].</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
S = "geeksforgeeks" , T = "ge"
<strong>Output:</strong> 6
<strong>Explanation</strong>: There are 6 sub-sequences:
[ge], [ ge], [g e], [g e] [g e] and [ g e].</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything.Your task is to complete the function&nbsp;<strong>subsequenceCount()</strong> which takes two strings as argument&nbsp;S and T and returns the count of the sub-sequences&nbsp;modulo&nbsp;10<sup>9</sup> + 7.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(n*m).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(n*m).<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ length of(T) ≤ 100<br>
1 ≤ length of(S) ≤ 8000</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;