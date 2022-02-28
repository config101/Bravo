number_array=[]
for i in range(256):
	for j in range(256):
		number_array.append(i)
data=bytearray(number_array)
with open("data.bin","wb") as output_file:
	output_file.write(data)
