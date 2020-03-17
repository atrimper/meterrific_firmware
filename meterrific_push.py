import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
from datetime import datetime
import time
cred = credentials.Certificate('meterrific-4202b-firebase-adminsdk-nqhxt-f29096a072.json')
firebase_admin.initialize_app(cred, {
	"databaseURL" : "https://meterrific-4202b.firebaseio.com/"
	})
root = db.reference()
oldTime = time.time()

while(True):
	root.update({
		"globalTime": int(datetime.now().strftime('%H'))
	})
	newTime = time.time()
	metersRef = root.child("meters")
	for meterName in metersRef.get():
		meter = metersRef.child(meterName)
		if (meter.child("purchaseStatus").get()):
			timeRemaining = meter.child("timeRemaining").get() - (newTime - oldTime)
			meter.update({
				"timeRemaining" : timeRemaining
				})
			if timeRemaining <= -10:
				meter.update({
					"purchaseStatus" : 0
					})
	oldTime = newTime
	time.sleep(10)
