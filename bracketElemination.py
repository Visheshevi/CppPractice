import re

class BracketHandler:
	
	def __init__(self):
		self.bracketHandler = list()
		
	def push(self,val):
		self.bracketHandler.append(val)
		
	def pop(self):
		if(len(self.bracketHandler)<=0):
			return ("Empty list")
		return self.bracketHandler.pop()
	
	def peek(self):
		return self.bracketHandler[len(self.bracketHandler) - 1]	
	
	def length(self):
		return len(self.bracketHandler)


flag = 0
pos_count = 0
neg_count = 0
handler = BracketHandler()
line = "{{[[(())]]}}"

for element in line:
	#if(re.match(element,"\[|{|\(|<")):	
	if(element == "{" or element =="[" or element == "(" or element =="<"):
		print("In if %s" %element)
		handler.push(element)
		pos_count += 1
	else:
		print("In else %s" %element)
		temp = handler.pop()
		neg_count +=1
		if((element == "}" and temp != "{") or (element == "]" and temp != "[") or (element == ")" and temp != "(") or (element == ">" and temp != "<")):			
			flag = 1
		

if (flag == 1):
	print("wrong")
elif(flag == 0 and handler.length()>0):
	print("Wrong");
elif(pos_count != neg_count):
	print("Wrong")
else:
	print("Right")
	

