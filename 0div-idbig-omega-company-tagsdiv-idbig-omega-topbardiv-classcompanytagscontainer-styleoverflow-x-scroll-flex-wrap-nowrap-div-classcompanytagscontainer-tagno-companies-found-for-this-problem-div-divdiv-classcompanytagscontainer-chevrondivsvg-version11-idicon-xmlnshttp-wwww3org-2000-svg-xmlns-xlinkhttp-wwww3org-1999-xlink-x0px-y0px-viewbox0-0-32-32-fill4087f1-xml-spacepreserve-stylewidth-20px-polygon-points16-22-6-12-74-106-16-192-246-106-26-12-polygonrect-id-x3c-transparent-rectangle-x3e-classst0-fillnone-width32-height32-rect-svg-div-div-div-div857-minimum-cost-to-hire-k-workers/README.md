<h2><a href="https://leetcode.com/problems/minimum-cost-to-hire-k-workers/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>857. Minimum Cost to Hire K Workers</a></h2><h3>Hard</h3><hr><div><p>There are <code>n</code> workers. You are given two integer arrays <code>quality</code> and <code>wage</code> where <code>quality[i]</code> is the quality of the <code>i<sup>th</sup></code> worker and <code>wage[i]</code> is the minimum wage expectation for the <code>i<sup>th</sup></code> worker.</p>

<p>We want to hire exactly <code>k</code> workers to form a paid group. To hire a group of <code>k</code> workers, we must pay them according to the following rules:</p>

<ol>
	<li>Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.</li>
	<li>Every worker in the paid group must be paid at least their minimum wage expectation.</li>
</ol>

<p>Given the integer <code>k</code>, return <em>the least amount of money needed to form a paid group satisfying the above conditions</em>. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> quality = [10,20,5], wage = [70,50,30], k = 2
<strong>Output:</strong> 105.00000
<strong>Explanation:</strong> We pay 70 to 0<sup>th</sup> worker and 35 to 2<sup>nd</sup> worker.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
<strong>Output:</strong> 30.66667
<strong>Explanation:</strong> We pay 4 to 0<sup>th</sup> worker, 13.33333 to 2<sup>nd</sup> and 3<sup>rd</sup> workers separately.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == quality.length == wage.length</code></li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= quality[i], wage[i] &lt;= 10<sup>4</sup></code></li>
</ul>
</div>