from Tkinter import Label, Frame, Button, LabelFrame, Tk, Entry, StringVar, LEFT, RIGHT
import urllib, urllib2

class GUI(Frame):
	def __init__(self,parent):
		Frame.__init__(self,parent)
		self.parent = parent
		
		self.ledON = '1'
		self.ledOFF = '0'
		self.initGUI()

	def initGUI(self):
		self.parent.title("Spark Core control")
		self.pack()

		# Initialize Entry widget for device_id and access_token
		self.frmDeviceId = Frame(self)
		self.frmDeviceId.pack()
		self.lblDeviceId = Label(self.frmDeviceId, text="Device ID")
		self.lblDeviceId.pack(side=LEFT)
		self.DeviceId = StringVar()
		self.entryDeviceId = Entry(self.frmDeviceId, textvariable=self.DeviceId)
		self.DeviceId.set("53ff70066678505553201467")
		self.entryDeviceId.pack()

		self.frmAccessToken = Frame(self)
		self.frmAccessToken.pack()
		self.lblDeviceId = Label(self.frmAccessToken, text="Access Token")
		self.lblDeviceId.pack(side=LEFT)
		self.AccessToken = StringVar()
		self.entryAccessToken = Entry(self.frmAccessToken, textvariable=self.AccessToken)
		self.AccessToken.set("f107f8f0fd642b56a2cdf0e88b3bf597761de556")
		self.entryAccessToken.pack()


		self.btnTurnOnLed = Button(self, text="LED ON", command=self.turnLedOn)
		self.btnTurnOnLed.pack()
		self.btnTurnOffLed = Button(self, text="LED OFF", command=self.turnLedOff)
		self.btnTurnOffLed.pack()


	def turnLedOn(self):
		self.path = "https://api.spark.io/v1/devices/" + self.DeviceId.get() + "/control"
		self.access_token = self.AccessToken.get()
		self.command = [('access_token',self.access_token),('args','1')]
		command_encode = urllib.urlencode(self.command)
		request = urllib2.Request(self.path,command_encode)
		urllib2.urlopen(request)


	def turnLedOff(self):
		self.path = "https://api.spark.io/v1/devices/" + self.DeviceId.get() + "/control"
		self.access_token = self.AccessToken.get()
		self.command = [('access_token',self.access_token),('args','0')]
		command_encode = urllib.urlencode(self.command)
		request = urllib2.Request(self.path,command_encode)
		urllib2.urlopen(request)
def main():
	window = Tk()
	window.geometry("300x200")
	mainGUI = GUI(window)
	window.mainloop()

if __name__ == "__main__":
	main()
