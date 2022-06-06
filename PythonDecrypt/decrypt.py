from cryptography.fernet import Fernet
f2=Fernet(key)
decrpted=f2.decrypt(decrpted)