from flask import Flask
from flask import request
app = Flask(__name__)

pivalue = '1'
led_state = '0'
#this the page that rpi3 will lesten to it
@app.route('/')
def hello_world():
    global led_state
    x = led_state
    led_state = 0
    return str(x)

#this the page that ifttt will set data, and web server will get
@app.route('/IFTTT')
def Receive():
    global led_state
    led_state = str(request.get_data())
    return ''
