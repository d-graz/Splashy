from mfrc522 import SimpleMFRC522

def write_to_card(name):
    reader = SimpleMFRC522()

    try:
        print("Posiziona il tuo tag NFC vicino al lettore...")
        reader.write(name)
        print("Scrittura completata")
    finally:
        GPIO.cleanup()

if __name__ == "__main__":
    name = input("Inserisci il nome da scrivere sul tag NFC: ")
    write_to_card(name)
