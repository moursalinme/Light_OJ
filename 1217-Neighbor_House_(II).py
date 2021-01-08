dp = [0] * 1007

def rec (ar, pos, n) :
	if pos >= n :
		return 0
	if dp[pos] != -1 :
		return dp[pos]

	ans1 = rec (ar, pos+2, n) + ar[pos]
	ans2 = rec (ar, pos+1, n)

	dp[pos] = max (ans1, ans2)
	return dp[pos]

def solve() :
	n = int(input())
	ar = list (map (int, input().split()))
	for k in range (1007) :
		dp[k] = -1
	ans1 = rec (ar, 0, n-1)
	for k in range (1007) :
		dp[k] = -1
	ans2 = rec (ar, 1, n)

	print (max (ans1, ans2))

if __name__ == '__main__':

	for i in range(int(input())) :
		print (f"Case {i+1}:", end = " ")
		solve()