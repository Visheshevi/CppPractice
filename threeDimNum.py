num = 179424693
prev = 0
#odd_rem = [1,1,1]
#odd_arr = [3,5,7]
main_num = num

def isPrime(num):
	if num<2:
		return 0
	if num==2:
		return 1
	if num%2 == 0:
		return 0
	temp = 3
	while temp*temp <= num:
		if num%temp == 0:
			return 0
		temp +=2
	return 1
			
def isEven(num):
	if num%2 == 0:
		return 1
	else:
		return 0
	

def check(temp_num,prev):
	if (isPrime(temp_num) == 1):
		prev = prev + 1
		#print("In isprime %d" %temp_num)
		return temp_num,prev
	
	elif (isEven(temp_num) == 1):
		temp_num  = temp_num/2	
		num = temp_num
		prev = prev + 1
		#print("in is even %d"  %temp_num)
		return temp_num,prev
	else:
		for i in range (3,round(temp_num/2)):
			if(isPrime(i) == 1):
				if(temp_num % i == 0):
					prev = prev +1
					temp_num = temp_num/i
					return temp_num,prev			
				
		'''
		for i in range(0,len(odd_arr)):
			if(temp_num%odd_arr[i] == 0):
				prev = prev + odd_rem[i]
				temp_num = temp_num/odd_arr[i];
				num = temp_num
				#print("In else %d" %temp_num)		
				#print(prev)		
				return temp_num,prev
		
	'''


while(num>1 and prev < 3 ):
	num,prev = check(num,prev)	
	if(main_num == num):
		break;
	main_num = num;
	#print("In main %d" %num)


if(prev>=3):
	print("can be divided")
else:
	print("cannot")


	
	
	
	

