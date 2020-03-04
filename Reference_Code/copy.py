#1. Deep Copy
 # If the contents of the list are primitive data types(int, float, string, boolean), you can use a comprehension
new_list = [i for i in old_list]

 # Multidimensional list
new_grid = [[i for i in row] for row in grid]





#2. 1차원에서는 깊은 복사
#   2차원에서는 얕은 복사 처럼 내부를 수정하면 같이 바뀜
#   그러나 append는 영향 X
list1 = ["list1"]
list2 = ["list2"]
list1.append(list2)

print "원래 list1:",list1

result1 = list1[:]
result2 = list(list1)

print "\n붙인 결과 : "
print "list1[:]\t\t\t\t", result1
print "list(list1)\t\t\t\t", result2

print "\nlist1을 바꿨을 때"
list1.append("list1.append")
list2.append("list2.append")
print "바뀐 list1\t\t\t\t", list1              
print "list1[:]\t\t\t\t", result1
print "list(list1)\t\t\t\t", result2

# 출력:
# 원래 list1: ['list1', ['list2']]
# 
# 붙인 결과 : 
# list1[:]                ['list1', ['list2']]
# list(list1)          ['list1', ['list2']]
# 
# list1을 바꿨을 때
# 바뀐 list1               ['list1', ['list2', 'list2.append'], 'list1.append']
# list1[:]                ['list1', ['list2', 'list2.append']]
# list(list1)          ['list1', ['list2', 'list2.append']]
