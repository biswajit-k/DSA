# Given input string with two parts separated by '#', first part is a group of words, second is group of phrases. 
# For each phrase find all combinations that can be formed from words in first part such that
# all characters of phrase are used once in the characters of those words(ordering doesn't matter)

from typing import Dict, List


def solve(input: str) -> Dict[str, List[List[str]]]:

    ans = {}
    inp = input.split('#')
    dic = inp[0].split('\n')
    phrase = inp[1].split('\n')
    dic = [x for x in dic if len(x) > 0]
    phrase = [x for x in phrase if len(x) > 0]
    
    print(dic)
    print(phrase)

    for p in phrase:
        res = []
        curr = []
        p_dic = {}
        for w in p.split(' '):
            get_dict(w, p_dic)
        # print(p_dic)
        form_words(p_dic, dic, 0, res, curr)
        if len(res) > 0:
            ans[p] = res
    return ans

def form_words(p_dic, dic, idx, res, curr):
    import itertools
    import copy
    if len(p_dic) == 0 and len(curr) > 0:
        x = list(itertools.permutations(curr))
        x = [list(k) for k in x]
        res += x
        return

    if idx == len(dic):
        return

    present = True
    new_dic = copy.deepcopy(p_dic)
    for c in dic[idx]:
        if c not in new_dic:
            present = False
            break
    
    if present:
        print(dic[idx])
        for c in dic[idx]:
            new_dic[c] -= 1
            if new_dic[c] == 0:
                new_dic.pop(c)
        curr.append(dic[idx])
        form_words(new_dic, dic, idx + 1, res, curr)
        curr.pop()
    form_words(p_dic, dic, idx + 1, res, curr)
    

def get_dict(s, dic):
    for c in s:
        dic[c] = dic.get(c, 0) + 1

inp = """THIS
IS
NICE
#
CINE
IS THIS
"""

"""
ans:
{'CINE': [['NICE']], 'IS THIS': [['THIS', 'IS'], ['IS', 'THIS']]}
"""
print(solve(inp))
