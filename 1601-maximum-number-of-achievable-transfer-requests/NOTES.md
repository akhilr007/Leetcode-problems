each request can either be process or not.
if we process the request, decrement from<i> and increment to<i>
if we are exceeded the requests size, find if all the requestProcessed counters are 0 or not, if any non-zero return immediately otherwise store the max