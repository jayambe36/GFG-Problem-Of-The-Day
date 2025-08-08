class Solution:
	def getLPSLength(self, s):
		# code here
		# ....(j-1)j .....(i-1)i ...
		# lsp[i]: matching length end at index i
		
		n = len(s)
		lsp = [0]*n
		for i in range(1, n):
		    # find the matched length of previous index i-1
		    # then s[j] will be next character on the prefix
		    j = lsp[i-1]
		    # if the current i can't match the coming j (in the prefix)
		    # since lsp[i-1] = j, the prefix with j characters should be
		    # the same as j characters immediately before i. s[i-j:i]
		    # it looks like ...([{}   {}]      [{}   {}])(j) ..............([{}     {}]    [{}    {}])(i).......
		    # the length of () is j, all (), [], {} are equal respectively.
		    #                                                                      
		    while j > 0 and s[i] != s[j]:
		        j = lsp[j-1]
		    if s[i] == s[j]:
		        j += 1
		    lsp[i] = j
        return lsp[-1]
		