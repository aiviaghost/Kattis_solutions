import bz2,re,json,gzip
w=[]
def dfs(d,c,a=0):
    if a:w.append(c)
    for k,v in d.items():
        dfs(v,c+k[0],len(k)>1)
p="[a-zA-Z&']"
f=re.sub
dfs(json.loads(f(":(,|})",lambda x:':{}'+x.group()[1:],f(p+"{",lambda x:'"'+x.group()[:-1]+'":{',f(p+"a",lambda x:f'"{x.group()}":',bz2.decompress(gzip.decompress(open("/src/aa","rb").read())).decode())))),"")
print("\n".join(sorted(x.replace("&","'s") for x in w)))