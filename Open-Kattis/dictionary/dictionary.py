import bz2,re,json,gzip
w=[]
def dfs(di,curr,app=0):
    if app:
        w.append("".join(curr))
    for k,v in di.items():
        dfs(v,curr+[k[:1]],len(k)>1)
dfs(json.loads(re.sub(":(,|})",lambda x:':{}'+x.group()[1:],re.sub("[a-zA-Z&']{",lambda x:'"'+x.group()[:-1]+'":{',re.sub("[a-zA-Z&']a",lambda x:'"'+x.group()+'":',bz2.decompress(gzip.decompress(open("/src/bin.txt","rb").read())).decode())))),[])
print("\n".join(sorted(map(lambda x:x.replace("&","'s"),w))))