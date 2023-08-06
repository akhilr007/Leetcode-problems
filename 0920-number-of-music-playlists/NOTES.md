for this, we have two options
-> one to take new song
-> one to take old song(replayed song)
​
suppose for n=3, if goal is also 3, then only taking unique songs
_ _ _
for 1 we have 3 options
for 2 we have 2 options
for 3 we have 1 options
​
if we take new song
-> solve(count_song+1, count_unique+1) * (n-count_unique)
if we take old song
->solve(count_song+1, count_unique) * (count_unique-k)
​
why count_unique - k ?
n=3, goal=10, k=2
a b c
for 4th postion, we have 1 option that is a
for 5th position, we have 1 option that is b
for 6th position, we have 1 option that is c
​
for n=3, goal=10, k=1
a b c
for 4th position, we have 2 options (a and b)
for 5th position, we have 2 options
​
so we get a pattern, a b c are unique so count_unique - k