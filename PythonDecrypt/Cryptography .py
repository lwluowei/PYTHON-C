from cryptography.fernet import Fernet

def generateKey():
    key=Fernet.generate_key()
    with open("secretkey.key","wb+") as key_file:
        key_file.write(key)
def load_key():
    return open("secretkey.key","rb+") .read() 
 
def encypt_message(message):
    key = load_key()
    encoded_message=message.encode()
    f=Fernet(key)
    encry_message = f.encrypt(encoded_message)
    return encry_message

def decypt_message(secret):
    key = load_key()
    f=Fernet(key)
    return (f.decrypt(secret)).decode()

enc_mess=encypt_message("ddddddddddwwffee")
print(decypt_message(enc_mess))
