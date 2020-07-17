def reverse(a, b):
	if len(a) != len(b):
		return ""
	t = ""
	for i in range(1,len(a)+1):
		t += a[-i]+b[-i]
	print(t)
	return t
