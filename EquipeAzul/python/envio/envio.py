import serial
import socket
from sys import argv
from time import sleep

ser = serial.Serial('/dev/ttyACM0',9600)
sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
endereco = argv[1]
porta = int(argv[2])
destino = (endereco,porta)
sock.connect(destino)


while True:   
    mensagem = ser.readline()
    if mensagem != '':
        mensagem = mensagem.replace('\n','')
        mensagem = mensagem.replace('\r','')
        print(mensagem+'\0')
        sock.send(mensagem)
        sleep(0.9)
