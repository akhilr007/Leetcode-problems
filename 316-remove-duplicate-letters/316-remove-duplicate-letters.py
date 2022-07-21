class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        
        n = len(s)
        visit = set()
        lastIndex = [0]*26
        
        for i in range(n):
            lastIndex[ord(s[i])-ord("a")] = i
        
        st = []
        for i in range(n):
            
            if s[i] in visit:
                continue
            
            visit.add(s[i])
            
            while len(st)>0 and ord(st[-1]) > ord(s[i]) and lastIndex[ord(st[-1]) -ord("a")]>i:
                visit.remove(st.pop())
            
            st.append(s[i])
            
        res = ""
        while st:
            res += st[-1]
            st.pop()
            
        res = res[::-1]
        return res
    