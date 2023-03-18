import serial
import requests
ser = serial.Serial('/dev/ttyAMA0', 9600)
data="0"
while True:
	date=requests.get("https://esraaalqassas.pythonanywhere.com/")
	if str(date.text) == 'b\'1\'':
		ser.write(b"N")
		print("NCC on")
	elif str(date.text) == 'b\'2\'':
		ser.write(b"O")
		print("CC off")
	else :
		print("invalid response")
