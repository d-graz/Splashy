import RPi.GPIO as GPIO
from mfrc522 import SimpleMFRC522
import threading

class RFIDReader:
    def __init__(self):
        self.reader = SimpleMFRC522()
        self.id = None
        self.text = None
        self.lock = threading.Lock()

    def read_card(self):
        while True:
            try:
                # reading the nfc card: blocking call
                identification, text = self.reader.read()
                print(f"ID: {identification}, text: {text}")
                with self.lock:
                    # set the read data from the card
                    self.id = identification
                    self.text = text.strip()
            except:
                print("HW ERR on NFC module")
                break

    def get_token_data(self):
        with self.lock:
            # get the read data from the card and then cleanup the code
            identification = self.id
            text = self.text
            self.id = None
            self.text = None
        # if the id or text is None, set it to a default value
        if identification is None:
            identification = "None"
        if text is None:
            text = "default"
        return identification, text
    
    def start_reading(self):
        threading.Thread(target=self.read_card, daemon=True).start()
