#1. Deep Copy

 # If the contents of the list are primitive data types(int, float, string, boolean), you can use a comprehension
new_list = [i for i in old_list]

 # Multidimensional list
new_grid = [[i for i in row] for row in grid]


#2. Shallow Copy

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
