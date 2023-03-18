##
# @Graphical User Interface(GUI) Project with Qt5
#
# @section description_main Description
# Cruise Control System with Automatic Emergency Braking.
# This project is for controlling the speed of the car to adapt its speed according to
# the circumstances of the obstacles ahead.
# Also, here we display the current speed and current Distance that the Driver reach at any moment.
# Further more, we display the mode and state of the Cruise Control selected.  
#
# @section notes_main Notes
#   there are nine buttons; Accelerate, Deacelerate, ACC, NCC, CC off ,
#    stop, and a three buttons to choose the Distance Range.
#
# Copyright Information Technology Institute (ITI)(c) 2023.  All rights reserved.


##
# @file main.py
#
# @section libraries_main Libraries/Modules
# - time standard library (https://docs.python.org/3/library/time.html)
#   - Access to sleep function.
# - sys standard library
#   - to exit the GUI
# - serial standard library
#   - to read and write data from UART
# - threading standard library
#   - to run different processes almost, simultaneously.
# - PyQT5 libraries
#   - to build the GUI
#
#
# @section author_main Author(s)
# - Created by Alaa Ashraf, Esraa El-Qassas on 19/02/2023.
#
# Copyright Information Technology Institute (ITI)(c) 2020 .  All rights reserved.




#imports
import sys
import time
import serial
from threading import *
from PyQt5.QtWidgets import QMainWindow, QWidget, QApplication,QLCDNumber,QPushButton,QLabel
import RPi.GPIO as GPIO

################################################################################################
# Import the generated UI
################################################################################################
from interface_ui import Ui_MainWindow as interface_ui

ser = serial.Serial('/dev/ttyAMA0', 9600)                 #to send and recieve data through UART


################################################################################################
# @MAIN WINDOW CLASS
################################################################################################
class MainWindow(QMainWindow, interface_ui):
	mode=0
	def __init__(self, parent=None):
		QMainWindow.__init__(self)
		################################################################################################
		# Setup the UI main window
		################################################################################################
		self.setupUi(self)


		################################################################################################
		# buttons
		################################################################################################
		self.accel.setAutoRepeat(True)
		self.accel.setAutoRepeatDelay(1000)
		self.decl.setAutoRepeat(True)
		self.decl.setAutoRepeatDelay(1000)
		self.accel.clicked.connect(self.accell)            #button to accelerate the motor
		self.decl.clicked.connect(self.decll)              #button to deacelerate the motor
		self.ACC.clicked.connect(self.acc)                 #button to activate Adabtive Cruise Control (ACC) mode
		self.NCC.clicked.connect(self.ncc)                 #button to activate Normal Cruise Control (NCC) mode
		self.CC.clicked.connect(self.cc)                   #button to turn off the cruise control
		self.Range1.clicked.connect(self.thread1)          #button to select range1 of distance ranges
		self.Range2.clicked.connect(self.thread2)          #button to select range2 of distance ranges
		self.Range3.clicked.connect(self.thread3)          #button to select range3 of distance ranges
		self.stop.clicked.connect(self.stopFun)            #button to stop the system

###ffff
		################################################################################################
		# Show window
		################################################################################################
		self.show()


		##############################################################################################
		#customize Analogue Gauge Wadget
		##############################################################################################
		self.widget.enableBarGraph =True

		self.widget.setEnableBarGraph(False)


		#set Gauge units
		self.widget.units = "m/min"

		#set minimum gaugae value
		self.widget.minValue =0


		#set max gaugae value
		self.widget.maxValue =50


		#set scale value
		self.widget.scalacount =5


		##############################################################################################
		#displaying the Analogue widget needle current value on the LCD
		##############################################################################################
		def change(value):
			self.lcd.display(value)

		self.widget.valueChanged.connect(change)




		#select gauage theme
		self.widget.setGaugeTheme(20)                                    #choose number from zero to 24



		self.widget.setScalePolygonColor(
			color1 = "Red",
			color2 = "green",
			color3 = "white"

		)



		self.widget.setNeedleCenterColor(
			color1 = "white" ,
			color2 = "#2D16B3" ,
			color3 = "#green"

		)

		self.widget.setBigScaleColor("white")           #set the Big scaler color
		self.widget.setFineScaleColor("blue")           #set the small scaler color


		self.widget.setScaleValueColor(255,255,255,255)              
		self.widget.setDisplayValueColor(255,255,255,255)

		self.widget.setNeedleColor(255,255,255,255)




		self.widget.setEnableCenterPoint(True)      

		self.widget.setMouseTracking(False)          




    ##############################################################################
    #threads and functions of the buttons
    ##############################################################################
	def thread1(self):
		t1=Thread(target=self.range1)
		t1.start()
        
        
	def thread2(self):
		t1=Thread(target=self.range2)
		t1.start()
        
        
	def thread3(self):
		t1=Thread(target=self.range3)
		t1.start()
        
        
	def thread4(self):
		t1=Thread(target=self.stop)
		t1.start()
        
        
	def threadRead(self):
		t12=Thread(target=self.SerUpdate)
		t12.start()
        
        

        
        
	def accell(self):
		ser.write(b"A")
		print('sent A')
    
    
	def decll(self):
		if self.mode==2:
			self.mode=1
			self.lineEdit_2.clear()
			self.lineEdit_2.setText('NCC')
		ser.write(b"D")
		print('sent D')
        
    
	def acc(self):
		self.lineEdit_2.setText('ACC')
		self.lineEdit_3.setText('CC ON')
		self.mode = 2
		ser.write(b"P")
		print('sent P')
        
        
        
	def ncc(self):
		self.lineEdit_2.setText('NCC')
		self.lineEdit_3.setText('CC ON')
		self.mode = 1
		ser.write(b"N")
		print('sent N')
        
    
    
	def cc(self):
		self.lineEdit_2.clear()
		self.lineEdit_3.setText('CC OFF')
		self.mode =0
		ser.write(b"O")
		print('sent O')

            
            
	def range1(self):
		ser.write(b"C")
		print('sent C')
		
		
	def range2(self):
		ser.write(b"M")
		print('sent M')
		
	def range3(self):
		ser.write(b"F")
		print('sent F')
		
		
		
	def stopFun(self):
		self.lineEdit_2.clear()
		self.lineEdit_3.setText('CC OFF')
		ser.write(b"S")
		print('sent S')





	def SerUpdate(self):
		while(1):
			c=ser.read(1)

			if c == b'\r':
				char=ser.read(22)
				msg=char.split(b' ')
				speed = msg[0].strip(b'\x00\r')
				distance = msg[1].strip(b'\x00\r')

				print("speed = {}".format(speed))
				print("distance = {}".format(distance))
				distance_str=str(distance)
				distance_string=distance_str.strip("b\'")
				Distance_String=distance_string
				for v in distance_string:
					if v == 'x' or v == '\\':
						error =1
						break
					error= 0
				if error==1:
					error=0
					dd_str=distance_string.split("\\")
					Distance_String=dd_str[0].strip("\'")
				self.lineEdit.setText(Distance_String)
				Distance = int(Distance_String)

				speed_str=str(speed)
				speed_string=speed_str.strip("b\'")
				for v in speed_string:
					if v == 'x' or v == '\\':
						error =1
						break
					error= 0
				if error==1:
					error=0
					continue
				Speed= int(speed_string)
				self.widget.updateValue(Speed)
				if Distance <= 10:

					self.mode =0
					self.lineEdit_2.clear()
					self.lineEdit_3.setText('CC OFF')




########################################################################
## EXECUTE APP
########################################################################
########################################################################
#  main function
########################################################################
if __name__ == '__main__':
    app = QApplication(sys.argv)


    window =MainWindow()    #the name of the main class
    window.show()
    window.threadRead()
    sys.exit(app.exec_())

########################################################################
## END
########################################################################
