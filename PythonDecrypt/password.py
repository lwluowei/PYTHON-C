#encoding = utf-8
import base64
import os


from Tkinter import *
import tkSimpleDialog as dl
import tkMessageBox as mb
from cryptography.fernet import Fernet
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
password = b"password"
salt = os.urandom(16)
kdf = PBKDF2HMAC(
    algorithm=hashes.SHA256(),
    length=32,
    salt=salt,
    iterations=390000,
)
root = Tk()
root.lift()

#root.minsize(100, 100)
#root.geometry("+100+50")


root.geometry('0x0+999999+0')
psw = dl.askstring("aa", "bb")
root.destroy()

print(psw)
key = base64.urlsafe_b64encode(kdf.derive(password))
f = Fernet(key)
token = f.encrypt(b"Secret message!")

print(f.decrypt(token))

