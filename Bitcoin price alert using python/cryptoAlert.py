import conf
import json,time
import requests
from boltiot import Sms,Bolt
selling_price = 600000.00
api_key = "3504af71-041a-45c4-b79f-27aa81c2e572"
device_id = "BOLT3851580"
sms = Sms(conf.SID, conf.AUTH_TOKEN, conf.TO_NUMBER, conf.FROM_NUMBER)
mybolt = Bolt(api_key, device_id)

def price_check():
    url = "https://min-api.cryptocompare.com/data/price"
    querystring = {"fsym":"BTC","tsyms":"INR"}
    response = requests.request("GET", url, params=querystring)
    response = json.loads(response.text)
    current_price = response['INR']
    return current_price

while True:
    market_price = price_check()
    print ('market price is: ',market_price)
    print ('Selling price is: ',selling_price)
    time.sleep(10)
    if market_price > selling_price:
        print("Making request to Twilio to send a SMS")
        response = sms.send_sms("The Current market value of bitcoin is"+str(market_price)+ " it is higher than fixed Selling price so time to Sell now")
        print("Response received from Twilio is: " + str(response))
        print("Status of SMS at Twilio is :" + str(response.status))
        mybolt.digitalWrite("0","HIGH")
        time.sleep(5)
        mybolt.digitalWrite("0","LOW")
        print("Process completed.")
        