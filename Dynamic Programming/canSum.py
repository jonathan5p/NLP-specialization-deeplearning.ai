def canSum_fun(target,nums_list,memo=None):
    
    if memo==None:
        memo={}
    if target<0:
        return False
    elif target == 0:
        return True
    elif target in nums_list:
        return True
    elif target in memo:
        return memo[target]
    else:
        node_results = [canSum_fun(target-num,nums_list,memo) for num in nums_list]
        memo[target] = sum(node_results)>0
        return memo[target]


print('init')
print('end',canSum_fun(300,[7,14]))      
print('init')
print(canSum_fun(7,[2,3,4,7]))
print('init')
print(canSum_fun(7,[2,4]))
print('init')
print(canSum_fun(8,[2,3,5]))
