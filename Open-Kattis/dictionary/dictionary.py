import bz2,re,json,gzip
w=[]
def dfs(d,c,a=0):
    if a:w.append(c)
    for k,v in d.items():
        dfs(v,c+k[0],len(k)>1)
p="[a-zA-Z&']"
dfs(json.loads(re.sub(":(,|})",lambda x:':{}'+x.group()[1:],re.sub(p+"{",lambda x:'"'+x.group()[:-1]+'":{',re.sub(p+"a",lambda x:f'"{x.group()}":',bz2.decompress(gzip.decompress(open("/src/aa","rb").read())).decode())))),"")
print("\n".join(sorted(map(lambda x:x.replace("&","'s"),w))))