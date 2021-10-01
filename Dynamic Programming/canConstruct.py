def canConstruct(target,wordBank,memo=None):
    
    if memo==None:
        memo={}

    if target == '':
        return True
    elif target in wordBank:
        return True
    elif target in memo:
        return True
    
    result = False

    for i in range(1,len(target)-1):
        if target[:i] in wordBank:
            memo[target]=canConstruct(target[i:],wordBank,memo)
            if memo[target]:
                return   True

    return result


print(canConstruct('abcdef',['ab','abc','cd','def','abcd']))
print(canConstruct('skateboard',['bo','rd','ate','t','ska','sk','boar']))